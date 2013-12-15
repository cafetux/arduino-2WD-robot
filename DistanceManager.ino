int ECHO_PIN ;
int TRIGGER_PIN ;



void initPing(int echoPintoInit, int triggerPintoInit){
  ECHO_PIN=echoPintoInit;
  TRIGGER_PIN=triggerPintoInit;
  pinMode(TRIGGER_PIN, OUTPUT);     
  pinMode(ECHO_PIN, INPUT);  
}

int pingDistanceInCm(){
  int duration, distance;
  digitalWrite(TRIGGER_PIN, HIGH);
  //delayMicroseconds(1000);
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  return ((duration/2) / 29.1);
}


