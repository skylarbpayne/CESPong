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
class Listener
{
private:
    static std::list<Listener<T>*> _Listeners;
public:
    Listener() { _Listeners.push_back(this); }
    virtual ~Listener() { _Listeners.remove(this); }

    virtual void OnMessage(T& msg) = 0;
    friend void Emit<T>(T& msg);
};

template<class T>
std::list<Listener<T>*> Listener<T>::_Listeners;

template<class T>
void Emit(T& msg)
{
    typename std::list<Listener<T>*>::iterator it;
    for(it = Listener<T>::_Listeners.begin(); it != Listener<T>::_Listeners.end(); it++)
    {
        if(*it)
        {
            (*it)->OnMessage(msg);
        }
    }
}
