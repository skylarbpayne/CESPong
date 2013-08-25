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

class SplashScene : public IScene, public ResourceAccessor, public WindowAccessor
{
private:
    sf::Clock _Clock;
    sf::Sprite _Splash;
    ResourceManager rm;
public:
    bool Load() override;
    void Update() override;
    void Unload() override;
};

class MainMenuScene : public IScene, public WindowAccessor, public ResourceAccessor
{
private:
    sf::Text _Title;
    sf::Text _Buttons[3];
    sf::RectangleShape _ButtonContainers[3];
    ResourceManager rm;
public:
    bool Load() override;
    void Update() override;
    void Unload() override;
};

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
