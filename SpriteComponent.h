/** Sprite Component Header
 *
 * @author      Caleb Geiger
 * Created:     8-19-2013
 * Source File:  SpriteComponent.h
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
    Sprite _XSprite;
public:
    RenderComponent() : IRenderComponent() {
        _XSprite.setColor(Red);
    }

    void SetPosition(const Vector2f &pos) override
    {
        _XSprite.setPosition(pos);
    }

    Drawable const& GetDrawable() const
    {
        return _XSprite;
    }
    void setSpriteColor(Color const& s){
        _XSprite.setColor(s);
    }
    void setSpriteTexture(const char* file){
        _XSprite.setTexture(*this->GetTexture(file));
    }
    Color const getSpriteColor(){
        return _XSprite.getColor();
    }
    Texture const getSpriteTexture(){
        return _XSprite.getTexture();
    }
};
