/**  
    Datei: parameter.c
    Beschreibung: Genauere beschreibung der Funktion zur Eingabe der Parameter.
*/

#include "../include/parameter.h"
#include <stdio.h>

void input_parameter(int *spaces, float *max_parking, int *size, float *chance_of_new_cars, int *seed)
{
    char *name[] = {"Anzahl der Stellplätze", "Maximale Parkdauer eines Autos (in Simulationsschritten)", "Simulationsdauer, also die Zeitschritte,", "Ankunftswahrscheinlichkeit in %%", "Zufalls-Seed"};
    int *parameter_int[] = {spaces, 0, size, 0, seed};                               // Array zum Durchlauf der int Parameter
    float *parameter_float[] = {0, max_parking, 0, chance_of_new_cars, 0};        // Array zum Durchlauf der float Parameter

    for (int i = 0; i < 5; i++) 
    {
        if (i == 1)                                       // Frage nach max_parking 
        {
            printf("Bitte geben Sie die %s an: ", name[i]); 
            if (scanf("%f", parameter_float[i]) != 1 || *parameter_float[i] <= 0)
            {
                printf("\nUngültige Eingabe, bitte Wiederholen. \n\n");
                i--;
                while(getchar() != '\n');
            }
        }
        if (i == 0 || i == 2)                                     // Frage nach spaces oder size
        {
            printf("Bitte geben Sie die %s an: ", name[i]); 
            if (scanf("%d", parameter_int[i]) != 1 || *parameter_int[i] <= 0)                    // Falscher Input kontrolle
            {
                printf("\nUngültige Eingabe, bitte Wiederholen.\n\n"); 
                i--;                                               // Es wird erneut nach dem Wert gefragt
                while(getchar() != '\n');                          // Die vorherig eingelesenen Werte werden gelöscht 
            }
            if (*max_parking > *size)
            {
                printf("\nUngültige Eingabe, die Simulationsdauer darf nicht kleiner als die Parkdauer sein. \nBitte Wiederholen.\n\n"); 
                i--;                                               // Es wird erneut nach dem Wert gefragt
                while(getchar() != '\n');                          // Die vorherig eingelesenen Werte werden gelöscht  
            }
        } 
        if (i == 3)                                                // Frage nach chance_of_new_cars 
        {
            printf("Bitte geben Sie die %s an: ", name[i]); 
            if (scanf("%f", parameter_float[i]) != 1 || *parameter_float[i] < 0 || *parameter_float[i] > (float)100)
            {
                printf("\nUngültige Eingabe, bitte Wiederholen. \n\n");
                i--;
                while(getchar() != '\n');
            }
        }
        if (i == 4)                                                 // Änderung des Anfänglichen Outputs, passt zum Satzbau für Zufalls-Seed besser
        {
            printf("Bitte geben Sie einen %s an: ", name[i]);
            if (scanf("%d", parameter_int[i]) != 1 || *parameter_int[i] <= 0) 
            {
                printf("\nUngültige Eingabe, bitte Wiederholen. \n\n"); 
                i--;
                while(getchar() != '\n');
            }
        }
    }
}

/*
Da diese Funktion Fehler selber Korigiert und 
erst Weiter macht, wenn ein gültiger Wert eingegeben wird.
Ist kein Unit-Test nötig.
*/