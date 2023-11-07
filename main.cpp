#include <SDL.h>
#include <stdio.h>
#include "game.h"
#include "GameState.h"

const int SCREEN_WIDTH = 1100;
const int SCREEN_HEIGHT = 700;

int main(int argc, char* args[])
{

    Game game;
    GameState gamestate;


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

    bool handle_events_quit = false;
    bool update_quit = false;

    game.DisplayStartingScreen(3000);

    while (!handle_events_quit and !update_quit)
    {   
        update_quit = game.Update(game,gamestate);
        handle_events_quit = game.HandleEvents();
        game.Render();
    }

    game.Cleanup();
    return 0;
}
