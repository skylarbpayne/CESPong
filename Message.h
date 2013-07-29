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
