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

/* int Function rate(int count_now, count_before)
(
    int rate
    rate = count_now - count_before
    return rate
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
    In diesem werden die Werte fullness_data, free_data, occupied, cars_in_line, all_cars und gespeichert.
    Diese werden jeweils einen Schritt weiter im Array gespeichert. 

    Das Array wird zurückgegeben.
)
*/

/* int Function out_maxval(double Array[])
(
    Es wird eine Variable size_ary erstellt, welches mit sizeof die größe des Arrays ermittelt und durch sizeof von einem 
    Eintrag im Array teilt und dann wird durch 5 geteilt. Dadurch wird die Anzahl der Einträge ermittelt.

    Dann wird durch das Array von der jeweiligen Stelle für den Wert gegangen, indem die Stelle immer um 5 erhöht wird. 
    Zubeginn wird der erste Wert in einer Variable max_(indize für die Füllmenge, Anzahl der Autos, ...) gespeichet. 
    Danach wird in einer Schleife solange, um 5 Schritte weitergegangen, bis size_ary erreicht wird. Dabei wird jedesmal 
    geschaut, ob der jetzige Wert größer ist als max_..., wenn ja, dann erhält max_... diesen Wert.

    In der Konsole wird dann Ausgegeben: "Der Maxwert von ... beträgt: ...", für jeden Speichertyp, also für die 
    Füllmenge, Anzahl der Autos, ... .

    Gleichzeitig wird jede Ausgabe, die in die Konsole ausgegeben wurde, auch in eine extra .txt Datei geschrieben.
)

*/

/* int Function tabel(double Array[])
(
    Es wird eine Variable steps erstellt, in welcher die Abstände der Simulations Schritte gespeichert werden. 
    Dafür wird die Größe des übergebenen Arrays ermittelt und durch die größe eines einzelnen Eintrags gerechnet 
    und danach nochmal durch 10 und durch 5, weil es 5 eingegbene Werte gibt, es wird auch eine Funktion 
    zum Runden verwendet, um ganze Zahlen zu erhalten.

    Dann wird in einer Schleife das Array aufgerufen und zu den jeweiligen Abständen, mit dem Faktor 5, gestopt, um die Wert in ihnre Spezifischen 
    Themengebiete zu Speichern. Dafür werden 5 neue Arrays angelegt. Daduch das die Werte hinterinander in dem übergebenen 
    Array gespeichert wurden, kann die Stelle für jeden Wert um eins erhöht werden. Damit meine ich, das pro Zeitschritt 
    5 Werte, also 5 Schritte im Array, einzel gespeichert wurden und diese einzeln in unterschiedliche Arrays erneut gespeichert werden.
    Dabei ist der erste Ausgelesene Wert, der Wert an der Stelle 0 und 
    der letzte, an der Stelle vom letzte Simulationsschritt (also steps mal 10). 

    Danach werden, über printf und eine Schleife, die einzelnen Zeitschritte (10) in der Konsole ausgegeben.
    Dann folgt eine Trennungslinie in Form von "--------", zur Formatierung. 
    Dann wird das Array zu den Werten von der Füllmenge ausgegeben, dann wieder eine Linie und dann die nächsten Werte, 
    bis alle 5 Werte dargestellt wurden.

    Gleichzeitig wird jede Ausgabe, die in die Konsole ausgegeben wurde, auch in eine extra .txt Datei geschrieben.
)
*/

/* int Function column_chart(double Array[])
(
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
)

*/

/* int Function bar_chart(double Array[])
(
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
)
*/