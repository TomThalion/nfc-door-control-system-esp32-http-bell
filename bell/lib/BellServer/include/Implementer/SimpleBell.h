#ifndef SIMPLE_BELL_H
#define SIMPLE_BELL_H

#include <Arduino.h>
#include "BellImplementer.h"

/**
 * @brief A special implementation of a Bell, which represents a simpleBell which should be
 * able to set and reset the output of the microcontroller 
 * Uses pin 4 as output.
 * 
 * @author Tom Gaßmann
 * @version 1.0
 */
class SimpleBell : public BellImplementer{
    public:
    /**
     * @brief Construct a new SimpleBell Bell object
     * 
     * @param duration the specified duration
     */
    SimpleBell(Duration duration, int BellPin);

    /**
     * @brief Destroy the Simple Bell object
     * 
     */
    virtual ~SimpleBell();

    /**
     * @brief Rings the bell for an specified duration
     * 
     * @return int return = 0 on success, otherwise return = -1;
     */
    int ring() override;


    /**
     * @brief Stop ringing the bell, if its ringing. If the bell doesn't ring nothing happens
     * 
     * @return int return = 0 on success, otherwise return = -1
     */
    int stopRing() override;

    /**
     * @brief Get the Duration object
     * 
     * @return Duration 
     */
    Duration getDurationA() const;

    /**
     * @brief Get the Task object
     * 
     * @return TaskHandle_t the task
     */
    TaskHandle_t getTask();

    /**
     * @brief Get the BellPin 
     * 
     * @return int the BellPin as an int
     */
    int getBellPin() const;

protected:
    TaskHandle_t ringing;
    Duration nextDuration;
    int BellPin;
};

#endif
