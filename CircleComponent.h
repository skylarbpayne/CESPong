/** Circle Component Header
 *
 * @author      Caleb Geiger
 * Created:     8-2-2013
 * Source File:  CircleComponent.h
 */

#pragma once
#include "IRenderComponent.h"

using namespace std;
using namespace sf;


class CircleComponent : public IRenderComponent
{
friend class RenderSystem;
private:
    CircleShape _Circle;
public:
    CircleComponent(){
        _Circle.setRadius(10);
        _Circle.setFillColor(Color::Red);
    }

    void SetPosition(const Vector2f &pos) override
    {
        _Circle.setPosition(pos);
    }

    Drawable const& GetDrawable() const override
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
