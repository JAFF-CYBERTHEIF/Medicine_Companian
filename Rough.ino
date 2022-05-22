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

void loop() {
  //Read time from RTC and store in 't'
  t = rtc.getTime();
  
}
