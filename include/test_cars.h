#ifndef TEST_CARS_H
#define TEST_CARS_H

#ifndef ASSERT_H
    #define ASSERT_H
    #include <assert.h>
#endif

//Alle eigenen include Dateien einbinden
#include "cars.h"
#include "parameter.h"
#include "parking_garage.h"
#include "queue.h"
#include "statistics.h"

#include "test_queue.h"


int test_cars(void);
/**
* @brief unit tests for cars.c
*
*
* @param[out] 0 Wenn ohne Fehler durchgelaufen

* @return 0 Wenn ohne Fehler durchgelaufen
*/

#endif