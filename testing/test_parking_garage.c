#include <assert.h>
#include "../include/parking_garage.h"

int test_parking_garage(int parking_spaces){
//Unit-Tests für das Parkhaus:
 
  //Tests für create_garage():
  car **ptr_parking_garage = create_garage(parking_spaces);
  assert(ptr_parking_garage != NULL);                                 //Überprüfung, ob das Parkhaus korrekt erstellt wurde
  assert(ptr_parking_garage == NULL || ptr_parking_garage != NULL);   //Überprüfung, ob die Funktion nicht definierte Werte zurückgibt
  car test_car;                                                       //Test-Auto für die Testzwecke
  ptr_parking_garage[0] = &test_car;
  assert(ptr_parking_garage[0] == &test_car);                         //Überprüfung, ob Pointer auf Car-Struct in dem Parkhaus gespeichert werden können


  //Tests für get_free_space();
  assert(get_free_space(ptr_parking_garage, parking_spaces) != -1);   //Überprüfung, ob der Funktionsaufruf erfolgreich ist
  for(int i=0; i<parking_spaces; i++){                                //Parkhaus wird komplett mit dem gleichen Testauto befüllt
    ptr_parking_garage[i] = &test_car;
  }
  assert(get_free_space(ptr_parking_garage, parking_spaces) == -1);   //Überprüfung, ob die Funktion einen Fehler zurückgibt, da der Aufruf dieser Funktion bei vollem Parkhaus garnicht erst möglich sein sollte
  ptr_parking_garage[0] = NULL;                                       //ein Parkplatz (hier Index 0) wird freigemacht
  assert(get_free_space(ptr_parking_garage, parking_spaces) == 0);    //Überprüfung, ob die Funktion den richtigen Rückgabewert liefert


  //Tests für park_car():
  int time_step = 1;                                                  //fiktiver Simulationswert als Funktionsparameter; ist für den Test nicht von Relevanz
  car test_car2;                                                      //Weiteres Test-Auto zur Unterscheidung von den anderen bereits geparkten Autos
  assert(park_car(&test_car2, ptr_parking_garage, parking_spaces, time_step) == 0); //Überprüfung der korrekten Ausführung der Funktion
  assert(ptr_parking_garage[0] != NULL);                              //Überprüfung, ob das Auto korrekt geparkt wurde
  assert(ptr_parking_garage[0] = &test_car2);
  assert(test_car2.arrival_time = time_step);                         //Überprüfung, ob die korrekte Ankunftszeit übergeben wurde


  //Tests für remove_car():
  remove_car(&test_car2, ptr_parking_garage, 0);                      //Entferne das Test-Auto test_car2 aus dem Parkhaus
  assert(ptr_parking_garage[0] == NULL);                              //Überprüfung, ob der zuvor belegte Parkplatz nun frei ist
  assert(&test_car2 == NULL);                                         //Überprüfung, ob der Pointer auf das Auto auf NULL gesetzt wurde


  //Tests für check_parking_time():
  car test_car3;
  test_car3.parking_duration = 3;
  test_car3.arrival_time = 5;                                         //setze die Ankunftszeit von test_car3 so, dass die maximale Parkdauer erreicht ist
  time_step = 8;
  assert(check_parking_time(&test_car3, time_step) == 1);             //Test bei erreichter maximaler Parkdauer
  assert(check_parking_time(&test_car3, time_step) == 1 || check_parking_time(&test_car3, time_step) == 0); //Überprüfung, ob die Funktion einen Fehlerwert zurückgibt
  test_car3.arrival_time = 7;                                         //setze die Ankunftszeit von test_car3 so, dass die maximale Parkdauer nicht erreicht ist
  assert(check_parking_time(&test_car3, time_step) == 0);             //Test bei nicht-erreichter maximaler Parkdauer


  //Tests für check_for_free_space():
  assert(check_for_free_space(ptr_parking_garage, parking_spaces) == 0);  //Überprüfung bei vollem Parkhaus -> Rückgabewert muss 0 sein
  for(int i=0; i<parking_spaces; i++){                                //Parkhaus wird komplett geleert
    ptr_parking_garage[i] = NULL;
  }
  assert(check_for_free_space(ptr_parking_garage, parking_spaces) == parking_spaces); //Überprüfung bei leerem Parkhaus -> Rückgabewert muss Anzahl der Parkplätze sein


  //Tests für manage_parking_garage():
  //Um die korrekte Funktionsweise dieser Funktion zu testen, wird ein Auto auf seine maximale Parkdauer gesetzt
  //und getestet, ob die Funktion dieses Auto korrekt aus dem Parkhaus entfernt:
  car test_car4;
  test_car4.parking_duration = 3;
  test_car4.arrival_time = 5;
  ptr_parking_garage[parking_spaces-1] = &test_car4;                  //Parke das Auto auf dem letzten Parkplatz
  time_step = 8;
  manage_parking_garage(ptr_parking_garage, parking_spaces, time_step);
  assert(ptr_parking_garage[parking_spaces-1] == NULL);


  free(ptr_parking_garage);                                           //Freigabe des für das Parkhaus reservierten Speichers

  return 0; //Tests erfolgreich
}
