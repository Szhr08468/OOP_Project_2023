#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <vector>
#include <string>
#include <cstdlib> // Include this header for rand() function

#include "GameState.h"
#include "pieces.h"
#include "money.h"


// std::vector<Player> p;
//     Player p1;
//     Player p2;
//     Player p3;
//     Player p4;
//     p.push_back(p1);
//     p.push_back(p2);
//     p.push_back(p3);
//     p.push_back(p4);

class Player;

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
    
    void InitializePlayers();
    void PlayBackgroundMusic();
    bool HandleEvents();
    bool Update();

    void RenderPieces();
    void RenderPlayerIcons();
    void RenderPlayerMoney();
    void RenderBackground();
    void Render();
    void Cleanup();
    void docommunitychest(int a, int p, int arr1[40][2]);
    void dochance(int b, int p, int arr[40][2]);

protected:

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
    

private:
    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;
    SDL_Texture* backgroundTexture;
    Mix_Music* backgroundMusic;

    int screenWidth;
    int screenHeight;
    SDL_Rect backgroundRect;

    std::vector<Player> player;
    GameState gamestate;


    std::string chest_paths[15] = {
    "assets/CommunityChest/CommunityChest0.jpg",
    "assets/CommunityChest/CommunityChest1.jpg",
    "assets/CommunityChest/CommunityChest2.jpg",
    "assets/CommunityChest/CommunityChest3.jpg",
    "assets/CommunityChest/CommunityChest4.jpg",
    "assets/CommunityChest/CommunityChest5.jpg",
    "assets/CommunityChest/CommunityChest6.jpg",
    "assets/CommunityChest/CommunityChest7.jpg",
    "assets/CommunityChest/CommunityChest8.jpg",
    "assets/CommunityChest/CommunityChest9.jpg",
    "assets/CommunityChest/CommunityChest10.jpg",
    "assets/CommunityChest/CommunityChest11.jpg",
    "assets/CommunityChest/CommunityChest12.jpg",
    "assets/CommunityChest/CommunityChest13.jpg",
    "assets/CommunityChest/CommunityChest14.jpg"
};

    std::string chance_paths [15] = {
    "assets/Chance/Chance0.jpg",
    "assets/Chance/Chance1.jpg",
    "assets/Chance/Chance2.jpg",
    "assets/Chance/Chance3.jpg",
    "assets/Chance/Chance4.jpg",
    "assets/Chance/Chance5.jpg",
    "assets/Chance/Chance6.jpg",
    "assets/Chance/Chance7.jpg",
    "assets/Chance/Chance8.jpg",
    "assets/Chance/Chance9.jpg",
    "assets/Chance/Chance10.jpg",
    "assets/Chance/Chance11.jpg",
    "assets/Chance/Chance12.jpg",
    "assets/Chance/Chance13.jpg",
    "assets/Chance/Chance14.jpg"
};




std::string all_cards[40][3] = {
    {"Go", "  "},
    {"Old Kent Road", "assets/properties/old_kent.jpg","60"},
    {"Community Chest", "assets/CommunityChest/CommunityChest" + std::to_string(rand() % 15) + ".jpg","0"},
    {"Whitechapel Road", "assets/properties/whitechapel_road.jpg","60"},
    {"Income Tax", "  ","200"},
    {"King's Cross Station", "assets/properties/kingcross_station.jpg","200"},
    {"The Angel Islington", "assets/properties/the_angel_islington.jpg","100"},
    {"Chance", "assets/Chance/Chance" + std::to_string(rand() % 15) + ".jpg","0"},
    {"Euston Road", "assets/properties/euston_road.jpg","100"},
    {"Pentonville Road", "assets/properties/pentonville_road.jpg","120"},
    {"Jail", "  ","0"},
    {"Pall Mall", "assets/properties/pallmall.jpg","140"},
    {"Electric Company", "assets/properties/electric_company.jpg","150"},
    {"Whitehall", "assets/properties/whitehall.jpg","140"},
    {"Northumberland Avenue", "assets/properties/northumberland_avenue.jpg","160"},
    {"Marylebone Station", "assets/properties/marylebone_station.jpg","200"},
    {"Bow Street", "assets/properties/bow_street.jpg","180"},
    {"Community Chest", "assets/CommunityChest/CommunityChest" + std::to_string(rand() % 15) + ".jpg","0"},
    {"Marlborough Street", "assets/properties/marlborough_street.jpg","180"},
    {"Vine Street", "assets/properties/vine_street.jpg","200"},
    {"Free Parking", "  ","200"},
    {"Strand", "assets/properties/strand.jpg","220"},
    {"Chance", "assets/Chance/Chance" + std::to_string(rand() % 15) + ".jpg","0"},
    {"Fleet Street", "assets/properties/fleet_street.jpg","220"},
    {"Trafalgar Square", "assets/properties/trafalgar_square.jpg","240"},
    {"Fenchurch St. Station", "assets/properties/fenchurch_street_station.jpg","200"},
    {"Leicester Square", "assets/properties/leicester_square.jpg","260"},
    {"Coventry Street", "assets/properties/coventry_street.jpg","260"},
    {"Water Works", "assets/properties/water_works.jpg","150"},
    {"Piccadilly", "assets/properties/piccadilly.jpg","280"},
    {"Go to Jail", "  ","0"},
    {"Regent Street", "assets/properties/regent_street.jpg","300"},
    {"Oxford Street", "assets/properties/oxfors_street.jpg","300"},
    {"Community Chest", "assets/CommunityChest/CommunityChest" + std::to_string(rand() % 15) + ".jpg","0"},
    {"Bond Street", "assets/properties/bond_street.jpg","320"},
    {"Liverpool St. Station", "assets/properties/liverpool_street_station.jpg","200"},
    {"Chance", "assets/Chance/Chance" + std::to_string(rand() % 15) + ".jpg","0"},
    {"Park Lane", "assets/properties/park_lane.jpg","350"},
    {"Super Tax", "  ","100"},
    {"Mayfair", "assets/properties/mayfair.jpg","400"}
};
};
#endif