/** Render Component Header
 *
 * @author      Caleb Geiger
 * Created:     8-2-2013
 * Source File:  RenderComponent.h
 */

#pragma once

#include "IComponent.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <lua.hpp>

using namespace std;
using namespace sf;


class RenderComponent : public IComponent
{
friend class RenderSystem;
private:
    CircleShape _Circle;
public:
    RenderComponent() : IComponent("Render") { _Circle.setRadius(10); _Circle.setFillColor(sf::Color::Red); }
    CircleShape const& GetShape() const
    {
        return _Circle;
    }
    void setRadius(float radius){
        _Circle.setRadius(radius);
    }
    void setColor(Color const& c){
        _Circle.setFillColor(c);
    }
    float getRadius(){
        return _Circle.getRadius();
    }
    Color const& getColor(){
        return _Circle.getFillColor();
    }

    void Load(lua_State *L) override
    {
        lua_pushstring(L, "radius");
        lua_gettable(L, -2);
        _Circle.setRadius(lua_tonumber(L, -1));
        lua_pop(L, 1);

        lua_getglobal(L, "x");
        lua_getglobal(L, "y");

        _Circle.setPosition(lua_tonumber(L, -2), lua_tonumber(L, -1));
        lua_pop(L, 2);
    }

};
