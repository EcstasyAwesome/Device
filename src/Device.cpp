#include "Device.h"

/*
 * @param pin
 *        pin number that a device is connected
 * @param trigger
 *        state when a device is active
 *        LOW/false - 0V trigger
 *        HIGH/true - 3.2/5V trigger
 */

Device::Device(const uint8_t pin, const bool trigger) {
  _pin = pin;
  _trigger = trigger;
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, _trigger ? LOW : HIGH);
}

/*
 * @return true if a device is activated
 */

bool Device::on() {
  if (!_state) {
    _state = true;
    _time = millis();
    digitalWrite(_pin, _trigger ? HIGH : LOW);
    return true;
  }
  return false;
}

/*
 * @return true if a device is deactivated
 */

bool Device::off() {
  if (_state) {
    _state = false;
    _time = millis();
    digitalWrite(_pin, _trigger ? LOW : HIGH);
    return true;
  }
  return false;
}

/*
 * @return time when a device was changed his state
 */

uint32_t Device::getTime() {
  return _time;
}

/*
 * @return device state
 */

bool Device::isActive() {
  return _state;
}