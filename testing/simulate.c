/*
 *  File: simulate.c
 *  Description: In simulate.c werden die Funktionen der src-Dateien zusammengeführt, um eine Simulation
 *  und das Testen der Funktionen zu ermöglichen.
 */

#ifndef DEBUG

// Alle include Dateien einbinden
#include "../include/cars.h"
#include "../include/parameter.h"
#include "../include/parking_garage.h"
#include "../include/queue.h"
#include "../include/statistics.h"


//Ab hier der C-Code: 
int main(){
  FILE *daten = fopen("src/Daten.txt", "w");
  FILE *auswertung = fopen("src/Auswertung.txt", "w");
  if(daten == NULL || auswertung == NULL)
  {
    printf("Fehler beim Oeffnen mindestens einer Datei.");
    return 1;
  }
  
  //Initialisieren von Simulationsparametern
  int spaces = 0;
  float max_parking = 0;
  int steps = 0;
  float chance_of_new_cars = 0;
  int seed = 0;

  //Einlesen und Setzen der Simulationsparameter
  input_parameter(&spaces, &max_parking, &steps, &chance_of_new_cars, &seed);

  //Einfügen von Kopfzeilen in den Dateien
  head_document(spaces, max_parking, steps, chance_of_new_cars, seed, daten);
  head_document(spaces, max_parking, steps, chance_of_new_cars, seed, auswertung);

  //Datenarray für Simulationswerte initialisieren
  int data[steps * 5];
  for (int i = 0; i <= (steps * 5); i++)
  {
    data[i] = 0;
  }

  
  //Random Seed für Simulation setzen
  srand(seed);
  
  //Array für das Parkhaus initalisieren
  car **parking_garage = create_garage(spaces);
  

  //Warteschlange vor dem Parkhaus initialisieren
  Queue *p_queue1 = queue_init();                                //Warteschlange vor dem Parkhaus initialisieren

  if(p_queue1 == NULL)
  {
    printf("Fehler bei der Initialisierung der Warteschlange.");
    return 1;
  }

  //Simulationsdurchlauf
  for(int i = 0; i < steps; i++)
  {
    manage_parking_garage(parking_garage, spaces, i);                      //Überprüfen der Parkzeiten + ggf. Ausparken

    int cars_in_queue = queue_get_size(p_queue1);                          //Anzahl der Autos in der Warteschlange abrufen
    if(cars_in_queue < 0)
    {
      printf("Fehler beim Abrufen der Anzahl der Autos in der Warteschlange.");
      return 1;
    }
    while((check_for_free_space(parking_garage, spaces) > 0) && (cars_in_queue > 0))
    {
      struct car* p_temp_first_car_in_queue = queue_dequeue(p_queue1);  //Auto aus Warteschlange entfernen
      if(p_temp_first_car_in_queue == NULL)
      {
        printf("Fehler beim Entfernen eines Autos aus der Warteschlange.");
        return 1;
      }
      park_car(p_temp_first_car_in_queue, parking_garage, spaces, i);
      cars_in_queue = queue_get_size(p_queue1);                         //Anzahl der Autos in der Warteschlange abrufen
      if(cars_in_queue < 0)
      {
        printf("Fehler beim Abrufen der Anzahl der Autos in der Warteschlange.");
        return 1;
      }
    }


    //Neue Autos mit einer gewissen Wahrscheinlichkeit generieren
    for(int j = 0; j < 5; j++)
    {

      if( ((float)rand() / RAND_MAX) * 100 < chance_of_new_cars )
      {
        car* p_Auto = malloc(sizeof(car));                                  //Speicher wird hier in der main reserviert

        int result_temp = create_car(max_parking, i, p_Auto, p_queue1, parking_garage, spaces);  //Auto erstellen und parken oder in Warteschlange einreihen
        if(result_temp != 0)
        {
          printf("Fehler bei der Erstellung eines Autos.");
          return 1;
        }
      }
    }

    int cars_in_line = queue_get_size(p_queue1);   //Anzahl der Autos in der Warteschlange abrufen

    if(cars_in_line < 0)
    {
      printf("Fehler beim Abrufen der Anzahl der Autos in der Warteschlange.");
      return 1;
    }

    
    output_data(check_for_free_space(parking_garage, spaces), spaces, cars_in_line, daten);
    save_data(data, steps, check_for_free_space(parking_garage, spaces), spaces, cars_in_line);
  }


  
  //Ausgabe der Endstatistiken
  tabel(data, steps, auswertung);
  column_chart(data, steps, auswertung);
  bar_chart(data, steps, auswertung);
  out_maxval(data, steps, auswertung);

  int success_daten = fclose(daten);
  int success_auswertung = fclose(auswertung);
  if(success_daten == -1 || success_auswertung == -1)
  {
    printf("Fehler beim Schließen von mindestens einer Datei.");
    return 1;
  }
  
  free(p_queue1);                   // Speicher der Warteschlange freigeben

  free(parking_garage);             // Speicher des Parkhauses freigeben und Pointer auf NULL setzen
  parking_garage = NULL;

  return 0;
}
#endif