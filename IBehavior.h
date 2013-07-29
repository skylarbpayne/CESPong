/**
    * The IBehavior class defines an interface to extend engine functionality
    *
    * Author: Skylar Payne
    * Date: 7/28/2013
    * File: IBehavior.h
**/

#pragma once

#include "Message.h"

class IBehavior
{
private:
    const char* _Type;
public:
    IBehavior(const char* type = "Behavior") : _Type(type) { }
    const char* GetType() const { return _Type; }

    virtual void Update() = 0;
    virtual void OnCollide(unsigned int ID, sf::Vector2f& norm) = 0;
};
