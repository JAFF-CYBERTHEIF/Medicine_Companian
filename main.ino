#include <Wire.h>
#include "RTClib.h"

DateTime now;
char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

RTC_DS3231 rtc;
const int On_Hour = 21; //Morning alarm ON time
const int On_Min = 48;

#define NUMBER_OF_STEPS_PER_REV 256//512 steps per revolution EDIT THIS TO ADJUST STEPPER 

//buzzer
#define buzzer 22
//green light
#define green 23

//stepper motor 1
#define AB 2
#define AA 3
#define AD 4
#define AC 5
//stepper motor 2
#define BB 6
#define BA 7
#define BD 8
#define BC 9
//stepper motor 3
#define CB 10
#define CA 11
#define CD 12
#define CC 13

void setup ()
{
  Serial.begin(9600);
   if (! rtc.begin()) 
  {
    Serial.println("Couldn't find RTC Module");
    while (1);
  }

  if (rtc.lostPower()) 
  {
    Serial.println("RTC lost power, lets set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  //defining OUTPUTS & INPUTS
  
pinMode(buzzer,OUTPUT);  
//stepper A
pinMode(AA,OUTPUT);
pinMode(AB,OUTPUT);
pinMode(AC,OUTPUT);
pinMode(AD,OUTPUT);
//stepper B
pinMode(BA,OUTPUT);
pinMode(BB,OUTPUT);
pinMode(BC,OUTPUT);
pinMode(BD,OUTPUT);
//stepper C
pinMode(CA,OUTPUT);
pinMode(CB,OUTPUT);
pinMode(CC,OUTPUT);
pinMode(CD,OUTPUT);
 
}
//CODE to run Stepper A
void Awrite(int a,int b,int c,int d){
digitalWrite(AA,a);
digitalWrite(AB,b);
digitalWrite(AC,c);
digitalWrite(AD,d);
}
void Aonestep(){
Awrite(1,0,0,0);
delay(1);
Awrite(1,1,0,0);
delay(1);
Awrite(0,1,0,0);
delay(1);
Awrite(0,1,1,0);
delay(1);
Awrite(0,0,1,0);
delay(1);
Awrite(0,0,1,1);
delay(1);
Awrite(0,0,0,1);
delay(1);
Awrite(1,0,0,1);
delay(1);
}
void A_Rev(){
int i;
i=0;
while(i<NUMBER_OF_STEPS_PER_REV){
Aonestep();
i++;
}
}
//CODE to run Stepper B
void Bwrite(int a,int b,int c,int d){
digitalWrite(BA,a);
digitalWrite(BB,b);
digitalWrite(BC,c);
digitalWrite(BD,d);
}
void Bonestep(){
Bwrite(1,0,0,0);
delay(1);
Bwrite(1,1,0,0);
delay(1);
Bwrite(0,1,0,0);
delay(1);
Bwrite(0,1,1,0);
delay(1);
Bwrite(0,0,1,0);
delay(1);
Bwrite(0,0,1,1);
delay(1);
Bwrite(0,0,0,1);
delay(1);
Bwrite(1,0,0,1);
delay(1);
}
void B_Rev(){
int i;
i=0;
while(i<NUMBER_OF_STEPS_PER_REV){
Bonestep();
i++;
}
}
//CODE to run Stepper C
void Cwrite(int a,int b,int c,int d){
digitalWrite(CA,a);
digitalWrite(CB,b);
digitalWrite(CC,c);
digitalWrite(CD,d);
}
void Conestep(){
Cwrite(1,0,0,0);
delay(1);
Cwrite(1,1,0,0);
delay(1);
Cwrite(0,1,0,0);
delay(1);
Cwrite(0,1,1,0);
delay(1);
Cwrite(0,0,1,0);
delay(1);
Cwrite(0,0,1,1);
delay(1);
Cwrite(0,0,0,1);
delay(1);
Cwrite(1,0,0,1);
delay(1);
}
void C_Rev(){
int i;
i=0;
while(i<NUMBER_OF_STEPS_PER_REV){
Conestep();
i++;
}
}

void loop () 
{
  now = rtc.now();
  Serial.print(now.hour());
  Serial.print(':');
  Serial.print(now.minute());
  Serial.print(':');
  Serial.print(now.second());
  Serial.println(" ");
  if (now.hour() == On_Hour && now.minute() == On_Min && now.second()==0){
    digitalWrite(green, HIGH);
    digitalWrite(buzzer,HIGH);
    delay(2000);
    digitalWrite(buzzer,LOW);
    digitalWrite(green, HIGH);
  A_Rev();
  B_Rev();
  B_Rev();
  C_Rev();
  
}
}
