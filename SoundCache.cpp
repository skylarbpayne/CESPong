/**
    * Implementation of SoundCache as declared in SoundCache.h
    *
    * Author: Skylar Payne
    * Date: 7/24/2013
    * File: SoundCache.cpp
**/

#include "SoundCache.h"

#include "Logger.h"

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
        g_Logger << __FILE__ << ": " << __LINE__ << "-Error: " << file << " already exists in SoundCache\n";
        return true;
    }

    sf::SoundBuffer* newSound = new sf::SoundBuffer();
    if(!newSound->loadFromFile(file))
    {
        delete newSound;
        newSound = nullptr;

        g_Logger << __FILE__ << ": " << __LINE__ << "-Error: " << file << " failed to load\n";
        return false;
    }

    _Resources[file] = newSound;
    g_Logger << __FILE__ << ": " << __LINE__ << "-" << file << " was successfullly added to SoundCache\n";
    return true;
}

/**
 * @brief SoundCache::Remove removes a sound from the cache
 * @param file the sound to remove
 */
void SoundCache::Remove(const char *file)
{
    SoundMap::iterator it = _Resources.find(file);

    if(it != _Resources.end())
    {
        _Resources.erase(it);
        g_Logger << __FILE__ << ": " << __LINE__ << "-" << file << " was removed from SoundCache\n";
    }
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
