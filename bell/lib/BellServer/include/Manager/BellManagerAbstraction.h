#ifndef BELL_MANAGER_ABSTRACTION_H
#define BELL_MANAGER_ABSTRACTION_H


#include "EventManager.h"
#include "Implementer/BellImplementer.h"
#include "memory"

/**
 * @brief Represents an abstract Bellmanager, which manages a bell according to the given Events
 * 
 * @author Tom Gaßmann
 * @version 1.0
 */

class BellManagerAbstraction: public EventManager {
public:

    /**
     * @brief Construct a new Bell Manager Abstraction object
     * 
     */
    BellManagerAbstraction() = default;

    /**
     * @brief manages the given Event
     * 
     * @param event the given Event
     * @return int return = 0 on succes, return = -1 on any error
     */
    int manageEvent(Event event);

    /**
     * @brief reset The bell and door count which borders the number of post which are performed, to avoid spaming 
     * 
     */
    void resetCount();
    
protected:
    std::shared_ptr<BellImplementer> bell;
    int bellCount = 0;
    int doorCount = 0;
};
#endif