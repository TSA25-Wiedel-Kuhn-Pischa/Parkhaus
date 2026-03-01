/**  
    Datei: parameter.c
    Beschreibung: Genauere beschreibung der Funktion zur Eingabe der Parameter.
*/

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

/*void FUNCTION input_parameter(int *spaces, float *max_parking, int *size, float *chance_of_new_cras, int *seed);

    char name[] = {"Anazhl der Stellplätze", "Maximale Parkdauer", "Simuationsdauer, also die Zeitschritte,", "Ankunftswahrscheinlichkeit in % (mind. 1%)", "eingabe eines Zufalls-Seed"}
    int *parameter_int[] = {spaces, 0, size, 0, seed}
    float *parameter_float[] = {0, max_parking, 0, chance_of_new_cars, seed}

    FOR i<-0 TO 4 DO
        IF (i == 0 || i == 2) THEN 
            OUTPUT Bitte geben Sie die name[i] an
             
        END IF 

END FUNCTION 

*/