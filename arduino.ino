#include <WiFiNINA.h>
#include <ThingSpeak.h>
#include <Wire.h>
#include <BH1750.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

char ssid[] = "4710 Bathroom Spy Cam";
char pass[] = "itsonthefridge";

unsigned long channelID = 3320149;
const char * writeAPIKey = "ODUYR73HF2YG6JHS";

WiFiClient client;
BH1750 lightMeter;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  Wire.begin();
  lightMeter.begin();
  dht.begin();

  // connect WiFi
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
  Serial.println("Connected to WiFi");

  ThingSpeak.begin(client);
}

void loop() {
  float temp = dht.readTemperature();
  float light = lightMeter.readLightLevel();

  Serial.print("Temp: ");
  Serial.println(temp);
  Serial.print("Light: ");
  Serial.println(light);

  if (!isnan(temp)) {
    ThingSpeak.setField(1, temp);
    ThingSpeak.setField(2, light);

    ThingSpeak.writeFields(channelID, writeAPIKey);
  }

  delay(30000); // every 30 sec
}