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
	RenderComponent() : IComponent("Render") { }
};
