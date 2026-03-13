#ifndef TEST_QUEUE_H
#define TEST_QUEUE_H

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

#include "test_cars.h"


int test_queue(void);
/**
* @brief unit tests for queue.c
*
*
* @param[out] 0 Wenn ohne Fehler durchgelaufen

* @return 0 Wenn ohne Fehler durchgelaufen
*/

#endif