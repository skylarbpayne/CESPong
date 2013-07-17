/**
    * EntityManager handles the adding and removing of entities and any other higher level entity management. Has write access
    *   to EntityAccessor. Implementation of class declared in EntityManager.h

    * Author: Skylar Payne
    * Date: 7/16/2013
    * File: EntityManager.cpp
**/

#include "EntityManager.h"
#include "Entity.h"
#include "Message.h"

std::vector<Entity*> EntityAccessor::s_Entities;

/**
 * @brief EntityManager::EntityManager used to subscribe to events
 */
EntityManager::EntityManager()
{
    this->Subscribe(Message::DestroyEntity);
}

/**
 * @brief EntityManager::~EntityManager unsubscribes from events and removes all entities.
 */
EntityManager::~EntityManager()
{
    this->Unsubscribe(Message::DestroyEntity);

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

            Message* msg = new Message();
            msg->_MessageType = Message::EntityDestroyed;
            msg->_EntityMessage.ID = (*it);
            this->SendMessage(msg);

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

    Message* msg = new Message();
    msg->_MessageType = Message::EntityDestroyed;
    msg->_EntityMessage.ID = ID;
    this->SendMessage(msg);
}

/**
 * @brief EntityManager::OnMessage handles messages of interest
 * @param msg the message to handle
 */
void EntityManager::OnMessage(Message *msg)
{
    if(msg->_MessageType == Message::DestroyEntity)
    {
        RemoveEntity(msg->_EntityMessage.ID);
    }
}
