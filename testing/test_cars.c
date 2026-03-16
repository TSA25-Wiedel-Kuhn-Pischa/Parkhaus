/*
 *  File: test_cars.c
 *  Description: In test_cars.c werden die Funktionen der src-Datei cars.c getestet.
 */


 #ifdef DEBUG
 printf("Debug-Modus aktiv\n");

#include "../include/test_queue.h"
#include "../include/test_cars.h"

int test_cars()
{
 // Tests für cars.c:

    //Tests für create_car()
    struct car test_car_one;
    Queue *test_queue = queue_init();
    assert(test_queue != NULL);                                 //Queue überprüfen
    assert(queue_get_size(test_queue) == 0);                    //Größe der Queue überprüfen
    assert(create_car(120, 0, &test_car_one, test_queue) == 0);
    assert(test_car_one.car_id > 0);                            //car_id überprüfen
    assert(test_car_one.parking_duration > 0);                  //Parkdauer überprüfen
    assert(test_car_one.ps > 0);                                //PS überprüfen
    assert(test_car_one.brand[0] != '\0');                      //Marke überprüfen
    assert(test_car_one.modelname[0] != '\0');                  //Modellname überprüfen
    
    struct car test_car_two;
    assert(create_car(80, 3, &test_car_two, test_queue) == 0);
    assert(test_car_two.car_id > 0);                            //car_id überprüfen
    assert(test_car_two.parking_duration > 0);                  //Parkdauer überprüfen
    assert(test_car_two.ps > 0);                                //PS überprüfen
    assert(test_car_two.brand[0] != '\0');                      //Marke überprüfen
    assert(test_car_two.modelname[0] != '\0');                  //Modellname überprüfen

    //falsche Inputs für create_car()
    struct car test_car_three;
    assert(create_car(80, -1, &test_car_three, test_queue) == -1);
    struct car test_car_four;
    assert(create_car(-5, 50, &test_car_four, test_queue) == -1);
    struct car test_car_five;
    assert(create_car(80, -1, &test_car_five, NULL) == -1);
    assert(create_car(83, 50, NULL, test_queue) == -1);

    //Tests für car_id_counter()
    int id1 = car_id_counter();
    int id2 = car_id_counter();
    assert(id2 == id1 + 1);
    id2 = car_id_counter();
    id2 = car_id_counter();
    id2 = car_id_counter();
    assert(id2 == id1 + 4);

    //Tests für randomize_parking_duration()
    assert(randomize_parking_duration(120) > 0);
    assert(randomize_parking_duration(0) == -1);
    assert(randomize_parking_duration(-5) == -1);

    return 0; //Tests bestanden
}

#endif