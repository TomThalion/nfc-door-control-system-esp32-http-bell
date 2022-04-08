#ifndef TEST_BELL_MANAGER_H
#define TEST_BELL_MANAGER_H

#include "Manager/BellManagerAbstraction.h"
#include "TestingBell.h"
#include <memory>

/**
 * @brief Represents an Bellmanager, which increases and decreases ints for testing instead of riging a real bell
 * 
 * @author Tom Gaßmann
 * @version 1.0
 */
class BellManagerForTesting : public BellManagerAbstraction {

public:
    /**
     * @brief Construct a new Arcustic Office Bell Manager object
     * 
     */
    BellManagerForTesting(std::shared_ptr<TestingBell> bell);
};
#endif