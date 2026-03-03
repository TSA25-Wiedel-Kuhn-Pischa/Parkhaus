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

typedef struct car{
    int car_id;
    float parking_duration;
    int parking_duration_reached;
    float arrival_time;
    int ps;
    char brand[50];
    char modelname[50];
} car;


int create_car(int max_parking_duration, int time_stemp, struct car* c, struct queue* queue1);
/**
    * @brief setzt die Werte eines Car-Structs
    *        und parkt das Auto oder setzt es in die Warteschlange
    *
    * @param[in]  time_stemp  aktueller Zeitschritt, zu dem das Auto ankommt
    * @param[in]  struct car* c  Pointer auf Car-Struct, dass bearbeitet wird
    * @param[in]  max_parking_duration maximale Parkdauer
    * @param[in]  *queue1  Zeiger auf die Warteschlange
    * 
    * return   nur zur Fehlersignalisierung, wenn die Funktion -1 zurückgibt, ist ein Fehler aufgetreten
*/

int car_id_counter();
/**
    * @brief zählt die IDs für die Autos hoch, damit jedes Auto eine eindeutige ID bekommt
    *
    * @param[out] counter aktuelle ID, die zurückgegeben wird, wenn die Funktion aufgerufen wird
    * @return            gibt counter zurück
*/

int randomize_parking_duration(int max_parking_duration);
/**
    * @brief gibt eine zufällige Parkdauer zurück
    *
    * @param[in]  r_max_parking_duration maximale Parkdauer
    * @param[in]  r_time_step_size Zeitschrittgröße für die Berechnung der Parkdauer
    * @param[out] random_parking_duration zufällige Parkdauer
    * @return            gibt random_parking_duration zurück
*/