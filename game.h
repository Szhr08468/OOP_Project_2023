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

    int aun = 2; 

    int red[41][2] = {

        {890,630},{805,630},{745,630},{685,630},{630,630},{575,630},
        {520,630},{460,630},{405,630},{350,630},{265,675},{265,550},
        {265,495},{265,435},{265,380},{265,325},{265,265},{265,205},
        {265,150},{265,95},{265,20},{350,20},{410,20},{465,20},
        {520,20},{580,20},{635,20},{690,20},{750,20},{805,20},
        {890,20},{890,105},{890,160},{890,215},{890,275},{890,330},
        {890,390},{890,450},{890,505},{890,565},{890,620}

    };

    int green[41][2] = {

        {920, 630},{835, 630},{775, 630},{715, 630},{660, 630},{605, 630},
        {550, 630},{490, 630},{435, 630},{380, 630},{295, 675},{295, 550},
        {295, 495},{295, 435},{295, 380},{295, 325},{295, 265},{295, 205},
        {295, 150},{295, 95},{295, 20},{380, 20},{440, 20},{495, 20},
        {550, 20},{610, 20},{665, 20},{720, 20},{780, 20},{835, 20},
        {920, 20},{920, 105},{920, 160},{920, 215},{920, 275},{920, 330},
        {920, 390},{920, 450},{920, 505},{920, 565},{920, 620}
    
    };

    int pink[41][2] = {
        {890, 660}, {805, 660}, {745, 660}, {685, 660}, {630, 660}, {575, 660},
        {520, 660}, {460, 660}, {405, 660}, {350, 660}, {265, 700}, {265, 575},
        {265, 520}, {265, 460}, {265, 405}, {265, 350}, {265, 290}, {265, 230},
        {265, 175}, {265, 120}, {265, 45}, {350, 45}, {410, 45}, {465, 45},
        {520, 45}, {580, 45}, {635, 45}, {690, 45}, {750, 45}, {805, 45},
        {890, 45}, {890, 130}, {890, 185}, {890, 240}, {890, 300}, {890, 355},
        {890, 415}, {890, 475}, {890, 530}, {890, 587}, {890, 642}
    };

    int blue[41][2] = {
        {920, 660}, {835, 660}, {775, 660}, {715, 660}, {660, 660}, {605, 660},
        {550, 660}, {490, 660}, {435, 660}, {380, 660}, {295, 700}, {295, 575},
        {295, 520}, {295, 460}, {295, 405}, {295, 350}, {295, 290}, {295, 230},
        {295, 175}, {295, 120}, {295, 50}, {380, 50}, {440, 50}, {495, 50},
        {550, 50}, {610, 50}, {665, 50}, {720, 50}, {780, 50}, {835, 50},
        {920, 50}, {920, 130}, {920, 185}, {920, 240}, {920, 300}, {920, 355},
        {920, 415}, {920, 475}, {920, 530}, {920, 587}, {920, 642}
    };

};

#endif
