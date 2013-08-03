/**
    * EntityManager handles the adding and removing of entities and any other higher level entity management. Has write access
    * to EntityAccessor. Also handles the removal of all entities at shutdown.
    *
    * Author: Skylar Payne
    * Date: 7/16/2013
    * File: EntityManager.h
**/

#include <list>
#include "EntityAccessor.h"

class EntityManager : public EntityAccessor
{
private:
    std::list<unsigned int> _EntitySpaces;
public:
    ~EntityManager();

    bool AddEntity(Entity* e);
    void RemoveEntity(unsigned int ID);
};
