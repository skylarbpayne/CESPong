/**
    * Implementation of ImageCache as declared in ImageCache.h
    * Author: Skylar Payne
    * Date: 7/24/2013
    * File: ImageCache.cpp
**/

#include "ImageCache.h"

/**
 * @brief ImageCache::Add adds an image into the cache
 * @param file the image to add into the cache
 * @return true if image was successfully loaded or already loaded, false otherwise
 */
bool ImageCache::Add(const char* file)
{
    sf::Image* newImage = new sf::Image();
    if(!newImage->loadFromFile(file) || !_Resources.Add(file, newImage))
    {
        delete newImage;
        newImage = nullptr;
        return false;
    }

    return true;
}

/**
 * @brief ImageCache::Remove removes an image from the cache
 * @param file the image to remove
 */
void ImageCache::Remove(const char* file)
{
    _Resources.Remove(file);
}

/**
 * @brief ImageCache::Get gets an image from the cache
 * @param file the image to get
 * @return the image if found, false otherwise
 */
sf::Image* ImageCache::Get(const char* file)
{
    return _Resources.Get(file);
}
