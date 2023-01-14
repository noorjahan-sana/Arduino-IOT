Servo myservo;
int ir=A0;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(D4);
  pinMode(ir,INPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  int pos;
  if(digitalRead(ir)==0)
  {
    myservo.write(0);
    delay(100);
    
  }
  else
  {
    myservo.write(90);
    delay(100);
    
  }

}
