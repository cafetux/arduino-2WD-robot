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
  initLogger(9600);    
} 
 
void loop() 
{ 
  switch(detect()){
     case BLOCKED: 
        pwmSpeed(150);
        pwmBackward();
        break;
     case NEAR_OBSTACLE: 
        pwmTurnLeft(90);
        break;
     case FARAWAY_OBSTACLE:
         pwmTurnSmoothRight(30);
         break;
     default:
        pwmSpeed(200);
        pwmForward();
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




