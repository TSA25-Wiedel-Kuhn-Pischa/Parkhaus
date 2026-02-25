/**  
    Datei: reapeted_statistics.h
    Beschreibung: Zusammenfasung aller Funktionen zur Ausgabe und Berechnung der wiederholten Statistiken.
*/
//#ifndef REAPETED_STATISTICS
//#define REAPETED_STATISTICS
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

    @brief Es wird berechnet, wie viele Parkplätze noch frei sind

    Es wird die Anzahl aller Parkplätze minus die Anazhl der belegten Parkplätze gerechnet.

    @param[in] occupied, Eingabe von der Anzahl der besetzten Parkplätze 
    @param[in] all, Eingabe von der Anazhl aller Parkplätze 

    @return Es wird der berechnete Wert zurück gegeben
*/

//int Function free(int occupied, int all);

/**

    @brief Es wird berechnet, wie viele Autos seit dem letzten Zeitpunkt dazu gekommen sind 

    Es wird der Wert, die Anzahl der Autos, des vorherigen Aufrufes gespeichert und von der jetzigen Anzahl der Autos abgezogen.

    @param[in] count, Eingabe von der Anzahl der Autos im Parkhaus und ggf. davor 

    @return Es wird der berechnete Wert zurück gegeben
*/

//int Function rate(int count);

/**

    @brief Es werden in der Konsole die aktuellen Daten ausgegeben

    Es werden die berechneten Werte, fullnes und freie Parkplätze, sowie die Anzahl der Autos mit dem aktuellen 
    Zeitschritt in der Konsole ausgegeben

    @param[in] occupied, Eingabe von der Anzahl der besetzten Parkplätze 
    @param[in] all, Eingabe von der Anazhl aller Parkplätze

    @return Ausgabe von den aktuellen Werten 
*/

//int Function output_data(int occupied, int all);

/**

    @brief Es werden in der Konsole die aktuellen Daten ausgegeben

    Es werden die berechneten Werte, fullnes und freie Parkplätze, sowie die Anzahl der Autos mit dem aktuellen 
    Zeitschritt gespeichert 

    @param[in] occupied, Eingabe von der Anzahl der besetzten Parkplätze 
    @param[in] all, Eingabe von der Anazhl aller Parkplätze
*/

//int Function save_data(int occupied, int all);

/**

    @brief Es wird eine Tabelle in der Konsole ausgegeben 

    Es wird, wenn die Funktion das erste mal aufgerufen wird, eine Tabelle erstellt. Es wird der Zeitpunkt des Aufrufens 
    dargestellt, sowie in den Zeilen dadrunter die Angabe der Füllmenge, Anzahl der freien Parkplätze, die Anzahl der 
    Autos, sowie die Rate der hinein- und hinuasfahrenden Fahrzeuge. Nach dem ersten Aufruf wird für jeden Aufrauf, eine 
    neue Spalte dazu geschrieben. Dies wird in der Konsole ausgegeben.

    @param[in] occupied, Eingabe von der Anzahl der besetzten Parkplätze 
    @param[in] all, Eingabe von der Anazhl aller Parkplätze

    @return Es wird eine Tabelle in der Kosole ausgegeben
*/

//int Function tabel(int occupied, int all);

/**

    @brief Es wird ein Säulendiagram in der Konsole ausgegeben 

    Es wird, wenn die Funktion das erste mal aufgerufen wird, ein Säulendiagram erstellt. Es wird der Zeitpunkt des Aufrufens 
    auf der X-Achse dargestellt und auf der Y-Achse wird die Prozentanzahl dargestellt (Maximal 100%). 
    Nach dem ersten Aufruf wird für jeden Aufrauf, eine neue Säule ergänzt, um den Verlauf sehen zu können.

    @param[in] occupied, Eingabe von der Anzahl der besetzten Parkplätze 
    @param[in] all, Eingabe von der Anazhl aller Parkplätze 
    @param[in] time, Eingabe von dem Aktuellen Zeitpunkt

    @return Es wird ein Säulendiagram in der Konsole Ausgegeben
*/

//int Function column_chart(int occupied, int all, int time);

//#endif
