#ifndef STDIO_H
    #define STDIO_H
    #include <stdio.h>
#endif
#ifndef STRING_H
    #define STRING_H
    #include <string.h>
#endif
#ifndef STDLIB_H
    #define STDLIB_H
    #include <stdlib.h>
#endif



typedef struct Node {
    struct car *data;
    struct Node *next;
} Node;


typedef struct {
    Node *head;
    Node *tail;
    int count;
} Queue;


Queue* queue_init(); 
int queue_enqueue(Queue *q, struct car *new_car); 
struct car* queue_dequeue(Queue *q); 
int queue_get_size(Queue *q); 