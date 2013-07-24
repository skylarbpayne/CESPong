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
 * @brief Logger::operator << logs a short
 * @param s the short to log
 * @return the global logger
 */
Logger& Logger::operator<<(const short s)
{
    std::cout << s;
    return g_Logger;
}

/**
 * @brief Logger::operator << logs a long
 * @param l the long to log
 * @return the global logger
 */
Logger& Logger::operator<<(const long l)
{
    std::cout << l;
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
 * @brief Logger::operator << logs a double
 * @param d the double to log
 * @return the global logger
 */
Logger& Logger::operator<<(const double d)
{
    std::cout << d;
    return g_Logger;
}
