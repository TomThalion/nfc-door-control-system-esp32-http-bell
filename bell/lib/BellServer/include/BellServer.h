#ifndef BELL_SERVER_H
#define BELL_SERVER_H

#include "Manager/EventManager.h"
#include <memory>
#include "Utils/Port.h"
#include "ESPAsyncWebServer.h"
#include <string>



/**
 * @brief Represents an BellServer, which receives posts from The midware,
 * specified in the API documentation,
 * and transmitts received Events to a given EventManager
 * 
 * @author Tom Gaßmann
 * @version 1.0
 */
class BellServer {

public:
    /**
     * @brief Construct a new BellServer object
     * -
     * @param manager given manager object to transmitt the Events
     * @param port the port for the server
     */
    BellServer();

    /**
     * @brief Initialize the BellServer object
     * -
     * @param manager given manager object to transmitt the Events
     * @param port the port for the server
     */
    int init(std::shared_ptr<EventManager> manager, Port port);

    /**
     * @brief Starts the BellServer
     * 
     * 
     * @param ssid name of the wifi the server will try to connect to
     * @param password the passwort of the wifi
     * @return int return = 0 on success, otherwise return = -1
     */
    int startBellServer(std::string ssid,std::string password);

    /**
     * @brief Stops the BellServer
     */
    void stopBellServer();

private:
    std::shared_ptr<EventManager> manager;
    std::shared_ptr<AsyncWebServer> server;
};

#endif