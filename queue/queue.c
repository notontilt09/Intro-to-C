#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

typedef struct Queue {
    unsigned int length;
    unsigned int capacity;
    int *storage;
} Queue;

/*
    Creates a queue by allocating the appropriate amount of memory for an
    instance of the Queue struct, and initializes all of the fields of the
    struct. Also allocates memory for the queue's storage structure. 
*/
Queue *createQueue(unsigned capacity)
{
    Queue *q = malloc(sizeof(Queue));
    q->length = 0;
    q->capacity = capacity;
    q->storage = malloc(q->capacity * sizeof(int));

    return q;
}

/*
    Adds the given item to the end of the queue. If the queue does
    not have room, expand the queue's available storage so that it 
    does have room for the additional item.
*/
void enqueue(Queue *q, int item)
{
    // if there's no room at the end
    if (q->capacity <= q->length) {
        // increase capacity
        q->capacity++;
        // reallocate memory to hold new item
        q->storage = resize_memory(q->storage, q->capacity * sizeof(int));
    } 
    // add item to end of storage array
    q->storage[q->length] = item;
    // increase length of storage array
    q->length++;
}

/*
    Removes the item at the front of the queue and returns it. 
    If the queue is empty, this function should return -1.
*/
int dequeue(Queue *q)
{     
    // if nothing in queue return -1
    if (q->length == 0) {
        return -1;
    }
    
    // return value
    int pop = q->storage[0];
    // decrement the length of the queue
    q->length--;
    // move the pointer to the next item in storage
    q->storage++;
    // return the old first value
    return pop;
}

/*
    Frees the memory used to hold the queue instance and its
    associated storage. 
*/
void destroyQueue(Queue *q)
{
    if (q->length > 0) {
        if (q->storage != NULL) {
            free(q->storage);
        }
    } 
    if (q != NULL) {
        free(q);
    }
}


#ifndef TESTING
int main(void)
{
    Queue *q = createQueue(4);

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);

    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));

    destroyQueue(q);

    // unsigned int capacity = (rand() % 30) + 1;
    // unsigned int increased_cap = capacity + 5;

    // Queue *q = createQueue(capacity);
    // int *rand_values = malloc(sizeof(int) * increased_cap);

    // unsigned int i;

    // for (i = 0; i < increased_cap; i++) {
    //     rand_values[i] = (rand() % 100) + 1;
    //     printf("%d\n", rand_values[i]);
    // }

    // printf("-----\n");

    // for (i = 0; i < increased_cap; i++) {
    //     enqueue(q, rand_values[i]);
    // }

    // for (i = 0; i < increased_cap; i++) {
    //     printf("%d\n", dequeue(q));
    // }

    // destroyQueue(q);

    return 0;
}
#endif