/** Rectangle Component Header
 *
 * @author      Caleb Geiger
 * Created:     8-19-2013
 * Source File:  RectangleComponent.h
 */

#pragma once
#include "IRenderComponent.h"

using namespace std;
using namespace sf;


class RenderComponent : public IRenderComponent
{
friend class RenderSystem;
private:
    RectangleShape _Rectangle;
public:
    RenderComponent() : IRenderComponent() {
        _Rectangle.setSize(Vector2f(100, 50));
        _Rectangle.setFillColor(Red);
    }
    RectangleShape const& GetDrawable() const
    {
        return _Rectangle;
    }
    void setSize(float x, float y){
        _Rectangle.setSize(Vector2f(x, y))
    }
    void setColor(Color const& c){
        _Rectangle.setFillColor(c);
    }
    Vector2f & const getSize(){
        return _Rectangle.getSize();
    }
    Color const& getColor(){
        return _Rectangle.getFillColor();
    }
};
