/**
    * EntityAccessor allows wide read access to game elements while restricting write priveledges to EntityManager
	
	* Author: Skylar Payne
	* Date: 6/8/2013
    * File: EntityAccessor.h
**/

#pragma once

#include <vector>


class EntityAccessor
{
friend class EntityManager;
private:
    static std::vector<Entity*> s_Entities;
protected:
    Entity* GetEntity(unsigned int ID) const { return (ID < s_Entities.size()) ? s_Entities[ID] : NULL; }
    std::vector<Entity*> const& GetEntities() const { return s_Entities; }
};
