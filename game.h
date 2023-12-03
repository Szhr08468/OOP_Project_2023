#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <vector>
#include <string>

#include "GameState.h"
#include "pieces.h"
#include "money.h"


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
    void LoadAllTextures(); 
    void DisplayStartingScreen(Uint32 duration);
    bool DisplayCardForBuy(const char* filePath);
    void DisplayCard(const char* filePath);
    void DisplayChanceOrComunnityChest(const char* filePath);
    int  RollDice();
    void IsRPressed();
    
    void InitializePlayers();
    void PlayBackgroundMusic();
    void HandleEvents();
    bool returnQuit();
    bool Update();

    void RenderPieces();
    void RenderPlayerIcons();
    void RenderPlayerMoney();
    void RenderBackground();
    void Render();
    void ShowAndDecideWinner();
    void Cleanup();
    


protected:

    GameState gamestate;
    std::vector<Player> player;

    std::string all_cards[40][4] = {
        {"Go", "  ", "  ","  "},
        {"Old Kent Road", "assets/properties/old_kent.jpg", "30","2"},
        {"Community Chest", "  ", "  ","  "},
        {"Whitechapel Road", "assets/properties/whitechapel_road.jpg", "30","4"},
        {"Income Tax", "  ", "  ","  "},
        {"King's Cross Station", "assets/properties/kingcross_station.jpg", "100","25"},
        {"The Angel Islington", "assets/properties/the_angel_islington.jpg", "50","6"},
        {"Chance", "  ", "  ","  "},
        {"Euston Road", "assets/properties/euston_road.jpg", "50","6"},
        {"Pentonville Road", "assets/properties/pentonville_road.jpg", "60","8"},
        {"Jail", "  ", "  ","  "},
        {"Pall Mall", "assets/properties/pallmall.jpg", "70","10"},
        {"Electric Company", "assets/properties/electric_company.jpg", "75","25"},
        {"Whitehall", "assets/properties/whitehall.jpg", "70","10"},
        {"Northumberland Avenue", "assets/properties/northumberland_avenue.jpg", "80","12"},
        {"Marylebone Station", "assets/properties/marylebone_station.jpg", "100","25"},
        {"Bow Street", "assets/properties/bow_street.jpg", "90","14"},
        {"Community Chest", "  ", "  ","  "},
        {"Marlborough Street", "assets/properties/marlborough_street.jpg", "90","14"},
        {"Vine Street", "assets/properties/vine_street.jpg", "100","16"},
        {"Free Parking", "  ", "  ","  "},
        {"Strand", "assets/properties/strand.jpg", "110","18"},
        {"Chance", "  ", "  ","  "},
        {"Fleet Street", "assets/properties/fleet_street.jpg", "110","18"},
        {"Trafalgar Square", "assets/properties/trafalgar_square.jpg", "120","20"},
        {"Fenchurch St. Station", "assets/properties/fenchurch_street_station.jpg", "100","25"},
        {"Leicester Square", "assets/properties/leicester_square.jpg", "130","22"},
        {"Coventry Street", "assets/properties/coventry_street.jpg", "130","22"},
        {"Water Works", "assets/properties/water_works.jpg", "75","25"},
        {"Piccadilly", "assets/properties/piccadilly.jpg", "140","24"},
        {"Go to Jail", "  ", "  ","  "},
        {"Regent Street", "assets/properties/regent_street.jpg", "150","26"},
        {"Oxford Street", "assets/properties/oxfors_street.jpg", "150","26"},
        {"Community Chest", "  ", "  ","  "},
        {"Bond Street", "assets/properties/bond_street.jpg", "160","28"},
        {"Liverpool St. Station", "assets/properties/liverpool_street_station.jpg", "100","25"},
        {"Chance", "  ", "  ","  "},
        {"Park Lane", "assets/properties/park_lane.jpg", "175","35"},
        {"Super Tax", "  ", "  ","  "},
        {"Mayfair", "assets/properties/mayfair.jpg", "200","50"}
    };

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
    SDL_Texture* WoodenbackgroundTexture;
    Mix_Music* backgroundMusic;

    int screenWidth;
    int screenHeight;
    SDL_Rect backgroundRect;
    bool quit = false;


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




   


    //////////////////////////////////////////////////////////////
    // These are SDL_Textures which were being created and destroyed which was occupying video memory
    // Becuase the fuctions were being called again and again after some some the game was crashing
    // So i am making these member variables

    // Roll Dice :

    SDL_Texture* D1 ;
    SDL_Texture* D2 ;
    SDL_Texture* D3 ;
    SDL_Texture* D4 ;
    SDL_Texture* D5 ;
    SDL_Texture* D6 ;
    std::vector<SDL_Texture*> D_tex;

    // RenderPieces : 

    SDL_Texture* pieceTexture1;
    SDL_Texture* pieceTexture2;
    SDL_Texture* pieceTexture3;
    SDL_Texture* pieceTexture4;

    //RenderPlayerIcons : 

    SDL_Texture* p1_T;
    SDL_Texture* p1_NT;
    SDL_Texture* p2_T;
    SDL_Texture* p2_NT;
    SDL_Texture* p3_T;
    SDL_Texture* p3_NT;
    SDL_Texture* p4_T;
    SDL_Texture* p4_NT;

    //RenderPlayerMoney :

    SDL_Texture* p1_D;
    SDL_Texture* p2_D;
    SDL_Texture* p3_D;
    SDL_Texture* p4_D;
    SDL_Texture* zero;
    SDL_Texture* one;
    SDL_Texture* two;
    SDL_Texture* three;
    SDL_Texture* four;
    SDL_Texture* five;
    SDL_Texture* six;
    SDL_Texture* seven;
    SDL_Texture* eight;
    SDL_Texture* nine;
    std::vector<SDL_Texture*> tex;
    

};
#endif