#include "Game.h"
#include "GameScenes.h"

int main()
{
    PlayScene* ps = new PlayScene();
    Game g;

    g.Init(800, 600, "testing", ps);
    g.Run();
    g.Quit();
    return g.GetExitStatus();
}
