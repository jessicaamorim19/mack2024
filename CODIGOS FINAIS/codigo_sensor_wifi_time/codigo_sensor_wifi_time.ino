#include "ESP8266WiFi.h"
#include <PubSubClient.h>
#include "DHT.h"

#include <NTPClient.h>
#include <WiFiUdp.h>

#define DHTPIN 4 // pino que estamos conectado
#define DHTTYPE DHT11 // DHT 11


//Parametros de conexão
const char* ssid = "Fanti-Family #1"; // REDE
const char* password = "FF190208"; // SENHA


// MQTT Broker
const char *mqtt_broker = "test.mosquitto.org";  //Host do broket
const char *topic = "JESSICA/teste";            //Topico a ser subscrito e publicado
const char *mqtt_username = "";         //Usuario
const char *mqtt_password = "";         //Senha
const int mqtt_port = 1883;             //Porta

//Variáveis
bool mqttStatus = 0;

//Objetos
DHT dht(DHTPIN, DHTTYPE);
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");
WiFiClient espClient;
PubSubClient client(espClient);

//Prototipos
bool connectMQTT();
void callback(char *topic, byte * payload, unsigned int length);

void setup(void)
{
  Serial.begin(9600);

  // Conectar
  WiFi.begin(ssid, password);

  //Aguardando conexão
  Serial.println();
  Serial.print("Conectando");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  //Envia IP através da UART
  Serial.println(WiFi.localIP());

  Serial.println("DHT11 teste!");
  dht.begin();

  mqttStatus =  connectMQTT();

  timeClient.begin();
  // Set offset time in seconds to adjust for your timezone
  timeClient.setTimeOffset(-10800);

}

void loop() {
  timeClient.update();
  String formattedTime = timeClient.getFormattedTime();
  Serial.print("Formatted Time: ");
  Serial.println(formattedTime);
  float t = dht.readTemperature();
  String temperatura = String(t);
  String mensagem = "{ \"temperatura\": " + temperatura + ", \"Hora Envio\": \"" + formattedTime + "\" }";
  delay(2000);
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" *C");

  static long long pooling  = 0;
  if ( mqttStatus){
    
    client.loop();    

    if (millis() > pooling +1000){
      pooling = millis();
      client.publish(topic, mensagem.c_str());
    }
       
  }
}



bool connectMQTT() {
  byte tentativa = 0;
  client.setServer(mqtt_broker, mqtt_port);
  client.setCallback(callback);

  do {
    String client_id = "JESSICA-";
    client_id += String(WiFi.macAddress());

    if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
      Serial.println("Exito na conexão:");
      Serial.printf("Cliente %s conectado ao broker\n", client_id.c_str());
    } else {
      Serial.print("Falha ao conectar: ");
      Serial.print(client.state());
      Serial.println();
      Serial.print("Tentativa: ");
      Serial.println(tentativa);
      delay(2000);
    }
    tentativa++;
  } while (!client.connected() && tentativa < 5);

  if (tentativa < 5) {
    // publish and subscribe   
    // client.publish(topic, "{teste123,113007042022}"); 
    // client.subscribe(topic);
    return 1;
  } else {
    Serial.println("Não conectado");    
    return 0;
  }
}

void callback(char *topic, byte * payload, unsigned int length) {
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
    Serial.print((char) payload[i]);
  }
  Serial.println();
  Serial.println("-----------------------");
}
