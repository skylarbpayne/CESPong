/**
    * Implementation of SoundCache as declared in SoundCache.h
    *
    * Author: Skylar Payne
    * Date: 7/24/2013
    * File: SoundCache.cpp
**/

#include "SoundCache.h"

/**
 * @brief SoundCache::Add adds a sound into the cache
 * @param file the sound to add
 * @return true if font was successfully added or already added, false otherwise
 */
bool SoundCache::Add(const char *file)
{
    SoundMap::iterator it = _Resources.find(file);
    if(it != _Resources.end())
    {
        return true;
    }

    sf::SoundBuffer* newSound = new sf::SoundBuffer();
    if(!newSound->loadFromFile(file))
    {
        delete newSound;
        newSound = nullptr;
        return false;
    }

    _Resources[file] = newSound;
    return true;
}

/**
 * @brief SoundCache::Remove removes a sound from the cache
 * @param file the sound to remove
 */
void SoundCache::Remove(const char *file)
{
    SoundMap::iterator it = _Resources.find(file);
    _Resources.erase(it);
}

/**
 * @brief SoundCache::Get gets a sound from the cache
 * @param file the sound to get
 * @return the sound, if found, nullptr otherwise
 */
sf::SoundBuffer* SoundCache::Get(const char *file)
{
    SoundMap::iterator it = _Resources.find(file);
    if(it == _Resources.end())
    {
        return nullptr;
    }

    return _Resources[file];
}
