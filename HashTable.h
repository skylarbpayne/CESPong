/**
    * Hash function and compare function to use c-string (const char*) strings as keys with unordered_map (Yay Lambda functions!)
    *
    * Author: Skylar Payne
    * Date: 7/18/2013
    * File: HashTable.h
**/

#pragma once

#include <unordered_map>
#include <cstring>


struct eqstr
{
    /**
     * @brief operator () Acts as a hash function for an unordered_map with c-string keys
     * @param s the c-string to hash
     * @return the hash of the c-string
     */
    inline size_t operator()(const char *s) const
    {
        size_t hash = 1;
        for (; *s; ++s) hash = hash * 5 + *s;
        return hash;
    }

    /**
     * @brief operator () Acts as a c-string comparison operator
     * @param s1 first c-string
     * @param s2 second c-string
     * @return true if the two c-strings are equivalent, false otherwise
     */
    inline bool operator()(const char *s1, const char *s2) const
    {
        return strcmp(s1, s2) == 0;
    }
};
