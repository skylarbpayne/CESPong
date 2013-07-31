/**
    * Definition of Game class as declared in Game.h
    *
    * Author: Skylar Payne
    * Date: 6/30/2013
    * File: Game.cpp
**/

#include "Game.h"
#include "WindowAccessor.h"

sf::RenderWindow* WindowAccessor::s_RenderWindow;

/**
 * @brief Game::Init initializes the game by setting up the window and scene manager
 * @param width the width of the window
 * @param height the height of the window
 * @param title the title of the window
 * @param startScene the scene with which to start
 * @return true if everything was properly initialized, false otherwise
 */
bool Game::Init(unsigned int width, unsigned int height, const char* title, IScene *startScene)
{
    WindowAccessor::s_RenderWindow = new sf::RenderWindow(sf::VideoMode(width, height), title);
    return (WindowAccessor::s_RenderWindow && _SceneManager.Init(startScene));
}

/**
 * @brief Game::Run continuously runs until _Running is set false by an exit message
 */
void Game::Run()
{
    while(_Running)
    {
        _SceneManager.Update();
    }
}

/**
 * @brief Game::Quit shuts down the scene manager and deallocates the window
 */
void Game::Quit()
{
    _SceneManager.Quit();

    if(WindowAccessor::s_RenderWindow)
    {
        WindowAccessor::s_RenderWindow->close();
        delete WindowAccessor::s_RenderWindow;
        WindowAccessor::s_RenderWindow = nullptr;
    }
}

/**
 * @brief Game::OnMessage catches the exit message to safely shut down the game
 * @param msg contains the exit status
 */
void Game::OnMessage(ExitMessage& msg)
{
    _ExitStatus = msg.ExitStatus;
    _Running = false;
}
