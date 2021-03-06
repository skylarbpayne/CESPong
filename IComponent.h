/**
	* Interface for all components to derive from. All components contain at the bare minimum a string type and parent entity
    *
	* Author: Skylar Payne
	* Date: 6/8/2013
	* File: IComponent.h
**/

#pragma once

class Entity;
class lua_State;

class IComponent
{
friend class Entity;
private:
    Entity* _Parent;
    const char* _Type;
public:
    IComponent(const char* type) : _Type(type) {};
    virtual ~IComponent() { }

    virtual void Load(lua_State* L) = 0;

	/**
        * @brief IComponent::GetParent Returns the parent entity to which this component is attached
		* @return the parent entity to which this component is attached
	**/
    Entity const* GetParent() const { return _Parent; }

	/**
        * @brief IComponent::GetType Returns the type of this component
		* @return the type of this component
	**/
    const char* GetType() const { return _Type; }
};
