/**
    * Templated class to allow a derived class to be notified of specific messages
    *
    * Author: Skylar Payne
    * Date: 7/24/2013
    * File: Listener.h
**/

#include <list>

template<class T>
class Listener
{
private:
    std::list<Listener<T>*> _Listeners;
public:
    Listener() { _Listeners.push_back(this); }
    virtual ~Listener() { _Listeners.remove(this); }

    virtual void onMessage(T& msg) { }
    void Emit(T& msg)
    {
        std::list<Listener<T>*>::iterator it;
        for(it = _Listeners.begin(); it != _Listeners.end(); it++)
        {
            if(*it)
            {
                (*it)->onMessage(msg);
            }
        }
    }
};
