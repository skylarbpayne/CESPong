/**
    * LuaBindings contains function declarations regarding lua binding.
    *
    * Author: Skylar Payne
    * Date: 8/1/2013
    * File: LuaBindings.h
**/

#include "LuaBindings.h"
#include "IListener.h"
#include "WindowAccessor.h"

#include "Logger.h"

struct LuaAccessor : public WindowAccessor
{
    sf::RenderWindow& GetRenderWindow() const { return *this->GetWindow(); }
};

extern "C"
{

/**
 * @brief exit Lets lua emit an exit message
 * @param L the calling lua thread
 * @return no return value if successful, error message if failed
 */
static int Exit(lua_State* L)
{
    if(lua_gettop(L) != 1)
    {
        lua_pushstring(L, "Error: incorrect number of parameters");
        return 1;
    }

    ExitMessage msg;
    msg.ExitStatus = lua_tonumber(L, 1);
    Emit<ExitMessage>(msg);
    return 0;
}

/**
 * @brief CreateEntity lets lua emit a CreateEntityMessage
 * @param L the calling lua thread
 * @return no return value if successful, error message if failed
 */
static int CreateEntity(lua_State* L)
{
    if(lua_gettop(L) != 3)
    {
        lua_pushstring(L, "Error: incorrect number of parameters");
        return 1;
    }

    CreateEntityMessage msg;
    msg.script = lua_tostring(L, 1);
    msg.position.x = lua_tonumber(L, 2);
    msg.position.y = lua_tonumber(L, 3);
    Emit<CreateEntityMessage>(msg);
    return 0;
}

/**
 * @brief DestroyEntity lets lua emit a DestroyEntityMessage
 * @param L the calling lua thread
 * @return no return value if successful, error message if failed
 */
static int DestroyEntity(lua_State* L)
{
    if(lua_gettop(L) != 1)
    {
        lua_pushstring(L, "Error: incorrect number of parameters");
        return 1;
    }

    DestroyEntityMessage msg;
    msg.ID = lua_tonumber(L, 1);
    Emit<DestroyEntityMessage>(msg);
    return 0;
}

/**
 * @brief GetKeyState gets the key state of a certain key
 * @param L the calling lua thread
 * @return true if key was pressed, false if not pressed, or error message if failed
 */
static int isKeyPressed(lua_State* L)
{
    if(lua_gettop(L) != 1)
    {
        lua_pushstring(L, "Error: incorrect number of parameters");
        return 1;
    }

    sf::Keyboard::Key key = static_cast<sf::Keyboard::Key>(lua_tointeger(L, 1));
    lua_pushboolean(L, sf::Keyboard::isKeyPressed(key));
    return 1;
}

/**
 * @brief GetCursorPosition gets the position of the on screen cursor
 * @param L the calling lua thread
 * @return 2 return values: x position and y position of cursor or error message if failed
 */
static int GetCursorPosition(lua_State* L)
{
    if(lua_gettop(L) != 0)
    {
        lua_pushstring(L, "Error: incorrect number of parameters");
        return 1;
    }

    LuaAccessor la;
    lua_pushnumber(L, sf::Mouse::getPosition(la.GetRenderWindow()).x);
    lua_pushnumber(L, sf::Mouse::getPosition(la.GetRenderWindow()).y);
    return 2;
}

/**
 * @brief MoveEntity Lets lua emit a MoveEntity message
 * @param L the calling lua thread
 * @return no return value if successful, error message if failed
 */
static int MoveEntity(lua_State* L)
{
    if(lua_gettop(L) != 3)
    {
        lua_pushstring(L, "Error: incorrect number of parameters");
        return 1;
    }

    MoveEntityMessage msg;
    msg.ID = lua_tonumber(L, 1);
    msg.newPosition.x = lua_tonumber(L, 2);
    msg.newPosition.y = lua_tonumber(L, 3);
    Emit<MoveEntityMessage>(msg);
    return 0;
}

/**
 * @brief PushEntity Lets lua emit a PushEntity message
 * @param L the calling lua thread
 * @return no return value if successful, error message if failed
 */
static int PushEntity(lua_State* L)
{
    if(lua_gettop(L) != 3)
    {
        lua_pushstring(L, "Error: incorrect number of parameters");
        return 1;
    }

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

    lua_pushcfunction(L, CreateEntity);
    lua_setglobal(L, "create_entity");

    lua_pushcfunction(L, DestroyEntity);
    lua_setglobal(L, "destroy_entity");

    lua_pushcfunction(L, GetCursorPosition);
    lua_setglobal(L, "get_cursor_position");

    lua_pushcfunction(L, isKeyPressed);
    lua_setglobal(L, "is_key_pressed");

    lua_pushcfunction(L, MoveEntity);
    lua_setglobal(L, "move_entity");

    lua_pushcfunction(L, PushEntity);
    lua_setglobal(L, "push_entity");

    lua_newtable(L);
    lua_pushliteral(L, "W");
    lua_pushnumber(L, sf::Keyboard::W);
    lua_settable(L, -3);

    lua_pushliteral(L, "S");
    lua_pushnumber(L, sf::Keyboard::S);
    lua_settable(L, -3);

    lua_pushliteral(L, "A");
    lua_pushnumber(L, sf::Keyboard::A);
    lua_settable(L, -3);

    lua_pushliteral(L, "D");
    lua_pushnumber(L, sf::Keyboard::D);
    lua_settable(L, -3);

    lua_pushliteral(L, "Up");
    lua_pushnumber(L, sf::Keyboard::Up);
    lua_settable(L, -3);

    lua_pushliteral(L, "Down");
    lua_pushnumber(L, sf::Keyboard::Down);
    lua_settable(L, -3);

    lua_pushliteral(L, "Left");
    lua_pushnumber(L, sf::Keyboard::Left);
    lua_settable(L, -3);

    lua_pushliteral(L, "Right");
    lua_pushnumber(L, sf::Keyboard::Right);
    lua_settable(L, -3);
    lua_setglobal(L, "Keys");
}
