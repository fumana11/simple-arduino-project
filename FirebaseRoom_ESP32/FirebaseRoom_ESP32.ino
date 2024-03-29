
#include <WiFi.h>
#include <IOXhop_FirebaseESP32.h>

#include "DHT.h"

// Set these to run example.
#define FIREBASE_HOST "esp32-363f2.firebaseio.com"
#define FIREBASE_AUTH "YB5dOr2RrB6Vtz2pvENCqUPqg9KVkExVIYYmhnyS"
#define WIFI_SSID "maulana"
#define WIFI_PASSWORD "maulana123"


#define DHTPIN 5  

#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);


const int grovePowerPin = 15;
const int vibratorPin = 5;
const int lightSensorPin = A0;
const int ledPin = 2;
const int buttonPin = 14;
const int fanPin = 13;

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(grovePowerPin, OUTPUT);
  digitalWrite(grovePowerPin, HIGH);

  pinMode(vibratorPin, OUTPUT);
  pinMode(lightSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(fanPin, OUTPUT);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.set("pushbutton", 0);
  Firebase.set("sunlight", 0);
  Firebase.set("redlight", 0);
  Firebase.set("cooldown", 0);
  Firebase.set("brrr", 0);
}

int button = 0;
float light = 0.0;

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  Firebase.set("Humidity", h);
  Firebase.set("Temperature",t);
  
  Serial.print("Humidity : ");
  Serial.print(h);
  Serial.print(" %    ");
  Serial.print(" Temperature : ");
  Serial.print(t);
  Serial.println(" C    ");

  
  digitalWrite(ledPin, Firebase.getInt("redlight"));
  digitalWrite(fanPin, Firebase.getInt("cooldown"));
  digitalWrite(vibratorPin, Firebase.getInt("brrr"));
  int newButton = digitalRead(buttonPin);
  if (newButton != button) {
    button = newButton;
    Firebase.setInt("pushbutton", button);
  }
  float newLight = analogRead(lightSensorPin);
  if (abs(newLight - light) > 100) {
    light = newLight;
    Firebase.setFloat("sunlight", light);
  }
  delay(200);
}
