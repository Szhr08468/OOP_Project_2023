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

    int pink[41][2]=  {
        
        {890, 650},{805, 650},{745, 650},{685, 650},{630, 650},{575, 650},
        {520, 650},{460, 650},{405, 650},{350, 650},{265, 705},{265, 580},
        {265, 525},{265, 465},{265, 410},{265, 355},{265, 295},{265, 235},
        {265, 180},{265, 125},{265, 50},{350, 50},{410, 50},{465, 50},
        {520, 50},{580, 50},{635, 50},{690, 50},{750, 50},{805, 50},
        {890, 50},{890, 135},{890, 190},{890, 245},{890, 305},{890, 360},
        {890, 420},{890, 480},{890, 535},{890, 595},{890, 650}
    
    };

    int blue[41][2] = {

        {920, 650},{835, 650},{775, 650},{715, 650},{660, 650},{605, 650},
        {550, 650},{490, 650},{435, 650},{380, 650},{295, 705},{295, 580},
        {295, 525},{295, 465},{295, 410},{295, 355},{295, 295},{295, 235},
        {295, 180},{295, 125},{295, 50},{380, 50},{440, 50},{495, 50},
        {550, 50},{610, 50},{665, 50},{720, 50},{780, 50},{835, 50},
        {920, 50},{920, 135},{920, 190},{920, 245},{920, 305},{920, 360},
        {920, 420},{920, 480},{920, 535},{920, 595},{920, 650}
    
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