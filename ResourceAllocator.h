/**
    * The ResourceAllocator allows load and unload
    *
    * Author: Skylar Payne
    * Date: 7/30/2013
    * File: ResourceAllocator.h
**/

#pragma once

#include "ResourceAccessor.h"

class ResourceAllocator
{
public:
    ~ResourceAllocator();

    bool AddFont(const char* file);
    void RemoveFont(const char* file);
    void UnloadFonts();

    bool AddSound(const char* file);
    void RemoveSound(const char* file);
    void UnloadSounds();

    bool AddTexture(const char* file);
    void RemoveTexture(const char* file);
    void UnloadTextures();
};
