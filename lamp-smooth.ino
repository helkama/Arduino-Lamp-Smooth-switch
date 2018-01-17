// bytes are half the size of int's, but restricted to a max value of 255
byte button;
byte oldbutton = 0;
byte buttonpin = 2;
byte state = 0;
int sensorValue;
int kirkkaus;
int kek;
int buttonState = 0;
int lastButtonState = 0;
void setup()
{
 pinMode(buttonpin, INPUT);
 pinMode(5, OUTPUT);
pinMode(2, INPUT);
Serial.begin(9600);
}

void loop()
{
 button = digitalRead(buttonpin);
 if(button && !oldbutton) // same as if(button == high && oldbutton == low)
 {
   //we have a new button press
   if(state == 0) // if the state is off, turn it on
   {
     //do stuff
     /* do{
    // statement block
    kirkkaus =(kirkkaus+1);
  delay(30);
} */ while (kirkkaus < 100){
  kirkkaus =(kirkkaus+1);
  delay(10);
  analogWrite(5, kirkkaus);
}
     state = 1;
   }
   else // if the state is on, turn it off
   {
while (kirkkaus > 0){
  kirkkaus =(kirkkaus-1);
  delay(10);
  analogWrite(5, kirkkaus);
}
     kirkkaus = 0;
     state = 0; 
   }
   oldbutton = 1;
 }
 else if(!button && oldbutton) // same as if(button == low && oldbutton == high)
 {
   // the button was released
   oldbutton = 0;
 }
 analogWrite(5, kirkkaus);
}
