#pragma once

#include "IComponent.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


class PositionComponent : public IComponent{
private:
	Vector2f _Position;
public:
	PositionComponent(float x = 0, float y = 0) : IComponent("Position"){
	    _Position.x = x;
	    _Position.y = y;
	}
	Vector2f const& GetPosition() const { return _Position; }
	void SetPosition(int x, int y) {
	    _Position.x = x;
	    _Position.y = y;
	}
};
