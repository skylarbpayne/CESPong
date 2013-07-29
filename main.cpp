#include <SFML/Graphics.hpp>
#include "EntityManager.h"
#include "SystemManager.h"
#include "BehaviorManager.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    SystemManager sm;
    EntityManager em;
    BehaviorManager bm;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        sm.Update();
        bm.Update();
        window.display();
    }

    return 0;
}
