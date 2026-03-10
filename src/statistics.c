/**  
    Datei: statistics.c
    Beschreibung: Beschreibung aller Funktionen zur Ausgabe und Berechnung der Statistiken.
*/

#include "../include/statistics.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fullness(int occupied, int all_spaces)
{
    return von (((float)occupied/all_spaces) * 100.f);
}

int rate(int count_now, int count_before)
{
    return count_now - count_before;
}

void head_document(int spaces, int max_parking, int size, int chance_of_new_cras, int seed, FILE* document)
{
    fprintf(document, "Anzahl der Stellplätze: %d \n", spaces);            //Datein müssen in Main mit dem Modus "w" geöffnet werden
    fprintf(document, "Maximale Parkdauer: %d \n", max_parking);
    fprintf(document, "Simulationsdauer: %d \n", size);
    fprintf(document, "Ankunftswahrscheinlichkeit neuer Fahrzeuge: %d %% \n", chance_of_new_cras);
    fprintf(document, "Der Zufalls-Seed: %d \n\n\n", seed);
}

void output_data(int free_spaces, int all_spaces, int cars_in_line, FILE* daten)
{
    static int i = 1;
    int occupied = all_spaces - free_spaces;
    int all_cars = occupied + cars_in_line;
    char empty = ' ';

    // Ausgabe in der Konsole 
    printf("Zeitpunkt %8d:  ", i);                                     // Verwendung von festen Formatierungen, damit die Zeichen sich nicht verschieben
    printf("fullness: %8d%%  ", fullness(occupied, all_spaces));
    printf("free spaces: %6d\n", free_spaces);
    printf("%21ccars parked: %6d", empty, occupied);                        // durch empty, wird einen Lücke am Anfang geschaffen
    printf("waiting cars: %5d\n", cars_in_line);
    printf("%21call cars: %9d \n\n", empty, all_cars);

    // Ausgabe in einem externen Document Daten.txt
    fprintf("Zeitpunkt %8d:  ", i);                                   
    fprintf("fullness: %8d%%  ", fullness(occupied, all_spaces));
    fprintf("free spaces: %6d\n", free_spaces);
    fprintf("%21ccars parked: %6d", empty, occupied);                      
    fprintf("waiting cars: %5d\n", cars_in_line);
    fprintf("%21call cars: %9d \n\n", empty, all_cars);
    i++;                                                                // Erhöhung des Simulationsschrittes
}

void save_data(int *save_data, int size, int free_spaces, int all_spaces, int cars_in_line)
{
    int occupied = all_spaces - free_spaces;                                // Berechnung der einzelnen Parameter
    int fullness_data = fullness(occupied, all_spaces);
    int all_cars = occupied + cars_in_line;

    static int steps_data = 0;                                              // Initialisierung der Variable, welche die Position im Array speichert

    if (steps_data < (size*5))                                              // Überprüfung ob die Vorgegebenen Simulationsschritte überschritten wurden 
    {
        //Speichern der einzelnen Simulationsschritte
        save_data[steps_data] = fullness_data;
        steps_data++;        
                                                                                
        save_data[steps_data] = free_spaces;
        steps_data++;

        save_data[steps_data] = occupied;
        steps_data++;

        save_data[steps_data] = cars_in_line;
        steps_data++;

        save_data[steps_data] = all_cars;
        steps_data++;
    }
}

//***********************************************************************************************************************************
//Hilfsfunktionen für tabel()

void tabel_creation(int info[], FILE* auswertung)
{
    printf("   | ");
    fprintf(auswertung,"   | ");  
    for (int i = 1; i < 11; i++)                            // Ausgabe der Obersten Zeile einer Tabelle (der Zeitschritte)
    {                                                      
        printf("\033[1m%8d\033[0m | ", i);                  // gibt Fettgedruckte Zahlen aus, damit die Skalierung besser unterschieden werden kann
        fprintf(auswertung,"\033[1m%8d\033[0m | ", i);  
    }

    printf("\n-------------------------------------------------------------------------------------------------------------------\n"); 
    fprintf(auswertung, "\n-------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < 6; i++)
    {   
        printf("\033[1m%d\033[0m | ", i+11);
        fprintf(auswertung, "\033[1m%d\033[0m | ", i+11);                                                 
        for (int g = 0; g < 10; g++)                                                 // Ausgabe der Einzelnen Werte
        {
            printf("%8d | ", info[g + 10*i]);
            fprintf(auswertung, "%8d | ", info[g + 10*i]);
        }
        printf("\n-------------------------------------------------------------------------------------------------------------------\n");
        fprintf(auswertung, "\n-------------------------------------------------------------------------------------------------------------------\n");
    }
}

void tabel_legend(int steps_x, int size_ary, FILE* auswertung)
{
    char* typ[] = {"Sätigung", "Anzahl der freien Parkplätze", "Anazahl der besetzten Parkplätze", "Anzahl der Autos in der Warteschlange", "Anzahl aller Autos", "die Änderungsrate"};

    printf("\nLegende zur Tabelle: \n\n");
    fprintf(auswertung, "\nLegende zur Tabelle: \n\n");
    for(int i = 1; i < 18; i++)                                                       
    { 
        if (i < 10)                                                                     // Ausgabe der Legende zur Obersten Zeile
        {
            printf("\033[1m%2d\033[0m. = %7d. Simulationsschritt\n", i, steps_x*(i-1));
            fprintf(auswertung, "\033[1m%2d\033[0m. = %7d. Simulationsschritt\n", i, steps_x*(i-1));
        }
        else if (i == 10) 
        {
            printf("\033[1m%d\033[0m. = %7d. Simulationsschritt\n\n", i, size_ary);
            fprintf(auswertung, "\033[1m%d\033[0m. = %7d. Simulationsschritt\n\n", i, size_ary);
        }
        else if (i > 10)                                                                // Ausgabe der Legende für die einzelenen Zeilen Zeitschritte
        {
            printf("\033[1m%d\033[0m. = Simulationsschritt %s \n", i, typ[i-11]);
            fprintf(auswertung, "\033[1m%d\033[0m. = Simulationsschritt %s \n", i, typ[i-11]);
        }
    }
}

//***********************************************************************************************************************************

void tabel(int data[], int size_ary, FILE* auswertung)
{
    int steps_x = round(size_ary / 10.f); 

    int info[60] = {0};                                                      // Array zur Speicherung der Ausgelsenen Werte

    for (int g = 0; g < 5; g++)
    {                             
        for (int i = g; i<= size_ary; i= i + steps_x)                       // Auslesen der Einzelnen Werte nach der Reinfolge der Speicherung
        {      
            static int f = 0;
            info[f] = data[i];                                              // Speichern des Wertes an der jeweiligen Stelle
            f = f + 1;
            if ((f-10*g) == 9) 
            {
                info[f] = data[size_ary];
            }
        }                                 
    }

    for (int i = (4 + steps_x); i <= size_ary; i = i+ steps_x)
    {          
        static int f = 51;                                 // Beginnt eins Später, da es zum Simulationsbeginn keine Änderungsrate gibt.                                                  
        info[f] = rate(data[i], data[i-steps_x]);
        f = f + 1;
    }

    tabel_creation(info, auswertung);
    tabel_legend(steps_x, size_ary, auswertung);
}

/* void FUNCTION column_chart(int data[], int size_ary, FILE* auswertung)       // Die Codingconvetion besagt, dass eine Funktion kürzer als 30 Lines sein soll
                                                                                // diese Funktion wird im Richtigen C-Code noch Modularisiert, aber Aktuell (als Pseudocode) im Sinne des Verständnisses so gelassen
    int steps_y = round(size_ary / 10.f)                     // Bereuchnung der Skala von der Y-Achse

    int info[10] = {0}
    char* spaces[] = {"| |", "_", " ", "^", "-", ">", "|"}   // Verwendete Zeichen zur Erstellung des Säulendiagrams 
                          
    FOR i <- 0 TO size_ary DO (Schrittweite(i = i + steps_y))
        Einmaliges Intialisieren int f = 0 
        info[f] = round(data[i] / 10.f)                     // Auslesen der Füllmenge und so umformen, das es zur Skalierung passt
        f = f + 1
        IF (f) == 9 THEN
            info[f] = round(data[size_ary] / 10.f)
        END IF
    END FOR

    // Erstellen des Säulendiagrams 
    FOR line <- 11 TO 0 DO                                  // durchgehen der Zeilen 
        FOR column <- 0 TO 21 DO                            // durchgehen der Spalten
            int f = 0
            IF line > 0 THEN  

                IF column == 0 && line == 11 THEN   
                    OUTPUT spaces[3] (Zeilenumbruch)        // Setztes der Pfeilspitze für die Y-Achse
                    fprintf(auswertung, spaces[3] (Zeilenumbruch))

                ELSE IF column == 0 THEN                    // Setzten der Pfeillinie für die Y-Achse
                    OUTPUT spaces[6]
                    fprintf(auswertung, spaces[6])
                END IF 

                IF column % 2 == 1 THEN             
                    OUTPUT spaces[2]                        // Setzten der Lücken zwischen den Säulen
                    fprintf(auswertung, spaces[2]) 

                ELSE IF column % 2 == 0 && column != 0 THEN 
                    IF (info[f] + 1) == line THEN           // Überprüfen, ob die Säule eine Zeile Tiefer existiert 
                        OUTPUT spaces[1]                    // Wenn ja, setzten eines Daches für die Säule 
                        fprintf(auswertung, spaces[1])

                    ELSE IF info[f] <= line THEN            // Überprüfen, ob der Wert groß genug ist, damit die Säule existiert
                        OUTPUT spaces[0]                    // Setzten der Säulemwände
                        fprintf(auswertung, spaces[0])
                    END IF 
                    f = f + 1
                END IF 

            // Setzten der X-Achse
            ELSE 
                IF column != 21 THEN
                    OUTPUT spaces[4]                         
                    fprintf(auswertung, spaces[4])
                ELSE
                    OUTPUT spaces[5]
                    fprintf(auswertung, spaces[5])
                END IF 
            END IF

        END FOR 
        OUTPUT (Zeilenumbruch)
        fprintf(auswertung, (Zeilenumbruch))
    END FOR

    FOR column <- 0 TO 21 DO
        int f = 1
        IF column % 2 == 1 || column == 0 THEN             
            OUTPUT spaces[2]                                // Setzten der Lücken, genauso wie zwischen den Säulen 
            fprintf(auswertung, spaces[2])
        ELSE IF column % 2 == 0 && column != 0 THEN 
            OUTPUT f
            fprintf(auswertung, f)                          // Setzten der Nummerierungen 
            f = f + 1
        END IF 
    END FOR 

    OUTPUT (Zeilenumbruch)
    fprintf(auswertung, (Zeilenumbruch))

    // Erstellen von einer Legende für die Säulen im Diagramm 

    FOR i <-1 TO 10 DO
        IF i < 10 THEN 
            OUTPUT i = Zeitschritt steps_y*i (Zeilenumbruch)              
            fprintf(auswertung, (i = Zeitschritt steps_y*i (Zeilenumbruch))
        ELSE 
            OUTPUT i = Zeitschritt size_ary (Zeilenumbruch)
            fprintf(auswertung, (i = Zeitschritt size_ary (Zeilenumbruch))
    END FOR

END FUNCTION

*/

/* void FUNCTION bar_chart(int data[], int size_ary, FILE* auswertung)      // Die Codingconvetion besagt, dass eine Funktion kürzer als 30 Lines sein soll
                                                                            // diese Funktion wird im Richtigen C-Code noch Modularisiert, aber Aktuell (als Pseudocode) im Sinne des Verständnisses so gelassen
    int steps_y = round(size_ary / 10.f)                        // Bereuchnung der Skala von der Y-Achse

    int info[10] = {0}
    char* spaces[] = { " ", "^", "-", ">", "|", "="}   // Verwendete Zeichen zur Erstellung des Balkendiagrams  

                                 
    FOR i <- 3 TO size_ary DO (Schrittweite(i = i + steps_y))   // Auslesen der Werte 
        Einmaliges Intialisieren int f = 0 
        info[f] = data[i] 
        f = f + 1
        IF (f) == 9 THEN
            info[f] = data[size_ary]
        END IF
    END FOR

    int max_x = info[0]                                                                  
    for i <- 0 TO 9 DO                                          // Berechnung des Max_Wertes für die X-Achse
        IF max_x < info[i] THEN
            max_x = info[i]
        END IF 
    END FOR

    int steps_x = round(max_x / 10.f)                           // Berechnung der einzelnen Schrittweite der X-Achse

    FOR i <- 0 TO 9 DO 
        info[i] = round(data[i] / steps.x)                      // Anpassen der Daten an die Skala
        IF (i) == 9 THEN
            info[i] = max_x
        END IF
    END FOR

    int f = 0

    FOR line <- 22 TO 0 DO                                      // durchgehen der Zeilen 
        FOR column <- 0 TO 21 DO                                // durchgehen der Spalten
            
            IF line > 1 && line % 2 == 0 THEN  

                IF column == 0 && line == 22 THEN   
                    OUTPUT spaces[1] (Zeilenumbruch)            // Setztes der Pfeilspitze für die Y-Achse
                    fprintf(auswertung, spaces[1] (Zeilenumbruch))

                ELSE IF column == 0 THEN                        // Setzten der Pfeillinie für die Y-Achse
                    OUTPUT spaces[4]  (Zeilenumbruch)
                    fprintf(auswertung, spaces[4] (Zeilenumbruch))
                END IF 

            IF line > 1 && line % 2 == 1 THEN                   // Zeile in der die Balken gesetzt werden
                OUTPUT f spaces[4]  
                fprintf(auswertung, f spaces[4])    
                FOR i <- 1 TO (info[f]*2)                       // Bestimmung der Länge der Balken
                    OUTPUT spaces[5]
                    fprintf(auswertung, spaces[5])
                END FOR 
                OUTPUT (Zeilenumbruch)
                fprintf(auswertung, (Zeilenumbruch))
            END IF
            // Setzten der X-Achse
            
            ELSE IF line == 0 THEN                              // Setzten der Nummerierungen für die X-Achse
                int f = 11
                IF column % 2 == 1 || column == 0 THEN             
                    OUTPUT spaces[0]                                
                    fprintf(auswertung, spaces[0])
                ELSE IF column % 2 == 0 && column != 0 THEN 
                    OUTPUT f
                    printf(auswertung, f)                     
                    f = f + 1
                END IF 

            ELSE IF line == 1 THEN                              //Setzten der Linie für die X-Achse
                IF column != 21 THEN
                    OUTPUT spaces[2]                         
                    printf(auswertung, spaces[2])
                ELSE
                    OUTPUT spaces[3]
                    fprintf(auswertung, spaces[3])
            END IF 

        END FOR 
        OUTPUT (Zeilenumbruch)
        fprintf(auswertung, (Zeilenumbruch))
    END FOR

    OUTPUT (Zeilenumbruch)
    fprintf(auswertung, (Zeilenumbruch))

    // Erstellen von einer Legende nur für die X-Achse im Diagramm, da die Werte von dem Säuelendiagramm mit den Zeitpunkten übereinstimmen 

    FOR i <-1 TO 10 DO
        IF i < 10 THEN 
            OUTPUT (i+10) = Wert steps_x*i (Zeilenumbruch)              
            fprintf(auswertung, ((i+10) = Wert steps_x*i (Zeilenumbruch))
        ELSE 
            OUTPUT (i+10) = Zeitschritt max_x (Zeilenumbruch)
            fprintf(auswertung, ((i+10) = Zeitschritt max_x (Zeilenumbruch))
    END FOR

END FUNCTION
*/

/* void FUNCTION out_maxval(int data[], int size, FILE* auswertung)

    int size_ary = round(size / 5)

    int max[] = {data[0], data[1], data[2], data[3], data[4], 0, 0, 0, 0, 0}
    char* typ[] = {"Sätigung", "Anzahl der freien Parkplätze", "Anazahl der besetzten Parkplätze", "Anzahl der Autos in der Warteschlange", "Anzahl aller Autos"}

    FOR g <- 0 TO 4 DO                             
        FOR i <- g TO size_ary DO (Schrittweite(i = i + 5))                 // Sortieren von jedem einzelnem Wert nach dem größten
            IF max[g] < data[i]
                max[g] = data[i]  
                max[g+5] = (i - g) / 5
            END IF
        END FOR                                    
    END FOR

    FOR g <- 0 TO 4 DO
        OUTPUT Die typ[g] war mit dem Wert max[g] zum Zeitpunkt max[g+5] am größten. (ein Zeilenumbruch)            // Ausgabe des jeweils größten Wertes
        fprintf(auswertung, Die typ[g] war mit dem Wert max[g] zum Zeitpunkt max[g+5] am größten. (ein Zeilenumbruch))                  
    END FOR

    IF max[3] > 15 THEN 
        OUTPUT Eine Bauliche Erweiterung wird empfohlen, da zu dem Zeitpunkt max[8], max[3] Autos in der Warteschlange waren.
        fprintf(auswertung, Eine Bauliche Erweiterung wird empfohlen, da zu dem Zeitpunkt max[8], max[3] Autos in der Warteschlange waren)
    ELSE IF max[3] <= 15 THEN 
        OUTPUT Eine Bauliche Erweiterung wird nicht empfohlen, da zu dem Zeitpunkt max[8], nur max[3] Autos in der Warteschlange waren.
        fprintf(auswertung, Eine Bauliche Erweiterung wird nicht empfohlen, da zu dem Zeitpunkt max[8], nur max[3] Autos in der Warteschlange waren.)
    END IF

END FUNCTION

*/

