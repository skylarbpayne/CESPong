/**
    * Templated class to allow a derived class to be notified of specific messages
    *
    * Author: Skylar Payne
    * Date: 7/24/2013
    * File: Listener.h
**/

#pragma once

#include <list>
#include "Message.h"

template<class T> void Emit(T& msg);

template<class T>
class IListener
{
private:
    static std::list<IListener<T>*> _Listeners;
public:
    IListener() { _Listeners.push_back(this); }
    virtual ~IListener() { _Listeners.remove(this); }

    virtual void OnMessage(T& msg) = 0;
    friend void Emit<T>(T& msg);
};

template<class T>
std::list<IListener<T>*> IListener<T>::_Listeners;

template<class T>
void Emit(T& msg)
{
    typename std::list<IListener<T>*>::iterator it;
    for(it = IListener<T>::_Listeners.begin(); it != IListener<T>::_Listeners.end(); it++)
    {
        if(*it)
        {
            (*it)->OnMessage(msg);
        }
    }
}
