/**
	* Implementation of the entity class declared in Entity.h
    *
	* Author: Skylar Payne
	* Date: 6/8/2013
	* File: Entity.cpp
**/

#include "Entity.h"
#include <cstring>

#include "Logger.h"

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
 * @brief Entity::FindBehavior finds a particular behavior
 * @param type the type of behavior to find
 * @param loc the location of the behavior, if found
 * @return true if the behavior was found, false otherwise
 */
bool Entity::FindBehavior(const char* type, std::list<IBehavior*>::iterator& loc)
{
    for(loc = _Behaviors.begin(); loc != _Behaviors.end(); loc++)
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
        g_Logger << __FILE__ << ": " << __LINE__ << "-Error: component pointer was nullptr\n";
		return false;
	}

	std::list<IComponent*>::iterator it;
    if(this->FindComponent(comp->GetType(), it))
	{
        g_Logger << __FILE__ << ": " << __LINE__ << "-Error: " << comp->GetType() << " already attached to Entity" << this->_ID << "\n";
		return false;
	}

	_Components.push_back(comp);
    g_Logger << __FILE__ << ": " << __LINE__ << "-" << comp->GetType() << " was added to Entity " << this->_ID << "\n";
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
        g_Logger << __FILE__ << ": " << __LINE__ << "-" << type << " was removed from Entity " << this->_ID << "\n";
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
 * @brief Entity::AttachBehavior attaches a behavior to an entity
 * @param beh the behavior to attach
 * @return true if the behavior was attached, false otherwise
 */
bool Entity::AttachBehavior(IBehavior* beh)
{
    if(beh == nullptr)
    {
        g_Logger << __FILE__ << ": " << __LINE__ << "-Error: behavior pointer was nullptr\n";
        return false;
    }

    std::list<IBehavior*>::iterator it;
    if(this->FindBehavior(beh->GetType(), it))
    {
        g_Logger << __FILE__ << ": " << __LINE__ << "-Error: " << beh->GetType() << " already attached to Entity" << this->_ID << "\n";
        return false;
    }

    _Behaviors.push_back(beh);
    g_Logger << __FILE__ << ": " << __LINE__ << "-" << beh->GetType() << " was added to Entity " << this->_ID << "\n";
    return true;
}

/**
 * @brief Entity::RemoveBehavior removes a behavior
 * @param type the type of behavior to remove
 */
void Entity::RemoveBehavior(const char* type)
{
    std::list<IBehavior*>::iterator it;
    if(this->FindBehavior(type, it))
    {
        _Behaviors.erase(it);
        g_Logger << __FILE__ << ": " << __LINE__ << "-" << type << " was removed from Entity " << this->_ID << "\n";
    }
}

/**
 * @brief Entity::GetBehavior Gets a specified behavior from the entity
 * @param type the type of behavior
 * @return the behavior, if found, nullptr otherwise.
 */
IBehavior* Entity::GetBehavior(const char *type)
{
    std::list<IBehavior*>::iterator it;
    if(this->FindBehavior(type, it))
    {
        return (*it);
    }

    return nullptr;
}
