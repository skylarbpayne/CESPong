/**
    * The MovementSystem updates PositionComponents
    *
    * Author: Skylar Payne
    * Date: 8/3/2013
    * File: MovementSystem.h
**/

#pragma once

#include "IListener.h"
#include "ISystem.h"

class MovementSystem : public ISystem
{
public:
    void Update(unsigned int dt) override;
    bool ValidateEntity(unsigned int ID) override;
};
