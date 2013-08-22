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
#include "IBehavior.h"

class Entity
{
friend class EntityManager;
friend class BehaviorSystem;
private:
    unsigned int _ID;
    std::string _Tag;
>>>>>>> 21997b1026dba1d287f279a3b8276c25038c1827
	std::list<IComponent*> _Components;
    std::list<IBehavior*> _Behaviors;
private:
    bool FindComponent(const char* type, std::list<IComponent*>::iterator& loc);
    bool FindBehavior(const char* type, std::list<IBehavior*>::iterator& loc);
public:
    Entity(const char* tag = "") : _Tag(tag) { }
    ~Entity();

    unsigned int GetID() const { return _ID; }
<<<<<<< HEAD
    const char* GetTag() const { return _Tag; }
=======
    const char* GetTag() const { return _Tag.c_str(); }
>>>>>>> 21997b1026dba1d287f279a3b8276c25038c1827
    void SetTag(const char* tag) { _Tag = tag; }

    bool AttachComponent(IComponent* comp);
    void RemoveComponent(const char* type);
    bool HasComponent(const char* type);

    template<class T>
    T* GetComponent(const char* type);

    bool AttachBehavior(IBehavior* beh);
    void RemoveBehavior(const char* type);
    bool HasBehavior(const char* type);
    IBehavior* GetBehavior(const char* type);
};

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
        return static_cast<T*>(*it);
    }

    return nullptr;
}
