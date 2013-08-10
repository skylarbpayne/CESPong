/**
    * The ColliderComponent contains essential data for collision checking
    *
    * Author: Skylar Payne
    * Date: 8/5/2013
    * File: ColliderComponent.h
**/

#pragma once

#include <SFML/Graphics.hpp>
#include "IComponent.h"
#include <lua.hpp>

class ColliderComponent : public IComponent
{
friend class CollisionSystem;
private:
    sf::Vector2f _Offset;
    sf::Vector2f _Dimensions;
public:
    ColliderComponent(float x = 0, float y = 0, float w = 0, float h = 0) : IComponent("Collider"), _Offset(x, y), _Dimensions(w, h) { }
    ~ColliderComponent() { }

    sf::Vector2f const& GetOffset() const { return _Offset; }
    sf::Vector2f const& GetDimensions() const { return _Dimensions; }

    void Load(lua_State *L) override
    {
        lua_pushstring(L, "w");
        lua_gettable(L, -2);
        _Dimensions.x = lua_tonumber(L, -1);
        lua_pop(L, 1);

        lua_pushstring(L, "h");
        lua_gettable(L, -2);
        _Dimensions.y = lua_tonumber(L, -1);
        lua_pop(L, 1);

        lua_pushstring(L, "offsetx");
        lua_gettable(L, -2);
        _Offset.x = lua_tonumber(L, -1);
        lua_pop(L, 1);

        lua_pushstring(L, "offsety");
        lua_gettable(L, -2);
        _Offset.y = lua_tonumber(L, -1);
        lua_pop(L, 1);
    }
};
