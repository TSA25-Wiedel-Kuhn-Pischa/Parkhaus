/**  
    Datei: statistics.h
    Beschreibung: Zusammenfasung aller Funktionen zur Ausgabe und Berechnung der Statistiken.
*/
//#ifndef STATISTICS
//#define STATISTICS
/**

    @brief Es wird berechnet, wie voll das Parkhaus in Prozent ist.

    Es wird die Anzahl der Belegten Parkplätze durch die Anazhl aller Parkplätze gerechnet und mit 100 multipliziert um einen 
    Prozentwert zu erhalten. 

    @param[in] occupied, Eingabe von der Anzahl der besetzten Parkplätze 
    @param[in] all, Eingabe von der Anazhl aller Parkplätze 

    @return Es wird der berechnete Wert zurück gegeben
*/

//int Function fullness(int occupied, int all);

/**

    @brief Es wird berechnet, wie viele Autos seit dem letzten Zeitpunkt dazu gekommen sind 

    Es wird der Wert, die Anzahl der Autos, des vorherigen Aufrufes gespeichert und von der jetzigen Anzahl der Autos abgezogen.

    @param[in] count, Eingabe von der Anzahl der Autos im Parkhaus und ggf. davor 

    @return Es wird der berechnete Wert zurück gegeben
*/

//int Function rate(int count);

/**

    @brief Es werden in der Konsole die aktuellen Daten ausgegeben

    Es wird der berechnete Werte von der Funktion fullnes, sowie die Anzahl der Autos im Parkhaus, in der möglichen 
    Warteschlange und Insgesamt ausgegeben, und auch die Anzahl der freien Parkplätze.
    All dies wird mit dem aktuellen Zeitschritt in der Konsole ausgegeben

    @param[in] occupied, Eingabe von der Anzahl der besetzten Parkplätze 
    @param[in] all, Eingabe von der Anazhl aller Parkplätze
    @param[in] cars_in_line, Eingabe von der Anazhl aller Autos in der Warteschlange

    @return Ausgabe von den aktuellen Werten 
*/

//void Function output_data(int occupied, int all, int cars_in_line);

/**

    @brief Es werden die Daten von dem aktuellen Zeitpunkt gespeichert

    Es werden die berechneten Werte, fullnes und freie Parkplätze, sowie die Anzahl der Autos im Parkhaus, 
    in der möglichen Warteschlange und Insgesamt mit dem aktuellen Zeitschritt gespeichert 

    @param[in] occupied, Eingabe von der Anzahl der besetzten Parkplätze 
    @param[in] all, Eingabe von der Anazhl aller Parkplätze
    @param[in] cars_in_line, Eingabe von der Anazhl aller Autos in der Warteschlange

    @return Rückgabe von dem erstellten Array, in dem die Werte gespeichert werden
*/

//int Function save_data(int occupied, int all, int cars_in_line);

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


    @param[in] Array, Eingabe von dem Array aus der Funktion save_data()

    @return Es wird ein Säulendiagram in der Konsole Ausgegeben
*/

//int Function bar_chart(int Array[]);

//#endif
