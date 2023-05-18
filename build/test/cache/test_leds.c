#include "inc/leds.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


static uint16_t puerto_virtual;



void setUp(void) {

  LedsInit(&puerto_virtual);

}



void tearDown(void) {



}





void test_todos_los_leds_inician_apagados(void) {

  puerto_virtual = 0xFFFF;

  do {if ((LedsInit(&puerto_virtual))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(41)));}} while(0);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

 ((void *)0)

 ), (UNITY_UINT)(42), UNITY_DISPLAY_STYLE_HEX16);



}





void test_prender_un_led(void) {

  LedsTurnOnSingle(2);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0002)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

 ((void *)0)

 ), (UNITY_UINT)(49), UNITY_DISPLAY_STYLE_HEX16);

}





void test_apagar_un_led(void) {

  LedsTurnOnSingle(2);

  LedsTurnOffSingle(2);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

 ((void *)0)

 ), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_HEX16);

}







void test_prendo_prendo_apago_apago(void) {

  LedsTurnOnSingle(3);

  LedsTurnOnSingle(5);

  LedsTurnOffSingle(3);

  LedsTurnOffSingle(7);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0010)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

 ((void *)0)

 ), (UNITY_UINT)(66), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prendo_y_leo(void) {

  LedsTurnOnSingle(4);

  do {if ((LedsIsOn(4))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(72)));}} while(0);

}





void test_apago_y_leo(void) {

  LedsTurnOnSingle(4);

  LedsTurnOffSingle(4);

  do {if (!(LedsIsOn(4))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(79)));}} while(0);

}







void test_prendo_todo_y_leo(void) {

  LedsTurnOnAll();

  do {if ((LedsIsOn(1))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(86)));}} while(0);

  do {if ((LedsIsOn(2))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(87)));}} while(0);

  do {if ((LedsIsOn(3))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(88)));}} while(0);

  do {if ((LedsIsOn(4))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(89)));}} while(0);

  do {if ((LedsIsOn(5))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(90)));}} while(0);

  do {if ((LedsIsOn(6))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(91)));}} while(0);

  do {if ((LedsIsOn(7))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(92)));}} while(0);

  do {if ((LedsIsOn(8))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(93)));}} while(0);

  do {if ((LedsIsOn(9))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(94)));}} while(0);

  do {if ((LedsIsOn(10))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(95)));}} while(0);

  do {if ((LedsIsOn(11))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(96)));}} while(0);

  do {if ((LedsIsOn(12))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(97)));}} while(0);

  do {if ((LedsIsOn(13))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(98)));}} while(0);

  do {if ((LedsIsOn(14))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(99)));}} while(0);

  do {if ((LedsIsOn(15))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(100)));}} while(0);

  do {if ((LedsIsOn(16))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(101)));}} while(0);

}





void test_apago_todo_y_leo(void) {

  LedsTurnOnAll();

  LedsTurnOffAll();

  do {if (!(LedsIsOn(1))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(108)));}} while(0);

  do {if (!(LedsIsOn(2))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(109)));}} while(0);

  do {if (!(LedsIsOn(3))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(110)));}} while(0);

  do {if (!(LedsIsOn(4))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(111)));}} while(0);

  do {if (!(LedsIsOn(5))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(112)));}} while(0);

  do {if (!(LedsIsOn(6))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(113)));}} while(0);

  do {if (!(LedsIsOn(7))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(114)));}} while(0);

  do {if (!(LedsIsOn(8))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(115)));}} while(0);

  do {if (!(LedsIsOn(9))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(116)));}} while(0);

  do {if (!(LedsIsOn(10))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(117)));}} while(0);

  do {if (!(LedsIsOn(11))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(118)));}} while(0);

  do {if (!(LedsIsOn(12))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(119)));}} while(0);

  do {if (!(LedsIsOn(13))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(120)));}} while(0);

  do {if (!(LedsIsOn(14))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(121)));}} while(0);

  do {if (!(LedsIsOn(15))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(122)));}} while(0);

  do {if (!(LedsIsOn(16))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(123)));}} while(0);

}







void test_prendo_y_leo_limites(void){

  LedsTurnOnSingle(1);

  LedsTurnOnSingle(16);

  do {if ((LedsIsOn(1))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(131)));}} while(0);

  do {if ((LedsIsOn(16))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(132)));}} while(0);

}





void test_valores_erroneos(void) {

  LedsTurnOnSingle(0);

  do {if (!(LedsIsOn(0))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(138)));}} while(0);

  LedsTurnOnSingle(255);

  do {if (!(LedsIsOn(255))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(140)));}} while(0);

  LedsTurnOnSingle(32);

  do {if (!(LedsIsOn(32))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(142)));}} while(0);

  LedsTurnOnSingle(17);

  do {if (!(LedsIsOn(17))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(144)));}} while(0);

}





void test_inicio_erroneo(void) {

  do {if (!(LedsInit(

 ((void *)0)

 ))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(149)));}} while(0);

}
