/**
    * Implementation of ImageCache as declared in ImageCache.h
    *
    * Author: Skylar Payne
    * Date: 7/24/2013
    * File: ImageCache.cpp
**/

#include "ImageCache.h"

#include "Logger.h"

/**
 * @brief ImageCache::Add adds an image into the cache
 * @param file the image to add into the cache
 * @return true if image was successfully loaded or already loaded, false otherwise
 */
bool ImageCache::Add(const char* file)
{
    ImageMap::iterator it = _Resources.find(file);
    if(it != _Resources.end())
    {
        g_Logger << __FILE__ << ": " << __LINE__ << "-Error: " << file << " already exists in ImageCache\n";
        return true;
    }

    sf::Image* newImage = new sf::Image();
    if(!newImage->loadFromFile(file))
    {
        delete newImage;
        newImage = nullptr;

        g_Logger << __FILE__ << ": " << __LINE__ << "-Error: " << file << " failed to load\n";
        return false;
    }

    _Resources[file] = newImage;
    g_Logger << __FILE__ << ": " << __LINE__ << "-" << file << " was successfullly added to SoundCache\n";
    return true;
}

/**
 * @brief ImageCache::Remove removes an image from the cache
 * @param file the image to remove
 */
void ImageCache::Remove(const char* file)
{
    ImageMap::iterator it = _Resources.find(file);

    if(it != _Resources.end())
    {
        _Resources.erase(it);
        g_Logger << __FILE__ << ": " << __LINE__ << "-" << file << " was removed from ImageCache\n";
    }

}

/**
 * @brief ImageCache::Get gets an image from the cache
 * @param file the image to get
 * @return the image if found, false otherwise
 */
sf::Image* ImageCache::Get(const char* file)
{
    ImageMap::iterator it = _Resources.find(file);
    if(it == _Resources.end())
    {
        return nullptr;
    }

    return _Resources[file];
}
