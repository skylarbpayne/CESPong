/** Text Component Header
 *
 * @author      Caleb Geiger
 * Created:     8-19-2013
 * Source File:  TextComponent.h
 */

#pragma once
#include "IRenderComponent.h"

using namespace std;
using namespace sf;


class RenderComponent : public IRenderComponent
{
friend class RenderSystem;
private:
    Text _XText;
public:
    RenderComponent() : IRenderComponent() {
        _XText.setString("Text");
    }
    RectangleShape const& GetDrawable() const
    {
        return _XText;
    }
    void setText(string s){
        _XText.setString(s);
    }
    void setColor(Color const& c){
        _XText.setColor(c);
    }
    string const getText(){
        return _XText.getString();
    }
    Color const& getColor(){
        return _XText.getColor();
    }
};
