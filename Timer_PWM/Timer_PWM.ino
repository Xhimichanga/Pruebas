int pot = A0;
int pin_digital = 3;
int lectura_pot = A0;
int periodo, residuo;

void setup() {
  Serial.begin(9600);            // inicializacion a 9600 bauds del puerto COM asignado
  // Configura el pin 9 como salida
  //pinMode(9, OUTPUT);
  pinMode(pin_digital, OUTPUT);  // Declaracion del pin 4 como salida (señal cuadrada)

  // Detener Timer 1
  TCCR1A = 0; // Limpiar registros
  TCCR1B = 0;

  // Configuración del Timer 1
  TCCR1A |= (1 << COM1A1) | (1 << WGM11); // Modo Fast PWM, Clear on Compare Match
  TCCR1B |= (1 << WGM12) | (1 << WGM13); // Modo Fast PWM, 16 bits
  TCCR1B |= (1 << CS11); // Prescaler 8

  // Establecer el valor del registro de comparación para obtener 400 Hz
  // Con un prescaler de 8, el reloj del timer es de 2 MHz.
  ICR1 = 4999; // Establecer el valor máximo (período de 400 Hz a 2 MHz)
  OCR1A = 2500; // 50% de ciclo de trabajo (2500 de 0 a 4999)
}

void loop() {
  // No se necesita hacer nada en el loop
  lectura_pot = analogRead(pot );        // Se direcciona entrada analoga A0 y se lee el valor del potenciómetro conectado
  periodo = map(lectura_pot,0,1023,0,255);  // interpolacion de valores leidos del potenciometro para su manejo en ciclos por segundo
  Serial.print("lectura_pot: ");
  Serial.print(lectura_pot);
  Serial.print("  periodo: ");
  Serial.print(periodo);
  Serial.print("   valor: ");
}