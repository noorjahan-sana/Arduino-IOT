int count=0;
void setup() {
 
 pinMode(2,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(7,OUTPUT);
  pinMode(8,INPUT); 
}
void forward()
  {
  digitalWrite(2, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(7, LOW);
  }
  void backward()
  {
  digitalWrite(2, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(7, HIGH);
  }
   void halt(){
   digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
  }
void loop() {

  if(digitalRead(8)==HIGH)
  {
    count++;
    //Serial.print(count);
    if(count==1)
    {
      forward();
      delay(50);
    }
    if(count==2)
    {
      backward();
      delay(50);
    }
    if(count==3)
    {  
      halt();
      delay(50);
      count=0;
    }
  }
   
}
