#ifndef queue_linear_h
#define queue_linear_h

#include "lab1.h"


#define MAX_QUEUE_SIZE 5

typedef struct ITEM_QUEUE{
    item_type data[MAX_QUEUE_SIZE];
    size_t front, rear, number_items_queue; 
    size_t max_items_queue;
}item_queue; 

item_queue *createQueue();
bool push_queue(item_queue* q, item_type const* item);
item_type pop_queue(item_queue* q);
item_type peek_queue(item_queue* q);
item_type peek_item(item_queue* q);
bool is_empty_queue(item_queue* q);
bool is_full_queue(item_queue* q);

#endif queue_linear_h
