#include <DHT.h>

#define DHTPIN 2          // DHT11 data pin
#define DHTTYPE DHT11     // Define DHT type
DHT dht(DHTPIN, DHTTYPE);

#define MQ135_PIN A0      // MQ135 sensor analog pin
#define LDR_PIN A1        // LDR analog pin
#define PIR_PIN 3         // PIR digital pin
#define LED_PIN 4         // LED pin for low light intensity

void setup() {
    Serial.begin(9600);
    dht.begin();
    pinMode(PIR_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);  // Initialize the LED pin
}

void loop() {
    // Read DHT11 data
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    // Read air quality from MQ135
    int air_quality = analogRead(MQ135_PIN);

    // Read light intensity from LDR
    int light_intensity = analogRead(LDR_PIN);

    // Read motion from PIR sensor
    int motion_detected = digitalRead(PIR_PIN);

    // Print data to Serial Monitor
    Serial.println("========== Environment Monitoring ==========");
    Serial.print("Temperature: "); Serial.print(temperature); Serial.println(" °C");
    Serial.print("Humidity: "); Serial.print(humidity); Serial.println(" %");
    Serial.print("Air Quality (MQ-135): "); Serial.println(air_quality);
    Serial.print("Light Intensity (LDR): "); Serial.println(light_intensity);
    Serial.print("Motion Detected: "); Serial.println(motion_detected ? "YES" : "NO");
    Serial.println("============================================");

    // Check if light intensity is very low (e.g., less than 300)
    if (light_intensity < 300) {
        digitalWrite(LED_PIN, HIGH);  // Turn on LED if light is low
    } else {
        digitalWrite(LED_PIN, LOW);   // Turn off LED if light is sufficient
    }

    delay(2000); // Wait for 2 seconds before next reading
}
