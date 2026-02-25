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

void create_car(float parking_duration, float arrival_time, struct car* c);
int car_id_counter();