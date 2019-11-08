#include <AFMotor.h>
//initialize motor instances
AF_DCMotor forwardRightMotor(3);
AF_DCMotor forwardLeftMotor(4);
AF_DCMotor backwardLeftMotor(1);
AF_DCMotor backwardRightMotor(2);

//define motor direction
#define forwardRightDir 22
#define forwardLeftDir 23
#define backwardLeftDir 24
#define backwardRightDir 25
#define neutralZone 26

//speed
int minSpeed = 80;
int maxSpeed = 255;
int noSpeed = 0;
void setup()
{
  // put your setup code here, to run once:
  pinMode(forwardRightDir,INPUT);
  pinMode(forwardLeftDir,INPUT);
  pinMode(backwardLeftDir,INPUT);
  pinMode(backwardRightDir,INPUT);
  pinMode(neutralZone,INPUT);
}

void moveControl()
{
  int m1 = digitalRead(forwardRightDir);
  int m2 = digitalRead(forwardLeftDir);
  int m3 = digitalRead(backwardLeftDir);
  int m4 = digitalRead(backwardRightDir);
  int n_zone = digitalRead(neutralZone);
  
  //move forward
  if(m1==HIGH && m2==HIGH && m3==HIGH && m4==HIGH)
  {
    forwardRightMotor.setSpeed(maxSpeed);
    forwardLeftMotor.setSpeed(maxSpeed);
    backwardLeftMotor.setSpeed(maxSpeed);
    backwardRightMotor.setSpeed(maxSpeed);
    
    forwardRightMotor.run(FORWARD);
    forwardLeftMotor.run(FORWARD);
    backwardLeftMotor.run(FORWARD);
    backwardRightMotor.run(FORWARD);
  }
  
  //move forward right
  else if(m1==HIGH && m2==LOW && m3==LOW && m4==HIGH)
  {
    forwardRightMotor.setSpeed(minSpeed);
    forwardLeftMotor.setSpeed(maxSpeed);
    backwardLeftMotor.setSpeed(maxSpeed);
    backwardRightMotor.setSpeed(minSpeed);
    
    forwardRightMotor.run(FORWARD);
    forwardLeftMotor.run(FORWARD);
    backwardLeftMotor.run(FORWARD);
    backwardRightMotor.run(FORWARD);
  }

   //move forward left
  else if(m1==LOW && m2==HIGH && m3==HIGH && m4==LOW)
  {
    forwardRightMotor.setSpeed(maxSpeed);
    forwardLeftMotor.setSpeed(minSpeed);
    backwardLeftMotor.setSpeed(minSpeed);
    backwardRightMotor.setSpeed(maxSpeed);
    
    forwardRightMotor.run(FORWARD);
    forwardLeftMotor.run(FORWARD);
    backwardLeftMotor.run(FORWARD);
    backwardRightMotor.run(FORWARD);
  }

  //move back
  else if(m1==LOW && m2==LOW && m3==LOW && m4==LOW && n_zone)
  {
    forwardRightMotor.setSpeed(maxSpeed);
    forwardLeftMotor.setSpeed(maxSpeed);
    backwardLeftMotor.setSpeed(maxSpeed);
    backwardRightMotor.setSpeed(maxSpeed);
    
    forwardRightMotor.run(BACKWARD);
    forwardLeftMotor.run(BACKWARD);
    backwardLeftMotor.run(BACKWARD);
    backwardRightMotor.run(BACKWARD);
  }

  //move back and right
  else if(m1==HIGH && m2==LOW && m3==HIGH && m4==LOW)
  {
    forwardRightMotor.setSpeed(minSpeed);
    forwardLeftMotor.setSpeed(maxSpeed);
    backwardLeftMotor.setSpeed(maxSpeed);
    backwardRightMotor.setSpeed(minSpeed);
    
    forwardRightMotor.run(BACKWARD);
    forwardLeftMotor.run(BACKWARD);
    backwardLeftMotor.run(BACKWARD);
    backwardRightMotor.run(BACKWARD);
  }

  //move back and left
  else if(m1==LOW && m2==HIGH && m3==LOW && m4==HIGH)
  {
    forwardRightMotor.setSpeed(maxSpeed);
    forwardLeftMotor.setSpeed(minSpeed);
    backwardLeftMotor.setSpeed(minSpeed);
    backwardRightMotor.setSpeed(maxSpeed);
    
    forwardRightMotor.run(BACKWARD);
    forwardLeftMotor.run(BACKWARD);
    backwardLeftMotor.run(BACKWARD);
    backwardRightMotor.run(BACKWARD);
  }
  else
  {
    forwardRightMotor.run(RELEASE);
    forwardLeftMotor.run(RELEASE);
    backwardLeftMotor.run(RELEASE);
    backwardRightMotor.run(RELEASE);
  }
}
void loop() 
{
  moveControl();
}

