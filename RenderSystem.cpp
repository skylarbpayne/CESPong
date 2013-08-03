/** Render System Implementation
 *
 * @author      Caleb Geiger
 * Created:     8-2-2013
 * Source File:  RenderSystem.cpp
 */
#include "Entity.h"
#include "RenderComponent.h"
#include "RenderSystem.h"

void RenderSystem::Update(unsigned int dt)
{
    std::list<unsigned int>::iterator it;

    for(it = _EntitiesToUpdate.begin(); it != _EntitiesToUpdate.end(); ++it)
    {
        Entity* e = this->GetEntity(*it);

        RenderComponent* rc = e->GetComponent<RenderComponent>("Render");
        this->GetWindow()->draw(rc->GetShape());

    }
}

bool RenderSystem::ValidateEntity(unsigned int ID)
{
    Entity* e = this->GetEntity(ID);

    return e->HasComponent("Render");
}
