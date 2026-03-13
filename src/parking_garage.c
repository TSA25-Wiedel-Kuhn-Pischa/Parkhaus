/*
 *  File: parking_garage.c
 *  Description: Implementierung von Funktionen, die für das Parkhaus und deren Verwaltung benutzt werden
 */

#include "../include/cars.h"
#include "../include/parking_garage.h"

car **create_garage(int parking_spaces){

  //Erstelle einen Pointer und reserviere Speicherplatz für ein Array
  car **ptr_parking_garage = calloc(parking_spaces, sizeof(car *));

  //Überprüfung, ob die Reservierung erfolgreich war
  if(ptr_parking_garage == NULL){
    return NULL;
  }
  
  return ptr_parking_garage;
}

int get_free_space(car **parking_garage, int parking_spaces){

  //Überprüfung jedes Parkplatzes daraufhin, ob es einen Pointer auf ein Car-Struct enthält
  for(int i=0; i<parking_spaces; i++){
    if(parking_garage[i] == NULL){
      return i;
    }
  }

  return -1;  //Fehler
}

int park_car(car *car, struct car **parking_garage, int parking_spaces, int time_step){

  int index = get_free_space(parking_garage, parking_spaces);
  if(index < 0){
    return -1;    //Fehler
  }

  parking_garage[index] = car;
  car->arrival_time = time_step;

  return 0;
}

void remove_car(car *car, struct car **parking_garage, int index){

  parking_garage[index] = NULL;   //entferne den Pointer aus dem Array
  free(car);  //Free den Speicherplatz, auf den der Pointer zeigt
  car = NULL;   //setze den Pointer auf den Speicherplatz auf NULL
}

int check_parking_time(car *car, int time_step){

  if((time_step - car->arrival_time) == car->parking_duration){  //maximale Parkdauer wurde erreicht
    return 1;
  }

  if((time_step - car->arrival_time) > car->parking_duration){
    return -1;  //Fehler
  }

  return 0;
}

int check_for_free_space(car **parking_garage, int parking_spaces){

  int free = 0;

  for(int i=0; i<parking_spaces; i++){
    if(parking_garage[i] == NULL){
      free++;
    }
  }

  return free;
}

void manage_parking_garage(car **parking_garage, int parking_spaces, int time_step){

  for(int i=0; i<parking_spaces; i++){

    if(parking_garage[i] == NULL){
      continue;
    }

    int check = check_parking_time(parking_garage[i], time_step);
    if(check){
      remove_car(parking_garage[i], parking_garage, i);
    }
  }
}