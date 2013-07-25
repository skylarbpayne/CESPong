/**
    * Data structs for all message types
    *
    * Author: Skylar Payne
    * Date: 7/24/2013
    * File: Message.h
**/

#pragma once

/**
 * @brief The EntityMessage struct carries essentially data regarding entity messages such as the creation or destruction of an entity.
 */
struct EntityMessage
{
    unsigned int ID;
    bool Destroyed;
};
