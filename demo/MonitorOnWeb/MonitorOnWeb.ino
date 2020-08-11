#include <ESP8266WiFi.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>


Adafruit_BMP085 bmp;

const char* ssid = "PDCN";
const char* password = "1234567890";

WiFiServer server(80);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  delay(10);
  
  if(!bmp.begin()){
    Serial.println("Could not find Senor");
    while(1){}
  }

//  pinMode(2,OUTPUT);
//  digitalWrite(2,0);
  Serial.println();
  Serial.println("Connecting to");
  Serial.println(ssid);

  WiFi.begin(ssid,password);

  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi connected");

  server.begin();
  Serial.println("Server started @");

  Serial.println(WiFi.localIP());
  Serial.println("To see monitor,open your web browser");

}

void loop() {
  WiFiClient client = server.available();
  if(!client){
    delay(100);
    return;
  };
  // put your main code here, to run repeatedly:


String req = client.readStringUntil('\n');
Serial.println(req);
client.flush();

int val ;
float temp = bmp.readTemperature();
int pressure = bmp.readPressure();
float altitude = bmp.readAltitude();
Serial.print("Temp:");
Serial.println(temp);
Serial.print("Pres:");
Serial.println(pressure);
Serial.print("Altitude:");
Serial.println(altitude);

String s = "HTTP/1.1 200 OK\r\nContent-Type: text\html\r\n\r\n<!DOCTYPE HTML>\r\n<html>";
s+="<head><meta http-equiv='refresh' content='5'></head>";
s+="\r\nTemp:";
s+=temp;
s+="<br>";
s+="pres:";
s+=pressure;
s+="<br>";
s+="altitude:";
s+=altitude;
s+="\r\n</html>\n";

client.print(s);
delay(1);
Serial.println("Client disconnected");

 





}
