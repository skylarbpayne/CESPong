/**
    * The MovementSystem updates PositionComponents
    *
    * Author: Skylar Payne
    * Date: 8/3/2013
    * File: MovementSystem.h
**/

#include "MovementSystem.h"

#include "Entity.h"
#include "MovementComponent.h"
#include "PositionComponent.h"

void MovementSystem::Update(unsigned int dt)
{
    std::list<unsigned int>::iterator it;

    for(it = _EntitiesToUpdate.begin(); it != _EntitiesToUpdate.end(); ++it)
    {
        Entity* e = this->GetEntity(*it);

        MovementComponent* mc = e->GetComponent<MovementComponent>("Movement");
        PositionComponent* pc = e->GetComponent<PositionComponent>("Position");

        sf::Vector2f const& pos = pc->GetPosition();
        sf::Vector2f const& vel = mc->GetVelocity();

        pc->SetPosition(pos.x + vel.x, pos.y + vel.y);

        //Emit message
    }
}

bool MovementSystem::ValidateEntity(unsigned int ID)
{
    Entity* e = this->GetEntity(ID);

    return (e->HasComponent("Position") && e->HasComponent("Movement"));
}
