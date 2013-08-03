#include <SFML/Graphics.hpp>

#include "Game.h"
#include "TestScene.h"

int main()
{
    TestScene* ts = new TestScene();
    Game g;

    g.Init(800, 600, "testing", ts);
    g.Run();
    g.Quit();
    return g.GetExitStatus();
}
