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

#include "include/cars.h"



int create_car(int max_parking_duration, int time_stemp, struct car* p_c, struct queue* p_queue1)
{ 
    if(p_c == NULL || max_parking_duration <= 0 || time_stemp < 0)        //auf ungültige Eingabe prüfen
    {
        return -1;
    }

    p_c->car_id = car_id_counter();
    if(p_c->car_id <= 0)        //auf ungültige Eingabe prüfen
    {
        return -1;
    }

    int randommodelnumber = (rand() % (50) +1);     //Zufällige um ein zufälliges Modell auszuwählen
    switch (randommodelnumber)
    {
        case 1:
            strcpy(p_c->brand, "Mercedes-Benz");
            strcpy(p_c->modelname, "A250e");
            p_c->ps = 172;
            break;
        case 2:
            strcpy(p_c->brand, "Mercedes-Benz");
            strcpy(p_c->modelname, "A180");
            p_c->ps = 150;
            break;
        case 3:
            strcpy(p_c->brand, "Mercedes-Benz");
            strcpy(p_c->modelname, "A45S");
            p_c->ps = 421;
            break;
        case 4:
            strcpy(p_c->brand, "Mercedes-Benz");
            strcpy(p_c->modelname, "CLA250+EQ");
            p_c->ps = 272;
            break;
        case 5:
            strcpy(p_c->brand, "Mercedes-Benz");
            strcpy(p_c->modelname, "CLA350EQ");
            p_c->ps = 150;
            break;
        case 6:
            strcpy(p_c->brand, "Mercedes-Benz");
            strcpy(p_c->modelname, "C63SE");
            p_c->ps = 680;
            break;
        case 7:
            strcpy(p_c->brand, "Mercedes-Benz");
            strcpy(p_c->modelname, "C300de");
            p_c->ps = 326;
            break;
        case 8:
            strcpy(p_c->brand, "Mercedes-Benz");
            strcpy(p_c->modelname, "E300de");
            p_c->ps = 326;
            break;
        case 9:
            strcpy(p_c->brand, "Mercedes-Benz");
            strcpy(p_c->modelname, "E53");
            p_c->ps = 612;
            break;
        case 10:
            strcpy(p_c->brand, "Mercedes-Benz");
            strcpy(p_c->modelname, "S350d");
            p_c->ps = 336;
            break;
        case 11:
            strcpy(p_c->brand, "Mercedes-Benz");
            strcpy(p_c->modelname, "S580e");
            p_c->ps = 612;
            break;
        case 12:
            strcpy(p_c->brand, "Mercedes-Benz");
            strcpy(p_c->modelname, "S580");
            p_c->ps = 560;
            break;
        case 13:
            strcpy(p_c->brand, "Mercedes-Benz");
            strcpy(p_c->modelname, "GLC400EQ");
            p_c->ps = 489;
            break;
        case 14:
            strcpy(p_c->brand, "Mercedes-Benz");
            strcpy(p_c->modelname, "G63");
            p_c->ps = 605;
            break;
        case 15:
            strcpy(p_c->brand, "Mercedes-Benz");
            strcpy(p_c->modelname, "CLE180");
            p_c->ps = 193;
            break;
        case 16:
            strcpy(p_c->brand, "Mercedes-Benz");
            strcpy(p_c->modelname, "CLE300e");
            p_c->ps = 333;
            break;
        case 17:
            strcpy(p_c->brand, "Mercedes-Benz");
            strcpy(p_c->modelname, "CLE53");
            p_c->ps = 472;
            break;
        case 18:
            strcpy(p_c->brand, "Mercedes-Benz");
            strcpy(p_c->modelname, "EQS450+");
            p_c->ps = 360;
            break;
        case 19:
            strcpy(p_c->brand, "Mercedes-Benz");
            strcpy(p_c->modelname, "EQS500");
            p_c->ps = 449;
            break;
        case 20:
            strcpy(p_c->brand, "Mercedes-Benz");
            strcpy(p_c->modelname, "EQS580");
            p_c->ps = 544;
            break;
        case 21:
            strcpy(p_c->brand, "Mercedes-Benz");
            strcpy(p_c->modelname, "EQS53");
            p_c->ps = 761;
            break;
        case 22:
            strcpy(p_c->brand, "Mercedes-Benz");
            strcpy(p_c->modelname, "GLE350de");
            p_c->ps = 353;
            break;
        case 23:
            strcpy(p_c->brand, "Mercedes-Benz");
            strcpy(p_c->modelname, "GLE400e");
            p_c->ps = 408;
            break;
        case 24:
            strcpy(p_c->brand, "Mercedes-Benz");
            strcpy(p_c->modelname, "GLE53");
            p_c->ps = 544;
            break;
        case 25:
            strcpy(p_c->brand, "Mercedes-Benz");
            strcpy(p_c->modelname, "GLE63S");
            p_c->ps = 612;
            break;
        case 26:
            strcpy(p_c->brand, "Mercedes-Benz");
            strcpy(p_c->modelname, "AMGONE");
            p_c->ps = 1063;
            break;
        case 27:
            strcpy(p_c->brand, "Mercedes-Benz");
            strcpy(p_c->modelname, "AMGPureSpeed");
            p_c->ps = 585;
            break;
        case 28:
            strcpy(p_c->brand, "Mercedes-Benz");
            strcpy(p_c->modelname, "S680");
            p_c->ps = 612;
            break;
        case 29:
            strcpy(p_c->brand, "Mercedes-Benz");
            strcpy(p_c->modelname, "EQS680SUV");
            p_c->ps = 658;
            break;
        
        case 30:
            strcpy(p_c->brand, "Aston Martin");
            strcpy(p_c->modelname, "Valkyrie");
            p_c->ps = 1155;
            break;
        case 31:
            strcpy(p_c->brand, "Aston Martin");
            strcpy(p_c->modelname, "Valhalla");
            p_c->ps = 1012;
            break;
        case 32:
            strcpy(p_c->brand, "Aston Martin");
            strcpy(p_c->modelname, "Vanquish (2025)");
            p_c->ps = 835;
            break;
        case 33:
            strcpy(p_c->brand, "Aston Martin");
            strcpy(p_c->modelname, "DBS770Ultimate");
            p_c->ps = 770;
            break;
        case 34:
            strcpy(p_c->brand, "Aston Martin");
            strcpy(p_c->modelname, "DBX707");
            p_c->ps = 707;
            break;
        case 35:
            strcpy(p_c->brand, "Aston Martin");
            strcpy(p_c->modelname, "DB12");
            p_c->ps = 680;
            break;
        case 36:
            strcpy(p_c->brand, "Aston Martin");
            strcpy(p_c->modelname, "Vantage (2024)");
            p_c->ps = 665;
            break;
        case 37:
            strcpy(p_c->brand, "Lamborghini");
            strcpy(p_c->modelname, "Revuelto");
            p_c->ps = 1015;
            break;
        case 38:
            strcpy(p_c->brand, "Lamborghini");
            strcpy(p_c->modelname, "Temerario");
            p_c->ps = 920;
            break;
        case 39:
            strcpy(p_c->brand, "Lamborghini");
            strcpy(p_c->modelname, "UrusSE");
            p_c->ps = 800;
            break;
        case 40:
            strcpy(p_c->brand, "Lamborghini");
            strcpy(p_c->modelname, "UrusPerformante");
            p_c->ps = 666;
            break;
        case 41:
            strcpy(p_c->brand, "Lamborghini");
            strcpy(p_c->modelname, "HuracanSTO");
            p_c->ps = 640;
            break;
        case 42:
            strcpy(p_c->brand, "Ferrari");
            strcpy(p_c->modelname, "F80");
            p_c->ps = 1200;
            break;
        case 43:
            strcpy(p_c->brand, "Ferrari");
            strcpy(p_c->modelname, "SF90Stradale");
            p_c->ps = 1000;
            break;
        case 44:
            strcpy(p_c->brand, "Ferrari");
            strcpy(p_c->modelname, "296GTB");
            p_c->ps = 830;
            break;
        case 45:
            strcpy(p_c->brand, "Ferrari");
            strcpy(p_c->modelname, "Purosangue");
            p_c->ps = 725;
            break;
        case 46:
            strcpy(p_c->brand, "Ferrari");
            strcpy(p_c->modelname, "RomaSpider");
            p_c->ps = 620;
            break;
        case 47:
            strcpy(p_c->brand, "Ferrari");
            strcpy(p_c->modelname, "812Superfast");
            p_c->ps = 800;
            break;
        case 48:
            strcpy(p_c->brand, "Ferrari");
            strcpy(p_c->modelname, "12cilindri");
            p_c->ps = 830;
            break;
        case 49:
            strcpy(p_c->brand, "Volvo");
            strcpy(p_c->modelname, "T6AWD");
            p_c->ps = 335;
            break;
        case 50:
            strcpy(p_c->brand, "Porsche");
            strcpy(p_c->modelname, "911TurboSCabriolet");
            p_c->ps = 711;
            break;
        default:
            strcpy(p_c->brand, "Unknown Brand");
            strcpy(p_c->modelname, "Unknown Model");
            p_c->ps = 100;
    }

    int temp_parking_duration = randomize_parking_duration(max_parking_duration);
    if(temp_parking_duration == -1)
    {
        return -1;
    }
    p_c->parking_duration = temp_parking_duration;

    if((queue_get_size(p_queue1) == 0) && ((check_for_free_space() == 1)))                  //prüft ob es eine Warteschlange und freie Plätze gibt
    {
        park_car(p_c, struct Car *parking_garage, time_stemp);                      //übergibt das Auto ans Parkhaus
    }
    else
    {
        queue_enqueue(p_queue1, p_c);                                                 //Auto wird in Warteschlange / Queue eingereiht
    }

    return 0;    
}


int car_id_counter()
{
    static int counter = 0;
    counter ++;
    
    return counter;
}

int randomize_parking_duration(int r_max_parking_duration)           //maximale Pardauer abrufen oder übergeben bekommen?
{
    if(r_max_parking_duration <= 0)            //auf ungültige Eingabe prüfen
    {
        return -1;
    }
    int random_parking_duration = 0;            //maximale Parkdauer in maximale Zeitschritte umrechnen
    
    random_parking_duration = rand() % r_max_parking_duration + 1;   //zufällige Parkdauer berechnen
    if (random_parking_duration <= 0)          //auf ungültige Eingabe prüfen
    {
        return -1;
    }

    return random_parking_duration;
}
