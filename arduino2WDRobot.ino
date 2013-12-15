//Arduino PLL Speed Control：
int MOTOR_RIGHT_SPEED = 4;   
int MOTOR_RIGHT = 5;
int MOTOR_LEFT_SPEED = 7;                         
int MOTOR_LEFT = 6;                           
int forwardLimit=128; 

void setup() 
{ 
    pinMode(MOTOR_RIGHT, OUTPUT);   
    pinMode(MOTOR_LEFT, OUTPUT); 
} 
 
void loop() 
{ 
  int value;
  if(false){
  digitalWrite(MOTOR_RIGHT,HIGH);   
  digitalWrite(MOTOR_LEFT, HIGH);       
  }
  analogWrite(MOTOR_RIGHT_SPEED, 130);   //PLL Speed Control
  analogWrite(MOTOR_LEFT_SPEED, 255);   //PLL Speed Control
  delay(300); 
    
}
