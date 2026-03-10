/*
 * File: queue.c
 * Description: Warteschlange vor dem Parkhaus von Queue
 */
/*
Pseudo-Code:

queue_init - Funktion ohne Eingabe
    - Speicher für Queue reservieren mit malloc
    - auf ungültige Eingabe prüfen
    - head, tail auf NULL setzen
    - count auf 0 setzen
    - Pointer auf Queue zurückgeben

queue_enqueue - Funktion mit Eingabe Pointer auf Queue, Pointer auf Auto
    - auf ungültige Eingabe prüfen
    - neuen Node mit malloc erstellen
    - auf ungültige Eingabe prüfen
    - data des Nodes auf neues Auto setzen
    - next des Nodes auf NULL setzen
    - IF tail == NULL DO
        - head und tail auf neuen Node setzen
    - ELSE
        - next von tail auf neuen Node setzen
        - tail auf neuen Node setzen
    END IF
    - count um 1 erhöhen
    - return 0

queue_dequeue - Funktion mit Eingabe Pointer auf Queue
    - auf ungültige Eingabe prüfen
    - temp Node auf head setzen
    - car Pointer auf data von temp Node setzen
    - head auf nextes Auto setzen
    - IF head == NULL DO
        - tail auf NULL setzen
    END IF
    - free temp Node
    - count um 1 verringern
    - car Pointer zurückgeben

queue_get_size - Funktion mit Eingabe Pointer auf Queue
    - auf ungültige Eingabe prüfen
    - count zurückgeben

*/




#ifndef QUEUE_H
    #define QUEUE_H
    #include "include/queue.h"
#endif

Queue* queue_init(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if(q == NULL){
        return NULL;
    }
    q->head = NULL;
    q->tail = NULL;
    q->count = 0;

    return q;
}

int queue_enqueue(Queue *q, struct car *new_car){
    if(q == NULL || new_car == NULL){
        return -1;
    }

    Node *new_node = (Node *)malloc(sizeof(Node));
    if(new_node == NULL){
        return -1;
    }

    new_node->data = new_car;
    new_node->next = NULL;

    if(q->tail == NULL){
        q->head = new_node;
        q->tail = new_node;
    }
    else{
        q->tail->next = new_node;
        q->tail = new_node;
    }
    q->count++;

    return 0;
}

struct car* queue_dequeue(Queue *q){
    if(q == NULL || q->head == NULL){
        return NULL;
    }

    Node *temp = q->head;
    struct car *ptr_car = temp->data;
    q->head = q->head->next;
    if(q->head == NULL){
        q->tail = NULL;
    }
    free(temp);
    q->count--;

    return ptr_car;
}

int queue_get_size(Queue *q){
    if(q == NULL){
        return -1;
    }
    return q->count;
}