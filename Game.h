/**
    * The Game class takes care of the lower level stuff such as setting up the window
    *
    * Author: Skylar Payne
    * Date: 6/30/2013
    * File: Game.h
**/

#pragma once

#include "SceneManager.h"
#include "IListener.h"

class Game
{
private:
    bool _Running;
    int _ExitStatus;
    SceneManager _SceneManager;
public:
    Game() : _Running(true), _ExitStatus(0) { }
    ~Game() { Quit(); }

    bool Init(unsigned int width, unsigned int height, const char* title, IScene* startScene);
    void Run();
    void Quit();

    /**
     * @brief GetExitStatus gets the exit status of the game
     * @return the exit status
     */
    int GetExitStatus() const { return _ExitStatus; }
};
