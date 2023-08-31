/* rawR&cv.ino Example sketch for IRLib2
 *  Illustrate how to capture raw timing values for an unknow protocol.
 *  You will capture a signal using this sketch. It will output data the 
 *  serial monitor that you can cut and paste into the "rawSend.ino"
 *  sketch.
 */
// Recommend only use IRLibRecvPCI or IRLibRecvLoop for best results
#include <IRLibRecvPCI.h> 

IRrecvPCI myReceiver(2);//pin number for the receiver

char *str;

void setup() {
  Serial.begin(9600);
  delay(2000); while (!Serial); //delay for Leonardo
  myReceiver.enableIRIn(); // Start the receiver
  Serial.println(F("Ready to receive IR signals"));
  myReceiver.setFrameTimeout(100000);
  
}

void loop() {
  //Continue looping until you get a complete signal received
  if (myReceiver.getResults()) { 
    Serial.println(F("Do a cut-and-paste of the following lines into the "));
    Serial.println(F("designated location in rawSend.ino"));
    Serial.print(F("\n#define RAW_DATA_LEN "));
    Serial.println(recvGlobal.recvLength,DEC);
    Serial.print(F("uint16_t rawData[RAW_DATA_LEN]={\n\t"));
    str = "{\n\t";
    for(bufIndex_t i=1;i<recvGlobal.recvLength;i++) {
      str = strcat(str, recvGlobal.recvBuffer[i]);
      str = strcat(str, ", ");
      // str = str + recvGlobal.recvBuffer[i]+", ";
      Serial.print(recvGlobal.recvBuffer[i],DEC);
      Serial.print(F(", "));
      if( (i % 8)==0) {
      Serial.print(F("\n\t"));
      str = strcat(str, "\n\t");}
    }
    Serial.println(F("1000};"));//Add arbitrary trailing space
    // Serial.println(F("som"));
    Serial.print(str);
    myReceiver.enableIRIn();      //Restart receiver
    
  }
}

