#include <unity.h>
#include <Arduino.h>

#include "Utils/Port.h"


/**
 * @brief Tests for Port
 * 
 * @author Tom Gaßmann
 * @version 1.0
 */
void tearDown() {
}

void testSetAndGetPort() {
    int p = 3000;
    Port port = Port(p);

    TEST_ASSERT_EQUAL(p, port.getPort());
    p = 10;
    port.setPort(p);

    TEST_ASSERT_EQUAL(p, port.getPort());

}

void setup() {
    delay(2000);
    UNITY_BEGIN();

    RUN_TEST(testSetAndGetPort);

    UNITY_END();
}

void loop() {
    // not neccessary
}
