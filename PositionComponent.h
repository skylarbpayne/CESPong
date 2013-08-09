/** Position Component Header
 *
 * @author      Caleb Geiger
 * Created:     8-2-2013
 * Source File:  PositionComponent.h
 */
 #pragma once

#include "IComponent.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <lua.hpp>

using namespace std;
using namespace sf;


class PositionComponent : public IComponent
{
private:
    Vector2f _Position;
public:
    PositionComponent(float x = 0, float y = 0) : IComponent("Position")
    {
        _Position.x = x;
        _Position.y = y;
    }
    Vector2f const& GetPosition() const
    {
        return _Position;
    }
    void SetPosition(float x, float y)
    {
        _Position.x = x;
        _Position.y = y;
    }

    void Load(lua_State *L) override
    {
        lua_getglobal(L, "x");
        lua_getglobal(L, "y");

        _Position.x = lua_tonumber(L, -2);
        _Position.y = lua_tonumber(L, -1);
    }
};
