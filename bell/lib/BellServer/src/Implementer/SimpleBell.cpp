#include <Arduino.h>
#include <memory>
#include "Implementer/SimpleBell.h"


/**
 * @file SimpleBell.cpp
 * @author Tom Gaßmann
 * @brief Implementation of SimpleBell
 * @version 1.0
 * 
 */

/**
 * @brief Taskfunktion for parallel (asynchron) ringing 
 * 
 * @param optionalARGS 
 */
void taskRinging(void *optionalARGS) {
    SimpleBell const *bell = static_cast<SimpleBell const*>(optionalARGS);
    while (true)
    {
        delay(bell->getDurationA().getDurationMilliseconds());
        digitalWrite(bell->getBellPin(),LOW);
        vTaskSuspend(nullptr);
    }
}

SimpleBell::SimpleBell(Duration duration, int BellPin) 
: ringing(nullptr)
, nextDuration(duration) {
    this->BellPin = BellPin;
    pinMode(this->BellPin, OUTPUT);
    digitalWrite(this->BellPin, LOW);
}

SimpleBell::~SimpleBell() {
    SimpleBell::stopRing();
    if ( this->ringing != nullptr ) {
        vTaskDelete(this->ringing);
    }
}

int SimpleBell::ring() {
   auto result = pdPASS;
   digitalWrite(this->BellPin,HIGH);
   if ( this->ringing != nullptr ) {
       vTaskResume(this->ringing);
   }
   else {
      result = xTaskCreate(
        taskRinging,
        "Ringing",
        10000,
        this,
        1,
        &(this->ringing)
    );
   }
    return result!=pdPASS;
}

int SimpleBell::stopRing() {
   digitalWrite(this->BellPin, LOW);
   return 0;
}

Duration SimpleBell::getDurationA() const {
    return this->nextDuration;
}

TaskHandle_t SimpleBell::getTask() {
    return this->ringing;
}

int SimpleBell::getBellPin() const {
    return this->BellPin;
}