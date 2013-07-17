/**
	* The Messenger class facilitates a global messaging system. Anything that inherits from it can message
    *
    * Note: When inheriting from Messenger, be sure to subscribe to events in constructor and unsubscribe in destructor. RAII
	
	* Author: Skylar Payne
	* Date: 6/8/2013
	* File: Messenger.h
**/

#pragma once

#include <vector>
#include <list>
#include <SFML/System.hpp>

class Message;
class Entity;

class Messenger
{
private:
	static std::vector<std::list<Messenger*> > s_Subscribers;
	static std::list<Message*> s_MessageQueue;
    static sf::Clock s_MessageClock;
    static unsigned int s_LastTime;
protected:
	void Subscribe(int type);
    void Unsubscribe(int type);
	void SendMessage(Message* msg);
	virtual void OnMessage(Message* msg) = 0;
public:
	static void DispatchMessages();
};
