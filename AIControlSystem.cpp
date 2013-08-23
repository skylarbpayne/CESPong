/**
    * The AIControlSystem facilitates the control of an AI pong paddle
    *
    * Author: Skylar Payne
    * Date: 8/22/2013
    * File: AIControlSystem.h
**/

#include "AIControlSystem.h"
#include "Entity.h"
#include "IListener.h"
#include "PositionComponent.h"
#include <cstring>

/**
 * @brief AIControlSystem::Update Moves ai paddles closer to the ball
 * @param dt the time splice since last frame
 */
void AIControlSystem::Update(unsigned int dt)
{
    std::set<unsigned int>::iterator it;

    for(it = _EntitiesToUpdate.begin(); it != _EntitiesToUpdate.end(); ++it)
    {
        float ease = 0.8f;
        Entity* e = this->GetEntity(*it);
        Entity* b = this->GetEntity(_BallID);

        sf::Vector2f ballPos = b->GetComponent<PositionComponent>("Position")->GetPosition();
        sf::Vector2f aiPos = e->GetComponent<PositionComponent>("Position")->GetPosition();
        sf::Vector2f vel;

        float yDis = ballPos.y - aiPos.y;
        vel.y = yDis * ease;

        if(yDis < -5)
        {
            vel.y = -5;
        }

        else if(yDis > 5)
        {
            vel.y = 5;
        }

        if(vel.y != 0.0f)
        {
            PushEntityMessage msg;
            msg.ID = *it;
            msg.newVelocity = vel;
            Emit<PushEntityMessage>(msg);
        }
    }
}

/**
 * @brief AIControlSystem::ValidateEntity inserts all ai paddles and takes note of the ball when created
 * @param ID the ID of the potential ai paddle
 * @return true if the entity is an AI, false otherwise
 */
bool AIControlSystem::ValidateEntity(unsigned int ID)
{
    Entity* e = this->GetEntity(ID);

    if(e)
    {
        if(strcmp(e->GetTag(), "Ball") == 0)
        {
            _BallID = ID;
        }

        else if(strcmp(e->GetTag(), "AI") == 0)
        {
            return true;
        }
    }
    return false;
}
