#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <Adafruit_ADS1015.h>
#include <ArduinoLowPower.h>
 
Adafruit_ADS1115 ads;
const float multiplier = 0.1875F;

SoftwareSerial mySerial(6,7);


String Publish = "sensorReading/publish"; //Publish Topic
String Subscribe = "sensorReading/subscribe"; //Subscribe Topic

void GSM_LTE_START(){

//This sets the cellphone provider. In this case, Claro BR is being used as an example.
mySerial.print("AT+CSTT=\"claro.com.br\",\"claro\",\"claro\"\r\n"); //APN name, username, password
  delay(1000);
  mySerial.print("AT+CIPMODE=0\r\n");
  delay(1000);
  mySerial.print("AT+CIICR\r\n");
  delay(5000);

}

void setup() 
{
  Serial.begin(9600);
  ads.setGain(GAIN_SIXTEEN);
  ads.begin();

  mySerial.begin(9600);
  GSM_LTE_START();

  //AT commands sent to the GSM chip for client ID and server address setup. This will establish the communication from now on.
  mySerial.println("ATE0");
  delay(2000);
  mySerial.println("AT+CMQTTSTART"); //Initiating the MQTT connection
  delay(2000); 
  mySerial.println("AT+CMQTTACCQ=0,\"mercurioSensor1\""); //Informing the client ID
  delay(2000);
  mySerial.println("AT+CMQTTCONNECT=0,\"tcp://example.com:00000\",90,1"); //Server address to which the client will connect to
  delay(2000);

  //The delay times set above are for waiting for the data to be sent, but can be substituted by a verification code for AT confirmation codes

  //SUBSCRIBE MESSAGE
  mySerial.println("AT+CMQTTSUBTOPIC=0,9,1"); //AT command for establishing the Subscribe topic's name 
  delay(2000);
  mySerial.println(Subscribe); //Topic's name
  delay(2000);
  mySerial.println("AT+CMQTTSUB=0,5,1,1"); //Sets the length of the message
  delay(2000);
  mySerial.println("START"); //Sends the message
  delay(2000);

}

void loop(){
  
  int16_t adc0;
  int16_t sensor_value;
  int wordCount = 0;
  bool dataTransmission = false;
 
  adc0 = ads.readADC_SingleEnded(0);
  sensor_value = adc0 * multiplier;

//for(i = 0; i < 32000; i++){}
  while(wordCount < 32000){
    mySerial.println("AT+CMQTTTOPIC=0,8"); //AT Command for Setting up the Publish Topic Name
    mySerial.println(Publish); //Topic's name
    mySerial.println("AT+CMQTTPAYLOAD=0,16"); //Payload length
    mySerial.println(sensor_value); //Payload message
    mySerial.println("AT+CMQTTPUB=0,1,60"); //Acknowledgment
    
    wordCount++;
    dataTransmission = true;
  } 
  
  if(dataTransmission == true){
      LowPower.deepSleep(3600000);
      dataTransmission = false;
  }
}
