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

template<class T>
class Listener
{
private:
    static std::list<Listener<T>*> _Listeners;
public:
    Listener() { _Listeners.push_back(this); }
    virtual ~Listener() { _Listeners.remove(this); }

    virtual void onMessage(T& msg) { }
    void Emit(T& msg)
    {
        typename std::list<Listener<T>*>::iterator it;
        for(it = _Listeners.begin(); it != _Listeners.end(); it++)
        {
            if(*it)
            {
                (*it)->onMessage(msg);
            }
        }

    }
};

template<class T>
std::list<Listener<T>*> Listener<T>::_Listeners;
