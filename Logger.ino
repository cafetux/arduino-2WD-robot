


void initLogger(int serial){
 Serial.begin(serial);   
}


void logger(String pattern,String value){
  pattern.replace("{}",value);
  Serial.println(pattern);
}
void logger(String pattern,int value){
  String valueString=String(value);
  pattern.replace("{}",valueString);
  Serial.println(pattern);
}
