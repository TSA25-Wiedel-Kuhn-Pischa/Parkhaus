/*
 *  File: parking_garage.h
 *  Description: Declaration of functions used for the parking-garage
 * 
 */

#ifndef PARKING_GARAGE_H
#define PARKING_GARAGE_H

/*
 * @brief  create garage with the given amount of parking spaces
 *
 * @param[in]  parking_spaces  put in amount of parking spaces by user
 * @param[out]  parking_garage  car-array that can store given amount of cars
 */
struct car *create_garage(int parking_spaces);

/*
 * @brief  park cars from outside queue into parking garage
 *
 * @param[in]  car   car that is header of queue and supposed to be parked
 */
void park_car(struct car);

/*
 * @brief  remove parking car from parking garage
 *
 * @param[in]  car   car that has reached its maximum parking time
 */
void remove_car(struct car);

/*
 * @brief  check if any parked car in parking garage has reached its maximum parking time
 *
 * @param[in]  parking_garage   array that can store given amount of cars
 */
void check_parking_time(struct car *parking_garage);

/*
 * @brief  manage cars in the parking garage
 *
 * @param[in]  parking_garage   array that can store given amount of cars 
 */
void manage_cars(struct car *parking_garage);

#endif
