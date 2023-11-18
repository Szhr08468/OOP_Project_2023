#include "game.h"
#include "GameState.h"
#include "pieces.h"
#include "money.h"
#include <cstdio>
#include <vector>
#include <iostream>


bool Game::Update()
{   

    int bottom[10] = {805,745,685,625,565,505,445,385,325,265}; //coordinates for each property in bottom section
    int right[10] = {}; //
    int left[10] = {};
    int top[10] = {};
    bool GameOver = false;

    GameState::State currentState = gamestate.GetCurrentState();

    if (currentState==GameState::State::GameStart) 
    {   
        // SDL_Delay(5000);
        RollDice();
        //GameOver=false;
        gamestate.SetState(GameState::State::Player1Turn);
    }
    else if (currentState==GameState::State::Player1Turn) 
    {
        PlayerMoney[0].AddAmount(12347);
        SDL_Delay(5000);   
        gamestate.SetState(GameState::State::Player2Turn);
    } 
    else if (currentState==GameState::State::Player2Turn) 
    {   
        PlayerMoney[1].SubtractAmount(7683);
        SDL_Delay(5000);
        gamestate.SetState(GameState::State::Player3Turn);
    }
    else if (currentState==GameState::State::Player3Turn) 
    {   
        PlayerMoney[2].SetAmount(3000);
        SDL_Delay(5000);
        gamestate.SetState(GameState::State::Player4Turn);
    }
    else if (currentState==GameState::State::Player4Turn) 
    {   
        PlayerMoney[3].SetAmount(99999);
        SDL_Delay(5000);
        // gamestate.SetState(GameState::State::Player1Turn);
        gamestate.SetState(GameState::State::GameOver);
    }
    else if (currentState==GameState::State::GameOver)
    {   
        SDL_Delay(3000);
        return GameOver=false;
    }
    return GameOver;
}