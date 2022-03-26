#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 11
int cmd = '0';
DHT dht(DHTPIN, DHTTYPE);
int light = 3;
int mq7 = A0;
int ldr = A1;

void setup() {
  Serial.begin(9600);
  //Serial.println(F("DHTxx test!"));
  pinMode(light,OUTPUT);
  pinMode(mq7,INPUT);
  pinMode(ldr,INPUT);
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  //delay(2000);
  float carbonValue = analogRead(mq7);
  float ldrValue = analogRead(ldr);
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  if(Serial.available()){
    cmd = Serial.read();
    if(cmd == 't'){
      Serial.println(t);
    }
    if(cmd == 'h'){
      Serial.println(h);
    }
    if(cmd == 'o'){
      digitalWrite(light,HIGH);
    }
    if(cmd == 'f'){
      digitalWrite(light,LOW);
    }
    if(cmd == 'c'){
      Serial.println(carbonValue);
    }
    if(cmd == "l"){
      Serial.println(ldrValue);
    }
  }


}
