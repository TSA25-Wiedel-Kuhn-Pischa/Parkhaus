/*
 * File: cars.c
 * Description: Funktion und struct von Autos
 */

/**
 * Pseudo-Code:
 * create_car - Funktion mit Eingabe: AnkunftsZeit, Car Struct, maximale Parkdauer, Warteschlange Struct
 *
     * auf ungültige Eingabe prüfen
     * car id = nächste ID von car_id_counter() Funktion
     * zufällige Zahl zwischen 1 und 50 generieren
     * switch je nach Zahl wird:
     * brand gesetzt
     * modelname gesetzt
     * ps gesetzt
     * int temp_parking_duration = randomize_parking_duration(max_parking_duration)
     * auf Fehler prüfen
     * parking_duration auf temp_parking_duration setzen
     * IF queue_get_size() == 0) && (check_for_free_space() == 1)) DO
        * park_car(c, struct Car *parking_garage, time_stemp)
     * ELSE DO
         * queue_enqueue(queue1, c)
     * END IF
     * return 0

 * car_id_counter - Funktion ohne Eingabe
     * einmalig counter auf 0 setzen
     * counter um 1 erhöhen
     * counter zurückgeben

 * randomize_parking_duration - Funktion mit Eingabe maximale Parkdauer
     * auf ungültige Eingabe prüfen
     * zufällige Zahl zwischen 1 und maximale Parkdauer generieren
     * auf Fehler prüfen
     * Zeitdauer zurückgeben
 */

#ifndef CARS_H
    #define CARS_H
    #include "include/cars.h"
#endif



int create_car(int max_parking_duration, int time_stemp, struct car* c, struct queue* queue1){
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

    if(c == NULL || max_parking_duration <= 0 || time_stemp < 0){        //auf ungültige Eingabe prüfen
        return -1;
    }

    c->car_id = car_id_counter();
    if(c->car_id <= 0){        //auf ungültige Eingabe prüfen
        return -1;
    }

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

    int temp_parking_duration = randomize_parking_duration(max_parking_duration);
    if(temp_parking_duration == -1){
        return -1;
    }
    c->parking_duration = temp_parking_duration;

    if((queue_get_size() == 0) && ((check_for_free_space() == 1))){             //prüft ob es eine Warteschlange und freie Plätze gibt
        park_car(c, struct Car *parking_garage, time_stemp);                    //übergibt das Auto ans Parkhaus
    }
    else{
        queue_enqueue(queue1, c);                                               //Auto wird in Warteschlange / Queue eingereiht
    }

    

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

int randomize_parking_duration(int r_max_parking_duration){           //maximale Pardauer abrufen oder übergeben bekommen?
    /**
    * @brief gibt eine zufällige Parkdauer zurück
    *
    * @param[in]  r_max_parking_duration maximale Parkdauer
    * @param[in]  r_time_step_size Zeitschrittgröße für die Berechnung der Parkdauer
    * @param[out] random_parking_duration zufällige Parkdauer
    * @return            gibt random_parking_duration zurück
    */
    if(r_max_parking_duration <= 0){        //auf ungültige Eingabe prüfen
        return -1;
    }
    int random_parking_duration = 0;       //maximale Parkdauer in maximale Zeitschritte umrechnen
    
    random_parking_duration = rand() % r_max_parking_duration + 1;   //zufällige Parkdauer berechnen
    if (random_parking_duration <= 0){        //auf ungültige Eingabe prüfen
        return -1;
    }

    return random_parking_duration;
}
