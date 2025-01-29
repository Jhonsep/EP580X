#include "stack.h"

Sensor* sensorMeasurements (uint8_t *data){
    Sensor* sensor = (Sensor*)malloc(sizeof(sensor));
    
    sensor->battery = data[0];
    sensor->temp = (uint16_t)(data[1]<<8 | data[2]);
    sensor->backupTank = (int32_t)(data[3]<<16 | data[4]<<8 | data[5]);
    sensor->pplTank = (uint32_t)(data[6]<<32 | data[7]<<16 | data[8]<<8 | data[9]);
    sensor->checksum = (uint16_t)(data[10]<<8 | data[11]);
    return sensor; 
    
}

int interruptionHandler(Stack *stack){
    bool pin1 = false;
    size_t counter;
    Item instruc;
    
    while (!isEmpty(stack))
    {
        instruc = pop(stack);
        switch (instruc.instruccion)
        {
        case toogle: 
            pin1 = !pin1;
            break;
        case  print:
                pin1 ? printf("TRUE"):  printf("false");
            break;
        case increment:
            counter++;
            break;
        case printCounter:
            printf("Contador en: %d", counter);
            break;
        case stackCheck:
            printf("Numero de items en la pila: %d", count(stack));
            break;
        case stackFull:
            if(isFull(stack)) exit(0);
            break;
        default:
            printf("%d instrucción no valida", instruc.instruccion);
            break;
        }
    }
    
}