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
    bool Find(const char* type, std::list<IComponent*>::iterator& loc);
public:
	bool Attach(IComponent* comp);
    void Remove(const char* type);
    bool Has(const char* type);
};
