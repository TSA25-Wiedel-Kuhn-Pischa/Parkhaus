#include "cars.h"
#include <stdio.h>
#include <string.h>


struct car{
    int car_id;
    float parking_duration;
    float remaining_parking_duration;
    float arrival_time;
    int ps;
    char brand[50];
    char modelname[50];
};

void create_car(int car_id, float parking_duration, float arrival_time, struct car* c){
    c->car_id = car_id;
    c->parking_duration = parking_duration;
    c->remaining_parking_duration = parking_duration;
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