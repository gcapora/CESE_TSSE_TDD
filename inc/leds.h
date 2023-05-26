#ifndef LEDS_H
#define LEDS_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define ALL_LEDS_OFF    0
#define ALL_LEDS_ON     0xFFFF

bool LedsInit(uint16_t *);
void LedsTurnOnSingle(uint8_t);
void LedsTurnOffSingle(uint8_t);
bool LedsIsOn(uint8_t);
void LedsTurnOnAll(void);
void LedsTurnOffAll(void);

#endif