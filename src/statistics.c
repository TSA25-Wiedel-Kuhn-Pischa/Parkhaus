/**  
    Datei: statistics.c
    Beschreibung: Beschreibung aller Funktionen zur Ausgabe und Berechnung der Statistiken.
*/

//Einbinden von reapeted_statistics.h

/* int FUNCTION fullness(int occupied, int all)

    return von ((occupied/all) * 100)

END FUNCTION
*/

/* int FUNCTION rate(int count_now, count_before)

    int rate
    rate = count_now - count_before
    return rate

END FUNCTION
*/

/* void FUNCTION output_data(int occupied, int all, int cars_in_line)

    einmaliges Initialisiern von int i = 1
    int free_spaces = all - occupied
    int all_cars = occupied + cars_in_line

    OUTPUT Zeitpunkt i(Ausgabe von dem Wert von i):     fullness: fullness(occupied, all) (Ausgabe des Wertes, der in der Funktion berechnet wurde)%     free spaces: free_data (Ausgabe von dem Wert von free_data)
    OUTPUT                                              cars parked: occupied (Ausgabe von dem Wert von occupied)            waiting cars: cars_in_line (Ausgabe von dem Wert von cars_in_line)
    OUTPUT                                              all cars: all_cars (Ausgabe von dem Wert von all_cars)

    i = i + 1

END FUNCTION
*/

/* int FUNCTION save_data(int *save_data, int *size, int occupied, int all, int cars_in_line)

    int fullness_data = fullness(occupied, all)
    int free_spaces = all - occupied
    int all_cars = occupied + cars_in_line
    
    int *temp = realloc(save_data, (size + 5) * sizeof(int))

    IF temp == NULL THEN
    return save_data
    END IF

    save_data = temp
    
    FOR g <- 1 TO 5 DO
        IF g = 1 THEN                               /* Dies wäre mit eine Switch-Case Abfrage besser und effizienter
            save_data[size] = fullness_data         *  umgesetzt. Da wir dafür aber keine einheitliche Defintion haben
        END IF                                      *  lässt sich das nicht in Pseudocode umsetzten.
                                                    *  Es wird aber im Entwurf mit einer Switch_Case Abfrage umgesetzt.
        IF g = 2 THEN                               *//*
            save_data[size] = free_spaces
        END IF

        IF g = 3 THEN 
            save_data[size] = occupied
        END IF

        IF g = 4 THEN 
            save_data[size] = cars_in_line
        END IF

        IF g = 5 THEN 
            save_data[size] = all_cars
        END IF

        size = size + 1
    END FOR

    return save_data

END FUNCTION
*/

/* void FUNCTION out_maxval(int data[], int size)

    int size_ary = round(size / 5)

    int max[] = {data[0], data[1], data[2], data[3], data[4], 0, 0, 0, 0, 0}
    char typ[] = {"Sätigung", "Anzahl der freien Parkplätze", "Anazahl der besetzten Parkplätze", "Anzahl der Autos in der Warteschlange", "Anzahl aller Autos"}

    FOR g <- 0 TO 4 DO
        IF g = 0 THEN                               
            FOR i <- g TO size_ary DO (Schrittweite(i = i + 5))
                IF max[g] < data[i]
                    max[g] = data[i]  
                    max[g+5] = (i - g) / 5
                END IF
            END FOR
        END IF                                     
    END FOR

    FOR g <- 0 TO 4 DO
        OUTPUT Die typ[g] war mit dem Wert max[g] zum Zeitpunkt max[g+5] am größten. (ein Zeilenumbruch)     
        fprintf(Auswertung.txt, Die typ[g] war mit dem Wert max[g] zum Zeitpunkt max[g+5] am größten. (ein Zeilenumbruch))                  
    END FOR

END FUNCTION

*/

/* void FUNCTION tabel(int data[], int size)

    int size_ary = round(size / 5.f)
    int steps = round(size_ary / 10.f) 

    int info[50] = {0}
    char typ[] = {"Sätigung", "Anzahl der freien Parkplätze", "Anazahl der besetzten Parkplätze", "Anzahl der Autos in der Warteschlange", "Anzahl aller Autos"}

    FOR g <- 0 TO 4 DO
        IF g = 0 THEN                               
            FOR i <- g TO size_ary DO (Schrittweite(i = i + steps))
                einmaliges Intialisieren int f = 0 + 10*g
                info[f] = data[i]
                f = f + 1
                IF (f-10*g) == 9 THEN
                    info[f] = data[size_ary]
                END IF
            END FOR
        END IF                                     
    END FOR

    FOR i <- 0 TO 9 DO
        IF i < 9 THEN
            OUTPUT steps * i |
        ELSE if i == 9 THEN
            OUTPUT size_ary
        END IF 
    END FOR 

    OUTPUT ---------------------------------

    FOR i <- 0 TO 4 DO
        FOR g <- 0 TO 9 DO
            OUTPUT (i+1) | 
            fprintf(Auswertung.txt, (i+1) | )
            OUTPUT info[g + 10*i] | 
            fprintf(Auswertung.txt, info[g + 10*i] | )
        END FOR
        OUTPUT (Zeilenumbruch) --------------------------------- (Zeilenumbruch)
        fprintf(Auswertung.txt, (Zeilenumbruch) --------------------------------- (Zeilenumbruch))
    END FOR 

    FOR i <-1 TO 5 DO
        OUTPUT i = typ[i-1] (Zeilenumbruch)
        fprintf(Auswertung.txt, (i = typ[i-1] (Zeilenumbruch))
    END FOR

END FUNCTION
*/

/* void FUNCTION column_chart(int data[], int size)

    int size_ary = round(size / 5.f)
    int steps = round(size_ary / 10.f)                      // Bereuchnung der Skala von der Y-Achse

    int info[10] = {0}
    char spaces[] = {"| |", "_", " ", "^", "-", ">", "|"}   // Verwendete Zeichen zur Erstellung des Säulendiagrams 

                                 
    FOR i <- 0 TO size_ary DO (Schrittweite(i = i + steps))
        Einmaliges Intialisieren int f = 0 
        info[f] = round(data[i] / 10.f)
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
                    fprintf(Auswertung.txt, spaces[3] (Zeilenumbruch))

                ELSE IF column == 0 THEN                    // Setzten der Pfeillinie für die Y-Achse
                    OUTPUT spaces[6]
                    fprintf(Auswertung.txt, spaces[6])
                END IF 

                IF column % 2 == 1 THEN             
                    OUTPUT spaces[2]                        // Setzten der Lücken zwischen den Säulen
                    fprintf(Auswertung.txt, spaces[2]) 

                ELSE IF column % 2 == 0 && column != 0 THEN 
                    IF (info[f] + 1) == line THEN           // Überprüfen, ob die Säule eine Zeile Tiefer existiert 
                        OUTPUT spaces[1]                    // Wenn ja, setzten eines Daches für die Säule 
                        fprintf(Auswertung.txt, spaces[1])

                    ELSE IF info[f] <= line THEN            // Überprüfen, ob der Wert groß genug ist, damit die Säule existiert
                        OUTPUT spaces[0]                    // Setzten der Säulemwände
                        fprintf(Auswertung.txt, spaces[0])
                    END IF 
                    f = f + 1
                END IF 

            // Setzten der X-Achse

            ELSE 
                IF column != 21 THEN
                    OUTPUT spaces[4]                         
                    fprintf(Auswertung.txt, spaces[4])
                ELSE
                    OUTPUT spaces[5]
                    fprintf(Auswertung.txt, spaces[5])
                END IF 
            END IF

        END FOR 
        OUTPUT (Zeilenumbruch)
        fprintf(Auswertung.txt, (Zeilenumbruch))
    END FOR

    FOR column <- 0 TO 21 DO
        int f = 1
        IF column % 2 == 1 || column == 0 THEN             
            OUTPUT spaces[2]                                // Setzten der Lücken, genauso wie zwischen den Säulen 
            fprintf(Auswertung.txt, spaces[2])
        ELSE IF column % 2 == 0 && column != 0 THEN 
            OUTPUT f
            fprintf(Auswertung.txt, f)                      // Setzten der Nummerierungen 
            f = f + 1
        END IF 
    END FOR 

    OUTPUT (Zeilenumbruch)
    fprintf(Auswertung.txt, (Zeilenumbruch))

    // Erstellen von einer Legende für die Säulen im Diagramm 

    FOR i <-1 TO 10 DO
        IF i < 10 THEN 
            OUTPUT i = Zeitschritt steps*i (Zeilenumbruch)              
            fprintf(Auswertung.txt, (i = Zeitschritt steps*i (Zeilenumbruch))
        ELSE 
            OUTPUT i = Zeitschritt size_ary (Zeilenumbruch)
            fprintf(Auswertung.txt, (i = Zeitschritt size_ary (Zeilenumbruch))
    END FOR

END FUNCTION

*/

/* void FUNCTION bar_chart(int data[], int size)

    int size_ary = round(size / 5.f)
    int steps_y = round(size_ary / 10.f)                        // Bereuchnung der Skala von der Y-Achse

    int info[10] = {0}
    char spaces[] = { " ", "^", "-", ">", "|", "="}   // Verwendete Zeichen zur Erstellung des Balkendiagrams  

                                 
    FOR i <- 3 TO size_ary DO (Schrittweite(i = i + steps_y))
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
                    fprintf(Auswertung.txt, spaces[1] (Zeilenumbruch))

                ELSE IF column == 0 THEN                        // Setzten der Pfeillinie für die Y-Achse
                    OUTPUT spaces[4]  (Zeilenumbruch)
                    fprintf(Auswertung.txt, spaces[4] (Zeilenumbruch))
                END IF 

            IF line > 1 && line % 2 == 1 THEN                   // Zeile in der die Balken gesetzt werden
                OUTPUT f spaces[4]  
                fprintf(Auswertung.txt, f spaces[4])    
                FOR i <- 1 TO (info[f]*2)                       // Bestimmung der Länge der Balken
                    OUTPUT spaces[5]
                    fprintf(Auswertung.txt, spaces[5])
                END FOR 
                OUTPUT (Zeilenumbruch)
                fprintf(Auswertung.txt, (Zeilenumbruch))
            END IF
            // Setzten der X-Achse

            
            ELSE IF line == 0 THEN                              // Setzten der Nummerierungen für die X-Achse
                int f = 11
                IF column % 2 == 1 || column == 0 THEN             
                    OUTPUT spaces[0]                                
                    fprintf(Auswertung.txt, spaces[0])
                ELSE IF column % 2 == 0 && column != 0 THEN 
                    OUTPUT f
                    printf(Auswertung.txt, f)                     
                    f = f + 1
                END IF 

            ELSE IF line == 1 THEN                              //Setzten der Linie für die X-Achse
                IF column != 21 THEN
                    OUTPUT spaces[2]                         
                    printf(Auswertung.txt, spaces[2])
                ELSE
                    OUTPUT spaces[3]
                    fprintf(Auswertung.txt, spaces[3])
            END IF 

        END FOR 
        OUTPUT (Zeilenumbruch)
        fprintf(Auswertung.txt, (Zeilenumbruch))
    END FOR


    OUTPUT (Zeilenumbruch)
    fprintf(Auswertung.txt, (Zeilenumbruch))

    // Erstellen von einer Legende nur für die X-Achse im Diagramm, da die Werte von dem Säuelendiagramm mit den Zeitpunkten übereinstimmen 

    FOR i <-1 TO 10 DO
        IF i < 10 THEN 
            OUTPUT (i+10) = Wert steps_x*i (Zeilenumbruch)              
            fprintf(Auswertung.txt, ((i+10) = Wert steps_x*i (Zeilenumbruch))
        ELSE 
            OUTPUT (i+10) = Zeitschritt max_x (Zeilenumbruch)
            fprintf(Auswertung.txt, ((i+10) = Zeitschritt max_x (Zeilenumbruch))
    END FOR

END FUNCTION
*/