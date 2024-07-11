const int ledPin = 13;     // LED de parpadeo
const int potPin = A0;     //  potenciómetro
const int buttonPin = 7;   //  botón
const int statusLedPin = 12; // LED de estado dl boton
bool blinkEnabled = false; // parpadeo apagado en inicio

void setup() {
  pinMode(ledPin, OUTPUT);       //  led de parpadeo como salida
  pinMode(potPin, INPUT);        //  potenciómetro como entrada
  pinMode(buttonPin, INPUT);     // botón como entrada
  pinMode(statusLedPin, OUTPUT); // LED de estado como salida
  Serial.begin(9600);            
}

void loop() {
  static bool lastButtonState = LOW; 
  bool currentButtonState = digitalRead(buttonPin); // Lee el estado del botón

  // Detecta el cambio de estado del botón (no presionado a presionado)
  if (currentButtonState == HIGH && lastButtonState == LOW) {
    blinkEnabled = !blinkEnabled; // cambiode  estado del parpadeo
    delay(50); // Debounce (antirrebote)
  }
  lastButtonState = currentButtonState; // Actualiza estado del botón

  // Controla el LED de estado según el estado del parpadeo
  digitalWrite(statusLedPin, blinkEnabled ? HIGH : LOW);

  int potValue = analogRead(potPin); 
  Serial.println(potValue);          

  // Calcula el retardo en función del valor del potenciómetro
  int delayTime = map(potValue, 0, 1023, 1000, 100); // Mapea el valor del potenciómetro 

  if (blinkEnabled) {
    digitalWrite(ledPin, HIGH); // Enciende LED de parpadeo
    delay(delayTime);           // Espera un tiempo proporcional 
    digitalWrite(ledPin, LOW);  // Apaga  LED de parpadeo
    delay(delayTime);           // Espera el mismo tiempo nuevamente
  } else {
    digitalWrite(ledPin, LOW); // Apaga LED 
  }
}