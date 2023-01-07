#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
int in1 = 6; 
int in2 = 7;
int ConA = 9;
int speed1;

int seconds = 0;
int sensorValue = 0;
int potPin = A0;
int potDegeri = 0;
int motorDegeri = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);
 
void setup() {
 Serial.begin(9600);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT); 
pinMode(9, OUTPUT);

lcd.begin();                                   
lcd.backlight();
  pinMode(A0, INPUT);
  Serial.begin(9600);
  
  lcd.print("POT---MOTOR");
}
 
void LCD(){ 
digitalWrite(in1, LOW); 
digitalWrite(in2, HIGH);
speed1 = analogRead(A0);
speed1 = speed1*0.2492668622;
analogWrite(ConA,speed1);
Serial.println(speed1);
motorDegeri = map(speed1, 0, 1023, 0, 255);

 lcd.setCursor(0, 1);
  lcd.print(speed1);
  lcd.print("--");
  lcd.print(motorDegeri);
  lcd.setBacklight(1);
  delay(1000);
lcd.clear();

}
void loop() {
LCD(); 
}
