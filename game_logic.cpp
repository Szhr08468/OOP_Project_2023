#include "game.h"
#include "GameState.h"
#include "pieces.h"
#include "money.h"
#include <cstdio>
#include <vector>
#include <iostream>


bool Game::Update()
{   

    static int dr = 0;
    static int dg = 0;
    static int dp = 0;
    static int db = 0;
    
    bool GameOver = false;

    GameState::State currentState = gamestate.GetCurrentState();
    
    if (currentState==GameState::State::GameStart) 
    {   
        PlayerMoney[0].SetAmount(1000);
        PlayerMoney[1].SetAmount(1000);
        PlayerMoney[2].SetAmount(1000);
        PlayerMoney[3].SetAmount(1000);
        gamestate.SetState(GameState::State::GameOver);
    }
    else if (currentState==GameState::State::Player1Turn) 
    {   

        gamestate.SetState(GameState::State::Player2Turn);
    } 
    else if (currentState==GameState::State::Player2Turn) 
    {   
        
        gamestate.SetState(GameState::State::Player3Turn);
    }
    else if (currentState==GameState::State::Player3Turn) 
    {   
        
        gamestate.SetState(GameState::State::Player4Turn);
    }
    else if (currentState==GameState::State::Player4Turn) 
    {   
        
        gamestate.SetState(GameState::State::GameOver);
        // gamestate.SetState(GameState::State::GameOver);
        // GameOver = true;
    }
    else if (currentState==GameState::State::GameOver) {
        return true;
    }

    SDL_Delay(3000);
    dr++;
    dg++;
    dp++;
    db++;

    return GameOver;
    
}