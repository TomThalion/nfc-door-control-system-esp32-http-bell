#include "Utils/Duration.h"



/**
 * @file Duration.cpp
 * @author Tom Gaßmann
 * @brief Implementation of Duration
 * @version 1.0
 * @date 2022-01-05
 * 
 */
Duration::Duration(int duration, int unit) {

    switch (unit) {

    case SECONDS:
        setDurationSeconds(duration);
        break;

    case MINUTES:
        setDurationMinutes(duration);
        break;

    default:
        setDurationMilliseconds(duration);
        break;
    }
}

int Duration::getDurationMilliseconds() {
    return this->duration;
}

int Duration::getDurationMinutes() {
    return (this->duration / 60000);
}

int Duration::getDurationSeconds() {
    return (this->duration/ 1000);
}

int Duration::setDurationMilliseconds(int duration) {
    this->duration = duration;
    return 0;
}

int Duration::setDurationSeconds(int duration) {
    this->duration = duration * 1000;
    return 0;
}

int Duration::setDurationMinutes(int duration) {
    this->duration = duration * 60000;
    return 0;
}