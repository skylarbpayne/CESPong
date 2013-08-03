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

using namespace std;
using namespace sf;


class RenderComponent : public IComponent
{
private:
    CircleShape _Circle;
public:
    RenderComponent() : IComponent("Render") { _Circle.setRadius(4); _Circle.setFillColor(sf::Color::Red); }
    CircleShape const GetShape()
    {
        return _Circle;
    }
};
