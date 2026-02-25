#ifndef CARS_H
    #define CARS_H
    #include "include/cars.h"
#endif
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



void create_car(float parking_duration, float arrival_time, struct car* c){
    c->car_id = car_id_counter();
    c->parking_duration = parking_duration;
    c->arrival_time = arrival_time;

    int randommodelnumber = (rand() % (50) +1);
    switch (randommodelnumber) {
        case 1:
            strcpy(c->brand, "Mercedes-Benz");
            strcpy(c->modelname, "A250e");
            c->ps = 172;
            break;
        case 2:
            strcpy(c->brand, "Mercedes-Benz");
            strcpy(c->modelname, "A180");
            c->ps = 150;
            break;
        case 3:
            strcpy(c->brand, "Mercedes-Benz");
            strcpy(c->modelname, "A45S");
            c->ps = 421;
            break;
        case 4:
            strcpy(c->brand, "Mercedes-Benz");
            strcpy(c->modelname, "CLA250+EQ");
            c->ps = 272;
            break;
        case 5:
            strcpy(c->brand, "Mercedes-Benz");
            strcpy(c->modelname, "CLA350EQ");
            c->ps = 150;
            break;
        case 6:
            strcpy(c->brand, "Mercedes-Benz");
            strcpy(c->modelname, "C63SE");
            c->ps = 680;
            break;
        case 7:
            strcpy(c->brand, "Mercedes-Benz");
            strcpy(c->modelname, "C300de");
            c->ps = 326;
            break;
        case 8:
            strcpy(c->brand, "Mercedes-Benz");
            strcpy(c->modelname, "E300de");
            c->ps = 326;
            break;
        case 9:
            strcpy(c->brand, "Mercedes-Benz");
            strcpy(c->modelname, "E53");
            c->ps = 612;
            break;
        case 10:
            strcpy(c->brand, "Mercedes-Benz");
            strcpy(c->modelname, "S350d");
            c->ps = 336;
            break;
        case 11:
            strcpy(c->brand, "Mercedes-Benz");
            strcpy(c->modelname, "S580e");
            c->ps = 612;
            break;
        case 12:
            strcpy(c->brand, "Mercedes-Benz");
            strcpy(c->modelname, "S580");
            c->ps = 560;
            break;
        case 13:
            strcpy(c->brand, "Mercedes-Benz");
            strcpy(c->modelname, "GLC400EQ");
            c->ps = 489;
            break;
        case 14:
            strcpy(c->brand, "Mercedes-Benz");
            strcpy(c->modelname, "G63");
            c->ps = 605;
            break;
        case 15:
            strcpy(c->brand, "Mercedes-Benz");
            strcpy(c->modelname, "CLE180");
            c->ps = 193;
            break;
        case 16:
            strcpy(c->brand, "Mercedes-Benz");
            strcpy(c->modelname, "CLE300e");
            c->ps = 333;
            break;
        case 17:
            strcpy(c->brand, "Mercedes-Benz");
            strcpy(c->modelname, "CLE53");
            c->ps = 472;
            break;
        case 18:
            strcpy(c->brand, "Mercedes-Benz");
            strcpy(c->modelname, "EQS450+");
            c->ps = 360;
            break;
        case 19:
            strcpy(c->brand, "Mercedes-Benz");
            strcpy(c->modelname, "EQS500");
            c->ps = 449;
            break;
        case 20:
            strcpy(c->brand, "Mercedes-Benz");
            strcpy(c->modelname, "EQS580");
            c->ps = 544;
            break;
        case 21:
            strcpy(c->brand, "Mercedes-Benz");
            strcpy(c->modelname, "EQS53");
            c->ps = 761;
            break;
        case 22:
            strcpy(c->brand, "Mercedes-Benz");
            strcpy(c->modelname, "GLE350de");
            c->ps = 353;
            break;
        case 23:
            strcpy(c->brand, "Mercedes-Benz");
            strcpy(c->modelname, "GLE400e");
            c->ps = 408;
            break;
        case 24:
            strcpy(c->brand, "Mercedes-Benz");
            strcpy(c->modelname, "GLE53");
            c->ps = 544;
            break;
        case 25:
            strcpy(c->brand, "Mercedes-Benz");
            strcpy(c->modelname, "GLE63S");
            c->ps = 612;
            break;
        
        case 50:
            strcpy(c->brand, "Porsche");
            strcpy(c->modelname, "911TurboSCabriolet");
            c->ps = 711;
            break;
        default:
            strcpy(c->brand, "Unknown Brand");
            strcpy(c->modelname, "Unknown Model");
            c->ps = 100;
    }
    
}


int car_id_counter(){
    static int counter = 0;
    counter ++;
    return counter;
}
