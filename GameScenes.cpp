/**
    * Declares all GameScenes: Splash Screen, Main Menu, Play, etc.
    *
    * Author: Skylar Payne
    * Date: 8/21/2013
    * File: GameScenes.cpp
**/

#include "GameScenes.h"

#include "IListener.h"

#include <lua.hpp>
#include "LuaBindings.h"

#include "PositionComponent.h"
#include "MovementComponent.h"
#include "ColliderComponent.h"
#include "CircleComponent.h"
#include "RectangleComponent.h"
#include "TextComponent.h"
#include "ScriptableBehavior.h"

#include "Entity.h"

#include "MovementSystem.h"
#include "CollisionSystem.h"
#include "BoundarySystem.h"
#include "RenderSystem.h"
#include "ScoringSystem.h"
#include "BehaviorSystem.h"

#include "AIControlSystem.h"

/**
 * @brief SplashScene::Load loads the splash scene texture
 * @return true if everything loaded properly
 */
bool SplashScene::Load()
{
    rm.AddTexture("resources/splash.png");
    _Splash.setTexture(*this->GetTexture("resources/splash.png"));
    return true;
}

/**
 * @brief SplashScene::Update slowly fades the splash scene out
 */
void SplashScene::Update()
{
    sf::Color color;
    color.r = 255;
    color.g = 255;
    color.b = 255;

    color.a = 255 - _Clock.getElapsedTime().asSeconds() * (255 / 3);

    _Splash.setColor(color);

    this->GetWindow()->clear();
    this->GetWindow()->draw(_Splash);
    this->GetWindow()->display();

    if(color.a == 0)
    {
        ChangeSceneMessage msg;
        msg.NextScene = new MainMenuScene();
        Emit<ChangeSceneMessage>(msg);
    }
}

/**
 * @brief SplashScene::Unload unloads all allocated resources
 */
void SplashScene::Unload()
{
    rm.Unload();
}

/**
 * @brief MainMenuScene::Load Loads all of the buttons
 * @return true if everything loaded properly
 */
bool MainMenuScene::Load()
{
    rm.AddFont("resources/Corki-Regular.otf");

    _Title.setString("Pong");
    _Title.setFont(*this->GetFont("resources/Corki-Regular.otf"));
    _Title.setCharacterSize(36);
    _Title.setColor(sf::Color::White);
    _Title.setPosition((this->GetWindow()->getSize().x - _Title.getGlobalBounds().width) / 2, 60);

    _Buttons[0].setString("Play (1-P)");
    _Buttons[1].setString("Play (2-P)");
    _Buttons[2].setString("Controls");

    for(unsigned int i = 0; i < 3; i++)
    {
        _Buttons[i].setFont(*this->GetFont("resources/Corki-Regular.otf"));
        _Buttons[i].setColor(sf::Color::White);
        _Buttons[i].setPosition((this->GetWindow()->getSize().x - _Buttons[i].getGlobalBounds().width) / 2, 120 * i + 220);

        _ButtonContainers[i].setFillColor(sf::Color::Blue);
        _ButtonContainers[i].setPosition(_Buttons[i].getPosition().x - 10, _Buttons[i].getPosition().y - 10);
        sf::Vector2f size;
        size.x = _Buttons[i].getGlobalBounds().width + 20;
        size.y = _Buttons[i].getGlobalBounds().height + 20;
        _ButtonContainers[i].setSize(size);
    }



    return true;
}

/**
 * @brief MainMenuScene::Update checks for any button presses and renders the buttons
 */
void MainMenuScene::Update()
{
    sf::Event event;
    while(this->GetWindow()->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            ExitMessage msg;
            msg.ExitStatus = 0;
            Emit<ExitMessage>(msg);
        }

        else if(event.type == sf::Event::MouseMoved)
        {
            for(unsigned int i = 0; i < 3; i++)
            {
                if(_ButtonContainers[i].getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
                {
                    _Buttons[i].setColor(sf::Color::Yellow);
                }

                else
                {
                    _Buttons[i].setColor(sf::Color::White);
                }
            }
        }

        else if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left)
        {
            for(unsigned int i = 0; i < 3; i++)
            {
                if(_ButtonContainers[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    ChangeSceneMessage msg;

                    switch(i)
                    {
                    case 0:
                        msg.NextScene = new PlayScene(true);
                        break;
                    case 1:
                        msg.NextScene = new PlayScene(false);
                        break;
                    case 2:
                        msg.NextScene = new ControlsScene();
                        break;
                    }

                    Emit<ChangeSceneMessage>(msg);
                }
            }
        }
    }

    this->GetWindow()->clear();

    this->GetWindow()->draw(_Title);
    for(unsigned int i = 0; i < 3; i++)
    {
        this->GetWindow()->draw(_ButtonContainers[i]);
        this->GetWindow()->draw(_Buttons[i]);
    }

    this->GetWindow()->display();
}

/**
 * @brief MainMenuScene::Unload unloads all allocated resources
 */
void MainMenuScene::Unload()
{
    rm.Unload();
}

/**
 * @brief ControlsScene::Load loads the controls texture
 * @return true if everything loaded correctly, false otherwise
 */
bool ControlsScene::Load()
{
    rm.AddTexture("resources/controls.png");
    _Controls.setTexture(*this->GetTexture("resources/controls.png"));
    return true;
}

/**
 * @brief ControlsScene::Update checks to see if escape was pressed
 */
void ControlsScene::Update()
{
    sf::Event event;
    while(this->GetWindow()->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            ExitMessage msg;
            msg.ExitStatus = 0;
            Emit<ExitMessage>(msg);
        }

        else if(event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::Escape)
            {
                ChangeSceneMessage msg;
                msg.NextScene = new MainMenuScene();
                Emit<ChangeSceneMessage>(msg);
            }
        }
    }

    this->GetWindow()->clear();
    this->GetWindow()->draw(_Controls);
    this->GetWindow()->display();
}

/**
 * @brief ControlsScene::Unload unloads all allocated resources
 */
void ControlsScene::Unload()
{
    rm.Unload();
}

/**
 * @brief PlayScene::Load sets up the game scene
 * @return true if everything loaded correctly, false otherwise
 */
bool PlayScene::Load()
{
    ISystem* s = nullptr;
    s = new RenderSystem();
    sm.Add(s);
    s = new MovementSystem();
    sm.Add(s);
    s = new CollisionSystem();
    sm.Add(s);
    s = new BoundarySystem();
    sm.Add(s);
    s = new ScoringSystem();
    sm.Add(s);
    s = new BehaviorSystem();
    sm.Add(s);

    if(_SinglePlayer)
    {
        s = new AIControlSystem();
        sm.Add(s);
    }

    s = nullptr;

    ef.Register("Position", []() { return new PositionComponent(); });
    ef.Register("Movement", []() { return new MovementComponent(); });
    ef.Register("Collider", []() { return new ColliderComponent(); });
    ef.Register("Circle", []() { return new CircleComponent(); });
    ef.Register("Rectangle", []() { return new RectangleComponent(); });
    ef.Register("Text", []() { return new TextComponent(); });

    rm.AddFont("resources/Corki-Regular.otf");

    ef.Create("scripts/ball.lua", this->GetWindow()->getSize().x / 2, this->GetWindow()->getSize().y / 2);
    ef.Create("scripts/paddle.lua", 0, this->GetWindow()->getSize().y / 2);

    if(_SinglePlayer)
    {
        ef.Create("scripts/ai_paddle.lua", this->GetWindow()->getSize().x - 10, this->GetWindow()->getSize().y / 2);
    }

    else
    {
        ef.Create("scripts/paddle2.lua",this->GetWindow()->getSize().x - 10, this->GetWindow()->getSize().y / 2);
    }

    _BeginPoint = true;
    return true;
}

/**
 * @brief PlayScene::Update Updates all systems and entities.
 */
void PlayScene::Update()
{
    sf::Event event;
    while(this->GetWindow()->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            ExitMessage msg;
            msg.ExitStatus = 0;
            Emit<ExitMessage>(msg);
        }

        else if(event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::Space && _BeginPoint)
            {
                _BeginPoint = false;

                PushEntityMessage msg;
                msg.ID = 0;
                msg.newVelocity.x = (rand() % 2) ? -7 : 7;
                msg.newVelocity.y = (rand() % 2) ? -5 : 5;
                Emit<PushEntityMessage>(msg);
            }

            else if(event.key.code == sf::Keyboard::Escape)
            {
                ChangeSceneMessage cmsg;
                cmsg.NextScene = new MainMenuScene();
                Emit<ChangeSceneMessage>(cmsg);
            }
        }
    }

    this->GetWindow()->clear();
    em.Update();
    sm.Update();
    this->GetWindow()->display();
}

/**
 * @brief PlayScene::Unload unloads all assets
 */
void PlayScene::Unload()
{
    rm.Unload();
}

/**
 * @brief PlayScene::OnMessage
 * @param msg contains the scorer
 */
void PlayScene::OnMessage(PointScoredMessage& msg)
{
    PositionComponent* pc = nullptr;
    sf::Vector2f pos;
    Entity* e = nullptr;

    for(unsigned int i = 0; i < this->GetEntities().size(); i++)
    {
        e = this->GetEntity(i);
        if(strcmp(e->GetTag(), "Ball") == 0)
        {
            pos.x = this->GetWindow()->getSize().x / 2;
            pos.y = this->GetWindow()->getSize().y / 2;
            PushEntityMessage pmsg;
            pmsg.ID = 0;
            pmsg.newVelocity.x = 0.f;
            pmsg.newVelocity.y = 0.f;
            Emit<PushEntityMessage>(pmsg);
        }

        else
        {
            pc = e->GetComponent<PositionComponent>("Position");
            pos = pc->GetPosition();
            pos.y = this->GetWindow()->getSize().y / 2;
        }

        MoveEntityMessage msg;
        msg.ID = i;
        msg.newPosition = pos;
        Emit<MoveEntityMessage>(msg);
    }

    _BeginPoint = true;
}
