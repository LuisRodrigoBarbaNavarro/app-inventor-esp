#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "Dormitorio";
const char* password = "109397DA0B69";

ESP8266WebServer server(80);

void handleRoot() {
  server.send(200, "text/plain", "¡Hola desde ESP8266!");
}

void handleNotFound(){
  String message = "Error 404: Recurso no encontrado\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMetodo: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArgumentos: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void setup(void){
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Esperar a que el dispositivo se conecte a la red WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi conectado");

  Serial.println("Dirección IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, handleRoot);
  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("Servidor HTTP iniciado");
}

void loop(void){
  server.handleClient();
}
