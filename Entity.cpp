/**
	* Implementation of the entity class declared in Entity.h

	* Author: Skylar Payne
	* Date: 6/8/2013
	* File: Entity.cpp
**/

#include "Entity.h"
#include <cstring>

/**
 * @brief Entity::Find finds a specified component
 * @param type the type of component to look for
 * @param loc the location of the component if found
 * @return true if the component was found, false otherwise
 */
bool Entity::Find(const char* type, std::list<IComponent*>::iterator &loc)
{
    for(loc = _Components.begin(); loc != _Components.end(); loc++)
    {
        if(strcmp((*loc)->GetType(), type) == 0)
        {
            return true;
        }
    }
    return false;
}

/**
    * @brief Entity::Attach Attaches a component to the entity if a component of that type is not already attached
	* @param comp The component to attach
	* @return true if the new component was attached, false otherwise.
**/
bool Entity::Attach(IComponent* comp)
{
    if(comp == nullptr)
	{
		return false;
	}

	std::list<IComponent*>::iterator it;
    if(this->Find(comp->GetType(), it))
	{
		return false;
	}

	_Components.push_back(comp);
	return true;
}

/**
    * @brief Entity::Remove Removes a type component from an entity if that entity has that component
	* @param type The component type to remove.
**/
void Entity::Remove(const char* type)
{
	std::list<IComponent*>::iterator it;
    if(this->Find(type, it))
	{
		_Components.erase(it);
	}
}

/**
    * @brief Entity::Has Finds a particular component
	* @param type The type of component to find
	* @return true if the component was found, false otherwise
**/
bool Entity::Has(const char* type)
{
    std::list<IComponent*>::iterator it;
    return this->Find(type, it);
}
