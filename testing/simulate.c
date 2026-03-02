/*
 *  File: simulate.c
 *  Description: In simulate.c werden die Funktionen der src-Dateien zusammengeführt, um eine Simulation
 *               und das Testen der Funktionen zu ermöglichen.
 */

/*
int main(){

  FILE *daten = fopen("../src/Daten.txt", "w")
  FILE *auswertung = fopen("../src/Auswertung.txt", "w")
  IF (daten == NULL || auswertung == NULL) DO

    OUTPUT "Fehler beim Öffnen mindestens einer Datei."
    return 1

  END IF

  //Initialisieren von Simulationsparametern
  int spaces = 0
  float max_parking = 0
  int steps = 0
  float chance_of_new_cars = 0
  int seed = 0

  //Einlesen und Setzen der Simulationsparameter
  input_parameters(&spaces, &max_parking, &steps, &chance_of_new_cars, &seed)

  //Datenarray für Simulationswerte initialisieren
  int data[(size*5)] = {0}

  //Random Seed für Simulation setzen
  srand(seed) 

  //Array für das Parkhaus initalisieren
  create_garage(spaces)

  FOR i <- 0 TO steps DO

    int index = 0

    FOR i <- 0 TO spaces DO

      index = check_parking_time(parking_garage[i])

      Initialisiere und setze die Variable index auf den Rückgabewert von check_parking_time()

      IF (Rückgabewert von check_parking_time() >= 0) DO

        Aufruf der Funktion remove_car() mit index als übergebener Parameter

      END IF

    END FOR

    Gebe den Rückgabewert des Aufrufs der Funktion check_for_free_space() zurück

    

    output_data(check_for_free_space(parking_garage), spaces, CARS_IN_LINE)
    save_data(data, steps, check_for_free_space(parking_garage), spaces, CARS_IN_LINE)

  END FOR

  //For schleife:
    //Überprüfung von Autos im Parkhaus und entsprechendes Ausparken
    //Erstellung von Autos und Fahren in die Warteschlange
    //Einparken von Autos ins Parkhaus, falls Plätze frei sind
    //Ausgabe von Statistiken

  //Ausgabe von Endstatistiken

  int success_daten = fclose(daten)
  int success_auswertung = fclose(auswertung)
  IF (success_daten == -1 || success_auswertung == -1) DO 

    OUTPUT "Fehler beim Schließen von mindestens einer Datei."
    return 1

  END IF
}
*/