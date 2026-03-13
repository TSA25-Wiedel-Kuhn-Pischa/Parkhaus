#include <assert.h>
#include "../include/parking_garage.h"

int test_parking_garage(int parking_spaces){
//Unit-Tests für das Parkhaus:
 
  //Tests für create_garage():
  car **ptr_parking_garage = create_garage(parking_spaces);
  assert(ptr_parking_garage != NULL);                       //Überprüfung, ob das Parkhaus korrekt erstellt wurde
  assert(ptr_parking_garage == NULL || ptr_parking_garage != NULL);       //Überprüfung, ob die Funktion nicht definierte Werte zurückgibt

  car test_car;
  ptr_parking_garage[0] = &test_car;
  assert(ptr_parking_garage[0] == &test_car);               //Überprüfung, ob Pointer auf Car-Struct in dem Parkhaus gespeichert werden können


  //Tests für get_free_space();
  assert(get_free_space(ptr_parking_garage, parking_spaces) != -1);   //Überprüfung, ob der Funktionsaufruf erfolgreich ist

  for(int i=0; i<parking_spaces; i++){    //Parkhaus wird komplett befüllt
    ptr_parking_garage[i] = &test_car;
  }
  assert(get_free_space(ptr_parking_garage, parking_spaces) == -1);   //Überprüfung, ob die Funktion einen Fehler zurückgibt, da der Aufruf
                                                                      //dieser Funktion bei vollem Parkhaus garnicht erst möglich sein sollte
  
  ptr_parking_garage[0] = NULL;     //ein Parkplatz (hier Index 0) wird freigemacht
  assert(get_free_space(ptr_parking_garage, parking_spaces) == 0);    //Überprüfung, ob die Funktion den richtigen Rückgabewert liefert


  //Tests für park_car():
  int time_step = 1;    //fiktiver Simulationswert als Funktionsparameter; ist für den Test nicht von Relevanz
  assert(park_car(test_car, ptr_parking_garage, parking_spaces, time_step) == 0);



  return 0; //Tests erfolgreich
}
