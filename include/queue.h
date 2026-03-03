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
/**
    * @brief initialisiert eine neue Warteschlange
    *
    * @param[out]  Queue Zeiger auf die initialisierte Warteschlange
    * 
    * return  QueueZeiger auf die initialisierte Warteschlange
    */

int queue_enqueue(Queue *q, struct car *new_car); 
/**
    * @brief fügt Auto am Ende der Warteschlange hinzu
    *
    * @param[in]  *queue1  Zeiger auf die Warteschlange
    * @param[in]  struct car* new_car  Zeiger auf das Auto, das in die Warteschlange eingereiht werden soll
    * 
    * return   nur zur Fehlersignalisierung, wenn die Funktion -1 zurückgibt, ist ein Fehler aufgetreten
*/

struct car* queue_dequeue(Queue *q);
/**
    * @brief nimmt das erste Auto aus der Warteschlange und gibt es zurück
    *
    * @param[in]  *queue1  Zeiger auf die Warteschlange
    * @param[out] struct car* car Zeiger auf das Auto, das aus der Warteschlange genommen wurde
    * 
    * return struct car* car Zeiger auf das Auto, das aus der Warteschlange genommen wurde
*/

int queue_get_size(Queue *q); 
/**
    * @brief gibt die Anzahl der Autos in der Warteschlange zurück
    *
    * @param[in]  *queue1  Zeiger auf die Warteschlange
    * @return count     Anzahl der Autos in der Warteschlange
*/