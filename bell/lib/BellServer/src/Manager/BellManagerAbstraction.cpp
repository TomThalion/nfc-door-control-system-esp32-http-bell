#include "Manager/BellManagerAbstraction.h"
#include <Arduino.h>


/**
 * @file BellManagerAbstraction.cpp
 * @author Tom Gaßmann
 * @brief Implementation of BellManagerAbstraction
 * @version 1.0
 * 
 */
int BellManagerAbstraction::manageEvent(Event event) {
    switch (event) {
    case DOOR_OPEN:
        if(doorCount < 3) {
            bell->stopRing();
            doorCount++;
        } else {
            Serial.printf("Door post rate-limit reached\n");
        }
        break;
    case BELL_RINGS:
        if(bellCount < 3) {
            bell->ring();
            bellCount++;
        } else {
             Serial.printf("Bell post rate-limit reached\n");
        }
        break;
    default:
        return -1;
        break;
    }
    return 0;
}

void BellManagerAbstraction::resetCount() {
    bellCount = 0;
    doorCount = 0;
}

