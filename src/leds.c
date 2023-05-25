#include "leds.h"
static uint16_t* puerto_virtual;

#define INDEX_OFFSET    1
#define FIRST_BIT       1
#define ALL_LEDS_OFF    0x0000
#define ALL_LEDS_ON     0xFFFF
#define LED_ON          1
#define LED_OFF         0

uint16_t indexToMask(uint8_t led){
    return(FIRST_BIT<<(led-INDEX_OFFSET));
}

void ledsInit(uint16_t* direccion){
    puerto_virtual=direccion;
    ledsTurnOffAll();
}

void ledsTurnOnSingle(int led){
    *puerto_virtual |= indexToMask(led);
}

void ledsTurnOffSingle(int led){
    *puerto_virtual&=~indexToMask(led);
}

bool isLedTurnOn(int led){
    bool state;
    if ((*puerto_virtual & indexToMask(led)) !=LED_OFF){
        state=true;
    }
    else{
        state=false;
    }
    return state;
}

void ledsTurnOnAll(void){
    *puerto_virtual=ALL_LEDS_ON;
}

void ledsTurnOffAll(void){
   *puerto_virtual=ALL_LEDS_OFF;
}