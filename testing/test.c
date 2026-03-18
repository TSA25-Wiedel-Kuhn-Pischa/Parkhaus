/*
 *  File: test.c
 *  Description: In test.c werden die Funktionen der src-Dateien getestet.
 */


#ifdef DEBUG
 

// Vorgefertigte Datein includieren
#include <assert.h>

// Alle eigenen include Dateien einbinden
#include "../include/cars.h"
#include "../include/parameter.h"
#include "../include/parking_garage.h"
#include "../include/queue.h"
#include "../include/statistics.h"

#include "../include/test_cars.h"
#include "../include/test_parking_garage.h"
#include "../include/test_queue.h"
#include "../include/test_statistics.h"


int main(void) {
    printf("Debug-Modus aktiv\n");

// Tests für cars.c:
    assert(test_cars() == 0);

// Tests für queue.c:
    assert(test_queue() == 0);

// Tests für parking_garage.c:
    int parking_spaces = 100;
    assert(test_parking_garage(parking_spaces) == 0);

// Tests für statistics.c:
    assert(test_statistics() == 0);

    printf("\nAlle Tests wurden erfolgreich bestanden.\n");
    return 0; //Tests bestanden
}

#endif
