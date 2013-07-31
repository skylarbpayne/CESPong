#include "TestScene.h"

#include <SFML/Graphics.hpp>
#include "IListener.h"

bool TestScene::Load()
{
    return true;
}

void TestScene::Update()
{
    sm.Update();
    bm.Update();

    sf::Event event;
    while(this->GetWindow()->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            ExitMessage msg;
            msg.ExitStatus = 0;
            Emit<ExitMessage>(msg);
        }
    }

    this->GetWindow()->clear();
    this->GetWindow()->display();
}

void TestScene::Unload()
{
    rm.Unload();
}
