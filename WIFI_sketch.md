//Network monitoring project by nyx.2k

#include <WiFi.h>
//define ssid and passwd
const char* ssid = "";
const char* password = "";

void setup() {
  //channel and init wifi
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  //try to connect
  Serial.print("trying to connect");
  while (WiFi.status() != WL_CONNECTED) {
    delay(750);
    Serial.print("*");
  }
  //print connection and ip 
  Serial.println("\n Connected");
  Serial.print("IP:> ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
