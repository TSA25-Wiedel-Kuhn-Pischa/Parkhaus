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

    int size_ary = size / 5

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

    int size_ary = size / 5
    int steps = size_ary / 10) 

    int info[50]
    char typ[] = {"Sätigung", "Anzahl der freien Parkplätze", "Anazahl der besetzten Parkplätze", "Anzahl der Autos in der Warteschlange", "Anzahl aller Autos"}

    FOR g <- 0 TO 4 DO
        IF g = 0 THEN                               
            FOR i <- g TO size_ary DO (Schrittweite(i = i + steps))
                int f = 0 + 10*g
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

/* void FUNCTION column_chart(double Array[])

    Es wird eine Variable steps erstellt, in welcher die Abstände der Simulations Schritte gespeichert werden. 
    Dafür wird die Größe des übergebenen Arrays ermittelt und durch die größe eines einzelnen Eintrags gerechnet 
    und danach nochmal durch 10 und durch 5, weil es 5 eingegbene Werte gibt, es wird auch eine Funktion 
    zum Runden verwendet, um ganze Zahlen zu erhalten.

    Dann wird in einer Schleife das Array aufgerufen und zu den jeweiligen Abständen, mit dem Faktor 5, gestopt, um die Füllmenge in 
    Prozent zu speichern. Dafür wird ein Arrays angelegt. 
    Dabei ist der erste Ausgelesene Wert, der Wert an der Stelle 0 und 
    der letzte, an der Stelle vom letzte Simulationsschritt (also steps mal 10). 

    Dann werden die einzelnen ausgelesenen Werte durch 10 geteilt und gerundet und in dem Array als Wert ersetzt. 
    Dieser Wert wird dann so weiter verwendet, das die einzelnen größen der Säulen bestimmt werden. 
    Das Diagram wird von oben nach unten erstellt, dabei ist die oberste Zeile, die Zahl 11. Dann wird jeder Wert 
    überprüft, ob er den Wert 11 hat, wenn ja, werden zwei Striche ausgeben | |. Wenn er genau eins kleiner ist, wird ein _ gesetzt.
    Dies wird so weit für jede Zeile darunter Wiederholt, bis zur Zeile 1 dort werden wenn denn nur noch | | gesetzt. 
    Zu beginn der Zeile wird jeweils noch ein | gesetzt um die Y-Achse darzustellen. 
    In der Zeile 0  wird dann die X-Achse dargestellt und darunter die einzelnen Zeitschritte (steps).

    Gleichzeitig wird jede Ausgabe, die in die Konsole ausgegeben wurde, auch in eine extra .txt Datei geschrieben.

END FUNCTION

*/

/* void FUNCTION bar_chart(double Array[])

    Es wird eine Variable steps_y erstellt, in welcher die Abstände der Simulations Schritte gespeichert werden. 
    Dafür wird die Größe des übergebenen Arrays ermittelt und durch die größe eines einzelnen Eintrags gerechnet 
    und danach nochmal durch 10 und durch 5, weil es 5 eingegbene Werte gibt, es wird auch eine Funktion 
    zum Runden verwendet, um ganze Zahlen zu erhalten.

    Dann wird in einer Schleife das Array aufgerufen und zu den jeweiligen Abständen, mit dem Faktor 5, an der 4. Stelle gestopt, 
    um die Anazahl der Autos in der Warteschlange zu speichern. Dafür wird ein Arrays angelegt. 
    Dabei ist der erste Ausgelesene Wert, der Wert an der Stelle 0 und 
    der letzte, an der Stelle vom letzte Simulationsschritt (also steps_y mal 10). 

    Dann wird ermittelt, welcher von den Ausgelsenen Werten der Größte ist, um die Größe der Balken zu bestimmen.
    Die X-Achse wird 10 Spalten lang sein, wodruch der ausgelsene Wert geteielt durch 10 in steps_x gespeichert wird.
    Das ist die Skalierung der X-Achse. Um zu erkenne wie groß jeder Balken, bei dieser Skalierung ist, wird jeder Wert 
    durch steps_x geteilt und gerundet. In der obersten Zeile wird die Skalierung der X-Achse, also 1 bis 10 ausgegeben. 
    Eine Zeile tiefer wird eine Linie "------" ausgeben, um die X-Achse darzustellen.
    Dann wird jede Zeile später, mit jeweils einer Zeile als Lücke, am Anfang der Zeitschritt und dann ein |, um die Y-Achse 
    dargestellt. Danach relativ von der der Größe des Wertes zu diesem Zeitschritt, eine Menge an "====". 
    Dies wird in einer Schleife wiederholt, bis alle Werte dargestellt wurden.

    Gleichzeitig wird jede Ausgabe, die in die Konsole ausgegeben wurde, auch in eine extra .txt Datei geschrieben.

END FUNCTION
*/