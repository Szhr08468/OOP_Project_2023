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
    static int dr = 0;
    static int dg = 0;
    static int dp = 0;
    static int db = 0;
    static int mon0 = 1500;
    static int mon1 = 1500;
    static int mon2 = 1500;
    static int mon3 = 1500;

    bool GameOver = false;

    GameState::State currentState = gamestate.GetCurrentState();

    if (currentState == GameState::State::GameStart)
    {
        PlayerMoney[0].SetAmount(mon0);
        PlayerMoney[1].SetAmount(mon1);
        PlayerMoney[2].SetAmount(mon2);
        PlayerMoney[3].SetAmount(mon3);
        gamePieces[0].SetPosition(red[0][0], red[0][1]);
        gamePieces[1].SetPosition(green[0][0], green[0][1]);
        gamePieces[2].SetPosition(pink[0][0], pink[0][1]);
        gamePieces[3].SetPosition(blue[0][0], blue[0][1]);
        gamestate.SetState(GameState::State::Player1Turn);
    }
    else if (currentState == GameState::State::Player1Turn)
    {
        dr = (dr + RollDice()) % 40;
        gamePieces[0].SetPosition(red[dr][0], red[dr][1]);
        if (all_cards[dr][0] != "Community Chest" && all_cards[dr][0] != "Chance" && all_cards[dr][0] != "Go" && all_cards[dr][0] != "Income Tax" && all_cards[dr][0] != "Jail" && all_cards[dr][0] != "Go to Jail" && all_cards[dr][0] != "Free Parking" && all_cards[dr][0] != "Super Tax")
        {
            DisplayCardForBuy(all_cards[dr][1].c_str());
            if(DisplayCardForBuy(all_cards[dr][1].c_str())==true)
            {
            mon0 = mon0 - stoi(all_cards[dr][2]);
            PlayerMoney[0].SetAmount(mon0);
            
            SDL_Delay(2000);
            }
        }
        else if (all_cards[dr][0] == "Community Chest")
        {
            int a = rand() % 15;
            DisplayChanceOrComunnityChest(("assets/CommunityChest/CommunityChest" + std::to_string(a) + ".jpg").c_str());
            if (a == 0)
            {
                gamePieces[0].SetPosition(red[0][0], red[0][1]);
            }
            else if (a == 1)
            {
                PlayerMoney[0].AddAmount(100);
            }
            else if (a == 2)
            {
                PlayerMoney[0].SubtractAmount(100);
            }
            else if (a == 3)
            {
                PlayerMoney[0].AddAmount(150);
            }
            else if (a == 4)
            {
                PlayerMoney[0].AddAmount(0);
            }
            else if (a == 5)
            {
                gamePieces[0].SetPosition(red[10][0], red[10][1]);
            }
            else if (a == 6)
            {
                PlayerMoney[0].AddAmount(300);
                PlayerMoney[1].SubtractAmount(100);
                PlayerMoney[2].SubtractAmount(100);
                PlayerMoney[3].SubtractAmount(100);
            }
            else if (a == 7)
            {
                PlayerMoney[0].AddAmount(200);
            }
            else if (a == 8 || a == 9 || a == 10)
            {
                PlayerMoney[0].SubtractAmount(200);
            }
            else if (a == 11)
            {
                PlayerMoney[0].AddAmount(150);
            }
            else if (a == 12)
            {
                PlayerMoney[0].AddAmount(250);
            }
            else if (a == 13)
            {
                PlayerMoney[0].SubtractAmount(200);
            }
            else if (a == 14)
            {
                PlayerMoney[0].AddAmount(200);
            }
            SDL_Delay(2000);
        }
        else if (all_cards[dr][0] == "Chance")
        {
            int b = rand() % 15;
            DisplayChanceOrComunnityChest(("assets/Chance/Chance" + std::to_string(b) + ".jpg").c_str());
            if (b == 0)
            {
                gamePieces[0].SetPosition(red[0][0], red[0][1]);
            }
            else if (b == 1)
            {
                gamePieces[0].SetPosition(red[39][0], red[39][1]);
            }
            else if (b == 2)
            {
                gamePieces[0].SetPosition(red[32][0], red[32][1]);
            }
            else if (b == 3)
            {
            }
            else if (b == 4)
            {
            }
            else if (b == 5)
            {
                gamePieces[0].SetPosition(red[27][0], red[27][1]);
            }
            else if (b == 6)
            {
                gamePieces[0].SetPosition(red[19][0], red[19][1]);
            }
            else if (b == 7)
            {
                PlayerMoney[0].SubtractAmount(300);
                PlayerMoney[1].AddAmount(100);
                PlayerMoney[2].AddAmount(100);
                PlayerMoney[3].AddAmount(100);
            }
            else if (b == 8)
            {
                gamePieces[0].SetPosition(red[dr][0], red[dr][1]);
            }
            else if (b == 9)
            {
                gamePieces[0].SetPosition(red[dr - 3][0], red[dr - 3][1]);
            }
            else if (b == 10)
            {
                gamePieces[0].SetPosition(red[10][0], red[10][1]);
            }
            else if (b == 11)
            {
                PlayerMoney[0].AddAmount(0);
            }
            else if (b == 12)
            {
                PlayerMoney[0].SubtractAmount(250);
            }
            else if (b == 13)
            {
                gamePieces[0].SetPosition(red[23][0], red[23][1]);
            }
            else if (b = 14)
            {
                gamePieces[0].SetPosition(red[13][0], red[13][0]);
            }
            SDL_Delay(2000);
        }
        gamestate.SetState(GameState::State::Player2Turn);
    }
    else if (currentState == GameState::State::Player2Turn)
    {
        dg = (dg + RollDice()) % 40;
        gamePieces[1].SetPosition(green[dg][0], green[dg][1]);

        if (all_cards[dg][0] != "Community Chest" && all_cards[dg][0] != "Chance" && all_cards[dg][0] != "Go" && all_cards[dg][0] != "Income Tax" && all_cards[dg][0] != "Jail" && all_cards[dg][0] != "Go to Jail" && all_cards[dg][0] != "Free Parking" && all_cards[dg][0] != "Super Tax")
        {
            DisplayCardForBuy(all_cards[dg][1].c_str());
            if(DisplayCardForBuy(all_cards[dg][1].c_str())==true)
            {
            mon1 = mon1 - stoi(all_cards[dg][2]);
            PlayerMoney[1].SetAmount(mon1);
            SDL_Delay(2000);
            }
        }
        else if (all_cards[dg][0] == "Community Chest")
        {
            int a = rand() % 15;
            DisplayChanceOrComunnityChest(("assets/CommunityChest/CommunityChest" + std::to_string(a) + ".jpg").c_str());
            if (a == 0)
            {
                gamePieces[1].SetPosition(green[0][0], green[0][1]);
            }
            else if (a == 1)
            {
                PlayerMoney[1].AddAmount(100);
            }
            else if (a == 2)
            {
                PlayerMoney[1].SubtractAmount(100);
            }
            else if (a == 3)
            {
                PlayerMoney[1].AddAmount(150);
            }
            else if (a == 4)
            {
                PlayerMoney[1].AddAmount(0);
            }
            else if (a == 5)
            {
                gamePieces[1].SetPosition(green[10][0], green[10][1]);
            }
            else if (a == 6)
            {
                PlayerMoney[1].AddAmount(300);
                PlayerMoney[0].SubtractAmount(100);
                PlayerMoney[2].SubtractAmount(100);
                PlayerMoney[3].SubtractAmount(100);
            }
            else if (a == 7)
            {
                PlayerMoney[1].AddAmount(200);
            }
            else if (a == 8 || a == 9 || a == 10)
            {
                PlayerMoney[1].SubtractAmount(200);
            }
            else if (a == 11)
            {
                PlayerMoney[1].AddAmount(150);
            }
            else if (a == 12)
            {
                PlayerMoney[1].AddAmount(250);
            }
            else if (a == 13)
            {
                PlayerMoney[1].SubtractAmount(200);
            }
            else if (a == 14)
            {
                PlayerMoney[1].AddAmount(200);
            }
            SDL_Delay(2000);
        }
        else if (all_cards[dg][0] == "Chance")
        {
            int b = rand() % 15;
            DisplayChanceOrComunnityChest(("assets/Chance/Chance" + std::to_string(b) + ".jpg").c_str());
            if (b == 0)
            {
                gamePieces[1].SetPosition(green[0][0], green[0][1]);
            }
            else if (b == 1)
            {
                gamePieces[1].SetPosition(green[39][0], green[39][1]);
            }
            else if (b == 2)
            {
                gamePieces[1].SetPosition(green[32][0], green[32][1]);
            }
            else if (b == 3)
            {
            }
            else if (b == 4)
            {
            }
            else if (b == 5)
            {
                gamePieces[1].SetPosition(green[27][0], green[27][1]);
            }
            else if (b == 6)
            {
                gamePieces[1].SetPosition(green[19][0], green[19][1]);
            }
            else if (b == 7)
            {
                PlayerMoney[1].SubtractAmount(300);
                PlayerMoney[0].AddAmount(100);
                PlayerMoney[2].AddAmount(100);
                PlayerMoney[3].AddAmount(100);
            }
            else if (b == 8)
            {
                gamePieces[1].SetPosition(green[dg][0], green[dg][1]);
            }
            else if (b == 9)
            {
                gamePieces[1].SetPosition(green[dg - 3][0], green[dg - 3][1]);
            }
            else if (b == 10)
            {
                gamePieces[1].SetPosition(green[10][0], green[10][1]);
            }
            else if (b == 11)
            {
                PlayerMoney[1].AddAmount(0);
            }
            else if (b == 12)
            {
                PlayerMoney[1].SubtractAmount(250);
            }
            else if (b == 13)
            {
                gamePieces[1].SetPosition(green[23][0], green[23][1]);
            }
            else if (b = 14)
            {
                gamePieces[1].SetPosition(green[13][0], green[13][0]);
            }
            SDL_Delay(2000);
        }
        gamestate.SetState(GameState::State::Player3Turn);
    }
    else if (currentState == GameState::State::Player3Turn)
    {
        dp = (dp + RollDice()) % 40;
        gamePieces[2].SetPosition(pink[dp][0], pink[dp][1]);

        if (all_cards[dp][0] != "Community Chest" && all_cards[dp][0] != "Chance" && all_cards[dp][0] != "Go" && all_cards[dp][0] != "Income Tax" && all_cards[dp][0] != "Jail" && all_cards[dp][0] != "Go to Jail" && all_cards[dp][0] != "Free Parking" && all_cards[dp][0] != "Super Tax")
        {
            DisplayCardForBuy(all_cards[dp][1].c_str());
            if(DisplayCardForBuy(all_cards[dp][1].c_str())==true)
            {
            mon2 = mon2 - stoi(all_cards[dp][2]);
            PlayerMoney[2].SetAmount(mon2);
            SDL_Delay(2000);
            }
        }
        else if (all_cards[dp][0] == "Community Chest")
        {
            int a = rand() % 15;
            DisplayChanceOrComunnityChest(("assets/CommunityChest/CommunityChest" + std::to_string(a) + ".jpg").c_str());
            if (a == 0)
            {
                gamePieces[2].SetPosition(pink[0][0], pink[0][1]);
            }
            else if (a == 1)
            {
                PlayerMoney[2].AddAmount(100);
            }
            else if (a == 2)
            {
                PlayerMoney[2].SubtractAmount(100);
            }
            else if (a == 3)
            {
                PlayerMoney[2].AddAmount(150);
            }
            else if (a == 4)
            {
                PlayerMoney[2].AddAmount(0);
            }
            else if (a == 5)
            {
                gamePieces[2].SetPosition(pink[10][0], pink[10][1]);
            }
            else if (a == 6)
            {
                PlayerMoney[2].AddAmount(300);
                PlayerMoney[0].SubtractAmount(100);
                PlayerMoney[1].SubtractAmount(100);
                PlayerMoney[3].SubtractAmount(100);
            }
            else if (a == 7)
            {
                PlayerMoney[2].AddAmount(200);
            }
            else if (a == 8 || a == 9 || a == 10)
            {
                PlayerMoney[2].SubtractAmount(200);
            }
            else if (a == 11)
            {
                PlayerMoney[2].AddAmount(150);
            }
            else if (a == 12)
            {
                PlayerMoney[2].AddAmount(250);
            }
            else if (a == 13)
            {
                PlayerMoney[2].SubtractAmount(200);
            }
            else if (a == 14)
            {
                PlayerMoney[2].AddAmount(200);
            }
            SDL_Delay(2000);
        }
        else if (all_cards[dp][0] == "Chance")
        {
            int b = rand() % 15;
            DisplayChanceOrComunnityChest(("assets/Chance/Chance" + std::to_string(b) + ".jpg").c_str());
            if (b == 0)
            {
                gamePieces[2].SetPosition(pink[0][0], pink[0][1]);
            }
            else if (b == 1)
            {
                gamePieces[2].SetPosition(pink[39][0], pink[39][1]);
            }
            else if (b == 2)
            {
                gamePieces[2].SetPosition(pink[32][0], pink[32][1]);
            }
            else if (b == 3)
            {
            }
            else if (b == 4)
            {
            }
            else if (b == 5)
            {
                gamePieces[2].SetPosition(pink[27][0], pink[27][1]);
            }
            else if (b == 6)
            {
                gamePieces[2].SetPosition(pink[19][0], pink[19][1]);
            }
            else if (b == 7)
            {
                PlayerMoney[2].SubtractAmount(300);
                PlayerMoney[0].AddAmount(100);
                PlayerMoney[1].AddAmount(100);
                PlayerMoney[3].AddAmount(100);
            }
            else if (b == 8)
            {
                gamePieces[2].SetPosition(pink[dp][0], pink[dp][1]);
            }
            else if (b == 9)
            {
                gamePieces[2].SetPosition(pink[dp - 3][0], pink[dp - 3][1]);
            }
            else if (b == 10)
            {
                gamePieces[2].SetPosition(pink[10][0], pink[10][1]);
            }
            else if (b == 11)
            {
                PlayerMoney[2].AddAmount(0);
            }
            else if (b == 12)
            {
                PlayerMoney[2].SubtractAmount(250);
            }
            else if (b == 13)
            {
                gamePieces[2].SetPosition(pink[23][0], pink[23][1]);
            }
            else if (b = 14)
            {
                gamePieces[2].SetPosition(pink[13][0], pink[13][0]);
            }
            SDL_Delay(2000);
        }
        gamestate.SetState(GameState::State::Player4Turn);
    }
    else if (currentState == GameState::State::Player4Turn)
    {
        db = (db + RollDice()) % 40;
        gamePieces[3].SetPosition(blue[db][0], blue[db][1]);
        if (all_cards[db][0] != "Community Chest" && all_cards[db][0] != "Chance" && all_cards[db][0] != "Go" && all_cards[db][0] != "Income Tax" && all_cards[db][0] != "Jail" && all_cards[db][0] != "Go to Jail" && all_cards[db][0] != "Free Parking" && all_cards[db][0] != "Super Tax")
        {
            DisplayCardForBuy(all_cards[db][1].c_str());
            if(DisplayCardForBuy(all_cards[db][1].c_str())==true)
            {
            mon3 = mon3 - stoi(all_cards[db][2]);
            PlayerMoney[3].SetAmount(mon3);
            SDL_Delay(2000);
            }
        }
        else if (all_cards[db][0] == "Community Chest")
        {
            int a = rand() % 15;
            DisplayChanceOrComunnityChest(("assets/CommunityChest/CommunityChest" + std::to_string(a) + ".jpg").c_str());
            if (a == 0)
            {
                gamePieces[3].SetPosition(blue[0][0], blue[0][1]);
            }
            else if (a == 1)
            {
                PlayerMoney[3].AddAmount(100);
            }
            else if (a == 2)
            {
                PlayerMoney[3].SubtractAmount(100);
            }
            else if (a == 3)
            {
                PlayerMoney[3].AddAmount(150);
            }
            else if (a == 4)
            {
                PlayerMoney[3].AddAmount(0);
            }
            else if (a == 5)
            {
                gamePieces[3].SetPosition(blue[10][0], blue[10][1]);
            }
            else if (a == 6)
            {
                PlayerMoney[3].AddAmount(300);
                PlayerMoney[0].SubtractAmount(100);
                PlayerMoney[1].SubtractAmount(100);
                PlayerMoney[2].SubtractAmount(100);
            }
            else if (a == 7)
            {
                PlayerMoney[3].AddAmount(200);
            }
            else if (a == 8 || a == 9 || a == 10)
            {
                PlayerMoney[3].SubtractAmount(200);
            }
            else if (a == 11)
            {
                PlayerMoney[3].AddAmount(150);
            }
            else if (a == 12)
            {
                PlayerMoney[3].AddAmount(250);
            }
            else if (a == 13)
            {
                PlayerMoney[3].SubtractAmount(200);
            }
            else if (a == 14)
            {
                PlayerMoney[3].AddAmount(200);
            }
            SDL_Delay(2000);
        }
        else if (all_cards[db][0] == "Chance")
        {
            int b = rand() % 15;
            DisplayChanceOrComunnityChest(("assets/Chance/Chance" + std::to_string(b) + ".jpg").c_str());
            if (b == 0)
            {
                gamePieces[3].SetPosition(blue[0][0], blue[0][1]);
            }
            else if (b == 1)
            {
                gamePieces[3].SetPosition(blue[39][0], blue[39][1]);
            }
            else if (b == 2)
            {
                gamePieces[3].SetPosition(blue[32][0], blue[32][1]);
            }
            else if (b == 3)
            {
            }
            else if (b == 4)
            {
            }
            else if (b == 5)
            {
                gamePieces[3].SetPosition(blue[27][0], blue[27][1]);
            }
            else if (b == 6)
            {
                gamePieces[3].SetPosition(blue[19][0], blue[19][1]);
            }
            else if (b == 7)
            {
                PlayerMoney[3].SubtractAmount(300);
                PlayerMoney[0].AddAmount(100);
                PlayerMoney[1].AddAmount(100);
                PlayerMoney[2].AddAmount(100);
            }
            else if (b == 8)
            {
                gamePieces[3].SetPosition(blue[db][0], blue[db][1]);
            }
            else if (b == 9)
            {
                gamePieces[3].SetPosition(blue[db - 3][0], blue[db - 3][1]);
            }
            else if (b == 10)
            {
                gamePieces[3].SetPosition(blue[10][0], blue[10][1]);
            }
            else if (b == 11)
            {
                PlayerMoney[3].AddAmount(0);
            }
            else if (b == 12)
            {
                PlayerMoney[3].SubtractAmount(250);
            }
            else if (b == 13)
            {
                gamePieces[3].SetPosition(blue[23][0], blue[23][1]);
            }
            else if (b = 14)
            {
                gamePieces[3].SetPosition(blue[13][0], blue[13][0]);
            }
            SDL_Delay(2000);
        }
        gamestate.SetState(GameState::State::Player1Turn);
    }
    // SDL_Delay(3000);
    return GameOver;
}