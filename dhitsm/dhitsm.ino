#include <HardwareSerial.h>

#define RXD2 16  // GPIO16 as RX
#define TXD2 17  // GPIO17 as TX

HardwareSerial mySerial(2); // Use Serial2

void setup() {
  Serial.begin(115200);  // Initialize Serial Monitor for debugging
  mySerial.begin(115200, SERIAL_8N1, RXD2, TXD2); // Initialize Serial2 with defined pins
  mySerial.println("ESP32 Ready to communicate with Raspberry Pi");
}

void loop() {
  if (mySerial.available() > 0) {
    String input = mySerial.readString();
    input.trim(); // Trim the input
    if (input == "1") {
      // Send signal to Raspberry Pi to start processing
      Serial.print('1');
      mySerial.println("Signal sent to Raspberry Pi to start processing");
    }
  }

  if (Serial.available() > 0) {
    String dataFromPi = Serial.readStringUntil('\n');
    if (dataFromPi.length() > 0) {
      mySerial.println("Data received from Raspberry Pi: " + dataFromPi);
    }
  }

  delay(1000); // Adjust delay as needed
}