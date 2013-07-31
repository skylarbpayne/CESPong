/**
    * The SceneManager facilitates the changing of scenes.
    *
    * Author: Skylar Payne
    * Date: 6/30/2013
    * File: SceneManager.cpp
**/

#include "SceneManager.h"

/**
 * @brief SceneManager::~SceneManager RAII
 */
SceneManager::~SceneManager()
{
    Quit();
}

/**
 * @brief SceneManager::Init initializes the SceneManager with a starting scene
 * @param startScene the scene to start with
 * @return true if not already initialized, startScene is not nullptr, AND loaded successfully. False otherwise.
 */
bool SceneManager::Init(IScene* startScene)
{
    if(startScene && !_CurrentScene)
    {
        _CurrentScene = startScene;
        return _CurrentScene->Load();
    }

    return false;
}

/**
 * @brief SceneManager::Update Updates the current scene. Also handles changing scenes if necessary.
 */
void SceneManager::Update()
{
    if(_NextScene)
    {
        this->ChangeScene();
    }

    if(_CurrentScene)
    {
        _CurrentScene->Update();
    }
}

/**
 * @brief SceneManager::Quit Handles the unloading of current scene when the program ends
 */
void SceneManager::Quit()
{
    if(_CurrentScene)
    {
        _CurrentScene->Unload();
        delete _CurrentScene;
        _CurrentScene = nullptr;
    }

    if(_NextScene)
    {
        delete _NextScene;
        _NextScene = nullptr;
    }
}

/**
 * @brief SceneManager::ChangeScene changes scenes when there's a new scene
 */
void SceneManager::ChangeScene()
{
    if(_CurrentScene)
    {
        _CurrentScene->Unload();
        delete _CurrentScene;
        _CurrentScene = nullptr;
    }

    _CurrentScene = _NextScene;
    _NextScene = nullptr;

    _CurrentScene->Load();
}

void SceneManager::OnMessage(ChangeSceneMessage& msg)
{
    _NextScene = msg.NextScene;
}
