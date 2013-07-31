/**
    * Interface for all Scenes. Scenes control the flow of logic
    *
    * Author: Skylar Payne
    * Date: 6/30/2013
    * File: IScene.h
**/

#pragma once

class IScene
{
    friend class SceneManager;
protected:
    virtual bool Load() = 0;
    virtual void Update() = 0;
    virtual void Unload() = 0;
};
