#ifndef LEDS_H
#define LEDS_h

#include <stdint.h>

void ledsInit(uint16_t* direccion);

void ledsTurnOnSingle(int led);

void ledsTurnOffSingle(int led);
#endif
