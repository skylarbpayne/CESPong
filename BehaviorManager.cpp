/**
    * Definition of the BehaviorManager class as defined in BehaviorManager.h
    *
    * Author: Skylar Payne
    * Date: 7/28/2013
    * File: IBehavior.cpp
**/

#include "BehaviorManager.h"
#include "Entity.h"

/**
 * @brief BehaviorManager::Update updates all behaviors of all entities
 */
void BehaviorManager::Update()
{
    std::list<IBehavior*>::iterator bit;

    for(unsigned int i = 0; i < this->GetEntities().size(); i++)
    {
        if(!this->GetEntities()[i])
        {
            continue;
        }

        for(bit = this->GetEntities()[i]->_Behaviors.begin(); bit != this->GetEntities()[i]->_Behaviors.end(); bit++)
        {
            (*bit)->Update();
        }
    }
}

/**
 * @brief BehaviorManager::OnMessage called when a CollisionMessage is emitted--Calls OnCollide method of appropriate behaviors
 * @param msg the collision data
 */
void BehaviorManager::OnMessage(CollisionMessage& msg)
{
    Entity* e1 = this->GetEntity(msg.ID1);
    Entity* e2 = this->GetEntity(msg.ID2);

    std::list<IBehavior*>::iterator it;

    for(it = e1->_Behaviors.begin(); it != e1->_Behaviors.end(); it++)
    {
        (*it)->OnCollide(msg.ID2, msg.norm);
    }

    for(it = e2->_Behaviors.begin(); it != e2->_Behaviors.end(); it++)
    {
        (*it)->OnCollide(msg.ID1, msg.norm);
    }
}
