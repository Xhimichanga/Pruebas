int pot = A0;          // Pin A0 de entrada analoga para el potenciómetro
int pin_digital = 3;  // Pin de salida para la señal de onda cuadrada
int lectura_pot;  // 
int periodo, residuo;
void setup() {
  Serial.begin(9600);
}
void loop() {
  lectura_pot = analogRead(pot);        // Se direcciona entrada analoga A0 y se lee el valor del potenciómetro conectado
  Serial.print(lectura_pot,"\n");
  periodo = map(lectura_pot,0,1023,0,255);  // interpolacion de valores leidos del potenciometro para su manejo en ciclos por segundo
  Serial.print(periodo);
  tone(3,lectura_pot,"\n");
}