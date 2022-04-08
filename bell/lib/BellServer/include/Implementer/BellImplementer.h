#ifndef BELL_IMPLEMENTER
#define BELL_IMPLEMENTER

#include "Utils/Duration.h"

/**
 * @brief An interface of a Bell
 * 
 * @author Tom Gaßmann
 * @version 1.0
 */
class BellImplementer {

public:
    /**
     * @brief Rings the bell
     * 
     * @return int return = 0 on success, otherwise return = -1;
     */
    virtual int ring() = 0;

    /**
     * @brief Stop ringing the bell, if its ringing. If the bell doesn't ring nothing happens
     * 
     * @return int return = 0 on success, otherwise return = -1
     */
    virtual int stopRing() = 0;

};
#endif