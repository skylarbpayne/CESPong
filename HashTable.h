/**
    * HashTable implementation utilizing chaining to avoid collisions. The key used should be of type string

    * Author: Skylar Payne
    * Date: 7/18/2013
    * File: HashTable.h
**/

#pragma once

#include <vector>
#include <list>
#include <cstring>
#include <cstdlib>

template<class T>
class HashTable
{
private:
    std::vector<std::list<std::pair<const char*, T> > > _HashTable;
private:
    /**
     * @brief Hash returns a hash of the string restricted to the size of the internal vector
     *  Uses pwj implementation from: http://www.cs.carleton.edu/faculty/rkirchne/cs257/cs257/textutils-2.1/lib/hash-pjw.c
     * @param key the key to hash
     * @return a hash of the key
     */
    unsigned int Hash(const char* key)
    {
        const char* s = key;
        unsigned int h = 0;
        unsigned int g;

        while (*s != 0)
        {
            h = (h << 4) + *s++;
            if ((g = h & (unsigned int) 0xf0000000) != 0)
            h = (h ^ (g >> 24)) ^ g;
        }

        return (h % _HashTable.size());
    }

    /**
     * @brief Find finds a particular element in the hash table if it exists
     * @param key the key of the element to find
     * @param loc the location of the element if found
     * @return true if the element was found, false otherwise.
     */
    bool Find(const char* key, typename std::list<std::pair<const char*, T> >::iterator& loc)
    {
        std::list<std::pair<const char*, T> > chain = _HashTable[Hash(key)];
        typename std::list<std::pair<const char*, T> >::iterator it;
        for(it = chain.begin(); it != chain.end(); it++)
        {
            if(strcmp(it->first, key) == 0)
            {
                loc = it;
                return true;
            }
        }
        return false;
    }

public:
    /**
     * @brief HashTable
     * @param size the number of elements to initialize in the internal vector
     */
    HashTable(unsigned int size = 10) : _HashTable(size) { }

    /**
     * @brief GetContainer returns the internal hashtable container; a hack for iteration
     * @return the hashtable container
     */
    std::vector<std::list<std::pair<const char*, T> > >& GetContainer() { return _HashTable; }

    /**
     * @brief Add adds an element into the hash table
     * @param key the key for which to hash the element
     * @param element the element to add
     * @return true if successfully added or already existed, false otherwise
     */
    bool Add(const char* key, T element)
    {
        typename std::list<std::pair<const char*, T> >::iterator it;
        if(Find(key, it))
        {
            return true;
        }

        _HashTable[Hash(key)].push_back(std::pair<const char*, T>(key, element));
        return true;
    }

    /**
     * @brief Remove removes an element from the hash table
     * @param key the key of the element to remove
     */
    void Remove(const char* key)
    {
        typename std::list<std::pair<const char*, T> >::iterator loc;
        if(Find(key, loc))
        {
            _HashTable[Hash(key)].erase(loc);
        }
    }

    /**
     * @brief Get gets an element from the hash table
     * @param key the key of the element to get
     * @return the element, if found, exits otherwise
     */
    T Get(const char* key)
    {
        typename std::list<std::pair<const char*, T> >::iterator loc;
        if(Find(key, loc))
        {
            return loc->second;
        }

        exit(EXIT_FAILURE);
    }
};
