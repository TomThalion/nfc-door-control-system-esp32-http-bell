#ifndef EVENT_MANAGER
#define EVENT_MANAGER

#include "Utils/Event.h"

/**
 * @brief Represents an Eventmanger, which can manage some Events of the type Event
 * 
 * @author Tom Gaßmann
 * @version 1.0
 */
class EventManager {

public:
    /**
     * @brief manages the given Event
     * 
     * @param event the given Event
     * @return int return = 0 on succes, return = -1 on any error
     */
    virtual int manageEvent(Event event) = 0;
};
#endif