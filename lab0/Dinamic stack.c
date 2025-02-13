#include "stack.h"

Stack* createStack(unsigned capacity) 
{ 
    Stack* stack = (Stack*)malloc(sizeof(Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->item = (Item*)malloc(stack->capacity * sizeof(Item)); 
    return stack; 
} 

int isFull(Stack* stack) 
{ 
    return stack->top == stack->capacity - 1; 
} 
