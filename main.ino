#include <Wire.h>
#include "RTClib.h"

DateTime now;
char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

RTC_DS3231 rtc;
const int On_Hour = 19; //Morning alarm ON time
const int On_Min = 19;
const int Off_Hour =19; //Morning alarm OFF time
const int Off_Min = 20;
#define NUMBER_OF_STEPS_PER_REV 512//512 steps per revolution EDIT THIS TO ADJUST STEPPER 

//Stepper motor 1
#define AA 2
#define AB 3
#define AC 4
#define AD 5
//stepper motor 2
#define BA 6
#define BB 7
#define BC 8
#define BD 9
//stepper motor 3
#define CA 10
#define CB 11
#define CC 12
#define CD 13

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
  if (now.hour() == On_Hour && now.minute() == On_Min){
  A_Rev();
  A_Rev();
  B_Rev();
}
}
