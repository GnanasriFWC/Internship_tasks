//----------------------Skeleton Code--------------------//
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
//    Can be client or even host   //
#ifndef STASSID
#define STASSID "Salient" // Add your network credentials
#define STAPSK  "12345678"
#endif

int W = 1,X = 0, Y = 1;
const char* ssid = STASSID;
const char* password = STAPSK;

void OTAsetup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }
  ArduinoOTA.begin();
}

void OTAloop() {
  ArduinoOTA.handle();
}

//-------------------------------------------------------//

void setup(){
  OTAsetup();
  
  pinMode(2,OUTPUT);
  //-------------------//
  // Custom setup code //
  //-------------------//
}

void loop() {
  OTAloop();
  int result;
  result = ( X && !Y ) || ( W && Y );
  if(result){
	digitalWrite(2,HIGH);
  }else{
	digitalWrite(2,LOW);
  }
 // digitalWrite(2,HIGH);
  
  //-------------------//
  // Custom loop code  //
  //-------------------//
}
