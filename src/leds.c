#include "leds.h"

#define INDEX_OFFSET    1
#define FIRST_BIT       1
#define ALL_LEDS_OFF    0
#define ALL_LEDS_ON     0xFFFF

static uint16_t * puerto;   // Me guarda la dirección de los leds

uint16_t indexToMask(uint8_t ledn) {
    return (FIRST_BIT << ledn-INDEX_OFFSET);
}

bool LedsInit(uint16_t * direccion) {
    if (NULL==direccion) return false;
    puerto = direccion;     // Guardo dirección de leds
    *puerto = ALL_LEDS_OFF; // Inicializo leds en cero
    return true;
}

void LedsTurnOnSingle(uint8_t led_number) {
    *puerto |= indexToMask(led_number);
}

void LedsTurnOffSingle(uint8_t led_number) {
    *puerto &= ~indexToMask(led_number);
}

bool LedsIsOn(uint8_t ledn) {
    uint16_t prueba = (*puerto) & indexToMask(ledn);
    return prueba==false ? false : true;
}

void LedsTurnOnAll(void) {
    *puerto = ALL_LEDS_ON;
}

void LedsTurnOffAll(void) {
    *puerto = ALL_LEDS_OFF;
}



