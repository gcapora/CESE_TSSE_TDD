/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_todos_los_leds_inician_apagados(void);
extern void test_prender_un_led(void);
extern void test_apagar_un_led(void);
extern void test_prendo_prendo_apago_apago(void);
extern void test_prendo_y_leo(void);
extern void test_apago_y_leo(void);
extern void test_prendo_todo_y_leo(void);
extern void test_apago_todo_y_leo(void);
extern void test_prendo_y_leo_limites(void);
extern void test_valores_erroneos(void);
extern void test_inicio_erroneo(void);


/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
}
static void CMock_Verify(void)
{
}
static void CMock_Destroy(void)
{
}

/*=======Test Reset Options=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  CMock_Verify();
  CMock_Destroy();
  CMock_Init();
  setUp();
}
void verifyTest(void);
void verifyTest(void)
{
  CMock_Verify();
}

/*=======Test Runner Used To Run Each Test=====*/
static void run_test(UnityTestFunction func, const char* name, UNITY_LINE_TYPE line_num)
{
    Unity.CurrentTestName = name;
    Unity.CurrentTestLineNumber = line_num;
#ifdef UNITY_USE_COMMAND_LINE_ARGS
    if (!UnityTestMatches())
        return;
#endif
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    CMock_Init();
    if (TEST_PROTECT())
    {
        setUp();
        func();
    }
    if (TEST_PROTECT())
    {
        tearDown();
        CMock_Verify();
    }
    CMock_Destroy();
    UNITY_EXEC_TIME_STOP();
    UnityConcludeTest();
}

/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_leds.c");
  run_test(test_todos_los_leds_inician_apagados, "test_todos_los_leds_inician_apagados", 39);
  run_test(test_prender_un_led, "test_prender_un_led", 47);
  run_test(test_apagar_un_led, "test_apagar_un_led", 53);
  run_test(test_prendo_prendo_apago_apago, "test_prendo_prendo_apago_apago", 61);
  run_test(test_prendo_y_leo, "test_prendo_y_leo", 70);
  run_test(test_apago_y_leo, "test_apago_y_leo", 76);
  run_test(test_prendo_todo_y_leo, "test_prendo_todo_y_leo", 84);
  run_test(test_apago_todo_y_leo, "test_apago_todo_y_leo", 105);
  run_test(test_prendo_y_leo_limites, "test_prendo_y_leo_limites", 128);
  run_test(test_valores_erroneos, "test_valores_erroneos", 136);
  run_test(test_inicio_erroneo, "test_inicio_erroneo", 148);

  return UnityEnd();
}
