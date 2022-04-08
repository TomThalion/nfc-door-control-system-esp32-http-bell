#ifndef LIGHTSIGN_BELL_H
#define LIGHTSIGN_BELL_H

#include <Arduino.h>
#include "SimpleBell.h"

/**
 * @brief A special implementation of a Bell, which represents a Lightsign Bell.
 * Should be able to set an reset the output of the micro controller suitable for the LightsignBell.
 * 
 * Uses Pin 2 for LED controll
 * 
 * @author Tom Gaßmann
 * @version 1.0
 */
class LightsignBell : public SimpleBell {
public:

    /**
     * @brief Construct a new Lightsign Bell object
     * 
     * @param duration the specified duration
     */
    LightsignBell(Duration duration);

    /**
     * @brief Destroy the Lightsign Bell object
     * 
     */
    virtual ~LightsignBell() = default;
};
#endif