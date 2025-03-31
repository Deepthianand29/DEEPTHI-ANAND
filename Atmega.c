//MASTER CODE(ATMEGA32)
#define SS PB4
#define MOSI PB5
#define MISO PB6
#define SCK PB7

void SPI_MasterInit() {
    DDRB |= (1 << MOSI) | (1 << SCK) | (1 << SS); // MOSI, SCK, SS as output
    DDRB &= ~(1 << MISO); // MISO as input
    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0); // Enable SPI, Master mode, SCK = Fosc/16
}

char SPI_Transceive(char data) {
    SPDR = data;  // Load data into the SPI data register
    while (!(SPSR & (1 << SPIF))); // Wait until transmission complete
    return SPDR; // Return received data
}

void setup() {
    Serial.begin(9600);
    SPI_MasterInit();
    delay(100);
}

void loop() {
    char received = SPI_Transceive('M'); // Master sends 'M' and receives data from Slave
    Serial.print("Master received: ");
    Serial.println(received);
    delay(1000);
}

//SLAVE CODE(ATMEGA8)

#define SS PB2
#define MOSI PB3
#define MISO PB4
#define SCK PB5

void SPI_SlaveInit() {
    DDRB |= (1 << MISO); // MISO as output
    DDRB &= ~((1 << MOSI) | (1 << SCK) | (1 << SS)); // MOSI, SCK, SS as input
    SPCR = (1 << SPE); // Enable SPI in Slave mode
}

char SPI_SlaveTransceive(char data) {
    while (!(SPSR & (1 << SPIF))); // Wait until reception complete
    char received = SPDR; // Read received data
    SPDR = data;  // Send new data back to Master
    return received;
}

void setup() {
    Serial.begin(9600);
    SPI_SlaveInit();
}

void loop() {
    char received = SPI_SlaveTransceive('S'); // Slave sends 'S' and receives data from Master
    Serial.print("Slave received: ");
    Serial.println(received);
}

