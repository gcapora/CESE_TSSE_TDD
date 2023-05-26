/******************************************************************************
 *  @file:     test_leds.c
 *  @author:   Guillermo Caporaletti
 *  @brief:    TDD (Testing Driven Development) para controlador de leds.
 *             Curso de TSSE, CESE-FIUBA.
 *  @date:     mayo de 2023
 ******************************************************************************
  - Al inicializar la biblioteca todos los leds deben estar apagados.
  - Con todos los leds apagados, prendo led 2 y verifico que se enciende 
    el bit 1 (vale 1).
  - Con led 2 prendido, apago y verifico que se apagó el bit 1 (vale 0).
  - Con todos los leds apagados, prendo led 3, prendo 5, apago el 3 y apago el 7;
    debería quedar bit 4 en 1, resto en 0.
  - Prendo un led, consulto el estado y verifico que esta prendido.
  - Apago un led, consulto el estado y tiene que estar apagado.
  - Con todos los leds apagados, enciendo todos los leds y verifico que 
    se enciendan.
  - Con todods prendidos, apago todos y verifico que se apagan.
  - Revisar los valores limites de los argumentos
  - Revisar que pasa con valores erróneos en los argumentos
  - Inicializo mal para que devuelva false...
 *****************************************************************************/

#include <stdint.h>
#include "unity.h"
#include "leds.h"

static uint16_t puerto_virtual;

void setUp(void) {
  LedsInit(&puerto_virtual);
}

void tearDown(void) {

}

// Al inicializar la biblioteca todos los leds deben estar apagados.
void test_todos_los_leds_inician_apagados(void) {
  puerto_virtual = 0xFFFF;
  TEST_ASSERT_TRUE(LedsInit(&puerto_virtual));
  TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

// Con todos los leds apagados, prendo led 2 y verifico que el bit 1 vale 1.
void test_prender_un_led(void) {
  LedsTurnOnSingle(2);
  TEST_ASSERT_EQUAL_HEX16(0x0002, puerto_virtual);
}

// Con led 2 prendido, apago y verifico que el bit 1 vale 0.
void test_apagar_un_led(void) {
  LedsTurnOnSingle(2);
  LedsTurnOffSingle(2);
  TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

// Con todos apagados, prendo led 3, prendo 5, apago el 3 y apago el 7;
// debería quedar bit 4 en 1, resto en 0.
void test_prendo_prendo_apago_apago(void) {
  LedsTurnOnSingle(3);
  LedsTurnOnSingle(5);
  LedsTurnOffSingle(3);
  LedsTurnOffSingle(7);
  TEST_ASSERT_EQUAL_HEX16(0x0010, puerto_virtual);
}

// Prendo un led, consulto el estado y verifico que esta prendido.
void test_prendo_y_leo(void) {
  LedsTurnOnSingle(4);
  TEST_ASSERT_TRUE(LedsIsOn(4));
  TEST_ASSERT_EQUAL_HEX16(0x0008, puerto_virtual);
}

// Apago un led, consulto el estado y tiene que estar apagado.
void test_apago_y_leo(void) {
  LedsTurnOnSingle(4);
  LedsTurnOffSingle(4);
  TEST_ASSERT_FALSE(LedsIsOn(4));
  TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

// Con todos los leds apagados, enciendo todos los leds 
// y verifico que se enciendan.
void test_prendo_todo_y_leo(void) {
  LedsTurnOnAll();
  TEST_ASSERT_EQUAL_HEX16(ALL_LEDS_ON, puerto_virtual);
  TEST_ASSERT_TRUE(LedsIsOn(1));
  TEST_ASSERT_TRUE(LedsIsOn(2));
  TEST_ASSERT_TRUE(LedsIsOn(3));
  TEST_ASSERT_TRUE(LedsIsOn(4));
  TEST_ASSERT_TRUE(LedsIsOn(5));
  TEST_ASSERT_TRUE(LedsIsOn(6));
  TEST_ASSERT_TRUE(LedsIsOn(7));
  TEST_ASSERT_TRUE(LedsIsOn(8));
  TEST_ASSERT_TRUE(LedsIsOn(9));
  TEST_ASSERT_TRUE(LedsIsOn(10));
  TEST_ASSERT_TRUE(LedsIsOn(11));
  TEST_ASSERT_TRUE(LedsIsOn(12));
  TEST_ASSERT_TRUE(LedsIsOn(13));
  TEST_ASSERT_TRUE(LedsIsOn(14));
  TEST_ASSERT_TRUE(LedsIsOn(15));
  TEST_ASSERT_TRUE(LedsIsOn(16));
}

// Con todods prendidos, apago todos y verifico que se apagan.
void test_apago_todo_y_leo(void) {
  LedsTurnOnAll();
  LedsTurnOffAll();
  TEST_ASSERT_EQUAL_HEX16(ALL_LEDS_OFF, puerto_virtual);
  TEST_ASSERT_FALSE(LedsIsOn(1));
  TEST_ASSERT_FALSE(LedsIsOn(2));
  TEST_ASSERT_FALSE(LedsIsOn(3));
  TEST_ASSERT_FALSE(LedsIsOn(4));
  TEST_ASSERT_FALSE(LedsIsOn(5));
  TEST_ASSERT_FALSE(LedsIsOn(6));
  TEST_ASSERT_FALSE(LedsIsOn(7));
  TEST_ASSERT_FALSE(LedsIsOn(8));
  TEST_ASSERT_FALSE(LedsIsOn(9));
  TEST_ASSERT_FALSE(LedsIsOn(10));
  TEST_ASSERT_FALSE(LedsIsOn(11));
  TEST_ASSERT_FALSE(LedsIsOn(12));
  TEST_ASSERT_FALSE(LedsIsOn(13));
  TEST_ASSERT_FALSE(LedsIsOn(14));
  TEST_ASSERT_FALSE(LedsIsOn(15));
  TEST_ASSERT_FALSE(LedsIsOn(16));
}

// Revisar los valores limites de los argumentos
// La lectura de límites debe dar siempre false
void test_prendo_y_leo_limites(void){
  LedsTurnOnSingle(1);
  LedsTurnOnSingle(16);
  TEST_ASSERT_TRUE(LedsIsOn(1));
  TEST_ASSERT_TRUE(LedsIsOn(16));
}

// Revisar que pasa con valores erróneos en los argumentos
void test_valores_erroneos(void) {
  LedsTurnOnSingle(0);
  TEST_ASSERT_FALSE(LedsIsOn(0));
  LedsTurnOnSingle(255);
  TEST_ASSERT_FALSE(LedsIsOn(255));
  LedsTurnOnSingle(32);
  TEST_ASSERT_FALSE(LedsIsOn(32));
  LedsTurnOnSingle(17);
  TEST_ASSERT_FALSE(LedsIsOn(17));
}

// Inicializo mal para que devuelva false
void test_inicio_erroneo(void) {
  TEST_ASSERT_FALSE(LedsInit(NULL));
}

