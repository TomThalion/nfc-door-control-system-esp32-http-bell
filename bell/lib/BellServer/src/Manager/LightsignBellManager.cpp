#include "Manager/LightsignBellManager.h"



/**
 * @file LightsignBellManager.cpp
 * @author Tom Gaßmann
 * @brief Implementation of LightsignBellManager
 * @version 1.0
 * 
 */
LightsignBellManager::LightsignBellManager(Duration duration) {
    this->bell = std::make_shared<LightsignBell>(duration);
}