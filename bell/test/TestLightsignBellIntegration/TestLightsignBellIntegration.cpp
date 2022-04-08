#include <Arduino.h>
#include <unity.h>
#include <memory>
#include "Manager/LightsignBellManager.h"
#include "Utils/Event.h"
#include "Utils/Duration.h"
#include "Utils/Event.h"

#define TESTDURATION 1000
#define BELL_PIN 2




/**
 * @brief Tests for Bell Manager
 * 
 * @author Tom Gaßmann
 * @version 1.0
 * 
 */

void setUp() {
}

void tearDown() {
   
}


void testDefault() {
    auto duration = Duration(TESTDURATION, Duration::MILLISECOND);
    auto manager = LightsignBellManager(duration);
    
    //should not ring by default
    TEST_ASSERT_EQUAL(LOW, digitalRead(BELL_PIN));
}


void testRing() {
    auto duration = Duration(TESTDURATION, Duration::MILLISECOND);
    auto manager = LightsignBellManager(duration);

    TEST_ASSERT_EQUAL(LOW, digitalRead(BELL_PIN));
    manager.manageEvent(Event::BELL_RINGS);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(BELL_PIN));
    delay(530);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(BELL_PIN));
    delay(530);
    // bell should have stoped ringing
    TEST_ASSERT_EQUAL(LOW, digitalRead(BELL_PIN));
}

void testDoorOpen() {
    auto duration = Duration(TESTDURATION, Duration::MILLISECOND);
    auto manager = LightsignBellManager(duration);

    TEST_ASSERT_EQUAL(LOW, digitalRead(BELL_PIN));
    manager.manageEvent(Event::BELL_RINGS);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(BELL_PIN));
    delay(530);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(BELL_PIN));
    manager.manageEvent(Event::DOOR_OPEN);
    // bell should have stoped ringing
    TEST_ASSERT_EQUAL(LOW, digitalRead(BELL_PIN));
}


void testEventError() {
    auto duration = Duration(TESTDURATION, Duration::MILLISECOND);
    auto manager = LightsignBellManager(duration);

    TEST_ASSERT_EQUAL(-1, manager.manageEvent(Event::ERROR_TEST));
    TEST_ASSERT_EQUAL(LOW, digitalRead(BELL_PIN));
}

void setup() {
    delay(2000);
    UNITY_BEGIN();

    RUN_TEST(testDefault);

    RUN_TEST(testRing);

    RUN_TEST(testDoorOpen);

    RUN_TEST(testEventError);


    UNITY_END();
}

void loop() {
    // not neccessary
}
