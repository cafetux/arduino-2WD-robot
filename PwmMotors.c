#include "PwmMotors.h"
#include "Arduino.h"

const int minimalSpeed=128; 
int demoIteration;

int MOTOR_RIGHT_SPEED ;   
int MOTOR_RIGHT_DIRECTION ;
int MOTOR_LEFT_SPEED ;                         
int MOTOR_LEFT_DIRECTION ;                           
int DEFAULT_SPEED; 

void initDefaultSpeed(int defaultSpeed){
  DEFAULT_SPEED=defaultSpeed;
}
void initRightMotorPwm(int directionPin,int speedPin){
  MOTOR_RIGHT_SPEED=speedPin;
  MOTOR_RIGHT_DIRECTION=directionPin; 
  pinMode(MOTOR_RIGHT_DIRECTION, OUTPUT);     
}

void initLeftMotorPwm(int directionPin,int speedPin){
  MOTOR_LEFT_SPEED=speedPin;
  MOTOR_LEFT_DIRECTION=directionPin; 
  pinMode(MOTOR_LEFT_DIRECTION, OUTPUT);     
}


void pwmForward(){
  digitalWrite(MOTOR_RIGHT_DIRECTION,HIGH);   
  digitalWrite(MOTOR_LEFT_DIRECTION, HIGH);  
}

void pwmBackward(){
  digitalWrite(MOTOR_RIGHT_DIRECTION,LOW);   
  digitalWrite(MOTOR_LEFT_DIRECTION, LOW);       
}
 
void pwmSpeed(int speedValue){
  analogWrite(MOTOR_RIGHT_SPEED,speedValue);   
  analogWrite(MOTOR_LEFT_SPEED, speedValue);
}
void pwmStop(){
  analogWrite(MOTOR_RIGHT_SPEED,0);   
  analogWrite(MOTOR_LEFT_SPEED, 0);   
}

void pwmTurnLeft(int degrees){
  analogWrite(MOTOR_RIGHT_SPEED,255);   
  digitalWrite(MOTOR_LEFT_DIRECTION, LOW);  
  analogWrite(MOTOR_LEFT_SPEED, 150);
  delay(degrees*4); 
  pwmSpeed(DEFAULT_SPEED);
  pwmForward();
}

void pwmTurnRight(int degrees){
  analogWrite(MOTOR_LEFT_SPEED,255);   
  digitalWrite(MOTOR_RIGHT_DIRECTION, LOW);  
  analogWrite(MOTOR_RIGHT_SPEED, 150);
  delay(degrees*4); 
  pwmSpeed(DEFAULT_SPEED);
  pwmForward();
}

void pwmTurnSmoothRight(int time){
  pwmForward();
  analogWrite(MOTOR_LEFT_SPEED,255);   
  analogWrite(MOTOR_RIGHT_SPEED, 150);
  delay(time*5); 
  pwmSpeed(DEFAULT_SPEED);
  pwmForward();
}
void pwmTurnSmoothLeft(int time){
  pwmForward();
  analogWrite(MOTOR_RIGHT_SPEED,255);   
  analogWrite(MOTOR_LEFT_SPEED, 150);
  delay(time*5); 
  pwmSpeed(DEFAULT_SPEED);
  pwmForward();
}

void showMotorsFeatures(){
  int value;
  if(demoIteration ==1 || demoIteration==3){
    pwmForward();
    pwmSpeed(200);  
  }
  if(demoIteration ==2 || demoIteration==4){
   pwmBackward();
    pwmSpeed(200);      
  }
  if(demoIteration==5){
      pwmTurnRight(30);
  }
  if(demoIteration==6){
      pwmTurnLeft(30);
  }
  
  if(demoIteration>6){
    pwmStop();
  }
  demoIteration+=1;
  delay(1000); 
  }
