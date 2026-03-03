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