/**
	* Interface for all systems. Systems act on a particular set of components.
	
	* Author: Skylar Payne
	* Date: 6/8/2013
	* File: ISystem.h
**/

#pragma once

#include <list>
#include "Messenger.h"
#include "EntityAccessor.h"

class ISystem : public Messenger, EntityAccessor
{
protected:
	bool _Active;
	std::string _Type;
	std::list<unsigned int> _EntitiesToUpdate;
public:
	ISystem() : _Active(true) {};
    virtual ~ISystem() {}
	void Activate() { _Active = true; }
	void Deactivate() { _Active = false; }
	bool isActive() const { return _Active; }
	std::string GetType() const { return _Type; }
    virtual void Update(unsigned long dt) = 0;
    virtual void ValidateEntity(unsigned int ID) = 0;
	virtual void OnMessage(Message* msg) = 0;
};
