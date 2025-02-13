#ifndef lab1_h
#define lab1_h
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

enum GPIO_PINS{
    GPIO1 = 0xA0,   //Chip Select (CS)
    GPIO2,          //INT1
    GPIO3,          //INT2
    GPIO4,          //INT3
    GPIO5           //INT4
};

enum SPI_PINS{
    SDO = 0xE0,     //Serial data output
    SDI,            //Serial data input
    SCK             //Serial clock
};

typedef enum {
	READ = 0x00,
	WRITE = 0x01
} SPI_MODE;

typedef enum {
	interruptConfigure_RW = 0x20,
	GRAVITY_L_R = 0x10
} ACCEL_REGISTERS;

typedef union  {
    uint8_t byte;
    struct {
        uint8_t gravitySizeDef : 2;    
        uint8_t extraInterruptsEnable : 1;
        uint8_t deviceState : 1;
        uint8_t : 4;
    };
}deviceDefinitions;

typedef union  {
    uint8_t byte;
    struct{
        uint8_t : 2;
        uint8_t measurment : 6;
    };
}gravityL;

typedef union  {
    uint8_t byte;
    struct {
        uint8_t tapEnable : 1;
        uint8_t gravityChangeEnable : 1;
        uint8_t inactivityEnable : 1;
        uint8_t doubleTapEnable : 1;
        uint8_t : 4;
    };
}gravityH;

typedef union {
    uint8_t byte;
    struct {
        uint8_t tapEnable : 1;
        uint8_t gravityChangeEnable : 1;
        uint8_t inactivityEnable : 1;
        uint8_t doubleTapEnable : 1;
        uint8_t : 4;
    };
}interruptConfig;

typedef struct ITEM_TYPE{
    uint8_t pinValue;
    uint8_t interruptionValue;
    uint8_t registerValue;
}item_type;

typedef struct {
    uint8_t pin;
    void (*interruptHandler)(uint8_t);
}ACCEL_INTERRUPT;


#endif lab1_hs