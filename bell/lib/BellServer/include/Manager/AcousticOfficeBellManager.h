#ifndef ARCUSTIC_OFFICE_BELL_MANAGER
#define ARCUSTIC_OFFICE_BELL_MANAGER

#include "BellManagerAbstraction.h"
#include "Implementer/AcousticOfficeBell.h"

/**
 * @brief Represents an Bellmanager, which uses an AcousticOfficeBell 
 * 
 * @author Tom Gaßmann
 * @version 1.0
 */
class AcousticOfficeBellManager : public BellManagerAbstraction {

public:
    /**
     * @brief Construct a new Arcustic Office Bell Manager object
     * 
     */
    AcousticOfficeBellManager(Duration duration);
};
#endif