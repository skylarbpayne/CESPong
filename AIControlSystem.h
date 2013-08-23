/**
    * The AIControlSystem facilitates the control of an AI pong paddle
    *
    * Author: Skylar Payne
    * Date: 8/22/2013
    * File: AIControlSystem.h
**/

#pragma once

#include "ISystem.h"

class AIControlSystem : public ISystem
{
private:
    unsigned int _BallID;
public:
    AIControlSystem() : ISystem("AI Control") { }

    void Update(unsigned int dt) override;
    bool ValidateEntity(unsigned int ID) override;
};
