
const int smokeA0=A0;
const int ledpin=13; // ledpin,flamepin and buzpin are not changed throughout the process
const int flamepin=A2;
const int buzpin=11;
const int dhp=7;
const int threshold=200;// sets threshold value for flame sensor
int flamesensvalue=0;// initialize flamesensor 
int dhpsenvalue=0;

#include <LCD_I2C.h>



LCD_I2C lcd(0x27); // Default address of most PCF8574 modules, change according

void setup()
{
  Serial.begin(9600);
pinMode(ledpin,OUTPUT);
pinMode(smokeA0, INPUT);
pinMode(flamepin,INPUT);
pinMode(buzpin,OUTPUT);
    lcd.begin(); // If you are using more I2C devices using the Wire library use lcd.begin(false)
                 // this stop the library(LCD_I2C) from calling Wire.begin()
    lcd.backlight();
}

void loop()
{
  flamesensvalue=analogRead(flamepin); // reads analog data from flame sensor
if(flamesensvalue>=threshold) { // compares reading from flame sensor with the threshold value
digitalWrite(ledpin,HIGH); //turns on led and buzzer
tone(buzpin,1000);
delay(1000); //stops program for 1 second
    lcd.print("Fire!Fire!"); // You can make spaces using well... spaces
    lcd.setCursor(1, 0); // Or setting the cursor in the desired position.
    lcd.print("Run!!!");
    delay(1000);



    lcd.backlight();
    lcd.clear();
    delay(10);

}
else{
digitalWrite(ledpin,LOW); //turns led off led and buzzer
noTone(buzpin);
}}
