/**
    * Cache for storage of all fonts
    * Author: Skylar Payne
    * Date: 7/24/2013
    * File: FontCache.h
**/

#pragma once

#include "IResourceCache.h"
#include <SFML/Graphics.hpp>

class FontCache : public IResourceCache<sf::Font>
{
public:
    FontCache(unsigned int size = 10) : IResourceCache(size) { }
    bool Add(const char* file);
    void Remove(const char* file);
    sf::Font* Get(const char* file);
};
