#include <SFML/Graphics.hpp>

#include "Game.h"
#include "TestScene.h"

int main()
{
    TestScene* ts = new TestScene();
    Game g;

    g.Init(200, 200, "testing", ts);
    g.Run();
    g.Quit();
    return g.GetExitStatus();
}
