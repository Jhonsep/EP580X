#ifndef STACK_H
#define STACK_H

#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <stdint.h>
#include <stdbool.h>

//Max capacity of a static stack
#define MAX 25

//A Struct that represents a item of a stack
typedef struct Item
{
    uint8_t pin;
    uint32_t interruptionTime;
    uint16_t refPointer;
    int instruccion;
}Item;

//A struct that represnent a dinamic stack
typedef struct Stack { 
    int top; 
    unsigned capacity; 
    Item *item; 
}Stack;

//a Struct that represents a dinamic stack
typedef struct staticStack { 
    int top; 
    Item item[MAX]; 
}staticStack; 


//a Struct that represents a data measure by a sensor
typedef struct Sensor
    {
        uint8_t *battery;
        int16_t *temp;
        int32_t *backupTank;
        uint32_t *pplTank;
        uint16_t *checksum;
    }Sensor;


//Enum of a set of instrucctions
enum instruction{
    toogle,                 // Hacer Toogle de una variable Booleana para el pin 1
    print,                  // Imprimir el valor del pin1 
    increment,              // Aumentar un contador de tipo size_t
    printCounter,           //Imprimir el Contador
    stackCheck = 0x05,      //Verificar el numero de items que hay en una pila
    stackFull               //Si la pila esta llena finaliza la ejecución del programa
};

// function to create a stack of given capacity. It initializes size of 
// stack as 0 
Stack* createStack(unsigned capacity);

// function to create a static stack of given capacity.
void initializeStack(Stack *Stack);

// Stack is empty when top is equal to -1 
int isEmpty(Stack *s);

// Stack is full when top is equal to the last index 
int isFull(Stack *s);

// Stack is full when top is equal to the last index 
int isStaticFull(Stack *stack);

// Function to add an item to stack. It increases top by 1 
void push(Stack *s, Item item);

// Function to remove an item from stack. It decreases top by 1 
Item pop(Stack *s);

// Function to return the top from stack without removing it 
Item peek(Stack* stack);

// Function to count elements in a stack
int count(Stack *stack);

//This function store the measuraments of a sensor
Sensor* sensorMeasurements (uint8_t *data);

//interruption Handler of an embeded system
int interruptionHandler(Stack *stack);

#endif  STACK_H