/**
    * WindowAccessor allows wide access to window specific methods while ensuring that only one class can change it

    * Author: Skylar Payne
    * Date: 7/23/2013
    * File: WindowAccessor.h
**/

#pragma once

#include <SFML/Graphics.hpp>

class WindowAccessor
{
friend class Engine;
private:
    static sf::RenderWindow* s_RenderWindow;
protected:
    /**
     * @brief GetWindow gets the main window
     * @return the main window, if set, nullptr otherwise
     */
    sf::RenderWindow const* GetWindow() const { return s_RenderWindow; }
};
