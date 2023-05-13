// Revisar los valores limites de los argumentos.
// Revisar que pasa con valores erroneos en los argumento
// Inicializar mal para que devuelva false

#include "unity.h"
#include "leds.h"

static uint16_t puerto_virtual;

void setUp(void){
ledsInit(&puerto_virtual);
}

void tearDown(void){

}

// Al inciarlizar la biblioteca todos los leds quedan apagados.
void test_todos_los_leds_inician_apagados(void){
    uint16_t puerto_virtual=0xFFFF;
    ledsInit(&puerto_virtual);
    TEST_ASSERT_EQUAL_HEX16(0x0000,puerto_virtual);
}

// Con todos los leds apagados, prendo el led 2, verifico que se el bit 1 vale 1.
void test_prendo_un_led(void){

    ledsTurnOnSingle(2);
    TEST_ASSERT_EQUAL_HEX16(0x0002,puerto_virtual);
}

// Con el led 2 prendido, apago el led 2, verifico que se enciende el bit 1 vale 0.
void test_prender_y_apagar_led(void){

    ledsTurnOnSingle(2);
    ledsTurnOffSingle(2);
    TEST_ASSERT_EQUAL_HEX16(0x00000,puerto_virtual);
}

// Con todos los leds apagados, prendo el 3, prendo el 5, apago el 3 y apago el 7, deberían quedar el bit 4 en 1 y el resto en 0
void test_prender_y_apagar_varios_leds(void){
    ledsTurnOnSingle(3);
    ledsTurnOnSingle(5);
    ledsTurnOffSingle(3);
    ledsTurnOffSingle(7);
    TEST_ASSERT_EQUAL_HEX16(0x0010,puerto_virtual);
}

// Prendo un led, consulto el estado y tiene que estar prendido.
void test_prender_y_consultar_estado_led(void){
    
    ledsTurnOnSingle(5);
    bool state_led=isLedTurnOn(5);
    TEST_ASSERT_TRUE(state_led);
}

// Apago un led, consulto el estado y tiene que estar apagado.
void test_apagar_y_consultar_estado_led(void){
    
    ledsTurnOnSingle(5);
    ledsTurnOffSingle(5);
    bool state_led=isLedTurnOn(5);
    TEST_ASSERT_FALSE(state_led);
}

// Con todos los leds apagados, prendo todos los leds y verifico que se encienden.   
void test_encender_todos_los_leds(void){
    ledsTurnOnAll();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF,puerto_virtual);
}

// Con todos los leds prendidos, apagado todos los leds y verifico que se apagan.
void test_apagar_todos_los_leds(void){
    ledsTurnOnAll();
    ledsTurnOffAll();
    TEST_ASSERT_EQUAL_HEX16(0x0000,puerto_virtual);
}