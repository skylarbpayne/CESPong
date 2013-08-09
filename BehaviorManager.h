/**
    * The BehaviorManager manages the updating of and facilitation of messages to behaviors.
    *
    * Author: Skylar Payne
    * Date: 7/28/2013
    * File: BehaviorManager.h
**/

#pragma once

#include "IBehavior.h"
#include "EntityAccessor.h"
#include "IListener.h"

class BehaviorManager : public EntityAccessor, public IListener<CollisionMessage>
{
private:
    void OnMessage(CollisionMessage& msg) override;
public:
    BehaviorManager();
    ~BehaviorManager();

    void Update();
};
