/**
    * Cache for sf::Images
    *
    * Author: Skylar Payne
    * Date: 7/24/2013
    * File: ImageCache.h
**/

#pragma once

#include "IResourceCache.h"
#include <SFML/Graphics.hpp>

class ImageCache : public IResourceCache<sf::Image>
{
public:
    ImageCache(unsigned int size = 10) : IResourceCache(size) { }
    bool Add(const char* file);
    void Remove(const char* file);
    sf::Image* Get(const char* file);
};
