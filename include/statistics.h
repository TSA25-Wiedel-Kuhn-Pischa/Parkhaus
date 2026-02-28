/**  
    Datei: statistics.h
    Beschreibung: Zusammenfasung aller Funktionen zur Ausgabe und Berechnung der Statistiken.
*/
//#ifndef STATISTICS
//#define STATISTICS
/**

*
*    @brief Es wird berechnet, wie voll das Parkhaus in Prozent ist.
*
*    Es wird die Anzahl der Belegten Parkplätze durch die Anazhl aller Parkplätze gerechnet und mit 100 multipliziert um einen 
*    Prozentwert zu erhalten. 
*
*    @param[in] occupied, Eingabe von der Anzahl der besetzten Parkplätze 
*    @param[in] all, Eingabe von der Anazhl aller Parkplätze 
*
*    @return Es wird der berechnete Wert zurück gegeben
*/

//int FUNCTION fullness(int occupied, int all);

/**
*
*    @brief Es wird berechnet, wie viele Autos seit dem letzten Zeitpunkt ins Parkhaus dazu gekommen sind 
*
*    Es wird eine Variable rate intialisiert. Die Variable erhält den Wert, den man erhält, 
*    wenn der übergebene Wert von count_now minus count_before gerechnet wird.
*
*    @param[in] count_now, Eingabe von der Anzahl der Autos im Parkhaus 
*    @param[in] count_before, Eingabe von der Anzahl der Autos im Parkhaus von einem vorherigen Simulationsschritt
*
*    @return Es wird der Wert von der Variable rate zurückgegeben
*/

//int FUNCTION rate(int count_now, count_before);

/**

    @brief Es wird ein Dateikopf für die externe datei erstellt

    Es wird in der externen .txt Datei eine kurz übersicht zu den eingebenen Parametern erstellt.


    @param[in] spaces, Eingabe des Speicherbestandes aus der Funktion save_data()
    @param[in] max_parking, Eingabe der Anzahl der Einträge des Arrays
    @param[in] steps, Eingabe der Anzahl der Einträge des Arrays
    @param[in] chance_of_new_cars, Eingabe der Anzahl der Einträge des Arrays
    @param[in] Seed, Eingabe der Anzahl der Einträge des Arrays

    @return Es wird in einem externen Dokument Auswertung.txt dargestellt, 
            aber kein direkter return Wert, da die Funktion den Datentyp void hat.
*/

//void FUNCTION head_document(int spaces, int max_parking, int steps);
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


//void FUNCTION output_data(int occupied, int all, int cars_in_line);


/**

    @brief Es werden die Daten von dem aktuellen Zeitpunkt gespeichert

    Es werden die berechneten Werte, fullnes und freie Parkplätze, sowie die Anzahl der Autos im Parkhaus, 
    in der möglichen Warteschlange und Insgesamt mit dem aktuellen Zeitschritt gespeichert 


    @param[in/out] *data, Eingabe des vorherigen Speicherbestandes 
    @param[in/out] *size, Eingabe der größe des Arrays

    @param[in] occupied, Eingabe von der Anzahl der besetzten Parkplätze 
    @param[in] all, Eingabe von der Anazhl aller Parkplätze
    @param[in] cars_in_line, Eingabe von der Anazhl aller Autos in der Warteschlange


    @return Rückgabe von dem erstellten Array, in dem die Werte gespeichert werden, 
*/

//int FUNCTION save_data(int *data, int *size, int occupied, int all, int cars_in_line);


/**

    @brief Es wird eine Tabelle in der Konsole ausgegeben 

    Es wird eine Tabelle erstellt, welche 10 Spalten und 8 Zeilen hat. 

    In diesem Abständen wird die Tabelle geliedert, wird in jeweils einzehtel von den Gesamtschritten gegliedert und
    in Form von 10 Schritten dargestellt. 

    Als Wert dargestellt werdem soll die Füllmenge, die Anzahl der Autos insgesamt, im Parkhaus und in der Wartschlange,
    sowie die Anzahl der freien Parkplätze und Rate.
    Um die Werte zu Erhalten, werden die Daten aus dem Array von der Funktion save_data(), ausgelesen. Um Rate zu erhälten
    wird mit der Anazhl der Autos die Funktion rate() aufgerufen. 


    @param[in] data[], Eingabe des Speicherbestandes aus der Funktion save_data()
    @param[in] size, Eingabe der Anzahl der Einträge des Arrays

    @return Es wird in der Kosole ausgegeben und in einem externen Dokument Auswertung.txt dargestellt, 
            aber kein direkter return Wert, da die Funktion den Datentyp void hat.
*/

//void FUNCTION tabel(int data[], int size);


/**

    @brief Es wird ein Säulendiagram in der Konsole ausgegeben 


    Es wird ein Säulendiagram erstellt. Auf der X-Achse werden 10 Zeitpunkte dargestellt, diese werden einzehntel von 
    der gesamnt Anzahl der Zeitschritte sein. 
    Auf der Y-Achse wird von 0 bis 100 in Prozent skaliert. 
    Als Wert pro Zeitschritt wird die Füllmenge dargestellt, welche aus dem Array von der Funktion save_data() entnommen wird.

    @param[in] data[], Eingabe des Speicherbestandes aus der Funktion save_data()
    @param[in] size, Eingabe der Anzahl der Einträge des Arrays

    @return Es wird ein Säulendiagram in der Konsole Ausgegeben und in einem externen Dokument Auswertung.txt dargestellt, 
            aber kein direkter return Wert, da die Funktion den Datentyp void hat.
*/

//void FUNCTION column_chart(int data[], int size);


/**

    @brief Es wird ein Balkendiagram in der Konsole ausgegeben 


    Es wird ein Balkendiagram erstellt. Auf der Y-Achse werden 10 Zeitpunkte dargestellt, diese werden einzehntel von 
    der gesamnt Anzahl der Zeitschritte sein. 



    @param[in] data[], Eingabe des Speicherbestandes aus der Funktion save_data()
    @param[in] size, Eingabe der Anzahl der Einträge des Arrays

    @return Es wird ein Balkendiagram in der Konsole und in einem externen Dokument Auswertung.txt Ausgegeben, 
            aber kein direkter return Wert, da die Funktion den Datentyp void hat.
*/

//void FUNCTION bar_chart(int data[], int size);

/**

    @brief Es wird jeweils der höchste Wert ausgegeben


    Es wird für jeden von den % Werten, der in save_data gespeichert wurde, der max wert ermittelt.
    Dies wird dann Formatiert ausgegeben. Ebenfalls wird beurteilt, ob eine Bauliche Erweiterung emphfohlen wird

    @param[in] data[], Eingabe des Speicherbestandes aus der Funktion save_data()
    @param[in] size, Eingabe der Anzahl der Einträge des Arrays

    @return Es wird in der Kosole ausgegeben und in einem externen Dokument Auswertung.txt dargestellt, 
            aber kein direkter return Wert, da die Funktion den Datentyp void hat 
*/

//void FUNCTION out_maxval(int data[], int size);

//#endif
