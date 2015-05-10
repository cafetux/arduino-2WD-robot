#include "PwmMotors.c";

#define echoPin 13
#define triggerPin 12
#define motorRightDirectionPin 4
#define motorRightSpeedPin 5
#define motorLeftDirectionPin 7
#define motorLeftSpeedPin 6

#define BLOCKED 10
#define NEAR_OBSTACLE 5
#define FARAWAY_OBSTACLE 3
#define NO_OBSTACLE 0


void setup() 
{ 
  initPing(echoPin, triggerPin);
  initRightMotorPwm(motorRightDirectionPin, motorRightSpeedPin);   
  initLeftMotorPwm(motorLeftDirectionPin, motorLeftSpeedPin); 
  initDefaultSpeed(SPEED_MEDIUM);
   
  initLogger(9600);    
} 
 
void loop() 
{ 
    
  switch(detect()){
     case BLOCKED: 
        pwmSpeed(SPEED_SLOW);
        pwmBackward();
        break;
     case NEAR_OBSTACLE: 
        if(random(0,2)==1){
          pwmTurnLeft(90);
        }else{
          pwmTurnRight(90);
        }
        break;
     case FARAWAY_OBSTACLE:
      pwmSpeed(SPEED_MEDIUM);
      if(random(0,2)==1){
          pwmTurnSmoothRight(20);
        }else{
          pwmTurnSmoothLeft(20);
        }
         break;
     default:
        pwmForward();
        pwmSpeed(SPEED_MEDIUM);
    }
  delay(100); 
}

int detect(){
  int distance=pingDistanceInCm();
  logger("distance: {} cm",distance);
  if(distance<10){
      return BLOCKED;
  }
  if(distance<30){
    return NEAR_OBSTACLE;
  }
  if(distance<50){
    return FARAWAY_OBSTACLE;
  }
  return NO_OBSTACLE; 
}




