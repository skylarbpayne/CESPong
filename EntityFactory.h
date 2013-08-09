/**
    * The EntityFactory creates Entities through Lua config scripts
    *
    * Author: Skylar Payne
    * Date: 8/9/2013
    * File: EntityFactory.h
**/

#pragma once

#include <functional>
#include "HashTable.h"
#include "IComponent.h"

typedef std::unordered_map<const char*, std::function<IComponent*()>, eqstr, eqstr> ConstructorMap;

class EntityFactory
{
private:
    ConstructorMap _ConstructorMap;
public:
    virtual ~EntityFactory() { }

    bool Register(const char* componentType, std::function<IComponent* ()> constructor);
    void Create(const char* entity);
};
