/**
    * The SceneManager facilitates the changing of scenes.
    *
    * Author: Skylar Payne
    * Date: 6/30/2013
    * File: SceneManager.h
**/

#pragma once

#include "IListener.h"
#include "IScene.h"

class SceneManager : public IListener<ChangeSceneMessage>
{
private:
    IScene* _CurrentScene;
    IScene* _NextScene;
private:
    void ChangeScene();
    void OnMessage(ChangeSceneMessage& msg) override;
public:
    SceneManager() : _CurrentScene(nullptr), _NextScene(nullptr) { }
    ~SceneManager();

    bool Init(IScene* startScene);
    void Update();
    void Quit();
};
