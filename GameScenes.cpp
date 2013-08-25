/**
    * Declares all GameScenes: Splash Screen, Main Menu, Play, etc.
    *
    * Author: Skylar Payne
    * Date: 8/21/2013
    * File: GameScenes.cpp
**/

#include "GameScenes.h"

#include "IListener.h"

#include <lua.hpp>
#include "LuaBindings.h"

#include "PositionComponent.h"
#include "MovementComponent.h"
#include "ColliderComponent.h"
#include "CircleComponent.h"
#include "RectangleComponent.h"
#include "TextComponent.h"
#include "ScriptableBehavior.h"

#include "Entity.h"

#include "MovementSystem.h"
#include "CollisionSystem.h"
#include "BoundarySystem.h"
#include "RenderSystem.h"
#include "ScoringSystem.h"
#include "BehaviorSystem.h"

#include "AIControlSystem.h"

bool SplashScene::Load()
{
    rm.AddTexture("resources/splash.png");
    _Splash.setTexture(*this->GetTexture("resources/splash.png"));
    return true;
}

void SplashScene::Update()
{
    sf::Color color;
    color.r = 255;
    color.g = 255;
    color.b = 255;

    color.a = 255 - _Clock.getElapsedTime().asSeconds() * (255 / 3);

    _Splash.setColor(color);

    this->GetWindow()->clear();
    this->GetWindow()->draw(_Splash);
    this->GetWindow()->display();

    if(color.a == 0)
    {
        ChangeSceneMessage msg;
        msg.NextScene = new PlayScene();
        Emit<ChangeSceneMessage>(msg);
    }
}

void SplashScene::Unload()
{
    rm.Unload();
}

/**
 * @brief PlayScene::Load sets up the game scene
 * @return true if everything loaded correctly, false otherwise
 */
bool PlayScene::Load()
{
    ISystem* s = nullptr;
    s = new RenderSystem();
    sm.Add(s);
    s = new MovementSystem();
    sm.Add(s);
    s = new CollisionSystem();
    sm.Add(s);
    s = new BoundarySystem();
    sm.Add(s);
    s = new ScoringSystem();
    sm.Add(s);
    s = new BehaviorSystem();
    sm.Add(s);
    s = new AIControlSystem();
    sm.Add(s);
    s = nullptr;

    ef.Register("Position", []() { return new PositionComponent(); });
    ef.Register("Movement", []() { return new MovementComponent(); });
    ef.Register("Collider", []() { return new ColliderComponent(); });
    ef.Register("Circle", []() { return new CircleComponent(); });
    ef.Register("Rectangle", []() { return new RectangleComponent(); });
    ef.Register("Text", []() { return new TextComponent(); });

    rm.AddFont("resources/Corki-Regular.otf");

    ef.Create("scripts/ball.lua", this->GetWindow()->getSize().x / 2, this->GetWindow()->getSize().y / 2);
    ef.Create("scripts/paddle.lua", 0, this->GetWindow()->getSize().y / 2);
    ef.Create("scripts/ai_paddle.lua", this->GetWindow()->getSize().x - 10, this->GetWindow()->getSize().y / 2);

    _BeginPoint = true;
    return true;
}

/**
 * @brief PlayScene::Update Updates all systems and entities.
 */
void PlayScene::Update()
{
    sf::Event event;
    while(this->GetWindow()->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            ExitMessage msg;
            msg.ExitStatus = 0;
            Emit<ExitMessage>(msg);
        }

        else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && _BeginPoint)
        {
            _BeginPoint = false;

            PushEntityMessage msg;
            msg.ID = 0;
            msg.newVelocity.x = (rand() % 2) ? -7 : 7;
            msg.newVelocity.y = (rand() % 2) ? -5 : 5;
            Emit<PushEntityMessage>(msg);
        }
    }

    this->GetWindow()->clear();
    em.Update();
    sm.Update();
    this->GetWindow()->display();
}

/**
 * @brief PlayScene::Unload unloads all assets
 */
void PlayScene::Unload()
{
    rm.Unload();
}

/**
 * @brief PlayScene::OnMessage
 * @param msg contains the scorer
 */
void PlayScene::OnMessage(PointScoredMessage& msg)
{
    PositionComponent* pc = nullptr;
    sf::Vector2f pos;
    Entity* e = nullptr;

    for(unsigned int i = 0; i < this->GetEntities().size(); i++)
    {
        e = this->GetEntity(i);
        if(strcmp(e->GetTag(), "Ball") == 0)
        {
            pos.x = this->GetWindow()->getSize().x / 2;
            pos.y = this->GetWindow()->getSize().y / 2;
            PushEntityMessage pmsg;
            pmsg.ID = 0;
            pmsg.newVelocity.x = 0.f;
            pmsg.newVelocity.y = 0.f;
            Emit<PushEntityMessage>(pmsg);
        }

        else
        {
            pc = e->GetComponent<PositionComponent>("Position");
            pos = pc->GetPosition();
            pos.y = this->GetWindow()->getSize().y / 2;
        }

        MoveEntityMessage msg;
        msg.ID = i;
        msg.newPosition = pos;
        Emit<MoveEntityMessage>(msg);
    }

    _BeginPoint = true;
}
