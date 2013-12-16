#define echoPin 13
#define triggerPin 12
#define motorRightDirectionPin 4
#define motorRightSpeedPin 5
#define motorLeftDirectionPin 7
#define motorLeftSpeedPin 6

void setup() 
{ 
  initPing(echoPin, triggerPin);
  initRightMotorPwm(motorRightDirectionPin, motorRightSpeedPin);   
  initLeftMotorPwm(motorLeftDirectionPin, motorLeftSpeedPin); 
  initLogger(9600);    
} 
 
void loop() 
{ 
  //Serial.println(new String("distance:").concat(distance).concat(" cm"));
  if(seeObstacle()){
    pwmSpeed(200);
    pwmForward();
  }else{
    pwmStop();
  }
  
  delay(100); 
}

boolean seeObstacle(){
  int distance=pingDistanceInCm();
  logger("distance: {} cm",distance);
  return distance>20;
}



