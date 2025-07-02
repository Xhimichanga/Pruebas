//DIRECTORSCUT
//////////////////////
int pot = A0;          // Pin A0 de entrada analoga para el potenciómetro
int pin_digital = 5;  // Pin de salida para la señal de onda cuadrada
int lectura_pot = A0;  // 
int periodo, residuo;
int tabla1[] = {45, 23};
int tabla2[] = {15000, 11200, 9000, 7500, 6400, 5600, 5000, 4500, 4080, 3740,
                3450, 3210, 3000, 2800, 2650, 2490, 2360, 2250, 2140, 2040,
                1955, 1870, 1797, 1729, 1663, 1605, 1550, 1497, 1448, 1403,
                1362, 1321, 1283, 1247, 1215, 1182, 1151, 1123, 1095, 1069,
                1044, 1020, 998, 976, 954, 934, 916, 910, 860, 840, 795, 740, 
                705, 670, 610, 580, 550, 530, 510, 498, 460, 440, 430, 415, 
                405, 380, 373};
//unsigned long tiempo = 0;

void setup() 
{
  pinMode(pot, INPUT);
  pinMode(pin_digital, OUTPUT);  // Declaracion del pin 4 como salida (señal cuadrada)
  Serial.begin(9600);            // inicializacion a 9600 bauds del puerto COM asignado
}

void loop() 
{
  lectura_pot = analogRead(pot);        // Se direcciona entrada analoga A0 y se lee el valor del potenciómetro conectado
  periodo = map(lectura_pot,127,1023,127,200);  // interpolacion de valores leidos del potenciometro para su manejo en ciclos por segundo
  analogWrite(pin_digital, periodo);
  delay(1);
  Serial.print("lectura_pot: ");
  Serial.print(lectura_pot);
  Serial.print("  periodo: ");
  Serial.print(periodo);
  Serial.print("   valor: ");
  Serial.println(tabla2[67-periodo]);
 
  if (periodo == 70)    // No hay señal cuadrada
      digitalWrite(pin_digital, LOW);  // Asignar estado ALTO (5V)
  if (periodo == 0)    // Generar la mas alta frecuencia, equivalente a 1000 Hz de la señal cuadrada
  { 
      digitalWrite(pin_digital, HIGH);  // Asignar estado ALTO (5V)
      delayMicroseconds(373);           // mantener durante 0.5ms el estado ALTO  
      digitalWrite(pin_digital, LOW);   // asigna estado BAJO (0V)  
      delayMicroseconds(373);           // mantener durante 0.5ms el estado BAJO
  }
  if (periodo == 69 || periodo == 68)
    {
     digitalWrite(pin_digital, HIGH);  // Asignar estado ALTO (5V)
     delay(tabla1[69-periodo]);                   // mantener estado ALTO
     digitalWrite(pin_digital, LOW);   // Asignar estado BAJO (0V)
     delay(tabla1[69-periodo]);                   // mantener estado BAJO           
    }
  if (periodo <= 67 && periodo >= 1)
  {
     digitalWrite(pin_digital, HIGH);  // Asignar estado ALTO (5V)
     delayMicroseconds(tabla2[67-periodo]);                   // mantener estado ALTO
     digitalWrite(pin_digital, LOW);   // Asignar estado BAJO (0V)
     delayMicroseconds(tabla2[67-periodo]);                   // mantener estado BAJO      
  }

}


