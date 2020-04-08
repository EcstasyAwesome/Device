#ifndef Device_h
#define Device_h
#include <Arduino.h>

class Device {
  private:
  	bool _trigger;
    bool _state;
    uint8_t _pin;
	uint32_t _time;
  public:
    Device(const uint8_t pin, const bool trigger);
    bool on();
    bool off();
    bool isActive();
	uint32_t getTime();
};
#endif