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
        dr = (dr + RollDice()) % 40;
        gamePieces[0].SetPosition(red[dr][0], red[dr][1]);
    
        if (all_cards[dr][0] != "Community Chest" && all_cards[dr][0] != "Chance" && all_cards[dr][0] != "Go" && all_cards[dr][0] != "Income Tax" && all_cards[dr][0] != "Jail" && all_cards[dr][0] != "Go to Jail" && all_cards[dr][0] != "Free Parking" && all_cards[dr][0] != "Super Tax") {
            DisplayCardForBuy(all_cards[dr][1].c_str());
            SDL_Delay(2000);
    }
        else if (all_cards[dr][0] == "Community Chest" || all_cards[dr][0] == "Chance") {
            DisplayChanceOrComunnityChest(all_cards[dr][1].c_str());
            SDL_Delay(2000);
    }
        gamestate.SetState(GameState::State::Player2Turn);
    } 
    else if (currentState==GameState::State::Player2Turn) 
    {   
        dg = (dg + RollDice()) % 40;
        gamePieces[1].SetPosition(green[dg][0], green[dg][1]);
    
        if (all_cards[dg][0] != "Community Chest" && all_cards[dg][0] != "Chance" && all_cards[dg][0] != "Go" && all_cards[dg][0] != "Income Tax" && all_cards[dg][0] != "Jail" && all_cards[dg][0] != "Go to Jail" && all_cards[dg][0] != "Free Parking" && all_cards[dg][0] != "Super Tax") {
            DisplayCardForBuy(all_cards[dg][1].c_str());
            SDL_Delay(2000);
    }
        else if (all_cards[dg][0] == "Community Chest" || all_cards[dg][0] == "Chance") {
            DisplayChanceOrComunnityChest(all_cards[dg][1].c_str());
            SDL_Delay(2000);
    }
        gamestate.SetState(GameState::State::Player3Turn);
    }
    else if (currentState==GameState::State::Player3Turn) 
    {   
        dp = (dp + RollDice()) % 40;
        gamePieces[2].SetPosition(pink[dp][0], pink[dp][1]);
    
        if (all_cards[dp][0] != "Community Chest" && all_cards[dp][0] != "Chance" && all_cards[dp][0] != "Go" && all_cards[dp][0] != "Income Tax" && all_cards[dp][0] != "Jail" && all_cards[dp][0] != "Go to Jail" && all_cards[dp][0] != "Free Parking" && all_cards[dp][0] != "Super Tax") {
            DisplayCardForBuy(all_cards[dp][1].c_str());
            SDL_Delay(2000);
            
    }
        else if (all_cards[dp][0] == "Community Chest" || all_cards[dp][0] == "Chance") {
            DisplayChanceOrComunnityChest(all_cards[dp][1].c_str());
            SDL_Delay(2000);
    }
        gamestate.SetState(GameState::State::Player4Turn);
    }
    else if (currentState==GameState::State::Player4Turn) 
    {   
        db = (db+RollDice())%40;
        gamePieces[3].SetPosition(blue[db][0],blue[db][1]);
        if(all_cards[db][0] != "Community Chest" && all_cards[db][0] != "Chance" && all_cards[db][0] != "Go" && all_cards[db][0] != "Income Tax" && all_cards[db][0] != "Jail" && all_cards[db][0] != "Go to Jail" && all_cards[db][0] != "Free Parking" && all_cards[db][0] != "Super Tax"){

            DisplayCardForBuy(all_cards[db][1].c_str());
            SDL_Delay(2000);
        }
        else if(all_cards[db][0] == "Community Chest" || all_cards[db][0] == "Chance"){
            DisplayChanceOrComunnityChest(all_cards[db][1].c_str());
            SDL_Delay(2000);
        }
        gamestate.SetState(GameState::State::Player1Turn);
    }
    
    
    


    //SDL_Delay(3000);
    return GameOver;
    
}