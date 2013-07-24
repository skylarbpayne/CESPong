/**
    * A pseudo singleton (public static methods) to allow log information to be sent from anywhere. Will only run in debug configuration.
    *
    * Author: Skylar Payne
    * Date: 6/8/2013
    * File: Entity.h
**/

#pragma once

class Logger
{
private:
    //later implement stream information here.
public:
    Logger& operator<<(const char* c);
    Logger& operator<<(const int i);
    Logger& operator<<(const short s);
    Logger& operator<<(const long l);
    Logger& operator<<(const float f);
    Logger& operator<<(const double d);
};

extern Logger g_Logger;
