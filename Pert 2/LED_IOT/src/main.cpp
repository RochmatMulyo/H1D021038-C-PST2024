#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <ESP8266WiFi.h>

// put function declarations here:
const char *ap_ssid = "kelapamuda";
const char *ap_password = "sdawegan";

const char *sta_ssid = "TEKNIK UNSOED D3";
const char *sta_password = "";

AsyncWebServer server(80);
String webpage;

int yellow = D5;
int green = D7;
int red = LED_BUILTIN;

void setup() {
  // put your setup code here, to run once:

  pinMode (red, OUTPUT);
  pinMode (green, OUTPUT);
  pinMode (yellow, OUTPUT);

  Serial.begin(9600);
  delay (10);

  // setting mode access point
  // Serial.println("Configure access point");
  // WiFi.mode(WIFI_AP);
  // WiFi.softAP(ap_ssid, ap_password);
  // Serial.print("Wifi: ");
  // Serial.println(ap_ssid);
  // Serial.print("IP address: ");
  // Serial.println(WiFi.softAPIP());

  // setting mode station
  Serial.print("Connecting to ");
  Serial.println(sta_ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(sta_ssid, sta_password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(300);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  webpage+= "<h1> Web Control ESP8266</h1>";
  webpage+= "<p>LED 1: ";
  webpage+= "<a href=\"redON\"\"><button>ON</button></a><a href=\"redOFF\"\"><button>OFF</button></a></p><br>";
  webpage+= "<p>LED 2: ";
  webpage+= "<a href=\"greenON\"\"><button>ON</button></a><a href=\"greenOFF\"\"><button>OFF</button></a></p><br>";
  webpage+= "<p>LED 3: ";
  webpage+= "<a href=\"yellowON\"\"><button>ON</button></a><a href=\"yellowOFF\"\"><button>OFF</button></a></p>";

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", webpage);
  });
  
  server.on("/redON", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(red, HIGH);
    request->send(200, "text/html", webpage);
  });
  
  server.on("/greenON", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(green, HIGH);
    request->send(200, "text/html", webpage);
  });

  server.on("/yellowON", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(yellow, LOW);
    request->send(200, "text/html", webpage);
  });

  server.on("/redOFF", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(red, LOW);
    request->send(200, "text/html", webpage);
  });
  
  server.on("/greenOFF", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(green, LOW);
    request->send(200, "text/html", webpage);
  });

  server.on("/yellowOFF", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(yellow, HIGH);
    request->send(200, "text/html", webpage);
  });

  server.begin();

}

void loop() {
  // put your main code here, to run repeatedly:

  
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}