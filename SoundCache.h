/**
    * Cache for storage of all sounds
    * Author: Skylar Payne
    * Date: 7/24/2013
    * File: SoundCache.h
**/

#include "IResourceCache.h"
#include <SFML/Audio.hpp>

class SoundCache : public IResourceCache<sf::SoundBuffer>
{
public:
    SoundCache(unsigned int size = 10) : IResourceCache(size) { }
    bool Add(const char* file);
    void Remove(const char* file);
    sf::SoundBuffer* Get(const char* file);
};
