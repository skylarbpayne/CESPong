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

ResourceManager::~ResourceAllocator()
{
    UnloadFonts();
    UnloadSounds();
    UnloadTextures();
}

bool ResourceManager::AddFont(const char *file)
{
    return ResourceAccessor::_FontCache.Add(file);
}

void ResourceManager::RemoveFont(const char *file)
{
    ResourceAccessor::_FontCache.Remove(file);
}

void ResourceManager::UnloadFonts()
{
    ResourceAccessor::_FontCache.Unload();
}

bool ResourceManager::AddSound(const char *file)
{
    return ResourceAccessor::_SoundCache.Add(file);
}

void ResourceManager::RemoveSound(const char *file)
{
    ResourceAccessor::_SoundCache.Remove(file);
}

void ResourceManager::UnloadSounds()
{
    ResourceAccessor::_SoundCache.Unload();
}

bool ResourceManager::AddTexture(const char *file)
{
    return ResourceAccessor::_TextureCache.Add(file);
}

void ResourceManager::RemoveTexture(const char *file)
{
    ResourceAccessor::_TextureCache.Remove(file);
}

void ResourceManager::UnloadTextures()
{
    ResourceAccessor::_TextureCache.Unload();
}
