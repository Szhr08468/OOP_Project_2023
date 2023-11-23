#include "game.h"
#include "GameState.h"
#include "pieces.h"
#include "money.h"
#include <cstdio>
#include <vector>
#include <iostream>


bool Game::Update()
{   

    int red[41][2] = {

        {890,620},{805,620},{745,620},{685,620},{630,620},{575,620},
        {520,620},{460,620},{405,620},{350,620},{265,675},{265,550},
        {265,495},{265,435},{265,380},{265,325},{265,265},{265,205},
        {265,150},{265,95},{265,20},{350,20},{410,20},{465,20},
        {520,20},{580,20},{635,20},{690,20},{750,20},{805,20},
        {890,20},{890,105},{890,160},{890,215},{890,275},{890,330},
        {890,390},{890,450},{890,505},{890,565},{890,620}

    };

    int green[41][2] = {

        {920, 620},{835, 620},{775, 620},{715, 620},{660, 620},{605, 620},
        {550, 620},{490, 620},{435, 620},{380, 620},{295, 675},{295, 550},
        {295, 495},{295, 435},{295, 380},{295, 325},{295, 265},{295, 205},
        {295, 150},{295, 95},{295, 20},{380, 20},{440, 20},{495, 20},
        {550, 20},{610, 20},{665, 20},{720, 20},{780, 20},{835, 20},
        {920, 20},{920, 105},{920, 160},{920, 215},{920, 275},{920, 330},
        {920, 390},{920, 450},{920, 505},{920, 565},{920, 620}
    
    };

int pink[41][2] = {
    {890, 650}, {805, 650}, {745, 650}, {685, 650}, {630, 650}, {575, 650},
    {520, 650}, {460, 650}, {405, 650}, {350, 650}, {265, 700}, {265, 575},
    {265, 520}, {265, 460}, {265, 405}, {265, 350}, {265, 290}, {265, 230},
    {265, 175}, {265, 120}, {265, 45}, {350, 45}, {410, 45}, {465, 45},
    {520, 45}, {580, 45}, {635, 45}, {690, 45}, {750, 45}, {805, 45},
    {890, 45}, {890, 130}, {890, 185}, {890, 240}, {890, 300}, {890, 355},
    {890, 415}, {890, 475}, {890, 530}, {890, 587}, {890, 642}
};

int blue[41][2] = {
    {920, 645}, {835, 645}, {775, 645}, {715, 645}, {660, 645}, {605, 645},
    {550, 645}, {490, 645}, {435, 645}, {380, 645}, {295, 700}, {295, 575},
    {295, 520}, {295, 460}, {295, 405}, {295, 350}, {295, 290}, {295, 230},
    {295, 175}, {295, 120}, {295, 45}, {380, 45}, {440, 45}, {495, 45},
    {550, 45}, {610, 45}, {665, 45}, {720, 45}, {780, 45}, {835, 45},
    {920, 45}, {920, 130}, {920, 185}, {920, 240}, {920, 300}, {920, 355},
    {920, 415}, {920, 475}, {920, 530}, {920, 587}, {920, 642}
};


    static int dr = 1;
    static int dg = 1;
    static int dp = 1;
    static int db = 1;
    
    bool GameOver = false;

    GameState::State currentState = gamestate.GetCurrentState();
    
    if (currentState==GameState::State::GameStart) 
    {   
        PlayerMoney[0].SetAmount(1000);
        PlayerMoney[1].SetAmount(1000);
        PlayerMoney[2].SetAmount(1000);
        PlayerMoney[3].SetAmount(1000);
        SDL_Delay(3000);
        gamestate.SetState(GameState::State::Player1Turn);
    }
    else if (currentState==GameState::State::Player1Turn) 
    {   
        gamePieces[0].SetPosition(red[dr][0],red[dr][1]);
        gamePieces[1].SetPosition(green[dg][0],green[dg][1]);
        gamePieces[2].SetPosition(pink[dp][0],pink[dp][1]);
        gamePieces[3].SetPosition(blue[db][0],blue[db][1]);
        SDL_Delay(3000);  
        gamestate.SetState(GameState::State::Player2Turn);
    } 
    else if (currentState==GameState::State::Player2Turn) 
    {   
        gamePieces[0].SetPosition(red[dr][0],red[dr][1]);
        gamePieces[1].SetPosition(green[dg][0],green[dg][1]);
        gamePieces[2].SetPosition(pink[dp][0],pink[dp][1]);
        gamePieces[3].SetPosition(blue[db][0],blue[db][1]);
        SDL_Delay(3000);
        gamestate.SetState(GameState::State::Player3Turn);
    }
    else if (currentState==GameState::State::Player3Turn) 
    {   
        gamePieces[0].SetPosition(red[dr][0],red[dr][1]);
        gamePieces[1].SetPosition(green[dg][0],green[dg][1]);
        gamePieces[2].SetPosition(pink[dp][0],pink[dp][1]);
        gamePieces[3].SetPosition(blue[db][0],blue[db][1]);
        SDL_Delay(3000);
        gamestate.SetState(GameState::State::Player4Turn);
    }
    else if (currentState==GameState::State::Player4Turn) 
    {   
        gamePieces[0].SetPosition(red[dr][0],red[dr][1]);
        gamePieces[1].SetPosition(green[dg][0],green[dg][1]);
        gamePieces[2].SetPosition(pink[dp][0],pink[dp][1]);
        gamePieces[3].SetPosition(blue[db][0],blue[db][1]);
        SDL_Delay(3000);
        gamestate.SetState(GameState::State::Player1Turn);
        // gamestate.SetState(GameState::State::GameOver);
        // GameOver = true;
    }

    dr++;
    dg++;
    dp++;
    db++;

    return GameOver;
    
}