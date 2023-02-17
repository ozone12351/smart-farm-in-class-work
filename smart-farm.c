

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); 
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <TridentTD_LineNotify.h>

String txt1 = "humid:";
#define SSID        "poa1"
#define PASSWORD    "12345678"
#define LINE_TOKEN  "NWljVgNvZoekUrsbifoI5pLYlUZO46eiE4e4V1TVXyL"

int sensorPin = 36;

void setup(){
Serial.begin(115200);
pinMode(sensorPin, INPUT);

WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n",  SSID);
  while(WiFi.status() != WL_CONNECTED) { Serial.print("."); delay(400); }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());  

  // กำหนด Line Token
  LINE.setToken(LINE_TOKEN);
}
void loop(){
  lcd.begin();
  
  int Humidity = analogRead(sensorPin);
 if (Humidity  >= 0 && Humidity <= 819) {
    Serial.print("Moisture Sensor Value:");
    Serial.println(Humidity);
    Serial.println("Water the plants");
     lcd.setCursor(0,0); 
     lcd.print("Moisture :");
    lcd.print(Humidity);
    lcd.setCursor(0,1);
    lcd.print("I need water!");
    LINE.notify(txt1 + Humidity + "I need water!");
    delay(3000);
   }
  else if (Humidity > 819 && Humidity <= 1638) {
    Serial.print("Moisture Sensor Value:");
    Serial.println(Humidity);
    Serial.println("Normal");
    lcd.setCursor(0,0); 
    lcd.print("Moisture :");
    lcd.print(Humidity);
    lcd.setCursor(0,1);
    lcd.print("I'm very happy");
        LINE.notify(txt1 + Humidity + "I'm very happy");
    delay(3000);
    }
  else if (Humidity > 1638 && Humidity <= 2457) {
    Serial.print("Moisture Sensor Value:");
    Serial.println(Humidity);
    Serial.println("Humidity Over");
    lcd.setCursor(0,0); 
    lcd.print("Moisture :");
    lcd.print(Humidity);
    lcd.setCursor(0,1);
    lcd.print("less water!");
     LINE.notify(txt1 + Humidity + "less water!");
    delay(3000);
  }
  else if (Humidity > 2457 && Humidity <= 3276) {
    Serial.print("Moisture Sensor Value:");
    Serial.println(Humidity);
    Serial.println("Humidity Over");
    lcd.setCursor(0,0); 
    lcd.print("Moisture :");
    lcd.print(Humidity);
    lcd.setCursor(0,1);
    lcd.print("I can't breath");
         LINE.notify(txt1 + Humidity + "I can't breath");
    delay(3000);
  }
   else if (Humidity > 3276 && Humidity <= 4094) {
    Serial.print("Moisture Sensor Value:");
    Serial.println(Humidity);
    Serial.println("Dangerous");
    lcd.setCursor(0,0); 
    lcd.print("Moisture :");
    lcd.print(Humidity);
    lcd.setCursor(0,1);
    lcd.print("I gonna die!");
             LINE.notify(txt1 + Humidity + "I gonna die!");
    delay(3000);
   }  else  {
    Serial.print("Moisture Sensor Value:");
    Serial.println(Humidity);
    lcd.setCursor(0,0); 
    lcd.print("Start");
    lcd.print(Humidity);
    lcd.setCursor(0,1);
    lcd.print("Start");
    delay(3000);
}
   }
