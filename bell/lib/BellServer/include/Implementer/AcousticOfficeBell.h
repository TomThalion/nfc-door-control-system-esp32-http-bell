#ifndef ARCUSTIC_OFFICE_BELL_H
#define ARCUSTIC_OFFICE_BELL_H

#include <Arduino.h>
#include "SimpleBell.h"

/**
 * @brief A special implementation of a Bell, which represents a Bell which should be
 * able to set and reset the output of the microcontroller suitable for the ArcusticBell
 * in the TECO office
 * Uses pin 4 as output.
 * 
 * @author Tom Gaßmann
 * @version 1.0
 */
class AcousticOfficeBell : public SimpleBell {

public:
    
    /**
     * @brief Construct a new Acoustic Office Bell object
     * 
     * @param duration the specified duration
     */
    AcousticOfficeBell(Duration duration);

    /**
     * @brief Destroy the Acoustic Office Bell object
     * 
     */
    virtual ~AcousticOfficeBell() = default;
};
#endif