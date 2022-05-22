//created by Jawahar B
//Medicine dispenser 
#include <DS3231.h>


DS3231  rtc(SDA, SCL); // CONNECT RTC SDA-PIN 20 & SCL-PIN 21
Time t;//char 't' to store current time

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

//set alarm times(24 HOUR FORMAT)
const int On_Hour_Morning = 08; //Morning alarm ON time
const int On_Min_Morning = 30;
const int Off_Hour_Morning =08; //Morning alarm OFF time
const int Off_Min_Morning = 59;

const int On_Hour_Lunch = 12; //Lunch alarm ON time
const int On_Min_Lunch = 30;
const int Off_Hour_Lunch = 13; //Lunch alarm OFF time
const int Off_Min_Lunch = 20;

const int On_Hour_Night = 20; //Night alarm ON time
const int On_Min_Night = 40;
const int Off_Hour_Night = 21; //Night alarm OFF time
const int Off_Min_Night = 30;

//MEDICINE prescription
const int A_Morning = 2
const int B_Lunch = 1
const int C_Night = 1

const int A_Morning = 1
const int B_Lunch= 2
const int C_Night = 1

const int A_Morning = 1
const int B_Lunch = 1
const int C_Night = 2



void setup() {
  
//Begin RTC
Serial.begin(9600);
rtc.begin();

//defining OUTPUTS & INPUTS

pinMode(AA,OUTPUT);
pinMode(AB,OUTPUT);
pinMode(AC,OUTPUT);
pinMode(AD,OUTPUT);

pinMode(BA,OUTPUT);
pinMode(BB,OUTPUT);
pinMode(BC,OUTPUT);
pinMode(BD,OUTPUT);

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

void loop() {
  //Read time from RTC and store in 't'
t = rtc.getTime();
  // call A_Rev to rotate Stepper A
   // call B_Rev to rotate Stepper B
    // call C_Rev to rotate Stepper C
  
}
