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

    char name[] = {"Anazhl der Stellplätze", "Maximale Parkdauer eines Autos", "Simuationsdauer, also die Zeitschritte,", "Ankunftswahrscheinlichkeit in % (mind. 1%)", "Zufalls-Seed"}
    int *parameter_int[] = {spaces, 0, size, 0, seed}                               // Array zum Durchlauf der int Parameter
    float *parameter_float[] = {0, max_parking, 0, chance_of_new_cars, seed}        // Array zum Durchlauf der float Parameter

    FOR i<-0 TO 4 DO
        IF (i == 0 || i == 2) THEN                                      // Frage nach spaces oder size
            OUTPUT Bitte geben Sie die name[i] an
            IF scanf(%d, parameter_int[i]) != 1 THEN                    // Falscher Input kontrolle
                OUTPUT Ungültige Eingabe, bitte Wiederholen.
                i = i - 1                                               // Es wird erneut nach dem Wert gefragt
            END IF
        END IF 
        IF (i == 1 || i == 3) THEN                                      // Frage nach max_parking oder chance_of_new_cars da float
            OUTPUT Bitte geben Sie die name[i] an   
            IF scanf(%f, parameter_float[i]) != 1 THEN
                OUTPUT Ungültige Eingabe, bitte Wiederholen.
                i = i - 1
            END IF
        END IF 
        IF (i == 4) THEN                                                // Änderung des Anfänglichen Outputs, passt zum Satzbau für Zufalls-Seed besser
            OUTPUT Bitte geben Sie einen name[i] an
            IF scanf(%d, parameter_int[i]) != 1 THEN
                OUTPUT Ungültige Eingabe, bitte Wiederholen.
                i = i - 1
            END IF
        END IF 
END FUNCTION 

*/