/**
    * The ResourceAccessor allows wide access to resources.
    *
    * Author: Skylar Payne
    * Date: 7/30/2013
    * File: ResourceAccessor.h
**/

#pragma once

#include "FontCache.h"
#include "SoundCache.h"
#include "TextureCache.h"

class ResourceAccessor
{
    friend class ResourceAllocator;
private:
    static FontCache _FontCache;
    static SoundCache _SoundCache;
    static TextureCache _TextureCache;
protected:
    sf::Font const* GetFont(const char* file) const { return _FontCache.Get(file); }
    sf::SoundBuffer const* GetSound(const char* file) const { return _SoundCache.Get(file); }
    sf::Texture const* GetTexture(const char* file) const {return _TextureCache.Get(file); }
};
