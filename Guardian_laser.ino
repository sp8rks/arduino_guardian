//Copyright Taylor Sparks 2018 (10-31-2018). Feel free to use this code but please retain attribution. 
//If you use the code for your own project send me a picture of your creation! sparks@eng.utah.edu

const int buttonPin = 13; 
int brightness = 0;
int brightadd = 15;
int brightness1 = 25;    // how bright the LEDStar is for star1
int fadeAmount1=10;
int counter=0;
int trigger=1;
int pause = 100;
int Wone=5;
int Wtwo=6;
int Pone=10;
int Yone=11;
int Ptwo=2;
int Ytwo=3;
int Bone=4;
int Gone=7;
int Btwo=8;
int Gtwo=12;
int Rone=9;
//free pins 10,11
int buttonState=LOW;


void setup() {
  // initialize the LED pins as output:
  pinMode(Wone, OUTPUT);
  pinMode(Wtwo, OUTPUT);
  pinMode(Pone, OUTPUT);
  pinMode(Ptwo, OUTPUT);
  pinMode(Yone, OUTPUT);
  pinMode(Ytwo, OUTPUT);
  pinMode(Bone, OUTPUT);
  pinMode(Btwo, OUTPUT);
  pinMode(Gone, OUTPUT);
  pinMode(Gtwo, OUTPUT);
  pinMode(Rone, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {

buttonState = digitalRead(buttonPin);
if (buttonState == LOW){
  trigger=-trigger;
}

if (trigger == 1) {
    if (brightness1 <= (0+10) || brightness1 >= (255-10)) {
    fadeAmount1 = -fadeAmount1;
  }

   analogWrite(Rone, brightness1);
  brightness1 = brightness1 + fadeAmount1;
  // wait for 30 milliseconds to see the dimming effect
  delay(30); 
}

if (trigger == -1) {
   analogWrite(Rone, 255);
if(counter<8){
digitalWrite(Btwo,HIGH);
delay(pause);
digitalWrite(Btwo,LOW);
digitalWrite(Gtwo,HIGH);
delay(pause);
digitalWrite(Gtwo,LOW);
digitalWrite(Bone,HIGH);
delay(pause);
digitalWrite(Bone,LOW);
digitalWrite(Gone,HIGH);
delay(pause);
digitalWrite(Gone,LOW);
counter=counter+1;
}

if(counter>=8 && counter<16){
digitalWrite(Btwo,HIGH);
digitalWrite(Yone,HIGH);
delay(pause);
digitalWrite(Btwo,LOW);
digitalWrite(Yone,LOW);
digitalWrite(Gtwo,HIGH);
digitalWrite(Pone,HIGH);
delay(pause);
digitalWrite(Gtwo,LOW);
digitalWrite(Pone,LOW);
digitalWrite(Bone,HIGH);
digitalWrite(Ytwo,HIGH);
delay(pause);
digitalWrite(Bone,LOW);
digitalWrite(Ytwo,LOW);
digitalWrite(Gone,HIGH);
digitalWrite(Ptwo,HIGH);
delay(pause);
digitalWrite(Gone,LOW);
digitalWrite(Ptwo,LOW);
counter=counter+1;
}

if(counter>=8) {
analogWrite(Wone,brightness);
brightness=brightness+brightadd;
}

if(counter==16) {
  analogWrite(Wone,255);
  analogWrite(Wtwo,255);
  delay(750);
  analogWrite(Wone,0);
  analogWrite(Wtwo,0);
  delay(250);
  analogWrite(Wone,255);
  analogWrite(Wtwo,255);
  delay(750);
  analogWrite(Wone,0);
  analogWrite(Wtwo,0);
  delay(250);
  analogWrite(Wone,255);
  analogWrite(Wtwo,255);
  delay(750);
  analogWrite(Wone,0);
  analogWrite(Wtwo,0);
  delay(250);
  counter=0;
  trigger=1;
}
}
}
