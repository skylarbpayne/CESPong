/**
	* The Messenger class facilitates a global messaging system. Anything that inherits from it can message
	
	* Author: Skylar Payne
	* Date: 6/8/2013
	* File: Messenger.cpp
**/

#include "Messenger.h"
#include "Message.h"

std::vector<std::list<Messenger*> > Messenger::s_Subscribers(Message::NumberOfMessages);
std::list<Message*> Messenger::s_MessageQueue;
sf::Clock Messenger::s_MessageClock;
unsigned int Messenger::s_LastTime = 0;

/**
    * @brief Messenger::Subscribe Subscribes the caller to a specific message type
	* @param type The type of message to which to subscribe
**/
void Messenger::Subscribe(int type)
{
	s_Subscribers[type].push_back(this);
}

/**
 * @brief Messenger::Unsubscribe unsubscribes the caller to a specific message type
 * @param type the type of message to which to unsubscribe
 */
void Messenger::Unsubscribe(int type)
{
    std::list<Messenger*>::iterator it;
    for(it = s_Subscribers[type].begin(); it != s_Subscribers[type].end(); it++)
    {
        if(this == (*it))
        {
            s_Subscribers[type].erase(it);
        }
    }
}

/**
    * @brief Messenger::SendMessage Stores a message into the message queue for dispatch at the end of the frame.
	* @param msg The msg to send
**/
void Messenger::SendMessage(Message* msg)
{
    if(msg->_Delay == 0)
    {
        s_MessageQueue.push_front(msg);
    }

    std::list<Message*>::iterator it;
    for(it = s_MessageQueue.begin(); it != s_MessageQueue.end(); it++)
    {
        if(msg->_Delay < (*it)->_Delay)
        {
            s_MessageQueue.insert(it, msg);
        }
    }
}

/**
    * @brief Messenger::DispatchMessages Dispatches all messages that are ready in the queue. To be called by a higher level of abstraction
**/
void Messenger::DispatchMessages()
{
    unsigned int frameTime = s_MessageClock.getElapsedTime().asMicroseconds() - s_LastTime;
    s_LastTime += frameTime;

	std::list<Message*>::iterator messageIt;
	for(messageIt = s_MessageQueue.begin(); messageIt != s_MessageQueue.end(); messageIt++)
	{
        if((*messageIt)->_Delay < frameTime)
        {
            std::list<Messenger*>::iterator messengerIt;

            for(messengerIt = s_Subscribers[(*messageIt)->_MessageType].begin(); messengerIt != s_Subscribers[(*messageIt)->_MessageType].end(); messengerIt++)
            {
                (*messengerIt)->OnMessage(*messageIt);
            }

            //Prevent an access violation
            std::list<Message*>::iterator temp = messageIt;
            messageIt++;

            if((*temp) == nullptr)
            {
                delete (*temp);
                (*temp) = nullptr;
            }
            s_MessageQueue.erase(temp);
        }

        else
        {
            (*messageIt)->_Delay -= frameTime;
        }
	}

	s_MessageQueue.clear();
}
