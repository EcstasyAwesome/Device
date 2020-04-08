#include <Device.h>

Device led(LED_BUILTIN, HIGH);

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (millis() - led.getTime() > 1000) {
    led.isActive() ? led.off() : led.on();
    Serial.println(led.isActive() ? "ON" : "OFF");
  }
}