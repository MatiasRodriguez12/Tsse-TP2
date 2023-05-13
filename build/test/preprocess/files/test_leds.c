#include "inc/leds.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


static uint16_t puerto_virtual;



void setUp(void){

ledsInit(&puerto_virtual);

}



void tearDown(void){



}





void test_todos_los_leds_inician_apagados(void){

    uint16_t puerto_virtual=0xFFFF;

    ledsInit(&puerto_virtual);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prendo_un_led(void){



    ledsTurnOnSingle(2);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0002)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_y_apagar_led(void){



    ledsTurnOnSingle(2);

    ledsTurnOffSingle(2);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x00000)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(42), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_y_apagar_varios_leds(void){

    ledsTurnOnSingle(3);

    ledsTurnOnSingle(5);

    ledsTurnOffSingle(3);

    ledsTurnOffSingle(7);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0010)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(51), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_y_consultar_estado_led(void){



    ledsTurnOnSingle(5);

    

   _Bool 

        state_led=isLedTurnOn(5);

    do {if ((state_led)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(59)));}} while(0);

}
