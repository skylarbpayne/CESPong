/**
    * The BehaviorManager manages the updating of and facilitation of messages to behaviors.
    *
    * Author: Skylar Payne
    * Date: 7/28/2013
    * File: IBehavior.h
**/

#pragma once

#include "IBehavior.h"
#include "EntityAccessor.h"
#include "Listener.h"

class BehaviorManager : public EntityAccessor, public Listener<CollisionMessage>
{
public:
    void Update();
    void OnMessage(CollisionMessage& msg) override;
};
