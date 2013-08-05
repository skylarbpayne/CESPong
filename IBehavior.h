/**
    * The IBehavior class defines an interface to extend engine functionality
    *
    * Author: Skylar Payne
    * Date: 7/28/2013
    * File: IBehavior.h
**/

#pragma once

#include "Message.h"

class Entity;

class IBehavior
{
friend class Entity;
friend class BehaviorManager;
private:
    Entity* _Parent;
    const char* _Type;
public:
    IBehavior(const char* type = "Behavior") : _Type(type) { }
    virtual ~IBehavior() { }

    Entity* GetParent() const { return _Parent; }
    const char* GetType() const { return _Type; }

    virtual void Update() = 0;
    virtual void OnCollide(unsigned int ID, sf::Vector2f& norm) = 0;
};
