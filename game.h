#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

class Game
{
public:
    Game();
    ~Game();

    bool InitializeSDL();
    bool Init(int screenWidth, int screenHeight, const char* windowTitle);
    bool LoadAssets(const char* backgroundImageFile, const char* backgroundMusicFile);
    SDL_Texture* LoadTexture(const char* filePath);
    void DisplayStartingScreen(Uint32 duration);
    void PlayBackgroundMusic();
    bool HandleEvents();
    void Update();
    void Render();
    void Cleanup();

private:
    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;
    SDL_Texture* backgroundTexture;
    Mix_Music* backgroundMusic;

    int screenWidth;
    int screenHeight;
    SDL_Rect backgroundRect;

    bool quit;
};

#endif
