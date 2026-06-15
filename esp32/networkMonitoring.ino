//Network monitoring project by nyx.2k
//project made with the help of AI,
//just to understand how to code in C++

#include <WiFi.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESPping.h>
#include <PubSubClient.h>

//set host and pass
const char* ssid = "";
const char* password = "";
const char* host = "192.168.88.1";
const char* mqtt_server = "192.168.88.153";

//LED Pins
#define LED_GREEN 17
#define LED_RED 16

//lcd & mqtt set
LiquidCrystal_I2C lcd(0x27, 16, 2);
WiFiClient espClient;
PubSubClient client(espClient);

void connectMQTT() {
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
    if (client.connect("ESP32Client")) {
      Serial.println("MQTT Connected!");
    } else {
      Serial.print("Failed, state: ");
      Serial.println(client.state());
      delay(2000);
    }
  }
}


void setup() {
  //define channel and pinmode 
  Serial.begin(115200);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  //init LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Connecting...");

  //Wifi init and loop until connected 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("*");
  }

  //show ip on lcd
  Serial.println("Wifi connected");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WiFi ok");
  lcd.setCursor(0, 1);
  lcd.print(WiFi.localIP());
  delay(2000);

  //broker conf
  client.setServer(mqtt_server, 1883);
  connectMQTT();
}

void loop() {
  //if mqtt
  if (!client.connected()) {
    connectMQTT();
  }
  client.loop();

  bool success = Ping.ping(host);

  if (success) {
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_RED, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("host is up");
    lcd.setCursor(0, 1);
    lcd.print(host);
    client.publish("network", "up and runnning");
    Serial.println("MQTT sent");
  } else {
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_RED, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("host is down");
    lcd.setCursor(0, 1);
    lcd.print(host);
    client.publish("network", "is DOWN!!");
    Serial.println("");
  }

  delay(5000);
}
