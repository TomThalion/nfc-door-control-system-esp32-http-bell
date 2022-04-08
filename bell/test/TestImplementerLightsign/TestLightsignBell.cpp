#include <Arduino.h>
#include <unity.h>

#include "Implementer/LightsignBell.h"
#include "Utils/Duration.h"

#define BELL_PIN 2


/**
 * @brief Tests for AcousticOfficeBell
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
    auto bell = LightsignBell(Duration(1, Duration::SECONDS));
    //should not ring by default
    TEST_ASSERT_EQUAL(LOW, digitalRead(BELL_PIN));
}

void testRing() {
    auto bell = LightsignBell(Duration(1, Duration::SECONDS));
    TEST_ASSERT_EQUAL(LOW, digitalRead(BELL_PIN));
    TEST_ASSERT_EQUAL(0, bell.ring());
    TEST_ASSERT_EQUAL(HIGH, digitalRead(BELL_PIN));
    delay(530);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(BELL_PIN));
    delay(530);
    // bell should have stoped ringing
    TEST_ASSERT_EQUAL(LOW, digitalRead(BELL_PIN));
}

void testStopRing() {
    auto bell = LightsignBell(Duration(1, Duration::SECONDS));
    TEST_ASSERT_EQUAL(0, bell.ring());
    TEST_ASSERT_EQUAL(HIGH, digitalRead(BELL_PIN));
    delay(530);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(BELL_PIN));
    bell.stopRing();
    TEST_ASSERT_EQUAL(LOW, digitalRead(BELL_PIN));
}


void testMultipleRing() {
    auto bell = LightsignBell(Duration(1, Duration::SECONDS));
    int counter=0;
    do {
        TEST_ASSERT_EQUAL(LOW, digitalRead(BELL_PIN));
        TEST_ASSERT_EQUAL(0, bell.ring());
        TEST_ASSERT_EQUAL(HIGH, digitalRead(BELL_PIN));
        delay(530);
        TEST_ASSERT_EQUAL(HIGH, digitalRead(BELL_PIN));
        delay(530);
        // bell should have stoped ringing
        TEST_ASSERT_EQUAL(LOW, digitalRead(BELL_PIN));
        counter++;
    } while (counter<5);
}


void setup() {
    delay(2000);
    UNITY_BEGIN();

    RUN_TEST(testDefault);

    RUN_TEST(testRing);

    RUN_TEST(testStopRing);

    RUN_TEST(testMultipleRing);

    UNITY_END();
}

void loop() {
    // not neccessary
}
