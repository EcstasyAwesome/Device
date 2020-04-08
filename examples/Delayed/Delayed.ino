#include <Device.h>

Device led(LED_BUILTIN, HIGH);

void setup() {
  Serial.begin(9600);
  led.on();
  Serial.println(led.isActive() ? "ON" : "OFF");
}

void loop() {
  if (led.isActive() && millis() - led.getTime() > 3000) {
    led.off();
    Serial.println(led.isActive() ? "ON" : "OFF");
  }
}