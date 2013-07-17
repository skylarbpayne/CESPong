#include <SFML/Graphics.hpp>
#include "EntityManager.h"
#include "SystemManager.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    SystemManager sm;
    EntityManager em;

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
        window.display();
    }

    return 0;
}
