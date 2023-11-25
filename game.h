#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <vector>
#include "GameState.h"
#include "pieces.h"
#include "money.h"
#include <string>


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

    

    int red[40][2] = {

        {890,630},{805,630},{750,630},{690,630},{635,630},{580,630},
        {520,630},{465,630},{405,630},{350,630},{255,615},{265,555},
        {265,495},{265,440},{265,385},{265,325},{265,270},{265,215},
        {265,157},{265,98},{265,20},{350,20},{406,20},{464,20},
        {520,20},{576,20},{635,20},{693,20},{750,20},{805,20},
        {890,20},{890,100},{890,160},{890,215},{890,270},{890,330},
        {890,385},{890,445},{890,501},{890,560}

    };

    int green[40][2] = {

        {920, 630},{835, 630},{775, 630},{720, 630},{660, 630},{605, 630},
        {545, 630},{490, 630},{435, 630},{375, 630},{255, 650},{295, 555},
        {295, 495},{295, 440},{295, 385},{295, 325},{295, 270},{295, 215},
        {295, 157},{295, 98},{295, 20},{375, 20},{434, 20},{490, 20},
        {546, 20},{605, 20},{662, 20},{720, 20},{776, 20},{831, 20},
        {920, 20},{920, 100},{920, 160},{920, 215},{920, 270},{920, 330},
        {920, 385},{920, 445},{920, 501},{920, 560}
    
    };

    int pink[40][2] = {
        {890, 660}, {805, 660}, {750, 660}, {690, 660}, {635, 660}, {580, 660},
        {520, 660}, {465, 660}, {405, 660}, {350, 660}, {285, 674}, {265, 580},
        {265, 520}, {265, 470}, {265, 410}, {265, 350}, {265, 295}, {265, 239},
        {265, 183}, {265, 120}, {265, 45}, {350, 45}, {406, 45}, {464, 45},
        {520, 45}, {576, 45}, {635, 45}, {693, 45}, {750, 45}, {805, 45},
        {890, 45}, {890, 125}, {890, 185}, {890, 240}, {890, 295}, {890, 355},
        {890, 410}, {890, 470}, {890, 526}, {890, 584}
    };

    int blue[40][2] = {
        {920, 660}, {835, 660}, {775, 660}, {720, 660}, {660, 660}, {605, 660},
        {545, 660}, {490, 660}, {435, 660}, {375, 660}, {315, 674}, {295, 580},
        {295, 520}, {295, 470}, {295, 410}, {295, 350}, {295, 295}, {295, 239},
        {295, 183}, {295, 120}, {295, 45}, {375, 45}, {434, 45}, {490, 45},
        {546, 45}, {605, 45}, {662, 45}, {720, 45}, {776, 45}, {831, 45},
        {920, 45}, {920, 125}, {920, 185}, {920, 240}, {920, 295}, {920, 355},
        {920, 410}, {920, 470}, {920, 526}, {920, 584}
    };

    std::string all_cards[40] = {
        "Go", "Old Kent Road", "Community Chest", "Whitechapel Road", "Income Tax",
        "King's Cross Station", "The Angel Islington", "Chance", "Euston Road", "Pentonville Road",
        "Jail", "Pall Mall", "Electric Company", "Whitehall", "Northumberland Avenue", "Marylebone Station",
        "Bow Street", "Community Chest", "Marlborough Street", "Vine Street", "Free Parking",
        "Strand", "Chance", "Fleet Street", "Trafalgar Square", "Fenchurch St. Station", "Leicester Square",
        "Coventry Street", "Water Works", "Piccadilly", "Go to Jail", "Regent Street", "Oxford Street",
        "Community Chest", "Bond Street", "Liverpool St. Station", "Chance", "Park Lane", "Super Tax", "Mayfair"
    };

};

