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
 * @param[in]  parking_spaces  Variable die die durch die/den NutzerIn eingegebene Größe des Parkhauses enthält 
 * @param[out]  parking_garage  leeres Car-Struct-Array, dass Car-Struct einspeichern kann
 */
struct car *create_garage(int parking_spaces);

/*
 * @brief  Einparken von Car-Structs in dem parking_garage-Array;
 *         Car-Struct wird aus der Warteschlange / Queue entfernt und der Funktion übergeben, wenn Platz im Parkhaus ist;
 *         Car-Struct wird in einem freien Platz im parking_garage-Array gespeichert und die Ankunftszeit eingespeichert
 *
 * @param[in]  car   Car-Struct, dass übergeben wird und im Array gespeichert werden soll / eingeparkt werden soll
 */
void park_car(struct car);

/*
 * @brief  Ausparken von Car-Structs aus dem parking_garage-Array;
 *         Car-Struct wird aus dem Array entfernt, dieser Platz wird frei;
 *         Car-Struct wird gelöscht
 *
 * @param[in]  car   Car-Struct, dass seine maximale Parkdauer erreicht hat
 */
void remove_car(struct car);

/*
 * @brief  Überprüfen und Abgleichen von Parkdauer und Ankunftszeiten von allen geparkten Autos, 
 *         um festzustellen, ob die maximale Parkdauer erreicht wurde;
 *         Falls die maximale Parkdauer erreicht wurde, wird eine Flag auf true gesetzt
 *
 * @param[in]  parking_garage   Car-Struct-Array, dass die Autos beinhaltet
 */
void check_parking_time(struct car *parking_garage);

/*
 * @brief  Verwaltung des Parkhauses, was das Ein- und Ausparken sowie die Überprüfung der Parkdauer der
 *         eingeparkten Autos beinhaltet
 *
 * @param[in]  parking_garage   Car-Struct-Array, dass die Autos beinhaltet
 */
void manage_cars(struct car *parking_garage);

#endif
