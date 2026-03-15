/**  
    Datei: parameter.h
    Beschreibung: Beinhaltung der Funktionen zur Eingabe der Parameter.
*/

#ifndef PARAMETER
#define PARAMETER


/**

*
*    @brief Es wird eine Eingabemöglichkeit der Fuktionsparameter aufgerufen
*
*    Im Terminal wird für die jeweiligen Werte eine Abfrage gestellt gestellt. 
*    Dabei wird auch auf Fehleingaben überprüft und die Werte werden übergeben 
*
*    @param[in] *spaces, Eingabe Anzahl der Stellplätze
*    @param[in] *max_parking, Eingabe Maximale Parkdauer
*    @param[in] *size, Eingabe Simulationsdauer (Zeitschritte)
*    @param[in] *chance_of_new_cars, Eingabe Ankunftswahrscheinlichkeit neuer Fahrzeuge in %
*    @param[in] *seed, Eingabe Zufalls-Seed für reprudzierbare Simulation
*
*    @return Es wird garnichts zurückgegeben, da void funktion. Die Werte werden über ihre Adressen übergeben 
*/

void input_parameter(int *spaces, float *max_parking, int *size, float *chance_of_new_cars, int *seed);

#endif