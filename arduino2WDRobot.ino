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
  Serial.begin(9600);    
} 
 
void loop() 
{ 
  //showMotorsFeatures();  
}



