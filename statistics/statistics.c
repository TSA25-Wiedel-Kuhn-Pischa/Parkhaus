/**  
    Datei: statistics.c
    Beschreibung: Beschreibung aller Funktionen zur Ausgabe und Berechnung der Statistiken.
*/

//Einbinden von reapeted_statistics.h

/* int Function fullness(int occupied, int all)
(
    return von ((occupied/all) * 100) 
)
*/

/* int Function rate(int count)
(
    Beim ersten Aufruf der Funktion wird ein Array intialisiert. In diesem werden die Werte von count gespeichert.
    Bei jedem neuen Aufruf wird der Wert einen Schritt weiter gespeichert. 
    return (aktueller Wert, also array an der aktuellen Stelle, minus den
    vorheriger Wert, also das Array an der vorherigen Stelle (aktuelle Stelle minus 1)
    Wenn die Funktion zum ersten mal aufgerufen wird, wird der aktuelle Wert mit 0 subtrahiert.
)
*/

/* void Function output_data(int occupied, int all, int cars_in_line)
(
    i = 1
    i wird einmalig Initialisiert und bei jedem Aufruf der Funktion um eins erhöht.
    Es wird die Funktion fullness mit den Werten occupied und all aufgerufen und in der Variable fullness_data gespeichert
    Es wird occupied von all abgezogen und in der Variable free_spaces gespeichert 
    Es wird occupied plus cars_in_line gerechnet und in der Variable all_cars gespeichert 

    OUTPUT Zeitpunkt i(Ausgabe von dem Wert von i):     fullness: fullness_data(Ausgabe von dem Wert von fullnes_data)%     free spaces: free_data (Ausgabe von dem Wert von free_data)
                                                        cars parked: occupied(Ausgabe von dem Wert von occupied)            waiting cars: cars_in_line(Ausgabe von dem Wert von cars_in_line)
                                                        all cars: all_cars(Ausgabe von dem Wert von all_cars)
)
*/

/* int Function save_data(int occupied, int all, int cars_in_line)
(
    Es wird die Funktion fullness mit den Werten occupied und all aufgerufen und in der Variable fullness_data gespeichert
    Es wird occupied von all abgezogen und in der Variable free_spaces gespeichert 
    Es wird occupied plus cars_in_line gerechnet und in der Variable all_cars gespeichert

    Beim ersten Aufruf der Funktion wird ein Array intialisiert.
    In diesem werden die Werte fullness_data, free_data, occupied, cars_in_line und all_cars gespeichert.
    Diese werden jeweils einen Schritt weiter im Array gespeichert. 

    Das Array wird zurückgegeben.
    
)
*/

/**

    @brief Es wird jeweils der höchste Wert ausgegeben

    ...

    @param[in] Array, Eingabe von dem Array aus der Funktion save_data()

    @return Es wird in der Kosole ausgegeben und in einem externen Dokument dargestellt 
*/

//int Function out_maxval(int Array[]);

/**

    @brief Es wird eine Tabelle in der Konsole ausgegeben 

    Es wird eine Tabelle erstellt, welche 10 Spalten und 8 Zeilen hat. 
    Es wird die Anzahl der gesamten Simulationsschritte durch 10 geteilt.
    Dadurch erhält man den Absatand der einzelnen Schritte. Mit diesen gff. gerundeten Abständen 
    wird von 0 bis zum letzten Simulatinsschritt durgegangen. 
    In diesem Abständen wird die Tabelle geliedert. 
    Als Wert dargestellt werdem soll die Füllmenge, die Anzahl der Autos insgesamt, im Parkhaus und in der Wartschlange,
    sowie die Anzahl der freien Parkplätze und Rate.
    Um die Werte zu Erhalten, werden die Daten aus dem Array von der Funktion save_data(), ausgelesen. Um Rate zu erhälten
    wird mit der Anazhl der Autos die Funktion rate() aufgerufen. 

    @param[in] Array, Eingabe von dem Array aus der Funktion save_data()

    @return Es wird in der Kosole ausgegeben und in einem externen Dokument dargestellt 
*/

//int Function tabel(int Array[]);

/**

    @brief Es wird ein Säulendiagram in der Konsole ausgegeben 

    Es wird ein Säulendiagram erstellt. Auf der X-Achse werden 10 Zeitpunkte dargestellt, diese werden ermittelt, 
    indem die Anzahl der gesamten Simulationsschritte durch 10 geteilt wird. Dadurch erhält man den Absatand der einzelnen 
    Schritte. Mit diesen gff. gerundeten Abständen wird von 0 bis zum letzten Simulatinsschritt durgegangen. 
    Auf der Y-Achse wird von 0 bis 100 in Prozent skaliert. 
    Als Wert pro Zeitschritt wird die Füllmenge dargestellt, welche aus dem Array von der Funktion save_data() entnommen wird.

    @param[in] Array, Eingabe von dem Array aus der Funktion save_data()

    @return Es wird ein Säulendiagram in der Konsole Ausgegeben und einem externen Dokument dargestellt
*/

//int Function column_chart(int Array[]);

/**

    @brief Es wird ein Balkendiagram in der Konsole ausgegeben 

    Es wird ein Balkendiagram erstellt. Auf der Y-Achse werden 10 Zeitpunkte dargestellt, diese werden ermittelt, 
    indem die Anzahl der gesamten Simulationsschritte durch 10 geteilt wird. Dadurch erhält man den Absatand der einzelnen 
    Schritte. Mit diesen gff. gerundeten Abständen wird von 0 bis zum letzten Simulatinsschritt durgegangen. 
    Auf der X-Achse wird skaliert von 0 bis zum höchsten Wert von der Anzahl der Autos in der Warteschlange.
    Als Wert pro Zeitschritt wird die Anzahl der Autos in der Warteschlange dargestellt, 
    welche aus dem Array von der Funktion save_data() entnommen werden.


    @param[in] occupied, Eingabe von der Anzahl der besetzten Parkplätze 
    @param[in] all, Eingabe von der Anazhl aller Parkplätze 
    @param[in] time, Eingabe von dem Aktuellen Zeitpunkt

    @return Es wird ein Säulendiagram in der Konsole Ausgegeben
*/

//int Function bar_chart(int occupied, int all, int time);