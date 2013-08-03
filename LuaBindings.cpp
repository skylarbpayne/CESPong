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

/**
 * @brief MoveEntity Lets lua emit a MoveEntity message
 * @param L the thread to run the function on
 * @return 0
 */
static int MoveEntity(lua_State* L)
{
    MoveEntityMessage msg;
    msg.ID = lua_tonumber(L, 1);
    msg.newPosition.x = lua_tonumber(L, 2);
    msg.newPosition.y = lua_tonumber(L, 3);
    Emit<MoveEntityMessage>(msg);
    return 0;
}

/**
 * @brief PushEntity Lets lua emit a PushEntity message
 * @param L the thread to run the function on
 * @return 0
 */
static int PushEntity(lua_State* L)
{
    PushEntityMessage msg;
    msg.ID = lua_tonumber(L, 1);
    msg.newVelocity.x = lua_tonumber(L, 2);
    msg.newVelocity.y = lua_tonumber(L, 3);
    Emit<PushEntityMessage>(msg);
    return 0;
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
