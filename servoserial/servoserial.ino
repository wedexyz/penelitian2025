
#include <EEPROM.h>
#include <ESP32Servo.h>
#define EEPROM_SIZE 1

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo6;

int speed = 15 ;

void setup() {
Serial.begin(9600); 
//EEPROM.begin(EEPROM_SIZE);
EEPROM.begin(EEPROM_SIZE);

myservo1.setPeriodHertz(50); 
myservo2.setPeriodHertz(50); 
myservo3.setPeriodHertz(50); 
myservo4.setPeriodHertz(50); 
myservo5.setPeriodHertz(50); 
myservo6.setPeriodHertz(50); 

myservo1.attach(12);
myservo2.attach(14);
myservo3.attach(27);
myservo4.attach(26);
myservo5.attach(25);
myservo6.attach(33);
EEPROM.write(0, 0);
}



void loop() {
int epr =  EEPROM.read(0);
Serial.println(epr);
if(Serial.available()>0)
{
char data= Serial.read();
switch(data)
{
case 'a':
  for (int i = epr; i < 181; i +=1) {
    Serial.println(i);
    myservo1.write(i);
    myservo2.write(i);
    myservo3.write(i);
    myservo4.write(i);
    //membuat servo bergerak max 
    //if (i>0 && i< 91){myservo5.write(i);}
    //if (i>0 && i< 100){myservo6.write(i);}
    delay(speed);
    EEPROM.write(0, i);
    EEPROM.commit();
  }
  break;

case 'b':
 case 2:
  if (epr >179){
  for (int i = epr; i >= 90; i -=1) {
    Serial.println(i);
    myservo1.write(i);
    myservo2.write(i);
    myservo3.write(i);
    myservo4.write(i);
    //if (i>0 && i< 91){myservo5.write(i);}
    //if (i>0 && i< 100){myservo6.write(i);}
    delay(speed);
    EEPROM.write(0, i);
    EEPROM.commit();
  }
  }else {
   for (int i = epr; i <= 90; i +=1) {
   Serial.println(i);
    myservo1.write(i);
    myservo2.write(i);
    myservo3.write(i);
    myservo4.write(i);
    //if (i>0 && i< 91){myservo5.write(i);}
    //if (i>0 && i< 100){myservo6.write(i);}
    delay(speed);
    EEPROM.write(0, i);
    EEPROM.commit();
    }
  
  
  }
break;

case 'c':
  for (int i = epr; i >= 0; i -=1) {
    Serial.println(i);
    myservo1.write(i);
    myservo2.write(i);
    myservo3.write(i);
    myservo4.write(i);
    
    //if (i>0 && i< 91){myservo5.write(i);}
    //if (i>0 && i< 100){myservo6.write(i);}
    delay(speed);
    EEPROM.write(0, i);
    EEPROM.commit();
  }   
break;

}


}

}
