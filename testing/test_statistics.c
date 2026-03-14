/**  
    Datei: test_statistics.h
    Beschreibung: Beschreibung aller Funktionen zum Testen von statistics.c
*/
#include "../include/test_statistics.h"
#include "../include/statistics.h"
#include <assert.h>

int test_statistics()
{
    // Öffnen von dem Pointer zum durchführen der gültigen Tests
    FILE* document = fopen("../src/Daten.txt", "r+");        // öffnen im Lese Modus, damit die Datei nicht überschrieben wird
    if (document == NULL)                                    // Überprüft das der Pointer nicht NULL ist, dann wäre er nämlich nicht zugelassen
    {
        printf("error");
        return 1;
    }

    // definieren von einem NULL Pointer zum überprüfen der Funktionen
    FILE* error = NULL;

    // definieren eines Arrays, welches therotisch die Simulationswerte Speichert
    // Da es die Tests nicht beeinflusst, kann es so deklariert werden
    int data_test[30] = {0};

    // Unit Tests für statistics 

    // Test für fullness():

    //Zugelassene Werte:
    assert(fullness(0, 10) == 0); 
    assert(fullness(5, 10) == 50);
    assert(fullness(10,10) == 100);

    // Nicht zugelassene Werte:
    assert(fullness(-1, 10) == -1);
    assert(fullness(2, 0) == -1);
    assert(fullness(8, 5) == -1);

    // Test für rate()
    
    // zugelassene Werte:
    int zwischenspeicher = 0;
    assert(rate(0, 10, &zwischenspeicher) == 0);
    assert(rate(20, 10, &zwischenspeicher) == 0);
    assert(rate(0, 0, &zwischenspeicher) == 0);

    // Nicht zugelassene Werte:
    assert(rate(-1, 10, &zwischenspeicher) == -1);
    assert(rate(1, -2, &zwischenspeicher) == -1);
    assert(rate(-1, -10, &zwischenspeicher) == -1);

    // Test für head_document()

    // Zugelassene Pointer:
    assert(head_document(3,3,3,3,3, document) == 0);
   
    // Nicht zugelassene Pointer:
    assert(head_document(3,3,3,3,3,error) == -1);


    // Test für output_data()

    // Zugelassene Werte / Pointer:
    assert(output_data(4, 10, 0, document) == 0);

    // Nicht zugelassene Werte / Pointer:
    assert(output_data(4, 10, 0, error)== -1);               // Fehlerhafter Pointer
    assert(output_data(20, 10, 0, document) == -1);          // Die Anzahl der Freien Parkplätze ist größer als die Gesamtanzahl 
    assert(output_data(3, 10, -5, document) == -1);          // Die Anzahl der Autos in der Warteschlange ist negativ
    assert(output_data(-3, 10, 0, document) == -1);          // Die Anzahl der Freien Parkplätze ist negativ

    // Test für save_data()

    // Zugelassene Werte:
    assert(save_data(data_test,6,2,10,0) == 0);

    // Nicht zugelassene Werte:
    assert(save_data(data_test,6, 20, 10, 0) == -1);        // Die Anzahl der freien Parkplätze ist größer als die der Gesamten Parkplätze
    assert(save_data(data_test,6, -2, 10, 0) == -1);        // Die Anzahl der freien Parkplätze ist negativ
    assert(save_data(data_test,6, 2, 10, -5) == -1);        // Die Anzahl der Autos in der Warteschlange ist negativ


    // Schließen der geöffneten Datei und überprüfen ob es geklappt hat
    int success_test = fclose(document);
    if (success_test == -1)                                  // Überprüfen, ob die Datei geschlossen wurde 
    {
        printf("error");
        return 1;
    }
}