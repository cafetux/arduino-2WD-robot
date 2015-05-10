


void initLogger(int serial){
 Serial.begin(serial);   
}

void logger(String message){
  Serial.println(message);
}
void logger(String pattern,String value){
  pattern.replace("{}",value);
  logger(pattern);
}
void logger(String pattern,int value){
  logger(pattern,String(value));
}
