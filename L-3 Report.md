# Task 1 - Build Chassis
*The objective of the task is to design a complete chassis of an RC car with dimentions compatible to be printed on the 3D printer available in MARVEL and the chassis should be have a calculated weight distribution depending on the application by using any software of our comfort.*


*I used Fusion 360,which is devoloped by Autodesk to design chassis.Fusion 360 is a cloud-based, lightweight CAD software with built-in CAD, CAM, and CAE tools. It supports parametric and direct modeling, AI-driven design, and real-time collaboration. Free for students and hobbyists, it’s ideal for 3D printing and prototyping, while CATIA and SolidWorks excel in large-scale industries.*


## Chassis Dimensions:

- Length: 180 mm

- Width: 90 mm

- Thickness: 4 mm

- Wheel Cutout Diameter: 30 mm

- Mounting Hole Diameter: 3 mm

- Mounting Hole Positions:

(±30, ±40) mm


- Center Hole Diameter: 10 mm

- Center Hole Positions:

(0, 0) mm

(0, ±20) mm


![](https://i.imgur.com/GI9Eh7J.jpeg)

*I designed the chassis by using python script code.Fusion 360 provides a Python API that allows users to automate tasks, create custom features, and enhance workflows.*

[Link for the script code](https://github.com/Deepthianand29/DEEPTHI-ANAND/blob/ANAND/Chassis.py)

# Task 2 - SPI Communication

*SPI (Serial Peripheral Interface) is a synchronous serial communication protocol used to transfer data between a master device (such as a microcontroller) and one or more slave devices (such as sensors, displays, or memory modules). It operates using four main lines:*
![](https://i.imgur.com/UoFWxyl.jpeg
1. MOSI (Master Out, Slave In) – Line which transmits data from master to slave.

2. MISO (Master In, Slave Out) – Line which transmits data from slave to master.

3. SCLK (Serial Clock) –Line for synchronizes data transfer, controlled by the master.

4. SS/CS (Slave Select/Chip Select) – Line for the master to select which slave to send data to.

*One unique benefit of SPI is the fact that data can be transferred without interruption. Any number of bits can be sent or received in a continuous stream. With I2C and UART, data is sent in packets, limited to a specific number of bits. Start and stop conditions define the beginning and end of each packet, so the data is interrupted during transmission.SPI allows high-speed full-duplex communication (sending and receiving data simultaneously) and supports multiple slave devices through separate SS lines or daisy-chaining. It is widely used in embedded systems for applications like SD cards, sensors, and displays.*

*The objective of task is to establish a master-slave communication between two arduino boards using SPI.*

## Components Required

- Two Arduino UNO
- Two 5mm LEDs
- Two Pushbuttons
- Two 220 ohm resistors
- Two 10k ohm resistors
- Connecting Wires
- Breadboard

## Circuit connections
![](https://i.imgur.com/Nx9zSYp.png)

*The connections are as shown in above circuit diagram.*

## Working
*The clock signal synchronizes the output of data bits from the master to the sampling of bits by the slave. One bit of data is transferred in each clock cycle, so the speed of data transfer is determined by the frequency of the clock signal. SPI communication is always initiated by the master since the master configures and generates the clock signal.*

![](https://i.imgur.com/MLFBheg.jpeg)

- The Master reads the push button state and sends it to the Slave via SPI.

- If the button is pressed (HIGH), both the Master and Slave LEDs turn ON.

- If the button is not pressed (LOW), both LEDs remain OFF.

[Link for the arduino code](https://github.com/Deepthianand29/DEEPTHI-ANAND/blob/ANAND/SPI.c)

# Task 3 - I2C Control

*I2C (Inter-Integrated Circuit) is a synchronous serial communication protocol that uses only two wires: SDA (Serial Data) for data transfer and SCL (Serial Clock) for synchronization. It supports multiple masters and multiple slaves using unique addresses instead of separate select lines like SPI. Data is transferred in frames, including address, data, and acknowledgment (ACK/NACK) bits. The master initiates communication, sends the slave address, and determines read/write operations. Advantages include fewer wires, support for multiple devices, and error checking. However, it has a slower data rate than SPI and requires more complex hardware for implementation.*

*Unlike SPI, which requires separate slave select lines, I2C allows multiple masters and multiple slaves to communicate on the same bus using unique addresses, making it highly scalable and efficient for complex systems.*

## Components Required

- Two Arduino UNO
- Connecting Wires
- Breadboard

## Circuit connections

Master (Arduino 1) to Slave (Arduino 2)

- SDA (A4) of Master → SDA (A4) of Slave

- SCL (A5) of Master → SCL (A5) of Slave

- GND of Master → GND of Slave

## Working 
1. The master starts communication by pulling SDA low before SCL.


2. It sends the slave address (7 or 10 bits) with a read/write bit.


3. If the address matches, the slave sends an ACK by pulling SDA low; otherwise, it stays high.


4. Data is then sent or received, with the receiver sending an ACK after each frame.


5. The master stops communication by setting SCL high before SDA.


![](https://i.imgur.com/5PiiWcq.jpeg)
*The master (Arduino 1) sends data to the slave (Arduino 2) and vice versa using I2C. Each Arduino receives the message, stores it, and displays it on the Serial Monitor. This process repeats every second for continuous communication.*

[Link for the code](https://github.com/Deepthianand29/DEEPTHI-ANAND/blob/ANAND/I2C.c)


# Task 4 - BMS

*A Battery Management System (BMS) is a technology that manages and protects a battery pack, which consists of multiple battery cells arranged in a specific order to provide the required voltage and current.*

![](https://i.imgur.com/EWHW2lT.jpeg)

*A BMS mainly does the following:*

- *Monitoring the battery.*
- *Providing battery protection.*
- *Estimating the battery’s operational state.*
- *Continually optimizing battery performance.*
- *Reporting operational status to external devices.*

## How Do Battery Management Systems Work?
*A BMS does not have a fixed design but varies based on battery size, application, safety concerns, and regulations. The key features include battery protection management and capacity management.*

### Battery Pack Protection Management
1. Electrical Protection (Current & Voltage) – Monitors current and voltage to prevent overcharging, over-discharging, and short circuits. It adjusts power flow based on battery conditions.

2. Thermal Protection – Controls battery temperature using heating and cooling systems to prevent overheating or freezing, which can damage battery cells.

### Capacity Management
1. Cell Balancing – Ensures all cells in the battery pack charge and discharge evenly using passive (shunting extra charge) or active (redistributing energy) balancing techniques.

2. State-of-Charge (SOC) Monitoring – Tracks battery charge levels and optimizes charging cycles to extend battery life and efficiency.  

### Types of Battery Management Systems (BMS)
1. Centralized BMS – A single BMS manages the entire battery pack, making it compact and cost-effective. However, it requires extensive wiring, making troubleshooting and maintenance difficult.

2. Modular BMS – Divides the BMS into multiple modules, each handling a section of the battery pack. It simplifies troubleshooting and allows easy expansion but increases costs due to some redundant features.

3. Primary/Subordinate BMS – Similar to modular BMS, but with a master-slave structure where submodules only relay data while the master handles computation and control. This reduces costs by minimizing unnecessary functions.

4. Distributed BMS – Each battery cell/module has its own control board, reducing wiring complexity. However, maintenance is harder, and costs are higher due to multiple BMS units.  

### Benefits of Battery Management Systems (BMS)
- Safety – Prevents overheating, overcharging, and potential hazards, ensuring safe battery operation.

- Longevity & Reliability – Protects cells from extreme usage, enhancing battery lifespan and stability.

- Performance Optimization – Balances cell charge levels to maximize battery capacity and efficiency.

- Diagnostics & Monitoring – Continuously tracks battery health, logs data, and communicates energy status.

- Cost & Warranty Reduction – Minimizes failures and maintenance costs, improving overall system affordability.



# Task 5 - Speed Control of BLDC

*The objective of the task is to control the speed of a BLDC motor using potentiometer. BLDC is a popular motor used in EV. Brushless DC motors (BLDC) feature high efficiency and excellent controllability, and are widely used in many applications.*


## Components used:

1. Brushless Motor
2. ESC 30A 
3. Li-Po battery/VRPS 
4. Arduino Board 
5. Potentiometer
6. Breadboard and Jump Wires

*The speed of BLDC motor can be controlled using potentiometer,with ESC and arduino setup.*
*The ESC (Electronic Speed Controller) plays a crucial role in the speed control of a BLDC motor. It acts as an intermediary between the Arduino and the motor, controlling the power supplied to the motor based on input pwm signals from potentiometer . The ESC ensures smooth operation of the motor, adjusting its speed, direction, and sometimes braking, by regulating the voltage and current delivered to the motor's windings.*

## Circuit connections:

![](https://i.imgur.com/IWXf24k.png)

Arduino to ESC:

1. Pin 9 to PWN signal pin of ESC(yellow wire).
2. 5V to  power pin(red wire) of ESC.
3. GND to ground pin (black wire) of ESC.

ESC to BLDC:

Connect the three output wires (A, B, C) from the ESC to the three input wires of the BLDC motor.


 ESC to LiPo Battery:

1. Connect the red wire (+) of the ESC to the positive terminal of the LiPo battery.

2. Connect the black wire (-) of the ESC to the negative terminal of the LiPo battery.


 Potentiometer to Arduino:

1. Connect one outer pin of the potentiometer to 5V on the Arduino.

2. Connect the other outer pin to GND on the Arduino.

3. Connect the middle pin (wiper) to A0 on the Arduino.

*After doing the connections ,the code is uploaded to the arduino and then the speed of BLDC motor is controlled using potentiometer.*

[Link for github repository for arduino code](https://github.com/Deepthianand29/DEEPTHI-ANAND/blob/ANAND/BLDC%20Speed%20control.c)

![](https://i.imgur.com/jfQalEC.jpeg)
[Link for the video of working](https://youtube.com/shorts/A0FmfAhBXsM?feature=share)

## Task 6 - Make an Atmega32 - Atmega8 Master-Slave SPI Communication

*The goal of this task is to implement mutual SPI communication, where both ATmega32 and ATmega8 can send and receive data in real time. The master initiates the communication, but the slave also transmits data back, ensuring full-duplex communication.*

 ## Components Required
- ATmega32 (Master)

- ATmega8 (Slave)

- Arduino (for serial monitoring)

- 16 MHz Crystal (for both ATmega32 & ATmega8)

- 2x 22pF Capacitors (for each MCU's crystal)

- 10kΩ Resistor (for each MCU's RESET pin)

- Jumper Wires

- Common Ground Connection

## Circuit connection

![](https://i.imgur.com/kjYrFDl.jpeg)


| Signal | ATmega32 (Master) | ATmega8 (Slave) | Arduino (for Programming) |
|--------|------------------|----------------|--------------------------|
| MISO   | PB6             | PB6            | -                        |
| MOSI   | PB5             | PB5            | -                        |
| SCK    | PB7             | PB7            | -                        |
| SS     | PB4             | PB4            | -                        |
| VCC    | 5V              | 5V             | 5V                        |
| GND    | GND             | GND            | GND                        |
| RESET  | RESET (via 10kΩ pull-up) | RESET (via 10kΩ pull-up) | Arduino RESET |
| XTAL1  | 16 MHz Crystal  | 16 MHz Crystal | -                        |
| XTAL2  | 16 MHz Crystal  | 16 MHz Crystal | -                        |

## Additional Notes:
- Connect a **10kΩ pull-up resistor** to the RESET pin of both ATmega32 and ATmega8.
- Add **22pF capacitors** to the crystal oscillator connections.
- Arduino can be used as an **ISP programmer** to upload code.
- Make sure `SS` on the slave is pulled low to activate SPI mode.

[Link for the code](https://github.com/Deepthianand29/DEEPTHI-ANAND/blob/ANAND/Atmega.c)


# Task 7 - Make a Lithium-ion Battery Pack
*The objective of this task is to design a Lithium-Ion battery pack with specific electrical characteristics to meet power requirements. The pack should be configured to achieve a desired voltage, capacity, and discharge rate while ensuring safety, efficiency, and reliability.A 14.8V battery pack was created by connecting individual lithium-ion cells in series.The negative terminal of one cell is connected to the positive terminal of the next cell.
This increases the voltage while maintaining the same capacity as an individual cell.*

![](https://i.imgur.com/pUuboSv.jpeg)

# Task 8 - Working with multiple sensors

*The main objective is to get familiarized with integrating multiple sensors in single task.Actually it is specified in the task to design RC car but due to some glitch in esp32 we were unable to it.So ,we did a environment monitoring system ,which also includes use of multiple sensors.This includes mainly 4 sensors.*
-  LDR for Auto night light,
 - Gas sensor to alarm when the particulate concentration over the threshold value
 - PIR sensor for motion detection.
 - A temparature sensor.

## Components required

1. Arduino Uno

2. TMP36 Temperature Sensor 

3. LDR (Light Dependent Resistor) 

4. MQ Gas Sensor (e.g., MQ-2, MQ-5, etc.) 

5. PIR sensor(For motion detection)
 LED

6. Resistors:
10kΩ, 220Ω

7. Jumper Wires

8. Breadboard 

## Circuit connections
MQ-135 (Air Quality Sensor)

- VCC → 5V

- GND → GND

- AO (Analog Output) → A0

DHT11 (Temperature & Humidity Sensor)

- VCC → 5V

- GND → GND

- Data → D2

LDR (Light Sensor - using voltage divider with 10kΩ resistor)

- One end of LDR → 5V

- Other end → A1 (also connected to a 10kΩ resistor, whose other end goes to GND)

PIR Sensor (Motion Detection)

- VCC → 5V

- GND → GND

- OUT → D3

LED connections
- Anode (long leg) of the LED to digital pin 4.

- Cathode (short leg) to a 220-ohm resistor, and the other end of the resistor to GND

## Working

*The circuit integrates multiple sensors to monitor environmental parameters such as temperature, humidity, air quality, light intensity, and motion detection. The system collects data from these sensors and displays the values on the Serial Monitor. Additionally, it controls an LED based on ambient light intensity.*
![](https://i.imgur.com/OKu4NPi.jpeg)
![](https://i.imgur.com/lx5iPFK.jpeg)
[Linl for the code](https://github.com/Deepthianand29/DEEPTHI-ANAND/blob/ANAND/EM.c)
