

#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"


#define BULB1 D0
#define BULB2 D1
#define BULB3 D2
#define BULB4 D3
/************************* WiFi Access Point *********************************/

#define WLAN_SSID       "NOOR WIFI"
#define WLAN_PASS       "noorsana"

/************************* Adafruit.io Setup *********************************/

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // use 8883 for SSL

#define IO_USERNAME  "NOORSANA"
#define AIO_KEY       "aio_imIu43d9FXB8UzCyDY55eX7Frx3M"

/************ Global State (you don't need to change this!) ******************/

WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, IO_USERNAME, AIO_KEY);

/****************************** Feeds ***************************************/


Adafruit_MQTT_Subscribe onoffbutton1 = Adafruit_MQTT_Subscribe(&mqtt, IO_USERNAME "/feeds/BULB1");
Adafruit_MQTT_Subscribe onoffbutton2 = Adafruit_MQTT_Subscribe(&mqtt, IO_USERNAME "/feeds/BULB2");
Adafruit_MQTT_Subscribe onoffbutton3 = Adafruit_MQTT_Subscribe(&mqtt, IO_USERNAME "/feeds/BULB3");
Adafruit_MQTT_Subscribe onoffbutton4 = Adafruit_MQTT_Subscribe(&mqtt, IO_USERNAME "/feeds/BULB4");

/*************************** Sketch Code ************************************/


void MQTT_connect();

void setup() {
  
  Serial.begin(115200);
  delay(10);
  
  pinMode(BULB1,OUTPUT);
      pinMode(BULB2,OUTPUT);
      pinMode(BULB3,OUTPUT);
        pinMode(BULB4,OUTPUT);

  
  digitalWrite(BULB1,LOW);
    digitalWrite(BULB2,LOW);
      digitalWrite(BULB3,LOW);
        digitalWrite(BULB4,LOW);

  
  Serial.println(F("IOT Based Home Automation"));

  // Connect to WiFi access point.
  Serial.println(); Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: "); Serial.println(WiFi.localIP());

  // Setup MQTT subscription for onoff feed.

  mqtt.subscribe(&onoffbutton1);
    mqtt.subscribe(&onoffbutton2);
      mqtt.subscribe(&onoffbutton3);
        mqtt.subscribe(&onoffbutton4);


}

uint32_t x=0;


void loop() {
 

  MQTT_connect();
 

  Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription(5000))) {
    if (subscription == &onoffbutton1)
    {
      Serial.print(F("Got: "));
      Serial.println((char *)onoffbutton1.lastread);
      uint16_t state1=atoi((char *)onoffbutton1.lastread);
      digitalWrite(BULB1,state1);   
    }
        if (subscription == &onoffbutton2)
    {
      Serial.print(F("Got: "));
      Serial.println((char *)onoffbutton2.lastread);
      uint16_t state1=atoi((char *)onoffbutton2.lastread);
      digitalWrite(BULB2,state1);   
    }
    if (subscription == &onoffbutton3)
    {
      Serial.print(F("Got: "));
      Serial.println((char *)onoffbutton3.lastread);
      uint16_t state1=atoi((char *)onoffbutton3.lastread);
      digitalWrite(BULB3,state1);   
    }
    if (subscription == &onoffbutton4)
    {
      Serial.print(F("Got: "));
      Serial.println((char *)onoffbutton4.lastread);
      uint16_t state1=atoi((char *)onoffbutton4.lastread);
      digitalWrite(BULB4,state1);   
    }
     
  }


}

void MQTT_connect() {
  int8_t ret;

  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // basically die and wait for WDT to reset me
         while (1);
       }
  }
  Serial.println("MQTT Connected!");
}
