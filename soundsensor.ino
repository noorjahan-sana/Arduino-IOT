int count=0;
void setup() {
 Serial.begin(9600);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(8,INPUT);
}

void loop() {
  Serial.print(digitalRead(8));
  delay(500);
  if(digitalRead(8)==HIGH)
  {
    count++;
    //Serial.print(count);
    if(count==1)
    {
      digitalWrite(3,HIGH);
      delay(500);
    }
    if(count==2)
    {
      digitalWrite(4,HIGH);
      delay(500);
    }
    if(count==3)
    {  
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      delay(500);
      count=0;
    }
  }
   
}
