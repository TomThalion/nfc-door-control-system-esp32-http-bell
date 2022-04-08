#ifndef LIGHTSIGN_BELL_MANAGER_H
#define LIGHTSIGN_BELL_MANAGER_H

#include "BellManagerAbstraction.h"
#include "Implementer/LightsignBell.h"

/**
 * @brief Represents an Bellmanager, which uses an LightsignBell 
 * 
 * @author Tom Gaßmann
 * @version 1.0
 */
class LightsignBellManager : public BellManagerAbstraction {

public:
    /**
     * @brief Construct a new Arcustic Office Bell Manager object
     * 
     */
    LightsignBellManager(Duration duration);
};
#endif