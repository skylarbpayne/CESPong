#pragma once

#include "IScene.h"
#include "WindowAccessor.h"

#include "ResourceManager.h"
#include "SystemManager.h"
#include "BehaviorManager.h"
#include "EntityManager.h"

class TestScene : public IScene, public WindowAccessor
{
private:
    ResourceManager rm;
    SystemManager sm;
    BehaviorManager bm;
    EntityManager em;
public:
    bool Load() override;
    void Update() override;
    void Unload() override;
};
