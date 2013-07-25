/**
	* Implementation of the entity class declared in Entity.h

	* Author: Skylar Payne
	* Date: 6/8/2013
	* File: Entity.cpp
**/

#include "Entity.h"
#include <cstring>

/**
 * @brief Entity::FindComponent finds a specified component
 * @param type the type of component to look for
 * @param loc the location of the component if found
 * @return true if the component was found, false otherwise
 */
bool Entity::FindComponent(const char* type, std::list<IComponent*>::iterator &loc)
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
    * @brief Entity::AttachComponent Attaches a component to the entity if a component of that type is not already attached
	* @param comp The component to attach
	* @return true if the new component was attached, false otherwise.
**/
bool Entity::AttachComponent(IComponent* comp)
{
    if(comp == nullptr)
	{
		return false;
	}

	std::list<IComponent*>::iterator it;
    if(this->FindComponent(comp->GetType(), it))
	{
		return false;
	}

	_Components.push_back(comp);
	return true;
}

/**
    * @brief Entity::RemoveComponent Removes a type component from an entity if that entity has that component
	* @param type The component type to remove.
**/
void Entity::RemoveComponent(const char* type)
{
	std::list<IComponent*>::iterator it;
    if(this->FindComponent(type, it))
	{
		_Components.erase(it);
	}
}

/**
    * @brief Entity::HasComponent Finds a particular component
	* @param type The type of component to find
	* @return true if the component was found, false otherwise
**/
bool Entity::HasComponent(const char* type)
{
    std::list<IComponent*>::iterator it;
    return this->FindComponent(type, it);
}

/**
 * @brief Entity::GetComponent templated method to get a Component
 * @param type the type of component to get
 * @return the component, if found, nullptr otherwise.
 */
template<class T>
T* Entity::GetComponent(const char* type)
{
    std::list<IComponent*>::iterator it;
    if(this->FindComponent(type, it))
    {
        return static_cast<T>(*it);
    }

    return nullptr;
}
