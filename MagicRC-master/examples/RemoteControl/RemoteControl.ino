#include <SoftwareSerial.h>
#include <MagicRC.h>

MagicRC myRC(8, 9, 3, 4, 5, 6); // Bluetooth TX, RX

void setup() {
  myRC.begin(9600); // Bluetooth baudrate
}

void loop() {
  myRC.run();
}
