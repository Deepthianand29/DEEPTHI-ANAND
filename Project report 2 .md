# *Project Report: Object Counter using ESP32-CAM and FTDI Module*  

## *1. Introduction*  
In industries, retail stores, and automation applications, counting objects is crucial for tracking inventory, optimizing processes, and ensuring accuracy. This project implements an *Object Counter using ESP32-CAM*, a low-cost Wi-Fi-enabled microcontroller with a camera module, to count objects using image processing.  

## *2. Objectives*  
- Develop an *automated object counter* using ESP32-CAM.  
- Use *image processing techniques* to detect and count objects.  
- Display the *counted objects on a web interface* using ESP32’s built-in server.  
- Interface the *ESP32-CAM with an FTDI Module* for programming and debugging.  

## *3. Components Required*  

| Component   | Description                                    |
|------------|--------------------------------|
| *ESP32-CAM*  | Wi-Fi-enabled microcontroller with an OV2640 camera |
| *FTDI Module* | USB to TTL serial converter for programming ESP32-CAM |
| *Power Supply* | 5V DC source |
| *Infrared (IR) LEDs* (optional) | Enhances object detection in low light |
| *Resistors & Capacitors* | Basic circuit elements for stability |
| *Jumper Wires* | For connections |

![](https://i.imgur.com/FmRHWe6.jpeg)

## *4. Working Principle*  

1. The *ESP32-CAM captures images* of objects passing in front of its camera.  
2. The *image processing algorithm* detects objects based on edge detection or color thresholding.  
3. A *counting algorithm* updates the object count based on movement or detected shape boundaries.  
4. The *ESP32-CAM hosts a web interface*, displaying the live object count.  
5. The *FTDI module* is used to program and debug the ESP32-CAM, allowing USB communication with a computer.  

## *5. Circuit Connections*  
![](https://i.imgur.com/IcpQEHm.jpeg)

### *ESP32-CAM to FTDI Module Wiring*  
| ESP32-CAM Pin | FTDI Module Pin |
|--------------|----------------|
| *U0TXD* | *RX* |
| *U0RXD* | *TX* |
| *GND* | *GND* |
| *5V* | *VCC (5V)* |
| *GPIO0* | *GND* (Only for programming mode) |

### *ESP32-CAM to Power Supply*  
- *5V pin* of ESP32-CAM to *5V Power Source*  
- *GND pin* to *Power Source GND*  

## *6. Software Implementation*  

### *6.1 Tools Required*
- *Arduino IDE* (for programming ESP32-CAM)  
- *ESP32 board package* (installed via Arduino IDE)  
- *OpenCV* (optional, for advanced image processing)  
- *Web Server Code* (to host object count on a webpage)  
[Link for the code.](https://github.com/Deepthianand29/Project2)
## *7. Web Server Interface*  

- The ESP32-CAM runs a *web server* to display the *object count in real-time*.
- The webpage fetches the latest count from ESP32-CAM using *AJAX requests*.


![](https://i.imgur.com/qfPg7A9.jpeg)
## *8. Advantages & Applications*  

### *Advantages*  
✔ Low-cost implementation  
✔ Wireless monitoring via Wi-Fi  
✔ No additional sensors required  

### *Applications*  
- *Factory automation* – Counting products in an assembly line  
- *Retail stores* – Tracking items on shelves  
- *Smart parking systems* – Counting available parking slots  

## *9. Future Improvements*  
- *Machine Learning Integration* for better accuracy  
- *Cloud Data Storage* for analytics  
- *Battery-powered version* for portability  

## *10. Conclusion*  
The *ESP32-CAM Object Counter* is a simple yet effective automation project that enables real-time object counting using a camera module. The integration with a *web server* makes monitoring easy from any device connected to the same network.

---

### *References*  
- [ESP32-CAM Documentation](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/hw-reference/esp32-cam.html)  
- [OpenCV for ESP32](https://github.com/espressif/esp-who)
