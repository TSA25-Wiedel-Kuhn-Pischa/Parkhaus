/*
 *  File: parking_garage.c
 *  Description: Funktionen, die für das Parkhaus und deren Verwaltung benutzt werden
 */

#include "parking_garage.h"
/*#include "cars.h"*/

struct car *create_garage(int parking_spaces){
  /*
  struct Car *car = calloc(parking_spaces, sizeof(car));
  */
}

void park_car(struct Car car){
  /*
  speicher einzelne Autos in dem car-array
  */
}

void remove_car(struct Car car){
  /*
  entferne car struct aus dem array
  entferne car struct
  */
}

void check_parking_time(struct car *parking_garage, int array_size, int time_step){
  /*
  FOR i <- 0 TO array_size DO
    IF (parking_garage[i] != NULL) THEN
      i++
    ELSE
      IF (time_step-(parking_garage[i]->arrival_time) == parking_garage[i]->parking_duration) THEN
        parking_garage[i]->parking_duration_reached = 1       //setze flag auf true wenn die maximale Parkdauer erreicht ist
      END IF
      i++
    END IF
  END FOR
  */
}

void manage_cars(struct car *parking_garage){
  /*
  
  */
}