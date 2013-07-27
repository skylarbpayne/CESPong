/**
    * Implementation of FontCache as declared in FontCache.h
    *
    * Author: Skylar Payne
    * Date: 7/24/2013
    * File: FontCache.cpp
**/

#include "FontCache.h"

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
        return true;
    }

    sf::Font* newFont = new sf::Font();
    if(!newFont->loadFromFile(file))
    {
        delete newFont;
        newFont = nullptr;
        return false;
    }

    _Resources[file] = newFont;
    return true;
}

/**
 * @brief FontCache::Remove removes a font from the cache
 * @param file the font to remove
 */
void FontCache::Remove(const char *file)
{
    FontMap::iterator it = _Resources.find(file);
    _Resources.erase(it);
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
