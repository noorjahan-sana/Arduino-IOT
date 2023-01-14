int l=0,r=0;
void setup() {
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
}
  void forward()
  {
  digitalWrite(2, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(7, LOW);
  }
  
 //for left right
 void left(){
 digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(7, LOW);
 }
  void right(){
  digitalWrite(2, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
  }
  //for stop(halt)
  void halt(){
   digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
  }
  
   void backward()
  {
  digitalWrite(2, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(7, HIGH);
  }
  //LOW->OBJECT
  //HIGH->NOOBJECT
void loop() {
  l=digitalRead(8);
  r=digitalRead(9);
  if(l==HIGH&&r==HIGH)
  {
    forward();
  }
  else if(l==LOW&&r==HIGH)
  {
    right();
  }
  else if(l==HIGH&&r==LOW)
  {
    left();
  }
  else if(l==LOW&&r==LOW)
  {
    backward();
    delay(2000);
    left();
    delay(2000);
  }
  
}
