# AC-Automatic-Control
Home made electronics project. An AC control device that switched AC ON and OFF autoumaticely based on a temperature sensor and the user defined threshold. Also turns off AC when no occupants are in room based on the motion detection of an HC-SR501 PIR Sensor. Data is shown on an LC screen and user input is given by a small key board.

Project was performed with the help of the project:
https://github.com/LokeshPatil-loki/akarsh98-Automatic-AC-Control-using-Arduino

With significant upgrates including: the addition of presence detection, manual threshold changing using the keypad, LCD screen for watching current temperature, AC state, presence state and chosed threshold.

## First stage- detect AC codes from AC remote
Equipment:
1. IR reciever
2. 3 jump wires
3. AC remote
4. Arduino uno
   
See figure below:

<img src="https://github.com/Aranofft/AC-Automatic-Control/assets/139975410/46c411d5-6c6d-4735-ae4e-8625cc9fe3d0" width="300" height="200">

Figure 1

Connect components according to the scheme below:

<img src="https://github.com/Aranofft/AC-Automatic-Control/assets/139975410/17041fe9-b1fc-4f93-b514-4f6b3e882243" width="300" height="200">

Figure 2

Connect arduino to computer, open Arduino IDE and burn the code file 'IRreciever'.
Turn AC ON and OFF infront of the IR reciever. Copy the printed code from the serial monitor in the Arduino IDE and save it somewhere.

## Second stage- paste codes
While the Arduino is connected by USB cable to the computer, turn the AC remote control infronte of the IR reciever and turn the AC ON and OFF.
Open the serial monitor in the IDE and copy the given codes to a notepad or equivalent. Open the IRSender code and replace the rawDataOn1 and rawDataOff1 codes with the copied ones, correspondingly to the ON and OFF states.

## Third stage- Build AC automatic control
Equipment:
1. Arduino Uno
2. M-M Junper wires
3. Breadboard
4. 940nm IR emitter
5. 470 ohm resistor
6. 2N2222 transistor
7. DHT11 Temperature snd humidity sensor
8. Power supply module
9. LCD1602 module
10. Potentiometer (10k)
11. 3 X 4 Keyboard
12. HC-SR501 PIR motion sensor
13. Toggle switch ON-OFF 2Pin
14. 9V Battery
15. 9V Battery holder box

See figure below:

<img src="https://github.com/Aranofft/AC-Automatic-Control/assets/139975410/b59040a8-83d2-4abc-9f01-67e20f34f18e" width="300" height="200">

Figure 3

Connect components according to the scheme below:

<img src="https://github.com/Aranofft/AC-Automatic-Control/assets/139975410/b3c27241-e6b1-402b-881d-f34d3d40bbc3" width="300" height="200">

Figure 4

The connected system looks as follows:

<img src="https://github.com/Aranofft/AC-Automatic-Control/assets/139975410/5b0a80a6-8dab-42c0-a0e7-3e5613320443" width="300" height="200">

Figure 5

After some arrangements:

<img src="https://github.com/Aranofft/AC-Automatic-Control/assets/139975410/8b9470db-4b91-4456-b72a-109b5686e159" width="300" height="200">

Figure 6








