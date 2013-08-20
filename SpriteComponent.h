/** Sprite Component Header
 *
 * @author      Caleb Geiger
 * Created:     8-19-2013
 * Source File:  SpriteComponent.h
 */

#pragma once
#include "IRenderComponent.h"

using namespace std;
using namespace sf;

class RenderComponent : public IRenderComponent
{
friend class RenderSystem;
private:
    Sprite _XSprite;
public:
    RenderComponent() : IRenderComponent() {
        _XSprite.setColor(Red);
    }
    Drawable const& GetDrawable() const
    {
        return _XSprite;
    }
    void setSpriteColor(string s){
        _XSprite.setColor();
    }
    void setSpriteTexture(Texture t){
        _XSprite.setTexture(t);
    }
    Color const getSpriteColor(){
        return _XSprite.getColor();
    }
    Texture const getSpriteTexture(){
        return _XSprite.getTexture();
    }
};
