#include "TestScene.h"

#include <SFML/Graphics.hpp>
#include "IListener.h"

#include <lua.hpp>
#include "LuaBindings.h"
#include "Logger.h"

bool TestScene::Load()
{
    return true;
}

void TestScene::Update()
{
    sm.Update();
    bm.Update();

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
    this->GetWindow()->display();
}

void TestScene::Unload()
{
    rm.Unload();
}
