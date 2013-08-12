/**
    * TestScene is the hub to test all code changes.
    *
    * Author: Skylar Payne
    * Date: 7/31/2013
    * File: TestScene.h
**/

#pragma once

#include "IScene.h"
#include "WindowAccessor.h"

#include "ResourceManager.h"
#include "SystemManager.h"
#include "EntityManager.h"
#include "EntityFactory.h"

class TestScene : public IScene, public WindowAccessor
{
private:
    ResourceManager rm;
    SystemManager sm;
    EntityManager em;
    EntityFactory ef;
public:
    bool Load() override;
    void Update() override;
    void Unload() override;
};
