/**  
    Datei: statistics.c
    Beschreibung: Beschreibung aller Funktionen zur Ausgabe und Berechnung der Statistiken.
*/

//Einbinden von reapeted_statistics.h

/* int FUNCTION fullness(int occupied, int all_spaces)

    return von ((occupied/all) * 100)

END FUNCTION
*/

/* int FUNCTION rate(int count_now, count_before)

    return count_now - count_before

END FUNCTION
*/

/* void FUNCTION head_document(int spaces, int max_parking, int size, int chance_of_new_cras, File* document)

    fprintf(document, Anzahl der Stellplätze: spaces (Zeilenumbruch))            //Datein müssen in Main mit dem Modus "w" geöffnet werden
    fprintf(document, Maximale Parkdauer: max_parking (Zeilenumbruch))
    fprintf(document, Simulationsdauer: size (Zeilenumbruch))
    fprintf(document, Ankunftswahrscheinlichkeit neuer Fahrzeuge: chance_of_new_cars % (Zeilenumbruch))
    fprintf(document, Der Zufalls-Seed: seed (Zeilenumbruch))

END FUNCTION

*/
/* void FUNCTION output_data(int free_spaces, int all_spaces, int cars_in_line, File* daten)

    einmaliges Initialisiern von int i = 1
    int occupied = all_spaces - free_spaces
    int all_cars = occupied + cars_in_line

    OUTPUT Zeitpunkt i(Ausgabe von dem Wert von i):     fullness: fullness(occupied, all_spaces) (Ausgabe des Wertes, der in der Funktion berechnet wurde)%     free spaces: free_data (Ausgabe von dem Wert von free_data) (Zeilenumbruch)
    OUTPUT                                              cars parked: occupied (Ausgabe von dem Wert von occupied)            waiting cars: cars_in_line (Ausgabe von dem Wert von cars_in_line) (Zeilenumbruch)
    OUTPUT                                              all cars: all_cars (Ausgabe von dem Wert von all_cars) (Zeilenumbruch) (Zeilenumbruch)

    fprintf(daten, Zeitpunkt i(Ausgabe von dem Wert von i):     fullness: fullness(occupied, all) (Ausgabe des Wertes, der in der Funktion berechnet wurde)%     free spaces: free_data (Ausgabe von dem Wert von free_data) (Zeilenumbruch))
    fprintf(daten,                                              cars parked: occupied (Ausgabe von dem Wert von occupied)            waiting cars: cars_in_line (Ausgabe von dem Wert von cars_in_line) (Zeilenumbruch))
    fprintf(daten,                                              all cars: all_cars (Ausgabe von dem Wert von all_cars) (Zeilenumbruch) (Zeilenumbruch))
    i = i + 1

END FUNCTION
*/

/* void FUNCTION save_data(int *save_data, int size, int free_spaces, int all_spaces, int cars_in_line)

    int occupied = all_spaces - free_spaces                                 //Berechnung der einzelnen Parameter
    int fullness_data = fullness(occupied, all_spaces)
    int all_cars = occupied + cars_in_line
    Einmaliges Initialisieren int steps_data = 0

    IF steps_data < (size*5) THEN
        save_data[steps_data] = fullness_data
        steps_data = steps_data + 1        
                                                                                
        save_data[steps_data] = free_spaces
        steps_data = steps_data + 1

        save_data[steps_data] = occupied
        steps_data = steps_data + 1

        save_data[steps_data] = cars_in_line
        steps_data = steps_data + 1

        save_data[steps_data] = all_cars
        steps_data = steps_data + 1
    END IF

END FUNCTION
*/



/* void FUNCTION tabel(int data[], int size_ary, File* auswertung)

    int steps_x = round(size_ary / 10.f) 

    int info[60] = {0}                                                      // Array zur Speicherung der Ausgelsenen Werte
    char* typ[] = {"Sätigung", "Anzahl der freien Parkplätze", "Anazahl der besetzten Parkplätze", "Anzahl der Autos in der Warteschlange", "Anzahl aller Autos", "die Änderungsrate"}

    FOR g <- 0 TO 4 DO                              
        FOR i <- g TO size_ary DO (Schrittweite(i = i + steps_x))         // Auslesen der Einzelnen Werte nach der Reinfolge der Speicherung
            einmaliges Initialisieren int f = 0 + 10*g
            info[f] = data[i]
            f = f + 1
            IF (f-10*g) == 9 THEN
                info[f] = data[size_ary]
            END IF
        END FOR                                   
    END FOR

    FOR i <- (4 + steps_x) TO size_ary DO (Schrittweite i = i + steps_x)            
        einmaliges Initalisieren int f = 51                                 // Beginnt eins Später, da das Array mit Nullen definiert ist und die erste Änderung ist 0.                                                  
        info[f] = rate(data[i], data[i-steps_x]
        f = f + 1
    END FOR

    OUTPUT    |
    fprintf(auswertung,   |)  
    FOR i <- 1 TO 10 DO                                                      // Ausgabe der Obersten Zeile einer Tabelle (der Zeitschritte)
        OUTPUT i  |
        fprintf(auswertung, i | )  
    END FOR 

    OUTPUT --------------------------------- (Zeilenumbruch)
    fprintf(auswertung, --------------------------------- (Zeilenumbruch))

    FOR i <- 0 TO 5 DO     
        OUTPUT (i+11) | 
        fprintf(auswertung, (i+11) | )                                                 
        FOR g <- 0 TO 9 DO                                                  // Ausgabe der Einzelnen Werte
            OUTPUT info[g + 10*i]| 
            fprintf(auswertung, info[g + 10*i]|)
        END FOR
        OUTPUT (Zeilenumbruch) --------------------------------- (Zeilenumbruch)
        fprintf(auswertung, (Zeilenumbruch) --------------------------------- (Zeilenumbruch))
    END FOR 

    FOR i <- 1 TO 10 DO                                                       // Ausgabe der Legende zur Obersten Zeile 
        IF i < 10 THEN
            OUTPUT i = (steps_x * (i-1)) (Zeilenumbruch)
            fprintf(auswertung, (steps_x * (i-1)) (Zeilenumbruch) )
        ELSE if i == 10 THEN
            OUTPUT size_ary (Zeilenumbruch)
            fprintf(auswertung, size_ary) (Zeilenumbruch)
        END IF 
    END FOR 

    FOR i <-11 TO 17 DO                                                       // Ausgabe der Legende für die einzelenen Zeilen Zeitschritte
        OUTPUT i = Zeitschritt typ[i-10] (Zeilenumbruch)
        fprintf(auswertung, (i = Zeitschritt typ[i-10] (Zeilenumbruch))
    END FOR

END FUNCTION
*/

/* void FUNCTION column_chart(int data[], int size_ary, File* auswertung)       // Die Codingconvetion besagt, dass eine Funktion kürzer als 30 Lines sein soll
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

/* void FUNCTION bar_chart(int data[], int size_ary, File* auswertung)      // Die Codingconvetion besagt, dass eine Funktion kürzer als 30 Lines sein soll
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

/* void FUNCTION out_maxval(int data[], int size, File* auswertung)

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

