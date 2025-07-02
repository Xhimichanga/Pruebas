#include "TimerOne.h"
#include <Servo.h> 
Servo myservo; 
int potpin = A0; 
int potpin2 = 5; // analog pin used to connect the potentiometer
int val1;    // variable to read the value from the analog pin 
int duty;
int freq;
int period;
void setup()
{
  //pq tengo un programa de un servo aqui?
  freq=1/period;
  

  pinMode(13, OUTPUT);
  Timer1.initialize(freq);         // initialize timer1, and set a 1/2 second period
  Timer1.pwm(13, duty, freq);                // setup pwm on pin 9, 50% duty cycle
  Timer1.attachInterrupt(callback);  // attaches callback() as a timer overflow interrupt
}

void callback()
{
  digitalWrite(13, digitalRead(13) ^ 1);
}

void loop()
{
   duty = analogRead(potpin2); 
    duty = map(duty, 0, 1023, 0, 100); 
   period = analogRead(potpin); 
    period = map(period, 0, 1023, 20, 500000); 
  Timer1.pwm(13, duty, freq);
}
