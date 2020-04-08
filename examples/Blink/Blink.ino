#include <Device.h>

Device led(LED_BUILTIN, HIGH);

void setup() {
  Serial.begin(9600);
}

void loop() {
  led.isActive() ? led.off() : led.on();
  Serial.println(led.isActive() ? "ON" : "OFF");
  delay(1000);
}
