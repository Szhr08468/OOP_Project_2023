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
        
        if (player[0].InJail==false)
        {
            IsRPressed();
            
            pos_p1 = pos_p1 + RollDice();
            if (pos_p1>39)
            {
                player[0].AddMoney(200);
                pos_p1 = pos_p1%40;
            }

            
            
            
        }

        
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


    SDL_Delay(1000);
    

    return GameOver;
}

