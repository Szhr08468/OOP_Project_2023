#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <vector>
#include "GameState.h"
#include "pieces.h"
#include "money.h"


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
    bool DisplayCardForBuy(const char* filePath);
    void DisplayChanceOrComunnityChest(const char* filePath);
    int  RollDice();
    bool IsKeyPressed(SDL_Scancode key);
    void InitializeGamePieces();
    void InitializeMoney();
    void PlayBackgroundMusic();
    bool HandleEvents();
    bool Update();

    void RenderPieces();
    void RenderPlayerIcons();
    void RenderPlayerMoney();
    void RenderBackground();
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

    std::vector<Piece> gamePieces;
    std::vector<Money> PlayerMoney;
    GameState gamestate;
};

#endif
