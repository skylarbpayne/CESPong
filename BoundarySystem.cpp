/**
    * The BoundarySystem ensures that both paddles and the game ball stay within the window.
    *
    * Author: Skylar Payne
    * Date: 8/23/2013
    * File: BoundarySystem.cpp
**/

#include "BoundarySystem.h"
#include "ColliderComponent.h"
#include "PositionComponent.h"
#include "Entity.h"

void BoundarySystem::Update(unsigned int dt)
{
    std::set<unsigned int>::iterator it;

    for(it = _EntitiesToUpdate.begin(); it != _EntitiesToUpdate.end(); ++it)
    {
        Entity* e = this->GetEntity(*it);

        ColliderComponent* cc = e->GetComponent<ColliderComponent>("Collider");
        PositionComponent* pc = e->GetComponent<PositionComponent>("Position");
        sf::Vector2f pos;
        pos.x = pc->GetPosition().x;
        pos.y = pc->GetPosition().y;

        if(pc->GetPosition().y + cc->GetOffset().y < 0.0f)
        {
            pos.y = -cc->GetOffset().y;
        }

        else if(pc->GetPosition().y + cc->GetOffset().y + cc->GetDimensions().y > this->GetWindow()->getSize().y)
        {
            pos.y = this->GetWindow()->getSize().y - (cc->GetOffset().y + cc->GetDimensions().y);
        }

        if(pos.y != pc->GetPosition().y)
        {
            MoveEntityMessage msg;
            msg.ID = *it;
            msg.newPosition = pos;
            Emit<MoveEntityMessage>(msg);

            CollisionMessage cmsg;
            cmsg.ID1 = *it;
            cmsg.ID2 = *it;
            Emit<CollisionMessage>(cmsg);
        }
    }
}

bool BoundarySystem::ValidateEntity(unsigned int ID)
{
    Entity* e = this->GetEntity(ID);

    return e->HasComponent("Collider") && e->HasComponent("Position");
}
