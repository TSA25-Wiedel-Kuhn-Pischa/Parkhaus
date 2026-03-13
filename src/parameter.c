/**  
    Datei: parameter.c
    Beschreibung: Genauere beschreibung der Funktion zur Eingabe der Parameter.
*/

void input_parameter(int *spaces, float *max_parking, int *size, float *chance_of_new_cars, int *seed)
{
    char name[] = {"Anazhl der Stellplätze", "Maximale Parkdauer eines Autos", "Simuationsdauer, also die Zeitschritte,", "Ankunftswahrscheinlichkeit in %% (mind. 1%%)", "Zufalls-Seed"};
    int *parameter_int[] = {spaces, 0, size, 0, seed};                               // Array zum Durchlauf der int Parameter
    float *parameter_float[] = {0, max_parking, 0, chance_of_new_cars, 0};        // Array zum Durchlauf der float Parameter

    for (int i = 0; i < 5; i++) 
    {
        if (i == 0 || i == 2)                                     // Frage nach spaces oder size
        {
            printf("Bitte geben Sie die %s an: ", name[i]); 
            if (scanf("%d", parameter_int[i]) != 1)                    // Falscher Input kontrolle
            {
                printf("Ungültige Eingabe, bitte Wiederholen.\n"); 
                i--;                                               // Es wird erneut nach dem Wert gefragt
            }
        } 
        if (i == 1 || i == 3)                                       // Frage nach max_parking oder chance_of_new_cars da float
        {
            printf("Bitte geben Sie die %s an: ", name[i]); 
            IF INPUT scanf(%f, parameter_float[i]) != 1 THEN
                OUTPUT Ungültige Eingabe, bitte Wiederholen.
                i = i - 1
            END IF
        }
        IF (i == 4) THEN                                                // Änderung des Anfänglichen Outputs, passt zum Satzbau für Zufalls-Seed besser
            OUTPUT Bitte geben Sie einen name[i] an
            IF INPUT scanf(%d, parameter_int[i]) != 1 THEN
                OUTPUT Ungültige Eingabe, bitte Wiederholen.
                i = i - 1
            END IF
        END IF 
    }
}