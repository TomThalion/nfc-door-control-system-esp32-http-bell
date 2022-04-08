#include <unity.h>
#include <Arduino.h>

#include "Utils/Duration.h"

/**
 * @brief Tests for Duration
 * 
 * @author Tom Gaßmann
 * @version 1.0
 */
void tearDown() {
}

void testSetAndGetDuration() {
    Duration d1 = Duration(5, Duration::MINUTES);
    TEST_ASSERT_EQUAL(5, d1.getDurationMinutes());
    // test initial value
    TEST_ASSERT_EQUAL(300000, d1.getDurationMilliseconds());
    d1.setDurationSeconds(10);
    TEST_ASSERT_EQUAL(10000, d1.getDurationMilliseconds());
    d1.setDurationMilliseconds(10);
    TEST_ASSERT_EQUAL(10, d1.getDurationMilliseconds());
    d1.setDurationMinutes(1);
    TEST_ASSERT_EQUAL(60000, d1.getDurationMilliseconds());
    d1 = Duration(5, Duration::SECONDS);
    TEST_ASSERT_EQUAL(5, d1.getDurationSeconds());
    d1 = Duration(5, Duration::MILLISECOND);
    TEST_ASSERT_EQUAL(5, d1.getDurationMilliseconds());
}

void setup() {
    delay(2000);
    UNITY_BEGIN();

    RUN_TEST(testSetAndGetDuration);

    UNITY_END();
}

void loop() {
    // not neccessary
}
