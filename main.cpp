#include <SDL.h>
#include <stdio.h>
#include "game.h"

const int SCREEN_WIDTH = 1100;
const int SCREEN_HEIGHT = 700;

int main(int argc, char* args[])
{

    Game game;

    if (!game.InitializeSDL())
    {
        return 1;
    }


    if (!game.Init(SCREEN_WIDTH, SCREEN_HEIGHT, "Background Image with Music"))
    {
        return 2;
    }

    if (!game.LoadAssets("assets/Board.jpg", "assets/background.mp3"))  // Replace with your file paths
    {
        return 3;
    }

    game.PlayBackgroundMusic();

    bool quit = false;

    game.DisplayStartingScreen(3000);

    while (!quit)
    {
        quit = game.HandleEvents();
        game.Update();
        game.Render();
    }

    game.Cleanup();
    return 0;
}
