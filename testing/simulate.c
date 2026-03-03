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

  //Einfügen von Kopfzeilen in den Dateien
  head_document(spaces, max_parking, steps, chance_of_new_cars, seed, "Daten.txt")
  head_document(spaces, max_parking, steps, chance_of_new_cars, seed, "Auswrtung.txt")

  //Datenarray für Simulationswerte initialisieren
  int data[(size*5)] = {0}

  //Random Seed für Simulation setzen
  srand(seed) 

  //Array für das Parkhaus initalisieren
  Car *parking_garage = create_garage(spaces)

  //Simulationsdurchlauf
  FOR i <- 0 TO steps DO

    manage_parking_garage(parking_garage, i)   //Überprüfen der Parkzeiten + ggf. Ausparken

    IF (check_for_free_space(parking_garage) > 0 && Auto in Warteschlange) DO

      park_car(Auto am Anfang der Warteschlange)

    END IF

    output_data(check_for_free_space(parking_garage), spaces, CARS_IN_LINE)
    save_data(data, steps, check_for_free_space(parking_garage), spaces, CARS_IN_LINE)

  END FOR

  //Ausgabe der Endstatistiken
  tabel(data, steps)
  column_chart(data, steps)
  bar_chart(data, steps)
  out_maxval(data, steps)

  int success_daten = fclose(daten)
  int success_auswertung = fclose(auswertung)
  IF (success_daten == -1 || success_auswertung == -1) DO 

    OUTPUT "Fehler beim Schließen von mindestens einer Datei."
    return 1

  END IF
}
*/
