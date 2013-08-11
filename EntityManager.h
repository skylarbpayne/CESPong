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
#include "IListener.h"

class EntityManager : public EntityAccessor, public IListener<AddEntityMessage>, public IListener<DestroyEntityMessage>
{
private:
    std::list<unsigned int> _EntitySpaces;
    std::list<unsigned int> _EntitiesToRemove;
private:
    void OnMessage(AddEntityMessage& msg) override;
    void OnMessage(DestroyEntityMessage& msg) override;
public:
    ~EntityManager();

    bool AddEntity(Entity* e);
    void RemoveEntity(unsigned int ID);
    void Update();
};
