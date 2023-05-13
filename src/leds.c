#include "leds.h"
static uint16_t* puerto_virtual;

#define INDEX_OFFSET 1
#define FIRST_BIT 1
#define ALL_LEDS_OFF 0x0000

uint16_t indexToMask(uint8_t led){
    return(FIRST_BIT<<(led-INDEX_OFFSET));
}

uint16_t indexToMaskStateLed(uint8_t led){
    return(FIRST_BIT<<(led-INDEX_OFFSET));
}

void ledsInit(uint16_t* direccion){
    puerto_virtual=direccion;
    *puerto_virtual=ALL_LEDS_OFF;
}

void ledsTurnOnSingle(int led){
    *puerto_virtual |= indexToMask(led);
}

void ledsTurnOffSingle(int led){
    *puerto_virtual&=~indexToMask(led);
}

bool isLedTurnOn(int led){
    bool state;
    if ((FIRST_BIT & (*puerto_virtual>>(led-1)))==1){
        state=true;
    }
    else{
        state=false;
    }
    return state;
}