#include <SDL.h>
#include <stdio.h>
#include "game.h"
#include "pieces.h"

const int SCREEN_WIDTH = 1200;
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

    game.LoadAllTextures();

    game.PlayBackgroundMusic();

    game.DisplayStartingScreen(3000);

    game.InitializePlayers();

    
    bool update_quit = false;

    Uint32 duration = 300000;

    Uint32 startTime = SDL_GetTicks();

    while (!(game.returnQuit()) and !update_quit)
    {
        game.Render(); // Calls SDL_RenderClear to clear the screen
        update_quit = game.Update();
        game.HandleEvents();

        if (SDL_GetTicks() - startTime >= duration)
        {   
            break;
        }
        
    }

    game.Cleanup();
    return 0;
}
