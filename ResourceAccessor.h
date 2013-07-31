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
    friend class ResourceManager;
private:
    static FontCache _FontCache;
    static SoundCache _SoundCache;
    static TextureCache _TextureCache;
protected:
    /**
     * @brief GetFont Gets a font from the FontCache
     * @param file the font to get
     * @return the font, if found, nullptr otherwise
     */
    sf::Font const* GetFont(const char* file) const { return _FontCache.Get(file); }

    /**
     * @brief GetSound Gets a sound from the SoundCache
     * @param file the sound to get
     * @return the sound, if found, nullptr otherwise
     */
    sf::SoundBuffer const* GetSound(const char* file) const { return _SoundCache.Get(file); }

    /**
     * @brief GetTexture Gets a texture from the TextureCache
     * @param file the texture to get
     * @return the texture, if found, nullptr otherwise
     */
    sf::Texture const* GetTexture(const char* file) const {return _TextureCache.Get(file); }
};
