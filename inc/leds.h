#ifndef LEDS_H
#define LEDS_h

#include <stdint.h>
#include <stdbool.h>

void ledsInit(uint16_t* direccion);

void ledsTurnOnSingle(int led);

void ledsTurnOffSingle(int led);

bool isLedTurnOn(int led);

void ledsTurnOnAll(void);

void ledsTurnOffAll(void);

#endif
