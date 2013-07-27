/**
    * Centralized logging implementation. Will add more streams later. Also need to make it Debug mode specific.
    * Author: Skylar Payne
    * Date: 6/8/2013
    * File: Entity.h
**/

#pragma once

#include <string>
#include <cstring>

class Logger
{
private:
    //later implement stream information here.
public:
    Logger& operator<<(const char* c);
    Logger& operator<<(const int i);
    Logger& operator<<(const unsigned int i);
    Logger& operator<<(const float f);
};

extern Logger g_Logger;
