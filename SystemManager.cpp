/**
	* SystemManager manages all component systems. Allows the addition and removal of systems. Updates all systems,
    * and facilitates pausing all systems.
    *
	* Author: Skylar Payne
	* Date: 6/23/2013
	* File: SystemManager.cpp
**/

#include "SystemManager.h"
#include "ISystem.h"

/**
    * @brief SystemManager::Add Adds a system to manager if a system of that type has not already been added
	* @param sys The system to add
	* @return true if the system was successfully added, false otherwise
**/
bool SystemManager::Add(ISystem* sys)
{
	if(sys == NULL)
	{
		return false;
	}

	std::list<ISystem*>::iterator it;
	if(this->Has(sys->GetType(), it))
	{
		return false;
	}

	_Systems.push_back(sys);
	return true;
}

/**
    * @brief SystemManager::Remove Removes a system from the manager
	* @param type The type of system to remove
**/
void SystemManager::Remove(std::string type)
{
	std::list<ISystem*>::iterator it;
	if(this->Has(type, it))
	{
		_Systems.erase(it);
	}
}

/**
    * @brief SystemManager::Has Checks to see if a system exists within the manager
	* @param type The type to check for
	* @param loc The location of the system if it was found
	* @return true if the system was found, false otherwise
**/
bool SystemManager::Has(std::string type, std::list<ISystem*>::iterator& loc)
{
    for(loc = _Systems.begin(); loc != _Systems.end(); loc++)
	{
		if((*loc)->GetType() == type)
		{
			return true;
		}
	}

	return false;
}

/**
    * @brief SystemManager::Activate Activates the manager (Useful for unpausing)
**/
void SystemManager::Activate()
{
	_Active = true;
}

/**
 * @brief SystemManager::Deactivate Deactivates the manager (Useful for pausing)
 */
void SystemManager::Deactivate()
{
	_Active = false;
}

/**
    * @brief SystemManager::isActive Checks whether the manager is active
	* @return true if active, false otherwise
**/
bool SystemManager::isActive() const
{
	return _Active;
}

/**
    * @brief SystemManager::Update Calls the update function of all active systems
**/
void SystemManager::Update()
{
    unsigned long currentTime = _SystemClock.getElapsedTime().asMicroseconds();

	std::list<ISystem*>::iterator it;
	for(it = _Systems.begin(); it != _Systems.end(); it++)
	{
		if( (*it) && (*it)->isActive())
		{
            (*it)->Update(currentTime - _LastTime);
		}
	}
}
