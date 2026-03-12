/**  
    Datei: statistics.h
    Beschreibung: Zusammenfassung aller Funktionen zur Ausgabe und Berechnung der Statistiken.
*/
#ifndef STATISTICS
#define STATISTICS

#include <stdio.h>
#include <stdlib.h>
/**

*
*    @brief Es wird berechnet, wie voll das Parkhaus in Prozent ist.
*
*    Es wird die Anzahl der Belegten Parkplätze durch die Anazhl aller Parkplätze gerechnet und mit 100 multipliziert um einen 
*    Prozentwert zu erhalten. 
*
*    @param[in] occupied, Eingabe von der Anzahl der besetzten Parkplätze 
*    @param[in] all_spaces, Eingabe von der Anazhl aller Parkplätze 
*
*    @return Es wird der berechnete Wert zurück gegeben
*/

int fullness(int occupied, int all_spaces);

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

int rate(int count_now, int count_before);

/**
*
*    @brief Es wird ein Dateikopf für die externe datei erstellt
*
*    Es wird in der externen .txt Datei eine kurz übersicht zu den eingebenen Parametern erstellt.
*
*    @param[in] spaces, Eingabe Anzahl der Stellplätze
*    @param[in] max_parking, Eingabe Maximale Parkdauer
*    @param[in] size, Eingabe Simulationsdauer (Zeitschritte)
*    @param[in] chance_of_new_cars, Eingabe Ankunftswahrscheinlichkeit neuer Fahrzeuge in %
*    @param[in] seed, Eingabe Zufalls-Seed für reprudzierbare Simulation
*    @param[in] document, Eingabe der .txt Datein für die der Header erzeugt werden soll
*
*    @return Es wird in einem externen Dokument Auswertung.txt dargestellt, 
*            aber kein direkter return Wert, da die Funktion den Datentyp void hat.
*/

void head_document(int spaces, int max_parking, int size, int chance_of_new_cras, int seed, FILE* document);
/**
*
*    @brief Es werden in der Konsole die aktuellen Daten ausgegeben
*
*    Es wird der berechnete Werte von der Funktion fullness, sowie die Anzahl der Autos im Parkhaus, in der möglichen 
*    Warteschlange und Insgesamt ausgegeben, und auch die Anzahl der freien Parkplätze.
*    All dies wird mit dem aktuellen Zeitschritt in der Konsole ausgegeben
*
*    @param[in] free_spaces, Eingabe von der Anzahl der besetzten Parkplätze 
*    @param[in] all_spaces, Eingabe von der Anazhl aller Parkplätze
*    @param[in] cars_in_line, Eingabe von der Anazhl aller Autos in der Warteschlange
*    @param[in] daten, Eingabe des Pointers für die Datei in die geschrieben werden soll
*
*    @return Ausgabe von den aktuellen Werten ind der Konsole und dem extra .txt Dokument
             Funktion an sich hat keinen return Wert.
*/


void output_data(int free_spaces, int all_spaces, int cars_in_line, FILE* daten);


/**
*
*    @brief Es werden die Daten von dem aktuellen Zeitpunkt gespeichert
*
*    Es werden die berechneten Werte, von fullness und den belegte Parkplätzen, sowie die Anzahl der freien Parkplätze im Parkhaus, 
*    die Anzahl der Autos in der möglichen Warteschlange und Insgesamt, an dem aktuellen Zeitschritt gespeichert. 
*
*
*    @param[in/out] *save_data, Eingabe des vorherigen Speicherbestandes 
*    @param[in/out] *size, Eingabe der größe des Arrays
*
*    @param[in] free_spaces, Eingabe von der Anzahl der freien Parkplätze 
*    @param[in] all_spaces, Eingabe von der Anazhl aller Parkplätze
*    @param[in] cars_in_line, Eingabe von der Anazhl aller Autos in der Warteschlange
*
*
*    @return Es wird nichts zurückgegeben 
*/

void save_data(int *save_data, int size, int free_spaces, int all_spaces, int cars_in_line);

//*************************************************
// Hilfsfunktionen für tabel()

/**
*
*    @brief Es wird die Tabelle erzeugt 
*
*    Die Funktion gibt geordnet alle sortierten Werte in einer Tabelle aus.
*
*
*    @param[in] info[], Eingabe der sortierten Werte
*    @param[in] auswertung, Eingabe des Pointers für die Datei in die geschrieben werden soll
*
*    @return Es wird in der Kosole ausgegeben und in einem externen Dokument Auswertung.txt dargestellt, 
*            aber kein direkter return Wert, da die Funktion den Datentyp void hat.
*/

void tabel_creation(int info[], FILE* auswertung);

/**
*
*    @brief Es wird eine Legende für die Tabelle erzeugt 
*
*    Die Funktion gibt die Zeitschritte zu der Tabelle aus, sowie welche Zeile welchen Wert entspricht.
*
*
*    @param[in] steps_x, Eingabe der Schrittweite der X-Achse
*    @param[in] size_ary, Eingabe der Anzahl der Einträge des Arrays
*    @param[in] auswertung, Eingabe des Pointers für die Datei in die geschrieben werden soll
*
*    @return Es wird in der Kosole ausgegeben und in einem externen Dokument Auswertung.txt dargestellt, 
*            aber kein direkter return Wert, da die Funktion den Datentyp void hat.
*/

void tabel_legend(int steps_x, int size_ary, FILE* auswertung);

//*************************************************

/**
*
*    @brief Es wird eine Tabelle in der Konsole ausgegeben 
*
*    Es wird eine Tabelle erstellt, welche 10 Spalten und 8 Zeilen hat. 
*
*    In diesem Abständen wird die Tabelle geliedert, wird in jeweils einzehtel von den Gesamtschritten gegliedert und
*    in Form von 10 Schritten dargestellt. 
*
*    Als Wert dargestellt werdem soll die Füllmenge, die Anzahl der Autos insgesamt, im Parkhaus und in der Wartschlange,
*    sowie die Anzahl der freien Parkplätze und Rate.
*    Um die Werte zu Erhalten, werden die Daten aus dem Array von der Funktion save_data(), ausgelesen. Um Rate zu erhälten
*    wird mit der Anazhl der Autos die Funktion rate() aufgerufen. 
*
*
*    @param[in] data[], Eingabe des Speicherbestandes aus der Funktion save_data()
*    @param[in] size_ary, Eingabe der Anzahl der Einträge des Arrays
*    @param[in] auswertung, Eingabe des Pointers für die Datei in die geschrieben werden soll
*
*    @return Es wird in der Kosole ausgegeben und in einem externen Dokument Auswertung.txt dargestellt, 
*            aber kein direkter return Wert, da die Funktion den Datentyp void hat.
*/

void tabel(int data[], int size_ary, FILE* auswertung);

//*************************************************
// Hilfsfunktionen für column_chart()

/**
*
*    @brief Es wird ein Säulendiagramm erstellt
*
*
*    Es wird ein Säulendiagram erstellt, welches dann in der Konsole und einem extra Document ausgegeben wird
*
*    @param[in] info[], Eingabe des Speicherbestandes aus der Funktion save_data()
*    @param[in] auswertung, Eingabe des Pointers für die Datei in die geschrieben werden soll
*
*    @return Es wird ein Säulendiagram in der Konsole Ausgegeben und in einem externen Dokument Auswertung.txt dargestellt, 
*            aber kein direkter return Wert, da die Funktion den Datentyp void hat.
*/

void column_chart_creation(int info[], FILE* auswertung);

/**
*
*    @brief Es wird eine Legende erstellt
*
*
*    Es wird eine Legende zum Säuelndiagramm mit Hilfe von Schleifen erzeugt.
*
*    @param[in] steps_x, Eingabe der Schrittweite an der X-Achse
*    @param[in] size_ary, Eingabe der größe des Arrays
*    @param[in] auswertung, Eingabe des Pointers für die Datei in die geschrieben werden soll
*
*    @return Es wird eine Legende zum Säulendiagramm in der Konsole ausgegeben 
*/

void column_chart_legend(int steps_x, int size_ary, FILE* auswertung);

//*************************************************

/**
*
*    @brief Es wird ein Säulendiagram in der Konsole und einem extra Document ausgegeben 
*
*
*    Es wird ein Säulendiagram erstellt. Auf der X-Achse werden 10 Zeitpunkte dargestellt, diese werden einzehntel von 
*    der gesamnt Anzahl der Zeitschritte sein. 
*    Auf der Y-Achse wird von 0 bis 100 in Prozent skaliert. 
*    Als Wert pro Zeitschritt wird die Füllmenge dargestellt, welche aus dem Array von der Funktion save_data() entnommen wird.
*
*    @param[in] data[], Eingabe des Speicherbestandes aus der Funktion save_data()
*    @param[in] size_ary, Eingabe der Anzahl der Einträge des Arrays
*    @param[in] auswertung, Eingabe des Pointers für die Datei in die geschrieben werden soll
*
*    @return Es wird ein Säulendiagram in der Konsole Ausgegeben und in einem externen Dokument Auswertung.txt dargestellt, 
*            aber kein direkter return Wert, da die Funktion den Datentyp void hat.
*/

void column_chart(int data[], int size_ary, FILE* auswertung);

/**
*
*    @brief Es wird ein Balkendiagramm erstellt
*
*
*    Es wird ein Balkendiagramm erstellt, welches dann in der Konsole und einem extra Document ausgegeben wird
*
*    @param[in] info[], Eingabe des Speicherbestandes aus der Funktion save_data()
*    @param[in] auswertung, Eingabe des Pointers für die Datei in die geschrieben werden soll
*
*    @return Es wird ein Balkendiagramm in der Konsole Ausgegeben und in einem externen Dokument Auswertung.txt dargestellt, 
*            aber kein direkter return Wert, da die Funktion den Datentyp void hat.
*/

void bar_chart_creation(int info[], FILE* auswertung);

/**
*
*    @brief Es wird eine Legende erstellt
*
*
*    Es wird eine Legende zum Balkendiagramm mit Hilfe von Schleifen erzeugt.
*
*    @param[in] steps_x, Eingabe der Schrittweite an der X-Achse
*    @param[in] size_ary, Eingabe der größe des Arrays
*    @param[in] auswertung, Eingabe des Pointers für die Datei in die geschrieben werden soll
*
*    @return Es wird eine Legende zum Balkendiagramm in der Konsole ausgegeben 
*/

void bar_chart_legend(int steps_x, int size_ary, FILE* auswertung);

/**
*
*    @brief Es wird ein Balkendiagram in der Konsole ausgegeben 
*
*
*    Es wird ein Balkendiagram erstellt. Auf der Y-Achse werden 10 Zeitpunkte dargestellt, diese werden einzehntel von 
*    der gesamnt Anzahl der Zeitschritte sein. 
*
*
*
*    @param[in] data[], Eingabe des Speicherbestandes aus der Funktion save_data()
*    @param[in] size_ary, Eingabe der Anzahl der Einträge des Arrays
*    @param[in] auswertung, Eingabe des Pointers für die Datei in die geschrieben werden soll
*
*    @return Es wird ein Balkendiagram in der Konsole und in einem externen Dokument Auswertung.txt Ausgegeben, 
*            aber kein direkter return Wert, da die Funktion den Datentyp void hat.
*/

void bar_chart(int data[], int size_ary, FILE* auswertung);

/**
*
*    @brief Es wird jeweils der höchste Wert ausgegeben
*
*
*    Es wird für jeden von den % Werten, der in save_data gespeichert wurde, der max wert ermittelt.
*    Dies wird dann Formatiert ausgegeben. Ebenfalls wird beurteilt, ob eine Bauliche Erweiterung emphfohlen wird
*
*    @param[in] data[], Eingabe des Speicherbestandes aus der Funktion save_data()
*    @param[in] size_ary, Eingabe der Anzahl der Einträge des Arrays
*    @param[in] auswertung, Eingabe des Pointers für die Datei in die geschrieben werden soll
*
*    @return Es wird in der Kosole ausgegeben und in einem externen Dokument Auswertung.txt dargestellt, 
*            aber kein direkter return Wert, da die Funktion den Datentyp void hat 
*/

void out_maxval(int data[], int size_ary, FILE* auswertung);

#endif

