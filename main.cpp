#include "Game.h"
#include "GameScenes.h"

int main()
{
    IScene* s = new SplashScene();
    Game g;

    g.Init(800, 600, "testing", s);
    g.Run();
    g.Quit();
    return g.GetExitStatus();
}
