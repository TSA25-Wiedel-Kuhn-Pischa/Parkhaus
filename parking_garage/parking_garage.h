/*
 *  File: parking_garage.h
 *  Description: Deklaration und Beschreibung der für das Parkhaus und deren Verwaltung benutzte Funktionen
 * 
 */

#ifndef PARKING_GARAGE_H
#define PARKING_GARAGE_H

/*
 * @brief  Erstellung einer Parkgarage bzw. eines Car-Struct-Arrays 
 *         mit der durch die zur Laufzeit angegebenen Parkplatzanzahl vorgegebenen Größe
 *
 * @param[in]  parking_spaces   Variable die die durch die/den NutzerIn eingegebene Größe des Parkhauses enthält 
 * @param[out]  parking_garage  leeres Car-Struct-Array, dass Car-Struct einspeichern kann
 */
struct car *create_garage(int parking_spaces);

/*
 * @brief  Überprüfung der Parkgarage darauf, wo sich ein freier Parkplatz befindet
 *
 * @param[in]  parking_garage   Car-Struct-Array, in welchem sich Autos befinden bzw. befinden können
 * @param[out]  integer         Index, an dem sich ein freier Parkplatz befindet
 */
int get_free_space(struct car *parking_garage)

/*
 * @brief  Einparken von Car-Structs in dem parking_garage-Array;
 *         Car-Struct wird aus der Warteschlange / Queue entfernt und der Funktion übergeben, wenn Platz im Parkhaus ist;
 *         Car-Struct wird in einem freien Platz im parking_garage-Array gespeichert und die Ankunftszeit eingespeichert
 *
 * @param[in]   car             Car-Struct, dass übergeben wird und im Array gespeichert werden soll / eingeparkt werden soll
 *              parking_garage  Car-Struct-Array, in welches das Auto gespeichert wird
 *              time_step       Aktuelle Zeit bzw- aktueller Zeitfortschritt
 */
void park_car(struct Car car, struct Car *parking_garage, int time_step);

/*
 * @brief  Ausparken von Car-Structs aus dem parking_garage-Array;
 *         Car-Struct wird aus dem Array entfernt, dieser Platz wird frei;
 *         Car-Struct wird gelöscht
 *
 * @param[in]   car             Car-Struct, dass seine maximale Parkdauer erreicht hat
 *              parking_garage  Car-Struct-Array, in welchem der Parkplatz geräumt wird
 *              index           Index, an welchem sich das Auto befindet, dass seine maximale Parkdauer erreicht hat
 */
void remove_car(struct Car car, struct Car *parking_garage, int index);

/*
 * @brief  Überprüfen und Abgleichen von Parkdauer und Ankunftszeiten von einem Auto, 
 *         und Festzustellung, ob die maximale Parkdauer erreicht wurde;
 *
 * @param[in]   parking_garage  Car-Struct-Array, dass die Autos beinhaltet
 *              time_step       Aktuelle Zeit bzw. aktueller Zeitfortschritt
 * @param[out]  integer         Index, an welchem sich ein Auto befindet, dass seine maximale Parkdauer erreicht hat
 */
int check_parking_time(struct Car car, int time_step);

/*
 * @brief  Überprüfung des parking_garage-Arrays darauf, ob freie Parkplätze vorhanden sind
 *
 * @param[in]   parking_garage  Car-Struct-Array, dass die Autos beinhaltet 
 * @param[out]  integer         Rückgabe, ob freie Parkplätze vorhanden sind (Rückgabewert = 1), oder nicht (Rückgabewert = 0)
 */
int check_for_free_space(struct Car *parking_garage)

/*
 * @brief  Verwaltung des Parkhauses, was das Ein- und Ausparken, die Überprüfung der Parkdauer der
 *         eingeparkten Autos und die Rückgabe über die Anzahl freier Parkplätze beinhaltet
 *
 * @param[in]   parking_garage  Car-Struct-Array, dass die Autos beinhaltet
 * @param[out]  integer         Rückgabe des Funktionsaufrufes von check_for_free_space()
 */
int manage_cars(struct car *parking_garage, int time_step);

#endif
