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

    int info[60] = {0};                                                     // Array zur Speicherung der Ausgelsenen Werte

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
        static int f = 51;                                  // Beginnt eins Später, da es zum Simulationsbeginn keine Änderungsrate gibt.                                                  
        info[f] = rate(data[i], data[i-steps_x]);
        f = f + 1;
    }

    tabel_creation(info, auswertung);                       // Erstellen der Tabelle
    tabel_legend(steps_x, size_ary, auswertung);            // Erstellen der Legende zur Tabelle 
}

//***********************************************************************************************************************************
//Hilfsfunktionen für column_chart()

void column_chart_creation(int info[], FILE* auswertung)
{
    char* spaces[] = {"| |", "_", "   ", "^", "---", ">", "|"};   // Verwendete Zeichen zur Erstellung des Säulendiagrams 

    // Erstellen des Säulendiagrams 
    for(int line = 11; line > -1; line--)                                 // durchgehen der Zeilen 
    {
        int f = 0;
        for(int column = 0; column < 23; column++)                            // durchgehen der Spalten
        {
            if (line > 0)
            {  
                if(column == 1 && line == 11) 
                {  
                    printf(" %s", spaces[3]);        // Setztes der Pfeilspitze für die Y-Achse
                    fprintf(auswertung, "%s", spaces[3]);
                }
                else if (column == 1)                  // Setzten der Pfeillinie für die Y-Achse
                {
                    printf("%s", spaces[6]);
                    fprintf(auswertung, "%s", spaces[6]);
                }

                else if (column % 2 == 0) 
                {   
                    if (column == 0 && line != 11)
                    {
                        printf("%3d ", line*10);
                        fprintf(auswertung, "%3d ", line*10);
                    }  
                    else 
                    {
                        printf("%s", spaces[2]);                        // Setzten der Lücken zwischen den Säulen
                        fprintf(auswertung, "%s", spaces[2]);
                    }       
                }
                else if (column % 2 == 1 && column != 1) 
                { 
                    if ((info[f] + 1) == line)              // Überprüfen, ob die Säule eine Zeile Tiefer existiert
                    { 
                        printf("%2s ", spaces[1]);                    // Wenn ja, setzten eines Daches für die Säule 
                        fprintf(auswertung, "%2s ", spaces[1]);
                    }
                    else if (info[f] >= line)               // Überprüfen, ob der Wert groß genug ist, damit die Säule existiert
                    {
                        printf("%2s", spaces[0]);                     // Setzten der Säulemwände
                        fprintf(auswertung, "%2s", spaces[0]);
                    } 
                    else 
                    {
                        printf("%s", spaces[2]);
                        fprintf(auswertung, "%s", spaces[2]);
                    }
                    f++;
                } 
            }
            // Setzten der X-Achse
            else 
            {
                if (column == 22) 
                {
                    printf("%s", spaces[5]);                          
                    fprintf(auswertung, "%s", spaces[5]);
                }
                else if (column > 1)
                {
                    printf("%s", spaces[4]); 
                    fprintf(auswertung, "%s", spaces[4]);
                }
                else 
                {
                    printf("  ");
                    fprintf(auswertung, "  ");
                }
            }
        } 
        printf("\n");
        fprintf(auswertung, ("\n"));
    }

    //Erzeugen der Skalierung für die X-Achse
    printf(" ");
    fprintf(auswertung, " ");
    for (int column = 0; column < 22; column++)
    {
        static int f = 1;
        if (column % 2 == 1 || column == 0) 
        {             
            printf("%s", spaces[2]);                                 // Setzten der Lücken, genauso wie zwischen den Säulen 
            fprintf(auswertung, "%s", spaces[2]);
        }
        else if (column % 2 == 0 && column != 0)  
        {
            printf("%3d", f); 
            fprintf(auswertung, "%3d", f);                          // Setzten der Nummerierungen 
            f++;
        }
    }
}

void column_chart_legend(int steps_x, int size_ary, FILE* auswertung)
{
    // Erstellen von einer Legende für die Säulen im Diagramm 

    printf("\n\n"); 
    fprintf(auswertung, "\n\n");

    for (int i = 1; i < 11; i++)
    {
        if (i < 10) 
        { 
            printf("\033[1m%2d\033[0m = %7d. Simulationsschritt\n", i, steps_x*i);              
            fprintf(auswertung, "\033[1m%2d\033[0m = %7d. Simulationsschritt\n", i, steps_x*i);
        }
        else
        {
            printf("\033[1m%d\033[0m = %7d. Simulationsschritt\n", i, size_ary);              
            fprintf(auswertung, "\033[1m%d\033[0m = %7d. Simulationsschritt\n", i, size_ary);
        }
    }
}

//***********************************************************************************************************************************

void column_chart(int data[], int size_ary, FILE* auswertung)       
{                                                                                
    int steps_x = round(size_ary / 10.f);                     // Bereuchnung der Skala von der X-Achse

    int info[10] = {0};
                          
    for(int i = steps_x; i <= size_ary;i = i + steps_x)
    {
        static int f = 0;
        info[f] = round(data[i] / 10.f);                     // Auslesen der Füllmenge und so umformen, das es zur Skalierung passt
        f++;
        if (f == 9)
        {
            info[f] = round(data[size_ary] / 10.f);
        }
    }

    //Ausgabe des Säulendiagramms 
    column_chart_creation(info, auswertung);
    //Ausgabe der Legende zum Säulendiagramm 
    column_chart_legend(steps_x, size_ary, auswertung);
}

void bar_chart(int data[], int size_ary, FILE* auswertung)      // Die Codingconvetion besagt, dass eine Funktion kürzer als 30 Lines sein soll
{                                                                            // diese Funktion wird im Richtigen C-Code noch Modularisiert, aber Aktuell (als Pseudocode) im Sinne des Verständnisses so gelassen
    int steps_y = round(size_ary / 10.f);                        // Bereuchnung der Skala von der Y-Achse

    int info[10] = {0};
    char* spaces[] = {" ", "   ^", "-", ">", "|", "="};   // Verwendete Zeichen zur Erstellung des Balkendiagrams  

                                 
    for(int i = 3; i <= size_ary; i = i + steps_y)  // Auslesen der Werte 
    {
        static int f = 0;
        info[f] = data[i]; 
        f++;
        if (f == 9) 
        {
            info[f] = data[size_ary];
        }
    }

    int max_x = info[0];                                                                  
    for (int i = 0; i < 10; i++)                                          // Berechnung des Max_Wertes für die X-Achse
    {
        if (max_x < info[i]) 
        {
            max_x = info[i];
        }
    }

    int steps_x = round(max_x / 10.f);                           // Berechnung der einzelnen Schrittweite der X-Achse

    for (int i = 0; i < 10; i++)
    { 
        info[i] = round((float)info[i] / steps_x);                      // Anpassen der Daten an die Skala
        if (i == 9)
        {
            info[i] = max_x;
        }
    }

    int f = 0;

    for (int line = 22; line > -1; line--)                                      // durchgehen der Zeilen 
    {
        if (line > 1 && line % 2 == 0)   
        {
            if (line == 22) 
            {   
                printf("%s\n", spaces[1]);            // Setztes der Pfeilspitze für die Y-Achse
                fprintf(auswertung, "%s\n", spaces[1]);
                printf("   %s\n", spaces[4]);
                fprintf(auswertung, "   %s\n", spaces[4]);
            }
            else 
            {                            // Setzten der Pfeillinie für die Y-Achse
                printf("   %s\n", spaces[4]);
                fprintf(auswertung, "   %s\n", spaces[4]);
            } 
        }
        else if (line > 1 && line % 2 == 1)                   // Zeile in der die Balken gesetzt werden
        {
            printf("%2d %s", f, spaces[4]);  
            fprintf(auswertung, "%2d %s", f, spaces[4]);    
            for (int i = 0; i < (info[f]*2); i++)                       // Bestimmung der Länge der Balken
            {
                printf("%s", spaces[5]); 
                fprintf(auswertung, "%s", spaces[5]);
            }
            printf ("\n"); 
            fprintf(auswertung, "\n");
            f++;
        }
            // Setzten der X-Achse
        else if (line == 1) 
        {                              //Setzten der Linie für die X-Achse
            printf("   ");
            fprintf(auswertung, "   ");
            for(int column = 0; column < 22; column++)
            {
                if (column != 21) 
                {
                    printf("%s", spaces[2]);                         
                    fprintf(auswertung, "%s", spaces[2]);
                }
                else
                {
                    printf("%s\n", spaces[3]);
                    fprintf(auswertung, "%s", spaces[3]);
                }
            } 
        }    
        else if (line == 0)                               // Setzten der Nummerierungen für die X-Achse
        {
            f = 10;
            for(int column = 0; column < 22; column++)
            {
                if (column % 4 != 0 && column % 2 != 0 || column == 0) 
                {             
                    printf("%s", spaces[0]);                                
                    fprintf(auswertung, "%s", spaces[0]);
                }
                else if (column % 4 == 0 && column != 0) 
                {
                    printf("%d", f);
                    printf(auswertung, "%d", f);                     
                    f = f + 2;
                }
            }
        }
    }

    printf("\n\n"); 
    fprintf(auswertung, "\n\n");

    // Erstellen von einer Legende nur für die X-Achse im Diagramm, da die Werte von dem Säuelendiagramm mit den Zeitpunkten übereinstimmen 

    for (int i = 1; i < 11; i++) 
    {
        if (i < 10) 
        {
            printf("%d= Wert %d \n", (i+10), steps_x*i);             
            fprintf(auswertung, "%d= Wert %d \n", (i+10), steps_x*i);
        }
        else
        {
            printf("%d = Zeitschritt %d \n", (i+10), max_x);
            fprintf(auswertung, "%d = Zeitschritt %d \n", (i+10), max_x);
        }
    }

}

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

