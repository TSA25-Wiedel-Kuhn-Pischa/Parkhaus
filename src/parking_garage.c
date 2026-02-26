/*
 *  File: parking_garage.c
 *  Description: Implementierung von Funktionen, die für das Parkhaus und deren Verwaltung benutzt werden
 */

 /*
struct car *create_garage(int parking_spaces){
  
  Variable parking_spaces = übergabene Variable; Anzahl der Parkplätze

  Reservierung von Speicherplatz und gleichzeitiges Erstellen eines Arrays, 
  angepasst an die der Funktion übergebenen Anzahl an verfügbaren Parkplätzen:

  IF (Reservierung von (parking_spaces * Größe eines Car-Structs) Bytes ist fehlgeschlagen) THEN

    OUTPUT ERROR

    Stoppe das Programm

  END IF
  
}

int get_free_space(struct car *parking_garage){
  
  Überprüfe das Array darauf, wo sich ein freier Parkplatz befindet:

  Initialisiere die Variable index

  FOR i <- TO (Größe des Arrays) DO

    IF (Aktuelle betrachteter Platz des Arrays ist nicht belegt) DO

      Setze index auf den aktuellen Index des Arrays

      Springe aus der For-Schleife

    END IF

  END FOR

  Gebe index zurück
  
}

void park_car(struct Car car, struct Car *parking_garage, int time_step){
  
  Nimm ein Auto entgegen und speicher es in einem freien Platz des Arrays:

  Rufe die Funktion get_free_space() auf

  Initialisiere und setze die Variable index auf diesen Wert

  Speicher das Auto in dem Array an dem Index von index

  Setze die Ankunftszeit des Autos auf time_step bzw. die aktuelle Zeit
  
}

void remove_car(struct Car car, struct Car *parking_garage, int index){
  
  Nimm Nummer des Parplatzes entgegen, auf dem sich ein Auto befindet, dass seine maximale Parkdauer
  erreicht hat und entferne es aus dem Array:

  Gebe den Inhalt vom Index index des Arrays frei, indem der Inhalt auf NULL gesetzt wird

  Gebe den durch das Auto belegten Speicherplatz wieder frei
  
}

int check_parking_time(struct Car car, int time_step){
  
  Überprüfe, ob ein Auto die festgelegte maximale Parkdauer erreicht hat:

  IF (maximale Parkdauer ist erreicht) DO

    Gebe den Index des Autos im Array zurück

  END IF

  Gebe -1 zurück
  
}

int check_for_free_space(struct Car *parking_garage){
  
  Überprüfe das Array darauf, ob es frei Plätze beinhaltet:
  
  Initialisiere und setze die Variable free auf 0

  FOR i <- 0 TO (Größe des Arrays) DO

    IF (Parkplatz ist nicht belegt) DO

      Erhöhe free um 1

    END IF

  END FOR

  IF (free ist größer als 0) DO

    Gebe 1 zurück

  END IF
  
  Gebe free zurück
  
}

int manage_cars(struct car *parking_garage, int time_step){
  
  Parke Autos in freie Parkplätze und überprüfe die Parkdauern der Autos und entferne ggf. Autos aus dem Parkhaus:

  IF (Auto hat die Warteschlange verlassen und wurde an das Parkhaus übergeben) DO

    Initialisiere die Variable index

    Setze index auf den Rückgabewert des Aufrufs der Funktion get_free_space()

    Aufruf der Funktion park_car() mit der Übergabe von index als übergebener Parameter

  END IF

  FOR i <- 0 TO (Größe des Arrays) DO

    Aufruf der Funktion check_parking_time()

    Initialisiere und setze die Variable index auf den Rückgabewert von check_parking_time()

    IF (Rückgabewert von check_parking_time() >= 0) DO

      Aufruf der Funktion remove_car() mit index als übergebener Parameter

    END IF

  END FOR

  Gebe den Rückgabewert des Aufrufs der Funktion check_for_free_space() zurück
  
}

*/