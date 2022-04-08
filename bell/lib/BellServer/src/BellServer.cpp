#include <ESPAsyncWebServer.h>
#include <WiFi.h>
#include <Arduino.h>
#include <string>
#include "BellServer.h"
#include "Utils/Port.h"
#include "Utils/Event.h"



BellServer::BellServer()
{
}

int BellServer::init(std::shared_ptr<EventManager> manager,Port a) {
  this->manager = manager;
  this->server = std::make_shared<AsyncWebServer>((uint16_t)a.getPort());
  return 0;
}

int BellServer::startBellServer(std::string ssid,std::string password) {

    Serial.begin(9600);
    auto status = WiFi.begin(ssid.c_str(), password.c_str());
    while((status = WiFi.status()) != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi..");
        Serial.println((int)status);
    }
    Serial.println("Connected");
    Serial.println("Local IP: " + WiFi.localIP().toString());
    server->on("/subscriber/bell/", HTTP_POST, [this](AsyncWebServerRequest *request) {
        //Serial.println("BELL_RINGS");
        manager->manageEvent(Event::BELL_RINGS);
        request->send(200);
    });

    /*server->on("/hello", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(200, "text/plain", "helloWorld");
    });
    */

    server->on("/subscriber/door/", HTTP_POST, [this](AsyncWebServerRequest *request) {
        //Serial.println("DOOR_OPEN");
        manager->manageEvent(Event::DOOR_OPEN);
        request->send(200);
    });

    server->begin();

    return 0;
}

void BellServer::stopBellServer() {
    server->end();
}


