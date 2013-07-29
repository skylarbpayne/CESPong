/**
    * Implementation of TextureCache as declared in TextureCache.h
    *
    * Author: Skylar Payne
    * Date: 7/24/2013
    * File: TextureCache.cpp
**/

#include "TextureCache.h"

#include "Logger.h"

/**
 * @brief TextureCache::Add adds a texture into the cache
 * @param file the texture to add into the cache
 * @return true if texture was successfully loaded or already loaded, false otherwise
 */
bool TextureCache::Add(const char* file)
{
    TextureMap::iterator it = _Resources.find(file);
    if(it != _Resources.end())
    {
        g_Logger << __FILE__ << ": " << __LINE__ << "-Error: " << file << " already exists in TextureCache\n";
        return true;
    }

    sf::Texture* newTexture = new sf::Texture();
    if(!newTexture->loadFromFile(file))
    {
        delete newTexture;
        newTexture = nullptr;

        g_Logger << __FILE__ << ": " << __LINE__ << "-Error: " << file << " failed to load\n";
        return false;
    }

    _Resources[file] = newTexture;
    g_Logger << __FILE__ << ": " << __LINE__ << "-" << file << " was successfullly added to SoundCache\n";
    return true;
}

/**
 * @brief TextureCache::Remove removes a texture from the cache
 * @param file the texture to remove
 */
void TextureCache::Remove(const char* file)
{
    TextureMap::iterator it = _Resources.find(file);

    if(it != _Resources.end())
    {
        _Resources.erase(it);
        g_Logger << __FILE__ << ": " << __LINE__ << "-" << file << " was removed from TextureCache\n";
    }

}

/**
 * @brief TextureCache::Get gets a texture from the cache
 * @param file the texture to get
 * @return the texture if found, nullptr otherwise
 */
sf::Texture* TextureCache::Get(const char* file)
{
    TextureMap::iterator it = _Resources.find(file);
    if(it == _Resources.end())
    {
        return nullptr;
    }

    return _Resources[file];
}
