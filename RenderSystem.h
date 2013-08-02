#pragma once

#include "IComponent.h"

RenderSystem : public ISystem, public WindowAccessor
{
public:
	void Update(unsigned int dt);
	bool ValidateEntity(unsigned int ID);
};
