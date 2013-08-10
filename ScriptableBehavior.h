/**
    * The ScriptableBehavior class implements IBehavior mechanics using a Lua script.
    *
    * Author: Skylar Payne
    * Date: 8/5/2013
    * File: ScriptableBehavior.h
**/

#pragma once

#include "IBehavior.h"
#include <string>

class lua_State;

class ScriptableBehavior : public IBehavior
{
friend class BehaviorManager;
private:
    static lua_State* s_L;
    std::string _Script;
private:
    void LoadFile();
public:
    ScriptableBehavior(const char* type, const char* script) : IBehavior(type) { _Script = script; }
    ~ScriptableBehavior() { }

    void Update() override;
    void OnCollide(unsigned int ID, sf::Vector2f& norm) override;
};
