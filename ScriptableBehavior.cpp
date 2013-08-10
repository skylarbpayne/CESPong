/**
    * The ScriptableBehavior class implements IBehavior mechanics using a Lua script.
    *
    * Author: Skylar Payne
    * Date: 8/5/2013
    * File: ScriptableBehavior.cpp
**/

#include "ScriptableBehavior.h"
#include <lua.hpp>
#include "Entity.h"

#include "Logger.h"

lua_State* ScriptableBehavior::s_L;

/**
 * @brief ScriptableBehavior::LoadFile loads a file, and parent ID into lua's global table
 */
void ScriptableBehavior::LoadFile()
{
    if(luaL_dofile(s_L, _Script.c_str()))
    {
        g_Logger << lua_tostring(s_L, -1) << "\n";
        lua_pop(s_L, 1);
    }

    lua_pushnumber(s_L, this->GetParent()->GetID());
    lua_setglobal(s_L, "ID");
}

/**
 * @brief ScriptableBehavior::Update Executes an update function from a lua script
 */
void ScriptableBehavior::Update()
{
    this->LoadFile();

    lua_getglobal(s_L, "Update");
    if(lua_pcall(s_L, 0, 0, 0))
    {
        g_Logger << lua_tostring(s_L, -1) << "\n";
        lua_pop(s_L, 1);
    }
}

/**
 * @brief ScriptableBehavior::OnCollide executes a scripted trigger on collision.
 * @param ID the entity collided with.
 * @param norm the collision surface/penetration depth
 */
void ScriptableBehavior::OnCollide(unsigned int ID, sf::Vector2f& norm)
{
    this->LoadFile();

    lua_getglobal(s_L, "OnCollide");
    lua_pushnumber(s_L, ID);
    lua_pushnumber(s_L, norm.x);
    lua_pushnumber(s_L, norm.y);
    lua_pcall(s_L, 3, 0, 0);
}
