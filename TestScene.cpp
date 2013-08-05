

#include "TestScene.h"
/**
    * TestScene is the hub to test all code changes.
    *
    * Author: Skylar Payne
    * Date: 7/31/2013
    * File: TestScene.h
**/

#include <SFML/Graphics.hpp>
#include "IListener.h"

#include <lua.hpp>
#include "LuaBindings.h"
#include "Logger.h"

#include "PositionComponent.h"
#include "MovementComponent.h"
#include "MovementSystem.h"
#include "RenderComponent.h"
#include "Entity.h"
#include "RenderSystem.h"
#include "ScriptableBehavior.h"

bool TestScene::Load()
{
    RenderSystem* rs = new RenderSystem();
    sm.Add(rs);
    MovementSystem* ms = new MovementSystem();
    sm.Add(ms);

    Entity* e = new Entity();
    PositionComponent* pc = new PositionComponent();
    MovementComponent* mc = new MovementComponent();
    RenderComponent* rc = new RenderComponent();
    ScriptableBehavior* sb = new ScriptableBehavior("Move", "move.lua");
    e->AttachComponent(pc);
    e->AttachComponent(mc);
    e->AttachComponent(rc);
    e->AttachBehavior(sb);
    em.AddEntity(e);

    return true;
}

void TestScene::Update()
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

        else if(event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::Q)
            {
                lua_State* L = luaL_newstate();
                SetBindings(L);
                if(luaL_dofile(L, "luatest.lua"))
                {
                    g_Logger << lua_tostring(L, -1) << "\n";
                    lua_pop(L, 1);
                }
                lua_close(L);
            }
        }
    }

    this->GetWindow()->clear();
    sm.Update();
    bm.Update();
    this->GetWindow()->display();
}

void TestScene::Unload()
{
    rm.Unload();
}
