#include "stack.h"

Stack* createStack(unsigned capacity) 
{ 
    Stack* stack = (Stack*)malloc(sizeof(Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->item = (int*)malloc(stack->capacity * sizeof(int)); 
    return stack; 
} 

int isFull(Stack* stack) 
{ 
    return stack->top == stack->capacity - 1; 
} 
