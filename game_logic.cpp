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
        if ((player[0].GetMoneyObject()).GetAmount()<0) 
        {}
        else if (player[0].InJail==false)
        {
            IsRPressed();
            
            pos_p1 = pos_p1 + RollDice();
            if (pos_p1>39)
            {
                player[0].AddMoney(200);
                pos_p1 = pos_p1%40;
            }
            player[0].ChangePosition(pos_p1);
            if (all_cards[pos_p1][0] != "Community Chest" && all_cards[pos_p1][0] != "Chance" && all_cards[pos_p1][0] != "Go" && all_cards[pos_p1][0] != "Income Tax" && all_cards[pos_p1][0] != "Jail" && all_cards[pos_p1][0] != "Go to Jail" && all_cards[pos_p1][0] != "Free Parking" && all_cards[pos_p1][0] != "Super Tax"){
                if(((player[0].buy_or_not)[pos_p1]==true) || ((player[1].buy_or_not)[pos_p1]==true) || ((player[2].buy_or_not)[pos_p1]==true) || ((player[3].buy_or_not)[pos_p1]==true)){
                    DisplayCard((all_cards[pos_p1][1]).c_str());

                    int pos = pos_p1;

                    player[0].SubMoney(std::stoi(all_cards[pos][3]));

                    if((player[0].buy_or_not)[pos]==true)
                    {
                        player[0].AddMoney(std::stoi(all_cards[pos][3]));
                    }
                    else if((player[1].buy_or_not)[pos]==true)
                    {
                        player[1].AddMoney(std::stoi(all_cards[pos][3]));
                    }
                    else if((player[2].buy_or_not)[pos]==true)
                    {
                        player[2].AddMoney(std::stoi(all_cards[pos][3]));
                    }
                    else if((player[3].buy_or_not)[pos]==true)
                    {
                        player[3].AddMoney(std::stoi(all_cards[pos][3]));
                    }
                    
                }
                else{
                    bool x = DisplayCardForBuy((all_cards[pos_p1][1]).c_str());
                    if(x==true){
                        player[0].SubMoney(std::stoi(all_cards[pos_p1][2]));
                        (player[0].buy_or_not)[pos_p1] = true;
                    }
                }
            }
            else if(all_cards[pos_p1][0] == "Community Chest"){
                int a = rand()%15;
                if (a==6){a=7;}
                if(a==4 && (player[0].GetOutJailCard[0]==true || player[1].GetOutJailCard[0]==true || player[2].GetOutJailCard[0]==true || player[3].GetOutJailCard[0]==true)){
                    a = rand()%15;
                    if (a==6){a=7;}
                    while(a==4){
                        a = rand()%15;
                        if (a==6){a=7;}
                    }
                }
                DisplayChanceOrComunnityChest(("assets/CommunityChest/CommunityChest" + std::to_string(a) + ".jpg").c_str());
                player[0].DoCommunityChest(a);

            }
            else if(all_cards[pos_p1][0] == "Chance"){
                int b = rand()% 15;
                if (b==7){b=6;}
                if(b==8 && (player[0].GetOutJailCard[1]==true || player[1].GetOutJailCard[1]==true || player[2].GetOutJailCard[1]==true || player[3].GetOutJailCard[1]==true)){
                    b = rand()% 15;
                    if (b==7){b=6;}
                    while(b==8){
                        b = rand()% 15;
                        if (b==7){b=6;}
                    }
                }
                DisplayChanceOrComunnityChest(("assets/Chance/Chance" + std::to_string(b) + ".jpg").c_str());
                player[0].DoChance(b);
                if(b==9 || b==6 || b==3 || b==4 || b==2 || b==1 || b==5 || b==13 || b==14){
                    if(((player[0].buy_or_not)[player[0].GetPlayerPosition()]==true) || ((player[1].buy_or_not)[player[0].GetPlayerPosition()]==true) || ((player[2].buy_or_not)[player[0].GetPlayerPosition()]==true) || ((player[3].buy_or_not)[player[0].GetPlayerPosition()]==true)){
                        DisplayCard((all_cards[player[0].GetPlayerPosition()][1]).c_str());

                        int pos = player[0].GetPlayerPosition();

                        player[0].SubMoney(std::stoi(all_cards[pos][3]));

                        if((player[0].buy_or_not)[pos]==true)
                        {
                            player[0].AddMoney(std::stoi(all_cards[pos][3]));
                        }
                        else if((player[1].buy_or_not)[pos]==true)
                        {
                            player[1].AddMoney(std::stoi(all_cards[pos][3]));
                        }
                        else if((player[2].buy_or_not)[pos]==true)
                        {
                            player[2].AddMoney(std::stoi(all_cards[pos][3]));
                        }
                        else if((player[3].buy_or_not)[pos]==true)
                        {
                            player[3].AddMoney(std::stoi(all_cards[pos][3]));
                        }
                    }
                    else{
                        bool x = DisplayCardForBuy((all_cards[player[0].GetPlayerPosition()][1]).c_str());
                        if(x==true){
                            player[0].SubMoney(std::stoi(all_cards[player[0].GetPlayerPosition()][2]));
                            (player[0].buy_or_not)[player[0].GetPlayerPosition()] = true;
                        }
                    }
                }

            }
            else if(all_cards[pos_p1][0]=="Income Tax"){
                player[0].SubMoney(200);
            }
            else if(all_cards[pos_p1][0]=="Go to Jail"){
                player[0].SendJail();
            }
            else if(all_cards[pos_p1][0]=="Super Tax"){
                player[0].SubMoney(500);
            }

  
        }
        else {
            if (player[0].GetOutJailCard[0]==true) {
                player[0].InJail=false;
                player[0].GetOutJailCard[0]=false;
            }
            else if (player[0].GetOutJailCard[1]==true) {
                player[0].InJail=false;
                player[0].GetOutJailCard[1]=false;
            }
            else {
                player[0].InJail=false;
                player[0].SubMoney(1000);
            }

            player[0].ChangePosition(10);
        }

        
        gamestate.SetState(GameState::State::Player2Turn);
    }
    else if (currentState == GameState::State::Player2Turn)
    {   
        if ((player[1].GetMoneyObject()).GetAmount()<0) 
        {}
        else if (player[1].InJail == false){
            IsRPressed();

            pos_p2 = pos_p2 + RollDice();
            if (pos_p2 > 39)
            {
                player[1].AddMoney(200);
                pos_p2 = pos_p2 % 40;
            }
            player[1].ChangePosition(pos_p2);
            if (all_cards[pos_p2][0] != "Community Chest" && all_cards[pos_p2][0] != "Chance" && all_cards[pos_p2][0] != "Go" && all_cards[pos_p2][0] != "Income Tax" && all_cards[pos_p2][0] != "Jail" && all_cards[pos_p2][0] != "Go to Jail" && all_cards[pos_p2][0] != "Free Parking" && all_cards[pos_p2][0] != "Super Tax")
            {
                if (((player[0].buy_or_not)[pos_p2] == true) || ((player[1].buy_or_not)[pos_p2] == true) || ((player[2].buy_or_not)[pos_p2] == true) || ((player[3].buy_or_not)[pos_p2] == true))
                {
                    DisplayCard((all_cards[pos_p2][1]).c_str());
                    int pos = pos_p2;

                    player[1].SubMoney(std::stoi(all_cards[pos][3]));

                    if((player[0].buy_or_not)[pos]==true)
                    {
                        player[0].AddMoney(std::stoi(all_cards[pos][3]));
                    }
                    else if((player[1].buy_or_not)[pos]==true)
                    {
                        player[1].AddMoney(std::stoi(all_cards[pos][3]));
                    }
                    else if((player[2].buy_or_not)[pos]==true)
                    {
                        player[2].AddMoney(std::stoi(all_cards[pos][3]));
                    }
                    else if((player[3].buy_or_not)[pos]==true)
                    {
                        player[3].AddMoney(std::stoi(all_cards[pos][3]));
                    }
                }
                else
                {
                    bool x = DisplayCardForBuy((all_cards[pos_p2][1]).c_str());
                    if (x == true)
                    {
                        player[1].SubMoney(std::stoi(all_cards[pos_p2][2]));
                        (player[1].buy_or_not)[pos_p2] = true;
                    }
                }
            }
            else if (all_cards[pos_p2][0] == "Community Chest")
            {
                int a = rand()%15;
                if (a==6){a=7;}
                if(a==4 && (player[0].GetOutJailCard[0]==true || player[1].GetOutJailCard[0]==true || player[2].GetOutJailCard[0]==true || player[3].GetOutJailCard[0]==true)){
                    a = rand()%15;
                    if (a==6){a=7;}
                    while(a==4){
                        a = rand()%15;
                        if (a==6){a=7;}
                    }
                }
                DisplayChanceOrComunnityChest(("assets/CommunityChest/CommunityChest" + std::to_string(a) + ".jpg").c_str());
                player[1].DoCommunityChest(a);
            }
            else if (all_cards[pos_p2][0] == "Chance")
            {
                int b = rand()% 15;
                if (b==7){b=6;}
                if(b==8 && (player[0].GetOutJailCard[1]==true || player[1].GetOutJailCard[1]==true || player[2].GetOutJailCard[1]==true || player[3].GetOutJailCard[1]==true)){
                    b = rand()% 15;
                    if (b==7){b=6;}
                    while(b==8){
                        b = rand()% 15;
                        if (b==7){b=6;}
                    }
                }
                DisplayChanceOrComunnityChest(("assets/Chance/Chance" + std::to_string(b) + ".jpg").c_str());
                player[1].DoChance(b);
                if(b==9 || b==6 || b==3 || b==4 || b==2 || b==1 || b==5 || b==13 || b==14){
                    if (((player[0].buy_or_not)[player[1].GetPlayerPosition()] == true) || ((player[1].buy_or_not)[player[1].GetPlayerPosition()] == true) || ((player[2].buy_or_not)[player[1].GetPlayerPosition()] == true) || ((player[3].buy_or_not)[player[1].GetPlayerPosition()] == true))
                    {
                        DisplayCard((all_cards[player[1].GetPlayerPosition()][1]).c_str());
                        int pos = player[1].GetPlayerPosition();

                        player[1].SubMoney(std::stoi(all_cards[pos][3]));

                        if((player[0].buy_or_not)[pos]==true)
                        {
                            player[0].AddMoney(std::stoi(all_cards[pos][3]));
                        }
                        else if((player[1].buy_or_not)[pos]==true)
                        {
                            player[1].AddMoney(std::stoi(all_cards[pos][3]));
                        }
                        else if((player[2].buy_or_not)[pos]==true)
                        {
                            player[2].AddMoney(std::stoi(all_cards[pos][3]));
                        }
                        else if((player[3].buy_or_not)[pos]==true)
                        {
                            player[3].AddMoney(std::stoi(all_cards[pos][3]));
                        }
                    }
                    else
                    {
                        bool x = DisplayCardForBuy((all_cards[player[1].GetPlayerPosition()][1]).c_str());
                        if (x == true)
                        {
                            player[1].SubMoney(std::stoi(all_cards[player[1].GetPlayerPosition()][2]));
                            (player[1].buy_or_not)[player[1].GetPlayerPosition()] = true;
                        }
                    }
                }
            }
            else if(all_cards[pos_p2][0]=="Income Tax"){
                player[1].SubMoney(200);
            }
            else if(all_cards[pos_p2][0]=="Go to Jail"){
                player[1].SendJail();
            }
            else if(all_cards[pos_p2][0]=="Super Tax"){
                player[1].SubMoney(500);
            }
        }
        else {
            if (player[1].GetOutJailCard[0]==true) {
                player[1].InJail=false;
                player[1].GetOutJailCard[0]=false;
            }
            else if (player[1].GetOutJailCard[1]==true) {
                player[1].InJail=false;
                player[1].GetOutJailCard[1]=false;
            }
            else {
                player[1].InJail=false;
                player[1].SubMoney(1000);
            }
            player[1].ChangePosition(10);
        }
        gamestate.SetState(GameState::State::Player3Turn);

    }
    else if (currentState == GameState::State::Player3Turn)
    {   
        if ((player[2].GetMoneyObject()).GetAmount()<0) 
        {}
        else if (player[2].InJail == false){
            IsRPressed();

            pos_p3 = pos_p3 + RollDice();
            if (pos_p3 > 39)
            {
                player[2].AddMoney(200);
                pos_p3 = pos_p3 % 40;
            }
            player[2].ChangePosition(pos_p3);
            if (all_cards[pos_p3][0] != "Community Chest" && all_cards[pos_p3][0] != "Chance" && all_cards[pos_p3][0] != "Go" && all_cards[pos_p3][0] != "Income Tax" && all_cards[pos_p3][0] != "Jail" && all_cards[pos_p3][0] != "Go to Jail" && all_cards[pos_p3][0] != "Free Parking" && all_cards[pos_p3][0] != "Super Tax")
            {
                if (((player[0].buy_or_not)[pos_p3] == true) || ((player[1].buy_or_not)[pos_p3] == true) || ((player[2].buy_or_not)[pos_p3] == true) || ((player[3].buy_or_not)[pos_p3] == true))
                {
                    DisplayCard((all_cards[pos_p3][1]).c_str());
                    int pos = pos_p3;

                    player[2].SubMoney(std::stoi(all_cards[pos][3]));

                    if((player[0].buy_or_not)[pos]==true)
                    {
                        player[0].AddMoney(std::stoi(all_cards[pos][3]));
                    }
                    else if((player[1].buy_or_not)[pos]==true)
                    {
                        player[1].AddMoney(std::stoi(all_cards[pos][3]));
                    }
                    else if((player[2].buy_or_not)[pos]==true)
                    {
                        player[2].AddMoney(std::stoi(all_cards[pos][3]));
                    }
                    else if((player[3].buy_or_not)[pos]==true)
                    {
                        player[3].AddMoney(std::stoi(all_cards[pos][3]));
                    }
                }
                else
                {
                    bool x = DisplayCardForBuy((all_cards[pos_p3][1]).c_str());
                    if (x == true)
                    {
                        player[2].SubMoney(std::stoi(all_cards[pos_p3][2]));
                        (player[2].buy_or_not)[pos_p3] = true;
                    }
                }
            }
            else if (all_cards[pos_p3][0] == "Community Chest")
            {
                int a = rand()%15;
                if (a==6){a=7;}
                if(a==4 && (player[0].GetOutJailCard[0]==true || player[1].GetOutJailCard[0]==true || player[2].GetOutJailCard[0]==true || player[3].GetOutJailCard[0]==true)){
                    a = rand()%15;
                    if (a==6){a=7;}
                    while(a==4){
                        a = rand()%15;
                        if (a==6){a=7;}
                    }
                }
                DisplayChanceOrComunnityChest(("assets/CommunityChest/CommunityChest" + std::to_string(a) + ".jpg").c_str());
                player[2].DoCommunityChest(a);
            }
            else if (all_cards[pos_p3][0] == "Chance")
            {
                int b = rand()% 15;
                if (b==7){b=6;}
                if(b==8 && (player[0].GetOutJailCard[1]==true || player[1].GetOutJailCard[1]==true || player[2].GetOutJailCard[1]==true || player[3].GetOutJailCard[1]==true)){
                    b = rand()% 15;
                    if (b==7){b=6;}
                    while(b==8){
                        b = rand()% 15;
                        if (b==7){b=6;}
                    }
                }
                DisplayChanceOrComunnityChest(("assets/Chance/Chance" + std::to_string(b) + ".jpg").c_str());
                player[2].DoChance(b);
                if(b==9 || b==6 || b==3 || b==4 || b==2 || b==1 || b==5 || b==13 || b==14){
                    if (((player[0].buy_or_not)[player[2].GetPlayerPosition()] == true) || ((player[1].buy_or_not)[player[2].GetPlayerPosition()] == true) || ((player[2].buy_or_not)[player[2].GetPlayerPosition()] == true) || ((player[3].buy_or_not)[player[2].GetPlayerPosition()] == true))
                    {
                        DisplayCard((all_cards[player[2].GetPlayerPosition()][1]).c_str());
                        int pos = player[2].GetPlayerPosition();

                        player[2].SubMoney(std::stoi(all_cards[pos][3]));

                        if((player[0].buy_or_not)[pos]==true)
                        {
                            player[0].AddMoney(std::stoi(all_cards[pos][3]));
                        }
                        else if((player[1].buy_or_not)[pos]==true)
                        {
                            player[1].AddMoney(std::stoi(all_cards[pos][3]));
                        }
                        else if((player[2].buy_or_not)[pos]==true)
                        {
                            player[2].AddMoney(std::stoi(all_cards[pos][3]));
                        }
                        else if((player[3].buy_or_not)[pos]==true)
                        {
                            player[3].AddMoney(std::stoi(all_cards[pos][3]));
                        }
                    }
                    else
                    {
                        bool x = DisplayCardForBuy((all_cards[player[2].GetPlayerPosition()][1]).c_str());
                        if (x == true)
                        {
                            player[2].SubMoney(std::stoi(all_cards[player[2].GetPlayerPosition()][2]));
                            (player[2].buy_or_not)[player[2].GetPlayerPosition()] = true;
                        }
                    }
                }
            }
            else if(all_cards[pos_p3][0]=="Income Tax"){
                player[2].SubMoney(200);
            }
            else if(all_cards[pos_p3][0]=="Go to Jail"){
                player[2].SendJail();
            }
            else if(all_cards[pos_p3][0]=="Super Tax"){
                player[2].SubMoney(500);
            }
        }
        else {
            if (player[2].GetOutJailCard[0]==true) {
                player[2].InJail=false;
                player[2].GetOutJailCard[0]=false;
            }
            else if (player[2].GetOutJailCard[1]==true) {
                player[2].InJail=false;
                player[2].GetOutJailCard[1]=false;
            }
            else {
                player[2].InJail=false;
                player[2].SubMoney(1000);
            }
            player[2].ChangePosition(10);
        }
        gamestate.SetState(GameState::State::Player4Turn);
    }
    else if (currentState == GameState::State::Player4Turn)
    {   
        if ((player[3].GetMoneyObject()).GetAmount()<0) 
        {}
        else if (player[3].InJail == false){
            IsRPressed();

            pos_p4 = pos_p4 + RollDice();
            if (pos_p4 > 39)
            {
                player[3].AddMoney(200);
                pos_p4 = pos_p4 % 40;
            }
            player[3].ChangePosition(pos_p4);
            if (all_cards[pos_p4][0] != "Community Chest" && all_cards[pos_p4][0] != "Chance" && all_cards[pos_p4][0] != "Go" && all_cards[pos_p4][0] != "Income Tax" && all_cards[pos_p4][0] != "Jail" && all_cards[pos_p4][0] != "Go to Jail" && all_cards[pos_p4][0] != "Free Parking" && all_cards[pos_p4][0] != "Super Tax")
            {
                if (((player[0].buy_or_not)[pos_p4] == true) || ((player[1].buy_or_not)[pos_p4] == true) || ((player[2].buy_or_not)[pos_p4] == true) || ((player[3].buy_or_not)[pos_p4] == true))
                {
                    DisplayCard((all_cards[pos_p4][1]).c_str());
                    int pos = pos_p4;

                    player[3].SubMoney(std::stoi(all_cards[pos][3]));

                    if((player[0].buy_or_not)[pos]==true)
                    {
                        player[0].AddMoney(std::stoi(all_cards[pos][3]));
                    }
                    else if((player[1].buy_or_not)[pos]==true)
                    {
                        player[1].AddMoney(std::stoi(all_cards[pos][3]));
                    }
                    else if((player[2].buy_or_not)[pos]==true)
                    {
                        player[2].AddMoney(std::stoi(all_cards[pos][3]));
                    }
                    else if((player[3].buy_or_not)[pos]==true)
                    {
                        player[3].AddMoney(std::stoi(all_cards[pos][3]));
                    }
                }
                else
                {
                    bool x = DisplayCardForBuy((all_cards[pos_p4][1]).c_str());
                    if (x == true)
                    {
                        player[3].SubMoney(std::stoi(all_cards[pos_p4][2]));
                        (player[3].buy_or_not)[pos_p4] = true;
                    }
                }
            }
            else if (all_cards[pos_p4][0] == "Community Chest")
            {
                int a = rand()%15;
                if (a==6){a=7;}
                if(a==4 && (player[0].GetOutJailCard[0]==true || player[1].GetOutJailCard[0]==true || player[2].GetOutJailCard[0]==true || player[3].GetOutJailCard[0]==true)){
                    a = rand()%15;
                    if (a==6){a=7;}
                    while(a==4){
                        a = rand()%15;
                        if (a==6){a=7;}
                    }
                }
                DisplayChanceOrComunnityChest(("assets/CommunityChest/CommunityChest" + std::to_string(a) + ".jpg").c_str());
                player[3].DoCommunityChest(a);
            }
            else if (all_cards[pos_p4][0] == "Chance")
            {
                int b = rand()% 15;
                if (b==7){b=6;}
                if(b==8 && (player[0].GetOutJailCard[1]==true || player[1].GetOutJailCard[1]==true || player[2].GetOutJailCard[1]==true || player[3].GetOutJailCard[1]==true)){
                    b = rand()% 15;
                    if (b==7){b=6;}
                    while(b==8){
                        b = rand()% 15;
                        if (b==7){b=6;}
                    }
                }
                DisplayChanceOrComunnityChest(("assets/Chance/Chance" + std::to_string(b) + ".jpg").c_str());
                player[3].DoChance(b);
                if(b==9 || b==6 || b==3 || b==4 || b==2 || b==1 || b==5 || b==13 || b==14){
                    if (((player[0].buy_or_not)[player[3].GetPlayerPosition()] == true) || ((player[1].buy_or_not)[player[3].GetPlayerPosition()] == true) || ((player[2].buy_or_not)[player[3].GetPlayerPosition()] == true) || ((player[3].buy_or_not)[player[3].GetPlayerPosition()] == true))
                    {
                        DisplayCard((all_cards[player[3].GetPlayerPosition()][1]).c_str());
                        int pos = player[3].GetPlayerPosition();

                        player[3].SubMoney(std::stoi(all_cards[pos][3]));

                        if((player[0].buy_or_not)[pos]==true)
                        {
                            player[0].AddMoney(std::stoi(all_cards[pos][3]));
                        }
                        else if((player[1].buy_or_not)[pos]==true)
                        {
                            player[1].AddMoney(std::stoi(all_cards[pos][3]));
                        }
                        else if((player[2].buy_or_not)[pos]==true)
                        {
                            player[2].AddMoney(std::stoi(all_cards[pos][3]));
                        }
                        else if((player[3].buy_or_not)[pos]==true)
                        {
                            player[3].AddMoney(std::stoi(all_cards[pos][3]));
                        }
                    }
                    else
                    {
                        bool x = DisplayCardForBuy((all_cards[player[3].GetPlayerPosition()][1]).c_str());
                        if (x == true)
                        {
                            player[3].SubMoney(std::stoi(all_cards[player[3].GetPlayerPosition()][2]));
                            (player[3].buy_or_not)[player[3].GetPlayerPosition()] = true;
                        }
                    }
                }
            }
            else if(all_cards[pos_p4][0]=="Income Tax"){
                player[3].SubMoney(200);
            }
            else if(all_cards[pos_p4][0]=="Go to Jail"){
                player[3].SendJail();
            }
            else if(all_cards[pos_p4][0]=="Super Tax"){
                player[3].SubMoney(500);
            }
        }       
        else {
            if (player[3].GetOutJailCard[0]==true) {
                player[3].InJail=false;
                player[3].GetOutJailCard[0]=false;
            }
            else if (player[3].GetOutJailCard[1]==true) {
                player[3].InJail=false;
                player[3].GetOutJailCard[1]=false;
            }
            else {
                player[3].InJail=false;
                player[3].SubMoney(1000);
            }
            player[3].ChangePosition(10);
        }
        gamestate.SetState(GameState::State::Player1Turn);

    }


    SDL_Delay(1000);
    

    return GameOver;
}

