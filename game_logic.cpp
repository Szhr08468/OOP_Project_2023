#include "game.h"
#include "GameState.h"
#include "pieces.h"
#include "money.h"
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include "player.h"

bool Game::Update()
{
    // static int dr = 0;
    // static int dg = 0;
    // static int dp = 0;
    // static int db = 0;
    // static int mon0 = 1500;
    // static int mon1 = 1500;
    // static int mon2 = 1500;
    // static int mon3 = 1500;

    int pos_p1 = player[0].GetPlayerPosition();
    int pos_p2 = player[1].GetPlayerPosition();
    int pos_p3 = player[2].GetPlayerPosition();
    int pos_p4 = player[3].GetPlayerPosition();

    bool GameOver = false;

    GameState::State currentState = gamestate.GetCurrentState();

    if (currentState == GameState::State::GameStart)
    {
        
        gamestate.SetState(GameState::State::Player1Turn);
    }
    else if (currentState == GameState::State::Player1Turn)
    {   
        pos_p1 = ( pos_p1 + RollDice() ) %40;
        player[0].ChangePosition(pos_p1);
        gamestate.SetState(GameState::State::Player2Turn);
    }
    else if (currentState == GameState::State::Player2Turn)
    {   
        pos_p2 = ( pos_p2 + RollDice() ) %40;
        player[1].ChangePosition(pos_p2);
        gamestate.SetState(GameState::State::Player3Turn);
    }
    else if (currentState == GameState::State::Player3Turn)
    {   
        pos_p3 = ( pos_p3 + RollDice() ) %40;
        player[2].ChangePosition(pos_p3);
        gamestate.SetState(GameState::State::Player4Turn);
    }
    else if (currentState == GameState::State::Player4Turn)
    {
        pos_p4 = ( pos_p4 + RollDice() ) %40;
        player[3].ChangePosition(pos_p4);
        gamestate.SetState(GameState::State::Player1Turn);
    }


    // SDL_Delay(1000);
    

    return GameOver;
}