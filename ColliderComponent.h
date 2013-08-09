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
    ColliderComponent(float x, float y, float w, float h) : IComponent("Collider"), _Offset(x, y), _Dimensions(w, h) { }
    ~ColliderComponent() { }

    sf::Vector2f const& GetOffset() const { return _Offset; }
    sf::Vector2f const& GetDimensions() const { return _Dimensions; }

    void Load(lua_State *L)
    {

    }
};
