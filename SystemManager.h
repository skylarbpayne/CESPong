/**
	* SystemManager manages all component systems. Allows the addition and removal of systems. Updates all systems,
    * and facilitates pausing all systems.
    *
	* Author: Skylar Payne
	* Date: 6/22/2013
	* File: SystemManager.h
**/

#pragma once

#include <list>
#include <string>
#include <SFML/System.hpp>

class ISystem;

class SystemManager
{
private:
	bool _Active;
    unsigned long _LastTime;
    sf::Clock _SystemClock;
	std::list<ISystem*> _Systems;
public:
    SystemManager() : _Active(true), _LastTime(0) {}
	bool Add(ISystem* sys);
	void Remove(std::string type);
	bool Has(std::string type, std::list<ISystem*>::iterator& loc);
	void Activate();
	void Deactivate();
	bool isActive() const;
	void Update();
};
