/**
    * The BoundarySystem ensures that both paddles and the game ball stay within the window.
    *
    * Author: Skylar Payne
    * Date: 8/23/2013
    * File: BoundarySystem.h
**/

#pragma once

#include "ISystem.h"
#include "WindowAccessor.h"

class BoundarySystem : public ISystem, public WindowAccessor
{
public:
    BoundarySystem() : ISystem("Boundary") { }

    void Update(unsigned int dt) override;
    bool ValidateEntity(unsigned int ID) override;
};
