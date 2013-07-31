/**
	* Interface for all systems. Systems act on a particular set of components.
    *
	* Author: Skylar Payne
	* Date: 6/8/2013
	* File: ISystem.h
**/

#pragma once

#include <list>
#include "EntityAccessor.h"
#include "IListener.h"

class ISystem : public EntityAccessor, public IListener<EntityMessage>
{
protected:
	bool _Active;
    const char* _Type;
	std::list<unsigned int> _EntitiesToUpdate;
private:
    void OnMessage(EntityMessage& msg) override;
public:
    ISystem() : _Active(true) { };
    virtual ~ISystem() {}
	void Activate() { _Active = true; }
	void Deactivate() { _Active = false; }
	bool isActive() const { return _Active; }
    const char* GetType() const { return _Type; }
    virtual void Update(unsigned long dt) = 0;
    virtual bool ValidateEntity(unsigned int ID) = 0;
};

/**
 * @brief ISystem::OnMessage When a new entity is added or destroyed, this will determine whether to add/remove entity from list
 * @param msg the message data
 */
void ISystem::OnMessage(EntityMessage &msg)
{
    if(msg.Destroyed)
    {
        _EntitiesToUpdate.remove(msg.ID);
    }

    else if(ValidateEntity(msg.ID))
    {
        _EntitiesToUpdate.push_back(msg.ID);
    }
}
