/*
 * File: cras.c
 * Description: Funktion und struct von Autos
 */

/**
 * Pseudo-Code:
 * create_car - Funktion mit Eingabe: AnkunftsZeit, Car Struct
 *
     * car id = nächste ID von car_id_counter() Funktion
     * parking duration = übergebenes Argument parking_duration
     * arrival time = übergebenes Argument arrival_time
     * zufällige Zahl zwischen 1 und 50 generieren
     * switch je nach Zahl wird:
     * brand gesetzt
     * modelname gesetzt
     * ps gesetzt
     *
 * car_id_counter - Funktion ohne Eingabe
     * einmalig counter auf 0 setzen
     * counter um 1 erhöhen
     * counter zurückgeben
 */

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



int create_car(int max_parking_duration, int time_step_size, struct car* c){
    /**
    * @brief setzt die Werte eines Car-Structs
    *        und parkt das Auto oder setzt es in die Warteschlange
    *
    * @param[in]  struct car* c  Pointer auf Car-Struct, dass bearbeitet wird
    * @param[in]  max_parking_duration maximale Parkdauer in Sekunden
    * @param[in]  time_step_size Zeitschrittgröße für die Berechnung der Parkdauer
    * 
    * return   nur zur Fehlersignalisierung, wenn die Funktion -1 zurückgibt, ist ein Fehler aufgetreten
    */

    if(c == NULL || max_parking_duration <= 0 || time_step_size <= 0){        //auf ungültige Eingabe prüfen
        return -1;
    }

    c->car_id = car_id_counter();

    int randommodelnumber = (rand() % (50) +1);     //Zufällige um ein zufälliges Modell auszuwählen
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

    int time_stemp = 0; //abruf von timestep abrufen

    if((check_for_free_space(struct Car *parking_garage) == 1)){                //woher bekomm ich die parking garage?
        park_car(*c, struct Car *parking_garage, time_stemp);                   //brauch ich den time_stemp?
    }
    else{
        //Auto wird in Warteschlange / Queue eingereiht
    }

    int temp_parking_duration = randomize_parking_duration(max_parking_duration, time_step_size);
    if(temp_parking_duration == -1){
        return -1;
    }
    c->parking_duration = temp_parking_duration;

    return 0;    
}


int car_id_counter(){
    /**
    * @brief zählt die IDs für die Autos hoch, damit jedes Auto eine eindeutige ID bekommt
    *
    * @param[out] counter aktuelle ID, die zurückgegeben wird, wenn die Funktion aufgerufen wird
    * @return            gibt counter zurück
    */
    static int counter = 0;
    counter ++;
    return counter;
}

int randomize_parking_duration(int r_max_parking_duration, int r_time_step_size){           //maximale Pardauer abrufen oder übergeben bekommen?
    /**
    * @brief gibt eine zufällige Parkdauer zurück
    *
    * @param[in]  r_max_parking_duration maximale Parkdauer
    * @param[in]  r_time_step_size Zeitschrittgröße für die Berechnung der Parkdauer
    * @param[out] random_parking_duration zufällige Parkdauer
    * @return            gibt random_parking_duration zurück
    */
    if(r_max_parking_duration <= 0 || r_time_step_size <= 0){        //auf ungültige Eingabe prüfen
        return -1;
    }
    int random_parking_duration = 0;
    int temp_duaration_step = r_max_parking_duration / r_time_step_size;        //maximale Parkdauer in maximale Zeitschritte umrechnen
    
    random_parking_duration = rand() % temp_duaration_step + 1;
    random_parking_duration *= r_time_step_size;                              //ermittelte zufällige Parkdauer in Zeit umrechnen

    return random_parking_duration;
}
