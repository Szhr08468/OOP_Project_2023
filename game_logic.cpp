#include "game.h"
#include "GameState.h"
#include "pieces.h"
#include "money.h"
#include <cstdio>
#include <vector>
#include <iostream>


bool Game::Update()
{   

    static int dr = 40;
    static int dg = 0;
    static int dp = 0;
    static int db = 0;
    
    bool GameOver = false;

    GameState::State currentState = gamestate.GetCurrentState();
    
    if (currentState==GameState::State::GameStart) 
    {   
        PlayerMoney[0].SetAmount(1500);
        PlayerMoney[1].SetAmount(1500);
        PlayerMoney[2].SetAmount(1500);
        PlayerMoney[3].SetAmount(1500);
        gamePieces[0].SetPosition(red[0][0],red[0][1]);
        gamePieces[1].SetPosition(green[0][0],green[0][1]);
        gamePieces[2].SetPosition(pink[0][0],pink[0][1]);
        gamePieces[3].SetPosition(blue[0][0],blue[0][1]);
        gamestate.SetState(GameState::State::Player1Turn);
        
    }

    
    else if (currentState==GameState::State::Player1Turn)
    {   
        dr = (dr+RollDice())%40;
        gamePieces[0].SetPosition(red[dr][0],red[dr][1]);

        gamestate.SetState(GameState::State::Player2Turn);
    } 
    else if (currentState==GameState::State::Player2Turn) 
    {   
        dg = (dg+RollDice())%40;
        gamePieces[1].SetPosition(green[dg][0],green[dg][1]);
        gamestate.SetState(GameState::State::Player3Turn);
    }
    else if (currentState==GameState::State::Player3Turn) 
    {   
        dp = (dp+RollDice())%40;
        gamePieces[2].SetPosition(pink[dp][0],pink[dp][1]);
        gamestate.SetState(GameState::State::Player4Turn);
    }
    else if (currentState==GameState::State::Player4Turn) 
    {   
        db = (db+RollDice())%40;
        gamePieces[3].SetPosition(blue[db][0],blue[db][1]);
        gamestate.SetState(GameState::State::Player1Turn);
    }
    
    
    


    SDL_Delay(3000);
    return GameOver;
    
}