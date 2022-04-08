#ifndef DURATION_H
#define DURATION_H

/**
 * @brief Represents a duration in multible units
 * 
 * @author Tom Gaßmann
 * @version 1.0
 */
class Duration {

public:
    static const int MILLISECOND = 0;
    static const int SECONDS = 1;
    static const int MINUTES = 2;

    /**
     * @brief Construct a new Duration object
     * 
     * @param duration the duration in one of the possible units
     * @param unit the unit of the duration given in the duration param
     */
    Duration(int duration, int unit);

    /**
     * @brief Get the Duration in seconds
     * 
     * @return int duration in seconds
     */
    int getDurationSeconds();

    /**
     * @brief Get the Duration in milliseconds
     * 
     * @return int duration in milliseconds
     */
    int getDurationMilliseconds();

    /**
     * @brief Get the Duration in minutes
     * 
     * @return int duration in minutes
     */
    int getDurationMinutes();

    /**
     * @brief Set the Duration interpreting as seconds
     * 
     * @param duration given duration 
     * @return int return = 0 on succes, otherwise return = -1
     */
    int setDurationSeconds(int duration);

    /**
     * @brief Set the Duration interpreting as milliseconds
     * 
     * @param duration given duration 
     * @return int return = 0 on succes, otherwise return = -1
     */
    int setDurationMilliseconds(int duration);

    /**
     * @brief Set the Duration interpreting as minutes
     * 
     * @param duration given duration 
     * @return int return = 0 on succes, otherwise return = -1
     */
    int setDurationMinutes(int duration);

private:
    int duration = 0;

};
#endif