/** Text Component Header
 *
 * @author      Caleb Geiger
 * Created:     8-19-2013
 * Source File:  TextComponent.h
 */

#pragma once
#include "IRenderComponent.h"
#include "ResourceAccessor.h"

using namespace std;
using namespace sf;


class RenderComponent : public IRenderComponent, public ResourceAccessor
{
friend class RenderSystem;
private:
    Text _XText;
public:
    RenderComponent() : IRenderComponent() {
        _XText.setString("Text");
    }

    void SetPosition(const Vector2f &pos) override
    {
        _XText.setPosition(pos);
    }

    RectangleShape const& GetDrawable() const
    {
        return _XText;
    }
    void setText(string const& s){
        _XText.setString(s);
    }
    void setFont(const char* file){
        _XText.setFont(*this->GetFont(file));
    }
    void setSize(unsigned int i){
        _XText.setCharacterSize(i);
    }
    void setStyle(Style const& sT){
        _XText.setStyle(sT);
    }
    void setColor(Color const& c){
        _XText.setColor(c);
    }
    string const& getText(){
        return _XText.getString();
    }
    Font const& getFont(){
       _XText.getFont();
    }
    unsigned int getSize(){
        _XText.getCharacterSize();
    }
    Style const& getStyle(){
        _XText.getStyle();
    }
    Color const& getColor(){
        return _XText.getColor();
    }
};
