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
int secondled;
void setup()
{
 pinMode(buttonpin, INPUT);
 pinMode(5, OUTPUT); //First led 
pinMode(2, INPUT);   //Button
pinMode(6, OUTPUT);  //Second led
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
     
// Code that turns the led on
while (kirkkaus < 100){
  kirkkaus =(kirkkaus+1);
  secondled =(secondled-1);
  delay(10);
  analogWrite(5, kirkkaus);
  analogWrite(6, secondled); //additional LED
}
     state = 1;
   }
   else // if the state is on, turn it off
   {

    // Code that makes the led turn off
while (kirkkaus > 0){
  kirkkaus =(kirkkaus-1);
  secondled =(secondled+1);
  delay(10);
  analogWrite(5, kirkkaus);
  analogWrite(6, secondled); //additional LED
}
     kirkkaus = 0;
     secondled = 100;
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
