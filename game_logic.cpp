#include "game.h"
#include "GameState.h"
#include <cstdio>

bool Game::Update(Game& game,GameState& gamestate)
{   
    GameState::State currentState = gamestate.GetCurrentState();

    // Implement game logic here
    bool GameOver = false;

    if (currentState==GameState::State::Player1Turn) 
    {
        GameOver = game.DisplayCardForBuy("assets/Properties/bond_street.jpg");
        gamestate.SetState(GameState::State::Player2Turn);
    } 
    else if (currentState==GameState::State::Player2Turn) 
    {
        GameOver = game.DisplayCardForBuy("assets/Properties/bow_street.jpg");
        gamestate.SetState(GameState::State::Player3Turn);
    }
    else if (currentState==GameState::State::Player3Turn) 
    {
        GameOver = game.DisplayCardForBuy("assets/Properties/pallmall.jpg");
        gamestate.SetState(GameState::State::Player4Turn);
    }
    else if (currentState==GameState::State::Player4Turn) 
    {
        GameOver = game.DisplayCardForBuy("assets/Properties/park_lane.jpg");
        gamestate.SetState(GameState::State::Player1Turn);
    }
    else if (currentState==GameState::State::GameOver)
    {
        return GameOver=true;
    }


    return GameOver;
}