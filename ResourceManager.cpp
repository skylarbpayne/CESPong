/**
    * Definition of ResourceManager as declared in ResourceManager.h
    *
    * Author: Skylar Payne
    * Date: 7/30/2013
    * File: ResourceManager.cpp
**/

#include "ResourceManager.h"

FontCache ResourceAccessor::_FontCache;
SoundCache ResourceAccessor::_SoundCache;
TextureCache ResourceAccessor::_TextureCache;

/**
 * @brief ResourceManager::~ResourceManager RAII
 */
ResourceManager::~ResourceManager()
{
    UnloadFonts();
    UnloadSounds();
    UnloadTextures();
}

/**
 * @brief ResourceManager::AddFont adds a font into the FontCache
 * @param file the font to add
 * @return true if successful, false otherwise
 */
bool ResourceManager::AddFont(const char *file)
{
    return ResourceAccessor::_FontCache.Add(file);
}

/**
 * @brief ResourceManager::RemoveFont removes a font from the FontCache
 * @param file the font to remove
 */
void ResourceManager::RemoveFont(const char *file)
{
    ResourceAccessor::_FontCache.Remove(file);
}

/**
 * @brief ResourceManager::UnloadFonts unloads all fonts from the FontCache
 */
void ResourceManager::UnloadFonts()
{
    ResourceAccessor::_FontCache.Unload();
}

/**
 * @brief ResourceManager::AddSound adds a sound into the SoundCache
 * @param file the sound to add
 * @return true if successful, false otherwise
 */
bool ResourceManager::AddSound(const char *file)
{
    return ResourceAccessor::_SoundCache.Add(file);
}

/**
 * @brief ResourceManager::RemoveSound removes a sound from the SoundCache
 * @param file the sound to remove
 */
void ResourceManager::RemoveSound(const char *file)
{
    ResourceAccessor::_SoundCache.Remove(file);
}

/**
 * @brief ResourceManager::UnloadSounds unloads all sounds from the SoundCache
 */
void ResourceManager::UnloadSounds()
{
    ResourceAccessor::_SoundCache.Unload();
}

/**
 * @brief ResourceManager::AddTexture adds a texture into the TextureCache
 * @param file the texture to add
 * @return true if successful, false otherwise
 */
bool ResourceManager::AddTexture(const char *file)
{
    return ResourceAccessor::_TextureCache.Add(file);
}

/**
 * @brief ResourceManager::RemoveTexture removes a texture from the TextureCache
 * @param file the texture to remove
 */
void ResourceManager::RemoveTexture(const char *file)
{
    ResourceAccessor::_TextureCache.Remove(file);
}

/**
 * @brief ResourceManager::UnloadTextures unloads all textures from the TextureCache
 */
void ResourceManager::UnloadTextures()
{
    ResourceAccessor::_TextureCache.Unload();
}
