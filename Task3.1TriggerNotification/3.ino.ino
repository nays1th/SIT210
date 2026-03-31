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

// IFTTT KEY
String key = "e-l3D4FHrwqfQCzsRZj30kGry2qg-DI17xPUBpeyOBH";

WiFiClient client;
BH1750 lightMeter;
DHT dht(DHTPIN, DHTTYPE);

bool sunlight = false;

void setup() {
  Serial.begin(9600);

  Wire.begin();
  lightMeter.begin();
  dht.begin();

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

  // SEND TO THINGSPEAK
  if (!isnan(temp)) {
    ThingSpeak.setField(1, temp);
    ThingSpeak.setField(2, light);
    ThingSpeak.writeFields(channelID, writeAPIKey);
  }

  //  TRIGGER LOGIC (NEW PART)
  if (light > 100 && sunlight == false) {
    Serial.println("Sunlight detected");
    sendIFTTT("sunlight_on");
    sunlight = true;
  }

  if (light < 50 && sunlight == true) {
    Serial.println("Sunlight stopped");
    sendIFTTT("sunlight_off");
    sunlight = false;
  }

  delay(30000);
}

//  FUNCTION TO SEND IFTTT
void sendIFTTT(String event) {
  if (client.connect("maker.ifttt.com", 80)) {
    String url = "/trigger/" + event + "/with/key/" + key;

    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: maker.ifttt.com\r\n" +
                 "Connection: close\r\n\r\n");
  }
}