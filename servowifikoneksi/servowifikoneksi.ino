#include <WiFi.h>
#include <ESPAsyncWebServer.h>
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

const char* ssid = "tanganrobot";
const char* password = "tanganrobot";
AsyncWebServer server(80);
void setup() {
 Serial.begin(115200);
 EEPROM.begin(EEPROM_SIZE);

  myservo1.setPeriodHertz(50); 
  myservo2.setPeriodHertz(50); 
  myservo3.setPeriodHertz(50); 
  myservo4.setPeriodHertz(50); 
  myservo5.setPeriodHertz(50); 
  
  myservo1.attach(12);
  myservo2.attach(14);
  myservo3.attach(27);
  myservo4.attach(26);
  myservo5.attach(25);
  
  EEPROM.write(0,159);

  
 Serial.println("Connecting to WiFi...");
 WiFi.begin(ssid, password);
 int attempts = 0;
 while (WiFi.status() != WL_CONNECTED && attempts < 20) {  // Try for 20 seconds
   delay(1000);
   Serial.print(".");
   attempts++;
 }
 if (WiFi.status() == WL_CONNECTED) {
   Serial.println("\nConnected to WiFi");
   Serial.print("IP Address: ");
   Serial.println(WiFi.localIP());
   
    
    server.on("/buka", HTTP_GET, [](AsyncWebServerRequest *request){
    int epr =  EEPROM.read(0);
    Serial.println(epr);
    bk();
    String ot = String(epr);
    request->send(200, "text/plain", ot);
   });
    server.on("/jimpit", HTTP_GET, [](AsyncWebServerRequest *request){
    int epr =  EEPROM.read(0);
    Serial.println(epr);
    jp();
     String ot = String(epr);
     request->send(200, "text/plain", ot);
   });
   server.on("/gengam", HTTP_GET, [](AsyncWebServerRequest *request){
    int epr =  EEPROM.read(0);
    Serial.println(epr);
    String ot = String(epr);
     gg();
     request->send(200, "text/plain", ot);
   });
   
   server.begin();
   Serial.println("Server started");
 } else {
   Serial.println("\nFailed to connect to WiFi");
 }
}

  void bk(){
    int epr =  EEPROM.read(0);
    Serial.println(epr);
    if ( epr==157){
      for (int i = 10;i <=159; i +=1) {
          Serial.println(i);
          myservo1.write(i);
          myservo2.write(i);
          myservo3.write(i);
          myservo4.write(i);
          delay(speed);
          EEPROM.write(0, 159);
          EEPROM.commit();
          }
      }
 if ( epr==158){
      for (int i = 1; i <=159; i +=1) {
          Serial.println(i);
          myservo1.write(i);
          myservo2.write(i);
          myservo3.write(i);
          myservo4.write(i);
          delay(speed);
          EEPROM.write(0, 159);
          EEPROM.commit();
          }
      }
        
    if ( epr==159){
      for (int i = epr; i <=159; i +=1) {
          Serial.println(i);
          myservo1.write(i);
          myservo2.write(i);
          myservo3.write(i);
          myservo4.write(i);
          delay(speed);
          EEPROM.write(0, i);
          EEPROM.commit();
          }
      }

    if (epr == 11){
        for (int i = epr; i <=158; i +=1) {
          Serial.println(i);
          myservo3.write(i);
          myservo4.write(i);
          delay(speed);
          EEPROM.write(0,159);
          EEPROM.commit();   
          }
        }
    if ( epr==10){
      for (int i = epr; i <=159; i +=1) {
          Serial.println(i);
          myservo1.write(i);
          myservo2.write(i);
          myservo3.write(i);
          myservo4.write(i);
          delay(speed);
          EEPROM.write(0, i);
          EEPROM.commit();
          }
      }


  }

  
  void gg(){
    int epr =  EEPROM.read(0);
    Serial.println(epr);



    if (epr ==11){
       for (int i = 158;i >= 11;i -=1) {
            Serial.println(i);
            myservo1.write(i);
            myservo2.write(i);
            delay(speed);
            }
            EEPROM.write(0, 157);
            EEPROM.commit(); 
        }
    
    //logika jimpit--12 10
    if (epr ==158){
       for (int i = epr; i >= 11;i -=1) {
            Serial.println(i);
            myservo1.write(i);
            myservo2.write(i);
            delay(speed);
            EEPROM.write(0, 157);
            EEPROM.commit(); 
            }
        }
     //logika buka--10
    if (epr == 159){
        for (int i = epr; i >= 10; i -=1) {
            Serial.println(i);
            myservo1.write(i);
            myservo2.write(i);
            myservo3.write(i);
            myservo4.write(i);
            delay(speed);
            EEPROM.write(0, i);
            EEPROM.commit(); 
            }
        }
    
    }
  
 void jp(){
    int epr =  EEPROM.read(0);
    Serial.println(epr);
    
    //logika jimpit bk 34 
    if (epr == 159){
        for (int i = epr; i >= 11;i -=1) {
          Serial.println(i);
          myservo3.write(i);
          myservo4.write(i);
          delay(speed);
          EEPROM.write(0, i);
          EEPROM.commit();     }
        }

           
    if (epr == 157){
        for  (int i = 10; i <= 158; i +=1) {
          Serial.println(i);
          myservo1.write(i);
          myservo2.write(i);
          delay(speed);
          EEPROM.write(0,11);
          EEPROM.commit();     }
        }

   if (epr == 10){
    for (int i = epr; i <= 158; i +=1) {
         Serial.println(i);
          myservo1.write(i);
          myservo2.write(i);
          delay(speed);
          EEPROM.write(0,11);
          EEPROM.commit();
          }
        }
     }
     
void loop() {}
