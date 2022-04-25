#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <LiquidCrystal.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  510 // this is the 'maximum' pulse length count (out of 4096)


// our servo # counter
int servoNum1 = 0, servoNum2 = 1, servoNum3 = 2, servoNum4 = 3, servoNum5 = 4, servoNum6 = 5;
int valueServo1,valueServo2,valueServo3,valueServo4,valueServo5,valueServo6 ;  // variable to read the value from bluetooth
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  lcd.begin(16,2);
  lcd.print("Servo Bluetooth");
  Serial.begin(9600);
}

void loop() {
      lcd.setCursor(0,1);
  while (Serial.available()<2) {} // Wait 'till there are 2 Bytes waiting {first byte == Servo Number; Secound byte== Angle}
  if(Serial.available()>0){
      int servoNum=Serial.read();
      int angle=Serial.read();
      switch (servoNum) {
      case 1:
        valueServo1 = map(angle, 0, 180, 45,150); // to resolve weird proteus bug {Maybe not necessary with real hardware}
        valueServo1 = map(valueServo1, 0, 180, SERVOMIN,SERVOMAX);
        pwm.setPWM(servoNum1, 0, valueServo1); 
        lcd.print("Grip");
        break;
      case 2:
      valueServo2 = map(angle, 0, 180, 45,150);
        valueServo2 = map(valueServo2, 0, 180, SERVOMIN,SERVOMAX);
        pwm.setPWM(servoNum2, 0, valueServo2);
        lcd.print("Wrist Pitch");
        break;
        case 3:
        valueServo3 = map(angle, 0, 180, 45,150);
        valueServo3 = map(valueServo3, 0, 180, SERVOMIN,SERVOMAX);
        pwm.setPWM(servoNum3, 0, valueServo3);
        lcd.print("Wrist Roll");
        break;
        case 4:
        valueServo4 = map(angle, 0, 180, 45,150);
        valueServo4 = map(valueServo4, 0, 180, SERVOMIN,SERVOMAX);
        pwm.setPWM(servoNum4, 0, valueServo4);
        lcd.print("Elbow");
        break;
        case 5:
        valueServo5 = map(angle, 0, 180, 45,150);
        valueServo5 = map(valueServo5, 0, 180, SERVOMIN,SERVOMAX);
        pwm.setPWM(servoNum5, 0, valueServo5);
        lcd.print("Shoulder");
        break;
        case 6:
        valueServo6 = map(angle, 0, 180, 45,150);
        valueServo6 = map(valueServo6, 0, 180, SERVOMIN,SERVOMAX);
        pwm.setPWM(servoNum6, 0, valueServo6);
        lcd.print("Waist");
        break;
      default:
        lcd.print(angle);
        break;
    }
         delay(15);
     }
}
