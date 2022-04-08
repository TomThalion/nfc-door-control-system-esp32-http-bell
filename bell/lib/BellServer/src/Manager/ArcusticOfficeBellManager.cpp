#include "Manager/AcousticOfficeBellManager.h"


/**
 * @file AcousticOfficeBellManager.cpp
 * @author Tom Gaßmann
 * @brief Implementation of AcousticOfficeBellManager
 * @version 1.0
 * 
 */
AcousticOfficeBellManager::AcousticOfficeBellManager(Duration duration) {
    this->bell =std::make_shared<AcousticOfficeBell>(duration);
}