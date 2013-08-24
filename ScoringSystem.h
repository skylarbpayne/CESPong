/**
    * The ScoringSystem tracks the scores of both players
    *
    * Author: Skylar Payne
    * Date: 8/23/2013
    * File: ScoringSystem.h
**/

#pragma once

#include "ISystem.h"
#include "WindowAccessor.h"
#include "ResourceAccessor.h"

class ScoringSystem : public ISystem, public WindowAccessor, public ResourceAccessor
{
private:
    unsigned int _Player1Score;
    unsigned int _Player2Score;
    unsigned int _BallID;
public:
    ScoringSystem() : ISystem("Scoring"), _Player1Score(0), _Player2Score(0) { }

    void Update(unsigned int dt) override;
    bool ValidateEntity(unsigned int ID) override;
};
