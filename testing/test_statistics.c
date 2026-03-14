/**  
    Datei: test_statistics.h
    Beschreibung: Beschreibung aller Funktionen zum Testen von statistics.c
*/
#include "../include/test_statistics.h"
#include "../include/statistics.h"
#include <assert.h>

int test_statistics()
{
    //Unit Tests für statistics 

    // Test für fullness():

    //Zugelassene Werte:
    assert(fullness(0, 10) == 0); 
    assert(fullness(5, 10) == 50);
    assert(fullness(10,10) == 100);

    // Nicht zugelassene Werte:
    assert(fullness(-1, 10) == -1);
    assert(fullness(2, 0) == -1);
    assert(fullness(8, 5) == -1);

    // Test für rate()
    
    //zugelassene Werte:
    int zwischenspeicher = 0;
    assert(rate(0, 10, &zwischenspeicher) == 0);
    assert(rate(20, 10, &zwischenspeicher) == 0);
    assert(rate(0, 0, &zwischenspeicher) == 0);

    // Nicht zugelassene Werte:
    assert(rate(-1, 10, &zwischenspeicher) == -1);
    assert(rate(1, -2, &zwischenspeicher) == -1);
    assert(rate(-1, -10, &zwischenspeicher) == -1);
}