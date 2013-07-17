/**
	* The Message class holds data regarding a message in the form of a message type and union of message data structs
	
	* Author: Skylar Payne
	* Date: 6/8/2013
	* File: Message.h
**/

#pragma once

#include <string>

class Message
{
public:
	struct EntityMessage
	{
		int ID;
	};

	struct ComponentMessage
	{
        int ID;
		const char* componentType;
	};

    enum MessageType
    {
        EntityCreated = 0, EntityDestroyed, DestroyEntity, ComponentAdded, ComponentRemoved, NumberOfMessages,
    };
public:
    unsigned int _Delay;
    MessageType _MessageType;
	
	union
	{
		EntityMessage _EntityMessage;
		ComponentMessage _ComponentMessage;
	};
};
