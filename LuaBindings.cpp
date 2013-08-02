/**
    * LuaBindings contains function declarations regarding lua binding.
    *
    * Author: Skylar Payne
    * Date: 8/1/2013
    * File: LuaBindings.h
**/

#include "LuaBindings.h"
#include "IListener.h"

extern "C"
{

/**
 * @brief exit Lets lua emit an exit message
 * @param L the lua thread to perform this function on
 * @return the exit status
 */
static int Exit(lua_State* L)
{
    ExitMessage msg;
    msg.ExitStatus = lua_tonumber(L, 1);
    Emit<ExitMessage>(msg);
    return msg.ExitStatus;
}
}

/**
 * @brief SetBindings loads standard lua libraries and binds the functions and data defined above
 * @param L the lua state to which to bind
 */
void SetBindings(lua_State *L)
{
    luaL_openlibs(L);

    lua_pushcfunction(L, Exit);
    lua_setglobal(L, "exit");
}
