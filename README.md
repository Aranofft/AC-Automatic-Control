# AC-Automatic-Control
Small home made electronic project. An AC automatic control device, that switched AC on and off autoumaticely based on temperature sensor and the user defined threshold. Also turns off AC when no occupants are on room based on an HC-SR501 PIR Sensor. Data is shown on an LC screen and user input is given by a small key board.

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










