#define BLYNK_TEMPLATE_ID "TMPL685Xj-IAd"
#define BLYNK_TEMPLATE_NAME "ESP8266"
#define BLYNK_AUTH_TOKEN "ipgJ1ArPVcW4Gk0OrNtUW4stzAnbKzi6"
#include <SoftwareSerial.h>


#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Phong 509";  // type your wifi name
char pass[] = "Namnamsausau";  // type your wifi password

SoftwareSerial esp8266Serial(D5, D6); // RX, TX pins

void setup() {
  Serial.begin(9600);    // Serial Monitor for debugging
  esp8266Serial.begin(9600);  // ESP8266 UART
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
  if (esp8266Serial.available()) {
    // Read incoming data from STM32F103
    String incomingData = esp8266Serial.readStringUntil('\n');
    Serial.println(incomingData); 
    if(incomingData == "1"){
      Blynk.logEvent("canhbaolua","Your home is in the fire");
    }
    if(incomingData == "2"){
      Blynk.logEvent("canhbaokhiga","Your home is in the fire");
    }
    if(incomingData == "3"){
      Blynk.logEvent("canhbaochay","Your home is in the fire");
    }
  }
}