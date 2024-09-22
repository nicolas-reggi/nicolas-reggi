#include <WiFi.h>
#include <PubSubClient.h>

// Configuración de WiFi
const char* ssid = "peque";           // Reemplaza con el nombre de tu red WiFi
const char* password = "lalola319";   // Reemplaza con la contraseña de tu red WiFi
WiFiClient wifiClient;

// Configuración de MQTT
const char* mqttBroker = "broker.hivemq.com";  // Servidor MQTT público
const char* mqttClientName = "nicolas emisor"; // Nombre del cliente MQTT
const char* topic = "control/servo";           // Tópico MQTT donde se publicarán los datos
PubSubClient mqttClient(wifiClient);

const int potPin = 34; // Pin donde está conectado el potenciómetro

void setup() {
  Serial.begin(115200);
  Serial.println("Iniciando nicolas emisor...");

  pinMode(potPin, INPUT);

  // Conectar al WiFi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.print("Conectando a WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConectado a WiFi");
  Serial.print("Dirección IP: ");
  Serial.println(WiFi.localIP());

  // Configuración de MQTT
  mqttClient.setServer(mqttBroker, 1883);
}

void loop() {
  // Verificar si seguimos conectados al broker MQTT
  if (!mqttClient.connected()) {
    mqttConnect();
  }
  mqttClient.loop();

  // Leer el potenciómetro y enviar el valor por MQTT
  int potValue = analogRead(potPin);
  int angle = map(potValue, 0, 4095, 0, 180); // Mapear el valor a un ángulo entre 0 y 180 grados

  char msg[10];
  snprintf(msg, sizeof(msg), "%d", angle); // Convertir el ángulo a una cadena de caracteres

  Serial.print("Publicando ángulo: ");
  Serial.println(msg);

  mqttClient.publish(topic, msg); // Publicar el ángulo en el tópico MQTT

  delay(100); // Pequeño retraso para no saturar el broker MQTT
}

void mqttConnect() {
  while (!mqttClient.connected()) {
    Serial.print("Intentando conectar al MQTT...");
    if (mqttClient.connect(mqttClientName)) {
      Serial.println("Conectado al broker MQTT");
      // No es necesario suscribirse a ningún tópico en el emisor
    } else {
      Serial.print("Falló, rc=");
      Serial.print(mqttClient.state());
      Serial.println(". Intentando de nuevo en 5 segundos");
      delay(5000);
    }
  }
}