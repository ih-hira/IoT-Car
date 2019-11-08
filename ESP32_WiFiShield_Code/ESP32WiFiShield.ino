#include <BlynkSimpleEsp32.h>
#include <SPI.h>
#include <WiFi.h>
#include <WiFiClient.h>
#define BLYNK_PRINT Serial

#define forwardRightDir 16
#define forwardLeftDir 17
#define backwardLeftDir 18
#define backwardRightDir 19
#define neutralZone 4

#define interruptPin 25

const float pi = 3.1416;
const int total_slot = 40;
const float r = 1.75;
int count;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "04848b6400fe498d9a845f90d543f560";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "iotcar";
char pass[] = "iotcar1996";

int minRange = 312;
int maxRange = 712;


void moveControl(int x,int y)
{
  //move forward
  if(y >= maxRange && x >= minRange && x <= maxRange)
  {
    digitalWrite(forwardRightDir,HIGH);
    digitalWrite(forwardLeftDir,HIGH);
    digitalWrite(backwardLeftDir,HIGH);
    digitalWrite(backwardRightDir,HIGH);
  }
  
  //move forward right
  else if(x >= maxRange && y >= maxRange)
  {
    digitalWrite(forwardRightDir,HIGH);
    digitalWrite(forwardLeftDir,LOW);
    digitalWrite(backwardLeftDir,LOW);
    digitalWrite(backwardRightDir,HIGH);
  }

  //move forward left
  else if(x <= minRange && y >= maxRange)
  {
    digitalWrite(forwardRightDir,LOW);
    digitalWrite(forwardLeftDir,HIGH);
    digitalWrite(backwardLeftDir,HIGH);
    digitalWrite(backwardRightDir,LOW);
  }

  //neutral zone
  else if(y < maxRange && y > minRange && x < maxRange && x > minRange)
  {
    digitalWrite(forwardRightDir,LOW);
    digitalWrite(forwardLeftDir,LOW);
    digitalWrite(backwardLeftDir,LOW);
    digitalWrite(backwardRightDir,LOW);
    digitalWrite(neutralZone,LOW);
  }

  //move back
  else if(y <= minRange && x >= minRange && x <= maxRange)
  {
    digitalWrite(forwardRightDir,LOW);
    digitalWrite(forwardLeftDir,LOW);
    digitalWrite(backwardLeftDir,LOW);
    digitalWrite(backwardRightDir,LOW);
    digitalWrite(neutralZone,HIGH);
  }

  //move back and right
  else if(y <= minRange && x >=maxRange)
  {
    digitalWrite(forwardRightDir,HIGH);
    digitalWrite(forwardLeftDir,LOW);
    digitalWrite(backwardLeftDir,HIGH);
    digitalWrite(backwardRightDir,LOW);
  }
  
  //move back and left
  else if(y <= minRange && x <=minRange)
  {
    digitalWrite(forwardRightDir,LOW);
    digitalWrite(forwardLeftDir,HIGH);
    digitalWrite(backwardLeftDir,LOW);
    digitalWrite(backwardRightDir,HIGH);
  }
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  
  pinMode(forwardRightDir,OUTPUT);
  pinMode(forwardLeftDir,OUTPUT);
  pinMode(backwardLeftDir,OUTPUT);
  pinMode(backwardRightDir,OUTPUT);
  pinMode(neutralZone,OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
BLYNK_WRITE(V1)
{
  int x = param[0].asInt();
  int y = param[1].asInt();
  moveControl(x,y);
}
