/**
    * EntityManager handles the adding and removing of entities and any other higher level entity management. Has write access
    * to EntityAccessor. Implementation of class declared in EntityManager.h
    *
    * Author: Skylar Payne
    * Date: 7/16/2013
    * File: EntityManager.cpp
**/

#include "EntityManager.h"
#include "Entity.h"

std::vector<Entity*> EntityAccessor::s_Entities;

/**
 * @brief EntityManager::~EntityManager removes all entities.
 */
EntityManager::~EntityManager()
{
    for(unsigned int i = 0; i < EntityAccessor::s_Entities.size(); i++)
    {
        if(EntityAccessor::s_Entities[i])
        {
            delete EntityAccessor::s_Entities[i];
            EntityAccessor::s_Entities[i] = nullptr;
        }
    }

    EntityAccessor::s_Entities.clear();
}

/**
 * @brief EntityManager::AddEntity Adds an entity to the entity container
 * @param e the entity to add
 * @return true if entity was added, false otherwise
 */
bool EntityManager::AddEntity(Entity *e)
{
    //Maybe update later to include a list of free IDs?
    if(e == nullptr)
    {
        return false;
    }

    if(_EntitySpaces.empty())
    {
        e->_ID = EntityAccessor::s_Entities.size();
        EntityAccessor::s_Entities.push_back(e);
        return true;
    }

    std::list<unsigned int>::iterator it;
    for(it = _EntitySpaces.begin(); it != _EntitySpaces.end(); it++)
    {
        if(EntityAccessor::s_Entities[*it] == nullptr)
        {
            e->_ID = *it;
            EntityAccessor::s_Entities[*it] = e;

           //EMIT MESSAGE HERE

            _EntitySpaces.erase(it);
            return true;
        }

        else
        {
            _EntitySpaces.erase(it);
        }
    }
    return false;
}

/**
 * @brief EntityManager::RemoveEntity removes an entity from the container
 * @param ID The ID of the entity to remove
 */
void EntityManager::RemoveEntity(unsigned int ID)
{
    if(ID > EntityAccessor::s_Entities.size())
    {
        return;
    }

    if(EntityAccessor::s_Entities[ID] != nullptr)
    {
        delete EntityAccessor::s_Entities[ID];
        EntityAccessor::s_Entities[ID] = nullptr;
        _EntitySpaces.push_back(ID);
    }

   //EMIT MESSAGE HERE
}
