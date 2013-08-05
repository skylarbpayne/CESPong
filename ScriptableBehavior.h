/**
    * The ScriptableBehavior class implements IBehavior mechanics using a Lua script.
    *
    * Author: Skylar Payne
    * Date: 8/5/2013
    * File: ScriptableBehavior.h
**/

#pragma once

#include "IBehavior.h"

class lua_State;

class ScriptableBehavior : public IBehavior
{
friend class BehaviorManager;
private:
    const char* _Script;
    static lua_State* s_L;
private:
    void LoadFile();
public:
    ScriptableBehavior(const char* script, const char* type) : _Script(script), IBehavior(type) { }
    ~ScriptableBehavior() { }

    void Update() override;
    void OnCollide(unsigned int ID, sf::Vector2f& norm) override;
};
