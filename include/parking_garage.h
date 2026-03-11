
/*
 *  File: parking_garage.h
 *  Description: Deklaration und Beschreibung der für das Parkhaus und deren Verwaltung benutzte Funktionen
 */

#ifndef PARKING_GARAGE_H
#define PARKING_GARAGE_H

#include "cars.h"
#include "queue.h"

/*
 * @brief  Erstellung eines Arrays, das Pointer auf Car-Structs enthält und damit das Parkhaus
 *         repräsentiert
 *
 * @param[in]  parking_spaces   Variable die die durch die/den NutzerIn eingegebene Größe des Parkhauses enthält 
 * @param[out]  ptr_parking_garage  Pointer auf das Car-Struct-Pointer-Array
 */
car **create_garage(int parking_spaces);

/*
 * @brief  Überprüfung der Parkgarage darauf, wo sich ein freier Parkplatz befindet
 *
 * @param[in]  parking_garage   Car-Struct-Pointer-Array, in welchem sich Autos befinden bzw. befinden können
 * @param[in]  parking_spaces   Anzahl der Parkplätze des Parkhauses
 * @param[out]  integer         Index, an dem sich ein freier Parkplatz befindet
 */
int get_free_space(car **parking_garage, int parking_spaces);

/*
 * @brief  Einparken von Autos in dem Parkhaus;
 *         Speichern von Pointer auf Car-Structs in dem Array, das das Parkhaus repräsentiert;
 *         Car-Struct wird aus der Warteschlange / Queue entfernt und ein Pointer auf dieses der Funktion übergeben, wenn Platz im Parkhaus ist;
 *         Car-Struct-Pointer wird in einem freien Platz im parking_garage-Array gespeichert und die Ankunftszeit eingespeichert
 *
 * @param[in]   car             Pointer auf Car-Struct, dass übergeben wird und im Array gespeichert werden soll / eingeparkt werden soll
 * @param[in]   parking_garage  Car-Struct-Array, in welches das Auto gespeichert wird
 * @param[in]   parking_spaces  Anzahl der Parkplätze im Parkhaus
 * @param[in]   time_step       Aktueller Zeitpunkt in der Simulation bzw. aktueller Zeitfortschritt
 */
int park_car(car *car, car **parking_garage, int parking_spaces, int time_step);

/*
 * @brief  Ausparken von Car-Structs aus dem parking_garage-Array;
 *         Car-Struct_Pointer wird aus dem Array entfernt, dieser Platz wird frei;
 *         Car-Struct und -Pointer werden "gelöscht": Speicherplatz wird freigegeben und Pointer auf NULL gesetzt
 *
 * @param[in]   car             Car-Struct-Pointer, auf ein Auto das seine maximale Parkdauer erreicht hat
 * @param[in]   parking_garage  Car-Struct-Pointer-Array, in welchem der Parkplatz geräumt wird
 * @param[in]   index           Index, an welchem sich das Auto befindet, dass seine maximale Parkdauer erreicht hat
 */
void remove_car(car *car, car **parking_garage, int index);

/*
 * @brief  Überprüfen und Abgleichen von Parkdauer und Ankunftszeiten von einem Auto, 
 *         und Festzustellung, ob die maximale Parkdauer erreicht wurde;
 *
 * @param[in]   car             Car-Struct-Pointer das auf ein Auto im Parkhaus zeigt
 * @param[in]   time_step       Aktueller Zeitpunkt in der Simulation bzw. aktueller Zeitfortschritt
 * @param[out]  integer         Rückgabe: 1 = max. Parkdauer erreicht;
 *                                        0 = max. Parkdauer noch nicht erreicht;
 */
int check_parking_time(car *car, int time_step);

/*
 * @brief  Überprüfung des parking_garage-Arrays darauf, wie viele freie Parkplätze vorhanden sind
 *
 * @param[in]   parking_garage  Car-Struct-Pointer-Array, dass die Pointer auf die Autos beinhaltet
 * @param[in]   parking_spaces  Anzahl der Parkplätze im Parkhaus 
 * @param[out]  free            Rückgabe, wie viele Parkplätze vorhanden sind
 */
int check_for_free_space(car **parking_garage, int parking_spaces);

/*
 * @brief  Verwaltung des Parkhauses, was die Überprüfung der Parkdauer der Autos und das
 *         entsprechende Ausparken von Autos beinhaltet, die die maximale Parkdauer erreicht haben
 *
 * @param[in]   parking_garage  Car-Struct-Pointer, Array, das Pointer; zeigend auf die Autos, beinhaltet
 * @param[in]   parking_spaces  Anzahl der Parkplätze des Parkhauses
 * @param[in]   time_step       Aktueller Zeitpunkt in der Simulation bzw. aktueller Zeitfortschritt
 */
void manage_parking_garage(car **parking_garage, int parking_spaces, int time_step);

#endif
