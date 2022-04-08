#include <Arduino.h>
#include <memory>
#include "Implementer/LightsignBell.h"

/**
 * @file LightsignBell.cpp
 * @author Tom Gaßmann
 * @brief Implementation of LightsignBell
 * Uses Pin 2 as Output
 * @version 1.0
 * 
 */
LightsignBell::LightsignBell(Duration duration) 
    : SimpleBell (duration, 2) {
}
