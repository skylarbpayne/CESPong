/** Render System Header
 *
 * @author      Caleb Geiger
 * Created:     8-2-2013
 * Source File:  RenderSystem.h
 */

#pragma once

#include "ISystem.h"
#include "WindowAccessor.h"


class RenderSystem : public ISystem, public WindowAccessor
{
public:
    RenderSystem() : ISystem("Render") { }
    void Update(unsigned int dt) override;
    bool ValidateEntity(unsigned int ID) override;
};
