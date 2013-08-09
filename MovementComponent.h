/**
    * The MovementComponent contains data allowing an entity to move.
    *
    * Author: Skylar Payne
    * Date: 8/3/2013
    * File: MovementComponent.h
**/

#pragma once

#include <SFML/Graphics.hpp>
#include "IComponent.h"
#include <lua.hpp>

class MovementComponent : public IComponent
{
private:
    sf::Vector2f _Velocity;
public:
    MovementComponent(float x = 0, float y = 0) : IComponent("Movement")
    {
        _Velocity.x = x;
        _Velocity.y = y;
    }

    sf::Vector2f const& GetVelocity() const
    {
        return _Velocity;
    }

    void SetVelocity(float x, float y)
    {
        _Velocity.x = x;
        _Velocity.y = y;
    }

    void Load(lua_State *L) override
    {
        lua_pushstring(L, "xv");
        lua_gettable(L, -2);
        _Velocity.x = lua_tonumber(L, -1);
        lua_pop(L, 1);
        lua_pushstring(L, "yv");
        lua_gettable(L, -2);
        _Velocity.y = lua_tonumber(L, -1);
        lua_pop(L, 1);
    }
};
