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

    bool GameOver = false;

    GameState::State currentState = gamestate.GetCurrentState();

    if (currentState == GameState::State::GameStart)
    {
        

        // PlayerMoney[0].SetAmount(mon0);
        // PlayerMoney[1].SetAmount(mon1);
        // PlayerMoney[2].SetAmount(mon2);
        // PlayerMoney[3].SetAmount(mon3);
        // gamePieces[0].SetPosition(red[0][0], red[0][1]);
        // gamePieces[1].SetPosition(green[0][0], green[0][1]);
        // gamePieces[2].SetPosition(pink[0][0], pink[0][1]);
        // gamePieces[3].SetPosition(blue[0][0], blue[0][1]);
        gamestate.SetState(GameState::State::Player1Turn);
    }
    else if (currentState == GameState::State::Player1Turn)
    {
        gamestate.SetState(GameState::State::Player2Turn);
    }
    else if (currentState == GameState::State::Player2Turn)
    {
        gamestate.SetState(GameState::State::Player3Turn);
    }
    else if (currentState == GameState::State::Player3Turn)
    {
        gamestate.SetState(GameState::State::Player4Turn);
    }
    else if (currentState == GameState::State::Player4Turn)
    {
        gamestate.SetState(GameState::State::Player1Turn);
    }
    SDL_Delay(1000);
    return GameOver;
}