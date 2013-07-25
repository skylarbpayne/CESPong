/**
    * Implementation of FontCache as declared in FontCache.h
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
    sf::Font* newFont = new sf::Font();
    if(!newFont->loadFromFile(file) || !_Resources.Add(file, newFont))
    {
        delete newFont;
        newFont = nullptr;
        return false;
    }

    return true;
}

/**
 * @brief FontCache::Remove removes a font from the cache
 * @param file the font to remove
 */
void FontCache::Remove(const char *file)
{
    _Resources.Remove(file);
}

/**
 * @brief FontCache::Get gets a font from the cache
 * @param file the font to get
 * @return the font, if found, nullptr otherwise
 */
sf::Font* FontCache::Get(const char *file)
{
    return _Resources.Get(file);
}
