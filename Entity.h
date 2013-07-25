/**
	* Wrapper class for collections of components and behaviors that constitute anything.
    *
	* Author: Skylar Payne
	* Date: 6/8/2013
	* File: Entity.h
**/

#pragma once

#include <list>
#include "IComponent.h"

class Entity
{
friend class EntityManager;
private:
    unsigned int _ID;
	std::list<IComponent*> _Components;
private:
    bool FindComponent(const char* type, std::list<IComponent*>::iterator& loc);
public:
    bool AttachComponent(IComponent* comp);
    void RemoveComponent(const char* type);
    bool HasComponent(const char* type);

    template<class T>
    T* GetComponent(const char* type);
};
