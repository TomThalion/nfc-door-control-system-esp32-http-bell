#ifndef TESTING_BELL
#define TESTING_BELL

#include "Implementer/BellImplementer.h"


/**
 * @brief An testingimplementtaion of an Bell
 * 
 * @author Tom Gaßmann
 * @version 1.0
 */
class TestingBell: public BellImplementer {

public:

    /**
     * @brief Construct a new Testing Bell object
     * 
     */
    TestingBell();

    /**
     * @brief Rings the bell
     * 
     * @return int return = 0 on success, otherwise return = -1;
     */
    int ring() ;

    /**
     * @brief Stop ringing the bell, if its ringing. If the bell doesn't ring nothing happens
     * 
     * @return int return = 0 on success, otherwise return = -1
     */
    int stopRing();

int ringCount;
};
#endif