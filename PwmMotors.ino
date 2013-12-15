int MOTOR_RIGHT_SPEED ;   
int MOTOR_RIGHT_DIRECTION ;
int MOTOR_LEFT_SPEED ;                         
int MOTOR_LEFT_DIRECTION ;                           
int minimalSpeed=128; 


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
  delay(degrees*10); 
  pwmForward();
}

void pwmTurnRight(int degrees){
  analogWrite(MOTOR_LEFT_SPEED,255);   
  digitalWrite(MOTOR_RIGHT_DIRECTION, LOW);  
  analogWrite(MOTOR_RIGHT_SPEED, 150);
  delay(degrees*10); 
  pwmForward();
}

void test(){
  analogWrite(MOTOR_RIGHT_SPEED,135);   
  analogWrite(MOTOR_LEFT_SPEED, 255);  
  delay(10000); 
}