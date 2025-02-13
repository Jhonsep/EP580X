
#include "stack.h"

void initializeStack()
{    
    staticStack* stack = (staticStack*)malloc(sizeof(staticStack)); 
    stack->top = -1; 
    return stack; 
}

int isStaticFull(Stack *stack) 
{ 
    return stack->top == MAX - 1; 
} 

int isEmpty (Stack *stack){
    return stack->top == -1;
}

void push(Stack *stack, Item item){
    if (isFull(stack))
    {
        printf("Is Full\n"); 
        return;
    }
    stack->item[++stack->top] = item; 
    printf("%d pushed to stack\n", item); 
}

Item pop(Stack *stack) 
{ 
    if (isEmpty(stack))
    {
        printf("Is empty\n"); 
        return;
    } 
    return stack->item[stack->top--]; 
}

Item peek(Stack *stack) 
{ 
    if (isEmpty(stack))
        printf("Is empty");
        return; 
    return stack->item[stack->top]; 
}


int count(Stack *stack)
{
    return stack->top+1;
}
