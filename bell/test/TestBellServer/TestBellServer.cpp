#include <Arduino.h>
#include <unity.h>
#include <stdio.h>

#include "Manager/AcousticOfficeBellManager.h"
#include "BellServer.h"
#include "Utils/Port.h"


/**
 * @brief Tests for BellServer
 * 
 * @author Tom Gaßmann
 * @version 1.0
 * 
 */

BellServer server;

void setUp() {
    std::shared_ptr<BellManagerAbstraction> manager = std::make_shared<AcousticOfficeBellManager>(Duration(500, Duration::MILLISECOND));
    server = BellServer();
    server.init(manager, Port(3000));
}

void tearDown() {
}

void testStartAndStop() {
    server.startBellServer("Gassi2", "Das15tM3in3S1");
    delay(4000);
    server.stopBellServer();
}

void setup() {
    delay(2000);
    UNITY_BEGIN();
    // RUN_TEST(testStartAndStop); test doesn't make sence 
    UNITY_END();
}

void loop() {
    // not neccessary
    }

