#include "Utils/Port.h"



/**
 * @file Port.cpp
 * @author Tom Gaßmann
 * @brief Implementation of Port
 * @version 1.0
 * 
 */
Port::Port(int port) {
    this->port = port;
}

int Port::getPort() {
    return this->port;
}

void Port::setPort(int port) {
    this->port = port;
}