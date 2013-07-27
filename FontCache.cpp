/**
    * Implementation of FontCache as declared in FontCache.h
    *
    * Author: Skylar Payne
    * Date: 7/24/2013
    * File: FontCache.cpp
**/

#include "FontCache.h"

#include "Logger.h"

/**
 * @brief FontCache::Add adds a font into the cache
 * @param file the font to add
 * @return true if font was successfully added or already added, false otherwise
 */
bool FontCache::Add(const char *file)
{
    FontMap::iterator it = _Resources.find(file);
    if(it != _Resources.end())
    {
        g_Logger << __FILE__ << ": " << __LINE__ << "-Error: " << file << " already exists in FontCache\n";
        return true;
    }

    sf::Font* newFont = new sf::Font();
    if(!newFont->loadFromFile(file))
    {
        delete newFont;
        newFont = nullptr;

        g_Logger << __FILE__ << ": " << __LINE__ << "-Error: " << file << " failed to load\n";
        return false;
    }

    _Resources[file] = newFont;
    g_Logger << __FILE__ << ": " << __LINE__ << "-" << file << " was successfullly added to FontCache\n";
    return true;
}

/**
 * @brief FontCache::Remove removes a font from the cache
 * @param file the font to remove
 */
void FontCache::Remove(const char *file)
{
    FontMap::iterator it = _Resources.find(file);

    if(it != _Resources.end())
    {
        _Resources.erase(it);
        g_Logger << __FILE__ << ": " << __LINE__ << "-" << file << " was removed from FontCache\n";
    }
}

/**
 * @brief FontCache::Get gets a font from the cache
 * @param file the font to get
 * @return the font, if found, nullptr otherwise
 */
sf::Font* FontCache::Get(const char *file)
{
    FontMap::iterator it = _Resources.find(file);
    if(it == _Resources.end())
    {
        return nullptr;
    }

    return _Resources[file];
}
