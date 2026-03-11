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




#include "include/queue.h"

Queue* queue_init()
{
    Queue *p_q = malloc(sizeof(Queue));
    if(p_q == NULL){                              //auf ungültige Eingabe prüfen
        return NULL;
    }
    p_q->head = NULL;
    p_q->tail = NULL;
    p_q->count = 0;                               //Anzahl der Autos in der Queue auf 0 setzen

    return p_q;
}

int queue_enqueue(Queue *p_q, struct car *p_new_car)
{
    if(p_q == NULL || p_new_car == NULL){
        return -1;
    }

    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL){
        return -1;
    }

    new_node->data = p_new_car;
    new_node->next = NULL;

    if(p_q->tail == NULL)
    {
        p_q->head = new_node;
        p_q->tail = new_node;
    }
    else
    {
        p_q->tail->next = new_node;
        p_q->tail = new_node;
    }
    p_q->count++;

    return 0;
}

struct car* queue_dequeue(Queue *p_q)
{
    if(p_q == NULL || p_q->head == NULL){
        return NULL;
    }

    Node *p_temp = p_q->head;
    struct car *p_car = p_temp->data;
    p_q->head = p_q->head->next;
    if(p_q->head == NULL)
    {
        p_q->tail = NULL;
    }
    free(p_temp);
    p_q->count--;

    return p_car;
}

int queue_get_size(Queue *p_q)
{
    if(p_q == NULL)
    {
        return -1;
    }

    return p_q->count;
}