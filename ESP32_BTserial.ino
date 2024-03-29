#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

char BTbuf[255];

void setup() {
  Serial.begin(115200);  
  SerialBT.begin("ESP32huz"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() { 
  uint8_t i, buflen;

  i=0;
  while (SerialBT.available()) {
      BTbuf[i]=SerialBT.read();
      i++;
  }
  buflen = i;
  for (i=0; i<buflen; i++) {
    Serial.write(BTbuf[i]);
  }
}
