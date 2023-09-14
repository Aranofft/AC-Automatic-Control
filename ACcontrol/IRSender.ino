//www.elegoo.com
//2016.12.9
#include <IRLibSendBase.h>    //We need the base code
#include <IRLib_HashRaw.h>    //Only use raw sender
#include <dht.h>
#include <LiquidCrystal.h>
#define dht_apin A0 // Analog Pin sensor is connected to

int ledPin = 13;  // LED on Pin 13 of Arduino
int pirPin = A5; // Input for HC-S501
int pirValue; 

int pressed_ON=0;
int pressed_OFF=0;
dht DHT;
// char customKey1;
// int out=0;
int in=0;
int temp_count = 0;
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {4, A3, A2, 6}; //connect to the row pins (R0-R3) of the keypad
byte colPins[COLS] = {5, 2, A1}; //connect to the column pins (C0-C2) of the keypad
//Create an object of keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
int last;
int temp;

// int tempPin = A0;
//                BS  E  D4 D5  D6 D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
IRsendRaw mySender;
int THRESHOLD;
// int THRESHOLD_new;
void setup()
{
  delay(3000);
  THRESHOLD=25;
  lcd.begin(16, 2);
  Serial.begin(9600);
  // delay(1000); 
  // while (!Serial); //delay for Leonardo
  Serial.println("DHT11 Humidity & temperature Sensor");
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
 
  digitalWrite(ledPin, LOW);


  DHT.read11(dht_apin);
  temp = DHT.temperature-1;
  list_temp = [temp];
  lcd.setCursor(0, 0);
  last = 0;
  lcd.print("         C ");
  lcd.setCursor(6, 0);
  lcd.print(temp);
  lcd.setCursor(0, 1);
  lcd.print("Turn ON at >   C");
  lcd.setCursor(12, 1);
  // Display Temperature in C
  lcd.print(THRESHOLD);
}
#define RAW_DATA_LEN 350
uint16_t rawDataOff1[RAW_DATA_LEN]=
{
	3046, 3086, 3042, 4462, 542, 1678, 542, 562, 
	538, 1682, 542, 562, 538, 562, 538, 1682, 
	538, 1682, 542, 558, 542, 1678, 542, 562, 
	538, 562, 538, 1682, 538, 562, 538, 562, 
	538, 566, 510, 586, 542, 562, 538, 562, 
	538, 562, 538, 562, 542, 562, 534, 562, 
	538, 566, 538, 562, 538, 562, 538, 562, 
	538, 562, 538, 562, 542, 562, 538, 562, 
	538, 562, 538, 562, 538, 562, 538, 562, 
	538, 562, 538, 562, 542, 562, 538, 562, 
	538, 562, 538, 562, 542, 1678, 538, 562, 
	538, 1682, 542, 558, 542, 558, 542, 558, 
	542, 562, 542, 558, 542, 558, 542, 558, 
	542, 558, 542, 558, 546, 558, 566, 534, 
	570, 530, 546, 554, 570, 530, 570, 534, 
	566, 1650, 570, 534, 570, 554, 546, 554, 
	546, 530, 570, 530, 570, 530, 570, 530, 
	570, 530, 570, 530, 570, 530, 570, 530, 
	574, 526, 570, 530, 570, 530, 570, 530, 
	570, 534, 566, 534, 562, 538, 562, 538, 
	538, 562, 558, 542, 534, 566, 558, 542, 
	534, 566, 530, 570, 530, 574, 526, 574,
	526, 574, 526, 574, 526, 574, 526, 578, 
	522, 598, 502, 598, 498, 606, 494, 606, 
	474, 626, 470, 630, 470, 630, 470, 630, 
	470, 634, 466, 634, 466, 634, 466, 1754, 
	466, 634, 462, 1758, 462, 1758, 462, 1758, 
	462, 1758, 462, 1758, 462, 1758, 462, 638, 
	462, 1758, 462, 1754, 466, 1000};
	
	

#define RAW_DATA_LEN 350
uint16_t rawDataOn1[RAW_DATA_LEN]=	{
	3082, 3050, 3054, 4454, 546, 1674, 550, 550, 
	550, 1670, 550, 554, 546, 554, 546, 1674, 
	546, 1674, 574, 526, 546, 1674, 550, 554, 
	546, 554, 546, 1670, 550, 554, 546, 554, 
	570, 1646, 550, 554, 546, 554, 550, 550, 
	574, 526, 546, 554, 546, 558, 546, 554, 
	546, 554, 546, 554, 570, 530, 546, 554, 
	570, 530, 562, 538, 546, 554, 570, 530, 
	570, 534, 570, 530, 542, 558, 570, 1646, 
	570, 530, 570, 534, 566, 534, 566, 534,
	566, 534, 566, 534, 566, 1650, 570, 534, 
	566, 1650, 566, 538, 562, 538, 562, 538, 
	562, 538, 546, 554, 562, 538, 558, 542, 
	534, 566, 534, 566, 534, 566, 534, 566, 
	534, 566, 558, 542, 534, 570, 530, 570, 
	526, 1690, 530, 574, 526, 574, 526, 574, 
	526, 574, 526, 574, 526, 574, 522, 578, 
	522, 582, 518, 602, 498, 606, 494, 602, 
	498, 606, 494, 606, 494, 606, 470, 630, 
	470, 630, 470, 630, 470, 630, 470, 630, 
	466, 634, 466, 638, 462, 638, 462, 638, 
	462, 638, 462, 638, 462, 638, 462, 638, 
	466, 634, 466, 634, 466, 638, 462, 638, 
	462, 638, 462, 638, 462, 638, 462, 638, 
	462, 638, 462, 638, 462, 638, 462, 638, 
	462, 638, 466, 638, 462, 638, 462, 1754, 
	482, 622, 458, 1758, 462, 662, 454, 630, 
	458, 1778, 442, 1778, 438, 1782, 438, 1782, 
	438, 662, 438, 1782, 438, 1000};
	
	
void loop() {
  //check if people are present:
  pirValue = digitalRead(pirPin);
  digitalWrite(ledPin, pirValue);
  // Serial.print("pirValue:");
  // Serial.println(pirValue);
  // Serial.print("pirValue: ");
  // Serial.println(pirValue);
  //get typing of threshold:
  char customKey1 = customKeypad.getKey();
  Serial.println(customKey1);
  // delay(500);
  // int NEW_THRESHOLD;
  if (customKey1){
    int custom = customKey1-'0';
    Serial.println("hhh");
    THRESHOLD = 20+ custom;
    // if(THRESHOLD!=THRESHOLD_new){
    //   THRESHOLD = THRESHOLD_new;
    lcd.setCursor(12, 1);
    // Display Temperature in C
    lcd.print(THRESHOLD);
    // }
  }
  else{
    delay(1000);
  }
  // Serial.println(THRESHOLD);
  DHT.read11(dht_apin);
  temp_count = temp_count +1;
  if(temp_count>=10){
    if (temp>=15){
      temp = DHT.temperature-1;}
    // temp = DHT.temperature;
    lcd.setCursor(6, 0);
    lcd.print(temp);
    temp_count = 0;
  }

  
  if(pirValue==0)//person is not present
  {
    if(in>-100){
    in=in-1;}
    else{
      last = -1;
      lcd.setCursor(0, 0);
      lcd.print("OUT");
    }
    // in=0;
  }
  else {
    if(in<30){
      in=in+10;}
    else{
      last = 1;
      lcd.setCursor(0, 0);
      lcd.print("IN");
    }
    // if (in>=50){
    //   lcd.setCursor(0, 0);
    //   lcd.print("IN ");}
      // out=0;
      // in=in+1;
  }
  // Serial.print("out: ");
  // Serial.println(out);
  Serial.print("in: ");
  Serial.println(in);
  if ((in>=30) && (temp > THRESHOLD) && (pressed_ON<2)) {
    mySender.send(rawDataOn1,RAW_DATA_LEN,36);//Pass the buffer,length, optionally frequency
    lcd.setCursor(0, 0);
    lcd.println(F("AC Switched On  "));
    // lcd.setCursor(0, 0);
    // lcd.print("AC Switched On  ");
    delay(1000);
    // lcd.setCursor(0, 0);
    lcd.setCursor(0, 0);
    lcd.print("IN       C  ");
    // else{
    //   lcd.print("         C  ");
    // }
    lcd.setCursor(6, 0);
    lcd.print(temp);
    pressed_ON=pressed_ON+1;
    pressed_OFF=0;
  }
  else if (((in<=-100) || (temp <= THRESHOLD)) && (pressed_OFF<2)){
    mySender.send(rawDataOff1,RAW_DATA_LEN,36);//Pass the buffer,length, optionally frequency
    lcd.setCursor(0, 0);
    lcd.print("AC Switched Off ");
    delay(1000);
    
    // if (in<=-30){
    //   // in = 0;
    //   last = -1;
    //   lcd.setCursor(0, 0);
    //   lcd.print("OUT      C  ");}
    //   else {
    // lcd.setCursor(0, 0);
    switch (last){
      case 0: 
      lcd.setCursor(0, 0);
      lcd.print("         C  ");
      // continue;
      case 1: 
      lcd.setCursor(0, 0);
      lcd.print("IN       C  ");
      break;
      case -1: 
      lcd.setCursor(0, 0);
      lcd.print("OUT      C  ");
      break;
      }
    //   default:
    // // statements
    //   lcd.print("         C  ");
    //   break;
        // lcd.print(last);
        // out = 0;
    
      // else {lcd.print("         C  ");}
    lcd.setCursor(6, 0);
    lcd.print(temp);
    
    pressed_OFF=1+pressed_OFF;
    pressed_ON=0;
  }
    
}
