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
  
  
void loop() {
  l=digitalRead(8);
  r=digitalRead(9);
  if(l==LOW&&r==LOW)
  {
    forward();
  }
  else if(l==LOW&&r==HIGH)
  {
    left();
  }
  else if(l==HIGH&&r==LOW)
  {
    right();
  }
  else
  {
    halt();
  }
  
}
