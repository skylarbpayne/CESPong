/**
    * Data structs for all message types
    *
    * Author: Skylar Payne
    * Date: 7/24/2013
    * File: Message.h
**/

#pragma once

#include <SFML/Graphics.hpp>

/**
 * @brief The EntityMessage struct carries essential data regarding entity messages such as the creation or destruction of an entity.
 */
struct EntityMessage
{
    unsigned int ID;
    bool Destroyed;
};

/**
 * @brief The CollisionMessage struct carries essential data regarding entity collisions.
 * includes IDs of the entities involved and the normal about which they collided.
 */
struct CollisionMessage
{
    unsigned int ID1;
    unsigned int ID2;
    sf::Vector2f norm;
};

class IScene;

/**
 * @brief The ChangeSceneMessage struct carries the NextScene-obviously essential for changing scenes.
 */
struct ChangeSceneMessage
{
    IScene* NextScene;
};

/**
 * @brief The ExitMessage struct carries the exit status (to denote success or failure) for when the game exits
 */
struct ExitMessage
{
    int ExitStatus;
};

/**
 * @brief The EntityMovedMessage struct carries the ID of an entity that moved along with its old and new positions
 */
struct EntityMovedMessage
{
    unsigned int ID;
    sf::Vector2f oldPosition;
    sf::Vector2f newPosition;
};

/**
 * @brief The MoveEntityMessage struct notifies appropriate systems to move a specific entity
 */
struct MoveEntityMessage
{
    unsigned int ID;
    sf::Vector2f newPosition;
};

/**
 * @brief The PushEntityMessage struct notifies appropriate systems to move a specific entity
 */
struct PushEntityMessage
{
    unsigned int ID;
    sf::Vector2f newVelocity;
};
