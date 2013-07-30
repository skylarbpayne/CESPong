/**
    * Definition of ResourceAllocator as declared in ResourceAllocator.h
    *
    * Author: Skylar Payne
    * Date: 7/16/2013
    * File: ResourceAllocator.cpp
**/

#include "ResourceAllocator.h"

FontCache ResourceAccessor::_FontCache;
SoundCache ResourceAccessor::_SoundCache;
TextureCache ResourceAccessor::_TextureCache;

ResourceAllocator::~ResourceAllocator()
{
    UnloadFonts();
    UnloadSounds();
    UnloadTextures();
}

bool ResourceAllocator::AddFont(const char *file)
{
    return ResourceAccessor::_FontCache.Add(file);
}

void ResourceAllocator::RemoveFont(const char *file)
{
    ResourceAccessor::_FontCache.Remove(file);
}

void ResourceAllocator::UnloadFonts()
{
    ResourceAccessor::_FontCache.Unload();
}

bool ResourceAllocator::AddSound(const char *file)
{
    return ResourceAccessor::_SoundCache.Add(file);
}

void ResourceAllocator::RemoveSound(const char *file)
{
    ResourceAccessor::_SoundCache.Remove(file);
}

void ResourceAllocator::UnloadSounds()
{
    ResourceAccessor::_SoundCache.Unload();
}

bool ResourceAllocator::AddTexture(const char *file)
{
    return ResourceAccessor::_TextureCache.Add(file);
}

void ResourceAllocator::RemoveTexture(const char *file)
{
    ResourceAccessor::_TextureCache.Remove(file);
}

void ResourceAllocator::UnloadTextures()
{
    ResourceAccessor::_TextureCache.Unload();
}
