/*
 *  File: test_queue.c
 *  Description: In test_queue.c werden die Funktionen der src-Datei queue.c getestet.
 */


 #ifdef DEBUG
 
#include <assert.h>

//Alle eigenen include Dateien einbinden
#include "../include/cars.h"
#include "../include/parameter.h"
#include "../include/parking_garage.h"
#include "../include/queue.h"
#include "../include/statistics.h"


int test_queue()
{
//Tests für queue.c:
    //Tests für queue_init()
    Queue *test_queue2 = queue_init();
    assert(test_queue2 != NULL);                                //Queue überprüfen
    assert(queue_get_size(test_queue2) == 0);                   //Größe der Queue überprüfen

    //Tests für queue_get_size()
    assert(queue_get_size(test_queue2) == 0);
    struct car test_car_six;
    assert(queue_enqueue(test_queue2, &test_car_six) == 0);
    assert(queue_get_size(test_queue2) == 1);
    assert(queue_get_size(NULL) == -1);

    //Tests für queue_enqueue()
    assert(queue_enqueue(NULL, &test_car_six) == -1);
    assert(queue_enqueue(test_queue2, NULL) == -1);

    //Tests für queue_dequeue()
    assert(queue_dequeue(NULL) == NULL);
    assert(queue_dequeue(test_queue2) == &test_car_six);
    assert(queue_dequeue(test_queue2) == NULL);

    return 0; //Tests bestanden
}

#endif