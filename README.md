# USB LED matrix - availability status at the workstation
## Link to Busylight Client: [Busylight Client](https://github.com/doubleSlashde/Busylight-Client)
## USB API
### Update light color
```plantuml
@startuml
"Java Client" -> "Controller" : REQUEST_IMAGE_CHANGE (0x02)
"Controller" -> "Java Client" : READY_FOR_IMAGE_CHANGE (0x03)
"Java Client" -> "Controller" : data (size: 2+n*3 byte;[brightness] [numbersOfLEDs] [red] [green] [blue] [red] [green] [blue] ...)
"Controller" -> "Java Client" : SUCCESSFULLY_TRANSMITTED_IMAGE (0x04)
@enduml
```

### Connection
```plantuml
@startuml
"Java Client" -> "Controller" : REQUEST_FOR_CONNECTION (0x00)
"Controller" -> "Java Client" : ANSWER_CONNECTION (0x01)
@enduml
```

### Check for connection loss
```plantuml
@startuml
"Java Client" -> "Controller" : CONNECTION_CHECK (0x05)
"Controller" -> "Java Client" : ANSWER_CONNECTION_CHECK (0x06)
@enduml
```

### Check for Versioning
```plantuml
@startuml
"Java Client" -> "Controller" : REQUEST_VERSION = (0x07)
"Controller" -> "Java Client" : ANSWER_VERSION = (0x08)
"Controller" -> "Java Client" : VERSION
@enduml
```

---

## Hardware
1. [WEMOS D1 Mini: ](https://www.wemos.cc/en/latest/d1/d1_mini.html)  
   <img src="readme/wemos_d1_mini.png " alt="WEMOS D1 Mini" width="400">  
1. [Micro USB cable: ](https://www.cyberport.de/pc-und-zubehoer/kabel-zubehoer/kabel/good-connections/pdp/4b02-37m/good-connections-micro-usb-2-0-kabel-1m-usb-a-stecker-micro-b-stecker.html)  
   <img src="readme/Micro_USB_Kabel.jpg " alt="Micro USB cable" width="400">  
1. [Jumper cable 3 pcs: ](https://www.berrybase.de/40pin-jumper/dupont-kabel-male-female-trennbar?number=DUPK-40-FM-20)  
   <img src="readme/jumper_Kabel.jpg " alt="Jumper cable" width="400">
1. [LED Strip WS2812b 10 LEDs: ](https://www.amazon.de/HJHX-LED-Streifen-individuell-adressierbar-Lichterkette/dp/B078S6Z9KG)  
   <img src="readme/LED_Strip.jpg " alt="LED Strip" width="400">
   

### How are the LEDs connected on the WEMOS?
GND ---->  Must be on GND  
+5V ----> Must be on 5V  
DIN ----> Is freely assignable (currently in the code at D7)  

<img src="readme/Wemos_LED_verbindung.png " alt="WEMOS LED connection" width="620">  
[WEMOS D1-mini](https://www.wemos.cc/en/latest/d1/d1_mini.html)


### How are the LEDs connected on the M5?
GND ---->  Must be on GND  
+5V ----> Must be on 5V  
DIN ----> Is freely assignable (currently in the code at G33)  

<img src="readme/M5_LED_verbindung.png " alt="M5 LED connection" width="620">  
[M5-Stack](https://www.bastelgarage.ch/m5stack-atom-matrix-esp32-development-kit)  

The DIN connection can be set in the [platformio.ini](platformio.ini) with the property `-DPIXEL_PIN=xx` to be changed.

### You can install the Busylight e.g. on the monitor
<img src="readme/LED_Monitor.jpg" alt="LED Monitor" width="260">
<img src="readme/Wemos_Monitor.jpg" alt="WEMOS Monitor" width="335">

---

## Update to MC with Visual Studio Code
1. Start Visual Studio Code and open the Busylight Microcontroller folder.  
   <img src="readme/Datei_oeffnen.png " alt="Open project" width="320">
1. First of all, you need to install PlatformIO IDE.  
   <img src="readme/PlatformIO.png " alt="Install PlatformIO" width="320">  
1. After that you can click on the ant on the side and then you just have to press "Upload".  
   <img src="readme/Icon_Upload.png " alt="Upload Firmware" width="320">
