#include <WiFi.h>
#include <PubSubClient.h>
#include <ESP32Servo.h> // Biblioteca para controlar el servo

// Configuración de WiFi
const char* ssid = "peque";             // Reemplaza con el nombre de tu red WiFi
const char* password = "lalola319";     // Reemplaza con la contraseña de tu red WiFi
WiFiClient wifiClient;

// Configuración de MQTT
const char* mqttBroker = "broker.hivemq.com";
const char* mqttClientName = "nicolas_receptor"; // Nombre único para el receptor
const char* topic = "control/servo";             // Tópico MQTT al que nos suscribiremos
PubSubClient mqttClient(wifiClient);

Servo myServo;          // Objeto Servo
const int servoPin = 4; // Pin donde está conectado el servo

void setup() {
  
  Serial.begin(115200);
  Serial.println("Iniciando nicolas receptor...");
  
  myServo.attach(servoPin); // Adjuntar el servo al pin definido
  
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
  mqttClient.setCallback(callback);
  
  mqttConnect(); // Conectar y suscribirse al tópico MQTT
}

void loop() {
  // Verificar si seguimos conectados al broker MQTT
  if (!mqttClient.connected()) {
    mqttConnect();
  }
  
  // Mantener la conexión MQTT
  mqttClient.loop();
}

void mqttConnect() {
  while (!mqttClient.connected()) {
    Serial.print("Intentando conectar al MQTT...");
    if (mqttClient.connect(mqttClientName)) {
      Serial.println("Conectado al broker MQTT");
      mqttClient.subscribe(topic); // Suscribirse al tópico MQTT
    } else {
      Serial.print("Falló, rc=");
      Serial.print(mqttClient.state());
      Serial.println(". Intentando de nuevo en 5 segundos");
      delay(5000);
    }
  }
}

// Función callback para manejar los mensajes entrantes
void callback(char* topic, byte* payload, unsigned int length) {
  String incomingMessage = "";
  for (unsigned int i = 0; i < length; i++){
    incomingMessage += (char)payload[i];
  } 
  Serial.print("Mensaje recibido [");
  Serial.print(topic);
  Serial.print("]: ");
  Serial.println(incomingMessage);

  int angle = incomingMessage.toInt(); // Convertir el mensaje a entero (ángulo)

  // Asegurarse de que el ángulo esté entre 0 y 180 grados
  if (angle < 0) angle = 0;
  if (angle > 180) angle = 180;

  myServo.write(angle); // Mover el servo al ángulo recibido
  Serial.print("Servo movido a: ");
  Serial.println(angle);
}
