#ifndef LEDS_H
#define LEDS_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

bool LedsInit(uint16_t *);
void LedsTurnOnSingle(uint8_t);
void LedsTurnOffSingle(uint8_t);
bool LedsIsOn(uint8_t);
void LedsTurnOnAll(void);
void LedsTurnOffAll(void);

#endif