/**
    * Logging implementation. Use the global instance of this class to log everything. Will wrap to file later
    *
    * Author: Skylar Payne
    * Date: 7/24/2013
    * File: Logger.h
**/

#include "Logger.h"
#include <iostream>

Logger g_Logger;

/**
 * @brief Debug::operator << logs a string
 * @param c the string to log
 * @return the global logger
 */
Logger& Logger::operator<<(const char* c)
{
    std::cout << c;
    return g_Logger;
}

/**
 * @brief Logger::operator << logs an integer
 * @param i the integer to log
 * @return the global logger
 */
Logger& Logger::operator<<(const int i)
{
    std::cout << i;
    return g_Logger;
}

/**
 * @brief Logger::operator << logs an unsigned integer
 * @param i the integer to log
 * @return the global logger
 */
Logger& Logger::operator<<(const unsigned int i)
{
    std::cout << i;
    return g_Logger;
}


/**
 * @brief Logger::operator << logs a float
 * @param f the float to log
 * @return the global logger
 */
Logger& Logger::operator<<(const float f)
{
    std::cout << f;
    return g_Logger;
}

/**
 * @brief Logger::flush flushes all streams to which the logger writes
 */
void Logger::flush()
{
    std::cout.flush();
}
