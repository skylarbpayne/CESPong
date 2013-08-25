/**
    * The ScoringSystem tracks the scores of both players
    *
    * Author: Skylar Payne
    * Date: 8/23/2013
    * File: ScoringSystem.cpp
**/

#include "ScoringSystem.h"
#include "Entity.h"
#include "PositionComponent.h"
#include "ColliderComponent.h"
#include <cstring>
#include <string>

#include "IListener.h"

/**
 * @brief ScoringSystem::Update Checks to see if either player scored and updates player scores accordingly. Also renders the scores
 * @param dt the time splice
 */
void ScoringSystem::Update(unsigned int dt)
{
    Entity* ball = this->GetEntity(_BallID);
    PositionComponent* pc = ball->GetComponent<PositionComponent>("Position");
    ColliderComponent* cc = ball->GetComponent<ColliderComponent>("Collider");

    if(pc->GetPosition().x + cc->GetOffset().x <= 0.0f)
    {
        _Player2Score++;
        PointScoredMessage msg;
        msg.scorer = 2;
        Emit<PointScoredMessage>(msg);
    }

    else if(pc->GetPosition().x + cc->GetOffset().x + cc->GetDimensions().x >= this->GetWindow()->getSize().x)
    {
        _Player1Score++;
        PointScoredMessage msg;
        msg.scorer = 1;
        Emit<PointScoredMessage>(msg);
    }

    sf::Text txt;
    std::string str;
    str = std::to_string(_Player1Score);
    txt.setFont(*this->GetFont("resources/Corki-Regular.otf"));;
    txt.setString(str);
    txt.setPosition(this->GetWindow()->getSize().x / 4, 0);
    this->GetWindow()->draw(txt);

    str = "";
    str = std::to_string(_Player2Score);
    txt.setString(str);
    txt.setPosition(this->GetWindow()->getSize().x * 3 / 4, 0);
    this->GetWindow()->draw(txt);
}

/**
 * @brief ScoringSystem::ValidateEntity Since this system only updates player scores, this method serves to get the Ball
 * @param ID the ID of the entity to check
 * @return always false
 */
bool ScoringSystem::ValidateEntity(unsigned int ID)
{
    Entity* e = this->GetEntity(ID);

    if(strcmp(e->GetTag(), "Ball") == 0)
    {
        _BallID = ID;
    }

    return false;
}
