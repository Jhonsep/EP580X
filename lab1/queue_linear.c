#include "queue_linear.h"
#include "lab1.h"

item_queue *createQueue(){
    item_queue *q = (item_queue*)malloc(sizeof(item_queue));
    q->front = q->rear = NULL;
    q->max_items_queue = MAX_QUEUE_SIZE;
    return q;
}

bool push_queue(item_queue* q, item_type const* item){
    if(q->number_items_queue == q->max_items_queue) {
        return false;
    }
    q->data[q->front + q->number_items_queue] = *item;
    q->number_items_queue++;
}

item_type pop_queue(item_queue* q){
    if (q->number_items_queue == 0){
        return;
    }
    for (int i = 1; i < q->number_items_queue; i++){
        q->data[q->front + i - 1] = q->data[q->front + i];
    }
    q->number_items_queue--;
}

item_type peek_queue(item_queue* q){
    for (int i = q->front; i < q->number_items_queue; i++){
        printf("Pin Value: %i\n", q->data[i].pinValue);
        printf("interruption Value: %i\n", q->data[i].interruptionValue);
        printf("Register Value %i\n", q->data[i].registerValue);
    }
}

item_type peek_item(item_queue* q){
    printf("Pin Value: %i\n", q->data[q->front].pinValue);
    printf("interruption Value: %i\n", q->data[q->front].interruptionValue);
    printf("Register Value %i\n", q->data[q->front].registerValue);
}

bool is_empty_queue(item_queue* q){
    return q->number_items_queue == 0;
}

bool is_full_queue(item_queue* q){
    return q->number_items_queue == q->max_items_queue;
}