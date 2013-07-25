/**
    * EntityAccessor allows wide read access to game elements while restricting write priveledges to EntityManager
    *
	* Author: Skylar Payne
	* Date: 6/8/2013
    * File: EntityAccessor.h
**/

#pragma once

#include <vector>

class Entity;

class EntityAccessor
{
friend class EntityManager;
private:
    static std::vector<Entity*> s_Entities;
protected:
    /**
     * @brief GetEntity gets an entity
     * @param ID the ID of the entity to get
     * @return the entity, if found, nullptr otherwise
     */
    Entity* GetEntity(unsigned int ID) const { return (ID < s_Entities.size()) ? s_Entities[ID] : nullptr; }

    /**
     * @brief GetEntities Gets the entire collection of entities
     * @return a vector of entities currently in play
     */
    std::vector<Entity*> const& GetEntities() const { return s_Entities; }
};
