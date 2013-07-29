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

typedef std::unordered_map<const char*, sf::Texture*, eqstr, eqstr> TextureMap;

class TextureCache : public IResourceCache<sf::Texture>
{
public:
    TextureCache(unsigned int size = 10) : IResourceCache("Texture", size) { }
    bool Add(const char* file);
    void Remove(const char* file);
    sf::Texture* Get(const char* file);
};
