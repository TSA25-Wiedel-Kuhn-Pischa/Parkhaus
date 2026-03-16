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

    // Unit Tests für statistics.c


    // Tests für fullness():

    //Zugelassene Werte:
    assert(fullness(0, 10) == 0);                           // Richtige Übergabe, Test ob ein intendierter Durchgang Funktioniert, ob die Kobinationen Fehlerfrei funktionieren
    assert(fullness(5, 10) == 50);
    assert(fullness(10,10) == 100);

    // Nicht zugelassene Werte:
    assert(fullness(-1, 10) == -1);                         // Übergabe von einer negativen Anzahl an besetzten Parkplätzen 
    assert(fullness(2, 0) == -1);                           // Übergabe von null Parkplätzen im Parkhaus
    assert(fullness(8, 5) == -1);                           // Übergabe von mehr besetzten Parkplätzen, als es Parkplätze gibt


    // Tests für rate()
    
    // zugelassene Werte:
    int zwischenspeicher = 0;
    assert(rate(0, 10, &zwischenspeicher) == 0);            // Richtige Übergabe, Test ob ein intendierter Durchgang Funktioniert, ob die Kobinationen Fehlerfrei funktionieren
    assert(rate(20, 10, &zwischenspeicher) == 0);
    assert(rate(0, 0, &zwischenspeicher) == 0);

    // Nicht zugelassene Werte:
    assert(rate(-1, 10, &zwischenspeicher) == -1);          // Übergabe von einer aktuellen negativen Anzahl an Autos im Parkhaus
    assert(rate(1, -2, &zwischenspeicher) == -1);           // Übergabe von einer vorherigen negativen Anzahl an Autos im Parkhaus
    assert(rate(-1, -10, &zwischenspeicher) == -1);         // Übergabe von einer aktuellen und vorherigen negativen Anzahl an Autos im Parkhaus


    // Tests für head_document()

    // Zugelassene Pointer:
    assert(head_document(3,3,3,3,3, document) == 0);        // Richtige Übergabe, Test ob ein intendierter Durchgang Funktioniert
   
    // Nicht zugelassene Pointer:
    assert(head_document(3,3,3,3,3,error) == -1);           // Übrgabe von einem NULL Pointer


    // Tests für output_data()

    // Zugelassene Werte / Pointer:
    assert(output_data(4, 10, 0, document) == 0);            // Richtige Übergabe, Test ob ein intendierter Durchgang Funktioniert

    // Nicht zugelassene Werte / Pointer:
    assert(output_data(4, 10, 0, error)== -1);               // Übergabe von einem NULL Pointer
    assert(output_data(20, 10, 0, document) == -1);          // Die Anzahl der Freien Parkplätze ist größer als die Gesamtanzahl 
    assert(output_data(3, 10, -5, document) == -1);          // Die Anzahl der Autos in der Warteschlange ist negativ
    assert(output_data(-3, 10, 0, document) == -1);          // Die Anzahl der Freien Parkplätze ist negativ


    // Tests für save_data()

    // Zugelassene Werte:
    assert(save_data(data_test,6,2,10,0) == 0);             // Richtige Übergabe, Test ob ein intendierter Durchgang Funktioniert

    // Nicht zugelassene Werte:
    assert(save_data(data_test,6, 20, 10, 0) == -1);        // Die Anzahl der freien Parkplätze ist größer als die der Gesamten Parkplätze
    assert(save_data(data_test,6, -2, 10, 0) == -1);        // Die Anzahl der freien Parkplätze ist negativ
    assert(save_data(data_test,6, 2, 10, -5) == -1);        // Die Anzahl der Autos in der Warteschlange ist negativ


    // Tests für tabel_creation()

    // Zugelassene Pointer:
    assert(tabel_creation(data_test, document) == 0);            // Richtige Übergabe, Test ob ein intendierter Durchgang Funktioniert

    // Nicht zugelassene Pointer:
    assert(tabel_creation(data_test, error) == -1);              // Übergabe von einem NULL Pointer


    // Tests für tabel_legend()

    // Zugelassene Pointer / Werte:
    assert(tabel_legend(1,10, document) == 0);                  // Richtige Übergabe, Test ob ein intendierter Durchgang Funktioniert

    // Nicht zugelassene Pointer / Werte: 
    assert(tabel_legend(3, 2, document) == -1);                 // Die Schrittweite ist größer als die größe des Arrays
    assert(tabel_legend(1,2, error) == -1);                     // Übergabe vom einem NULL Pointer


    // Tests für tabel()

    // Zugelassene Pointer:
    assert(tabel(data_test, 3, document) == 0);                 // Richtige Übergabe, Test ob ein intendierter Durchgang Funktioniert

    // Nicht zugelassener Pointer:
    assert(tabel(data_test, 3, error) == -1);                   // Ein NULL Pointer wurde übergeben


    // Tests für column_chart_creation()

    // Zugelassene Pointer:
    assert(column_chart_creation(data_test, document) == 0);    // Richtige Übergabe, Test ob ein intendierter Durchgang Funktioniert

    // Nicht zugelassene Pointer:
    assert(column_chart_creation(data_test, error) == -1);      // Übergabe von einem NULL Pointer


    // Tests für column_chart_legend

    // Zugelassene Pointer / Werte:
    assert(column_chart_legend(1,10,document) == 0);            // Richtige Übergabe, Test ob ein intendierter Durchgang Funktioniert

    // Nicht zugelassene Pointer / Werte:
    assert(column_chart_legend(12, 10 , document) == -1);       // Die Anzahl der Schritte auf der X-Achse ist größer als die Y-Achse
    assert(column_chart_legend(1,10,error) == -1);              // Übergabe eines NULL Pointers


    // Tests für column_chart()

    // Zugelassene Pointer:
    assert(column_chart(data_test, 3, document) == 0);          // Richtige Übergabe, Test ob ein intendierter Durchgang Funktioniert

    // Nicht zugelassene Pointer:
    assert(column_chart(data_test, 3, error) == -1);            // Übergabe von einem NULL Pointer

    
    // Tests für bar_chart_creation()

    // Zugelassene Pointer:
    assert(bar_chart_creation(data_test, document) == 0);       // Richtige Übergabe, Test ob ein intendierter Durchgang Funktioniert

    // Nicht zugelassene Pointer:
    assert(bar_chart_creation(data_test, error) == -1);         // Übergabe von einem NULL Pointer


    // Tests für bar_chart_legend()

    // Zugelassene Pointer / Werte:
    assert(bar_chart_legend(1, 10, document) == 0);             // Richtige Übergabe, Test ob ein intendierter Durchgang Funktioniert

    // Nicht zugelassene Pointer / Werte:
    assert(bar_chart_legend(12,10,document) == -1);             // Die Schrittweite der X-Achse ist größer als die X-Achse
    assert(bar_chart_legend(1,10,error) == -1);                 // Übergabe von einem NULL Pointer


    // Tests für bar_chart()

    // Zugelassene Pointer:
    assert(bar_chart(data_test,3,document) == 0);               // Richtige Übergabe, Test ob ein intendierter Durchgang Funktioniert

    // Nicht zugelassene Pointer:
    assert(bar_chart(data_test, 3, error) == -1);               // Übergabe von einem NULL Pointer


    // Tests für out_maxval()
    
    // Zugelassene Pointer:
    assert(out_maxval(data_test,3,document) == 0);              // Richtige Übergabe, Test ob ein intendierter Durchgang Funktioniert

    // Nicht zugelassene Pointer:
    assert(out_maxval(data_test,3,error) == -1);                // Übergabe von einem NULL Pointer 



    // Schließen der geöffneten Datei und überprüfen ob es geklappt hat
    int success_test = fclose(document);
    if (success_test == -1)                                  // Überprüfen, ob die Datei geschlossen wurde 
    {
        printf("error");
        return 1;
    }
}