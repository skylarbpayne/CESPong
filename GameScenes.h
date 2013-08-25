/**
    * Declares all GameScenes: Splash Screen, Main Menu, Play, etc.
    *
    * Author: Skylar Payne
    * Date: 8/21/2013
    * File: GameScenes.h
**/

#pragma once

#include "IScene.h"
#include "WindowAccessor.h"
#include "IListener.h"
#include "EntityAccessor.h"

#include "ResourceManager.h"
#include "SystemManager.h"
#include "EntityManager.h"
#include "EntityFactory.h"

class PlayScene : public IScene, public WindowAccessor, public IListener<PointScoredMessage>, public EntityAccessor
{
private:
        bool _BeginPoint;
        ResourceManager rm;
        SystemManager sm;
        EntityManager em;
        EntityFactory ef;
public:
        bool Load() override;
        void Update() override;
        void Unload() override;

        void OnMessage(PointScoredMessage& msg) override;
};
