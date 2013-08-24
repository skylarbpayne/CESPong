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

bool PlayScene::Load()
{
    RenderSystem* rs = new RenderSystem();
    MovementSystem* ms = new MovementSystem();
    CollisionSystem* cs = new CollisionSystem();
    BoundarySystem* bos = new BoundarySystem();
    ScoringSystem* ss = new ScoringSystem();
    BehaviorSystem* bs = new BehaviorSystem();
    AIControlSystem* as = new AIControlSystem();
    sm.Add(rs);
    sm.Add(ms);
    sm.Add(cs);
    sm.Add(ss);
    sm.Add(bos);
    sm.Add(bs);
    sm.Add(as);

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

    PushEntityMessage msg;
    msg.ID = 0;
    msg.newVelocity.x = (rand() % 2) ? -7 : 7;
    msg.newVelocity.y = (rand() % 2) ? -4 : 4;
    Emit<PushEntityMessage>(msg);
    return true;
}

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
    }

    this->GetWindow()->clear();
    em.Update();
    sm.Update();
    this->GetWindow()->display();
}

void PlayScene::Unload()
{
    rm.Unload();
}
