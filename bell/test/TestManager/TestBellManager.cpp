#include <Arduino.h>
#include <unity.h>
#include <memory>
#include "BellManagerForTesting.h"
#include "TestingBell.h"
#include "Utils/Event.h"


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
    auto bell = std::make_shared<TestingBell>();
    auto manager = BellManagerForTesting(bell);
    TEST_ASSERT_EQUAL(0, bell->ringCount);    
}

void testManagerBELL_RINGS() {
    auto bell = std::make_shared<TestingBell>();
    auto manager = BellManagerForTesting(bell);
    for(int i = 1; i< 5; i++) {
        manager.manageEvent(Event::BELL_RINGS);
    }   
    TEST_ASSERT_EQUAL(3, bell->ringCount);
}

void testManagerDOOR_OPEN() { 
    auto bell = std::make_shared<TestingBell>();
    auto manager = BellManagerForTesting(bell);
    for(int i = 1; i< 5; i++) {
        manager.manageEvent(Event::DOOR_OPEN);
    }   
    TEST_ASSERT_EQUAL((-3), bell->ringCount);
}

void testManagerMultiEvents() {
    auto bell = std::make_shared<TestingBell>();
    auto manager = BellManagerForTesting(bell);
    for(int i = 1; i< 6; i++) {
        manager.manageEvent(Event::BELL_RINGS);
    }  
    TEST_ASSERT_EQUAL(3, bell->ringCount);
    for(int i = 1; i< 4; i++) {
        manager.manageEvent(Event::DOOR_OPEN);
    }   
    TEST_ASSERT_EQUAL(0, bell->ringCount);
    manager.manageEvent(Event::ERROR_TEST);
    TEST_ASSERT_EQUAL(0, bell->ringCount); 
}

void testEventError() {
    auto bell = std::make_shared<TestingBell>();
    auto manager = BellManagerForTesting(bell);
    TEST_ASSERT_EQUAL(-1, manager.manageEvent(Event::ERROR_TEST));
    TEST_ASSERT_EQUAL(0, bell->ringCount);  

}

void testResetCount() {
    auto bell = std::make_shared<TestingBell>();
    auto manager = BellManagerForTesting(bell);

    for(int i = 0; i< 3; i++) {
        manager.manageEvent(Event::BELL_RINGS);
    }  
    TEST_ASSERT_EQUAL(3, bell->ringCount);
    manager.resetCount();
    for(int i = 0; i< 3; i++) {
        manager.manageEvent(Event::BELL_RINGS);
    }  
    TEST_ASSERT_EQUAL(6, bell->ringCount);
}


void setup() {
    delay(2000);
    UNITY_BEGIN();

    RUN_TEST(testDefault);

    RUN_TEST(testEventError);

    RUN_TEST(testManagerBELL_RINGS);

    RUN_TEST(testManagerDOOR_OPEN);

    RUN_TEST(testManagerMultiEvents);

    RUN_TEST(testResetCount);

    UNITY_END();
}

void loop() {
    // not neccessary
}
