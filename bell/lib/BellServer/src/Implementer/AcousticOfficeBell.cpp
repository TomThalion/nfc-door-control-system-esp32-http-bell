#include <Arduino.h>
#include <memory>
#include "Implementer/AcousticOfficeBell.h"

/**
 * @file AcousticOfficeBell.cpp
 * @author Tom Gaßmann
 * @brief Implementation of AcousticOfficeBell
 * Uses Pin 4 as an Output
 * @version 1.0
 * 
 */
AcousticOfficeBell::AcousticOfficeBell(Duration duration) 
: SimpleBell(duration, 4){   
}
