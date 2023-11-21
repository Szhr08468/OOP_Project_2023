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
    int right[10] = {550,495,440,380,325,270,215,155,100,40}; //
    int left[10] = {};
    int top[10] = {};
    // int player1vect[40][2]={[805,620],[745,620],[685,620],[625,620],[565,620],[505,620],[445,620],[385,620],[325,620],[265,620],[265,560],[265,500],[265,440],[265,380],[265,320],[265,260],[265,200],[265,140],[265,80],[265,20],[325,20],[385,20],[445,20],[505,20],[565,20],[625,20],[685,20],[745,20],[805,20],[890,20],[890,80],[890,140],[890,200],[890,260],[890,320],[890,380],[890,440],[890,500],[890,560],[890,620]};
    // int player2vect[40][2]={[835,620],[775,620],[715,620],[655,620],[595,620],[535,620],[475,620],[415,620],[355,620],[295,620],[295,560],[295,500],[295,440],[295,380],[295,320],[295,260],[295,200],[295,140],[295,80],[295,20],[355,20],[415,20],[475,20],[535,20],[595,20],[655,20],[715,20],[775,20],[835,20],[920,20],[920,80],[920,140],[920,200],[920,260],[920,320],[920,380],[920,440],[920,500],[920,560],[920,620]};
    // int player3vect[80]={830,620,770,620,710,620,650,620,590,620,530,620,470,620,410,620,350,620,290,620,290,560,290,500,290,440,290,380,290,320,290,260,290,200,290,140,290,80,290,20,350,20,410,20,470,20,530,20,590,20,650,20,710,20,770,20,830,20,890,20,890,80,890,140,890,200,890,260,890,320,890,380,890,440,890,500,890,560,890,620};
    int player4vect[80]={830,620,770,620,710,620,650,620,590,620,530,620,470,620,410,620,350,620,290,620,290,560,290,500,290,440,290,380,290,320,290,260,290,200,290,140,290,80,290,20,350,20,410,20,470,20,530,20,590,20,650,20,710,20,770,20,830,20,890,20,890,80,890,140,890,200,890,260,890,320,890,380,890,440,890,500,890,560,890,620};
    int player1vect[40][2] = {
    {805,620},{745,620},{685,620},{625,620},{565,620},{505,620},{445,620},{385,620},{300,620},
    {300,560},{300,500},{300,440},{300,300},{300,320},{300,260},{300,200},{300,140},{300,80},
    {385,80},{445,80},{505,80},{565,80},{625,80},{685,80},{745,80},{805,80},{890,80},
    {890,140},{890,200},{890,260},{890,320},{890,380},{890,440},{890,500},{890,560},{890,620}};
//     int player1vect[40][2] = {
//     {805,620},{745,620},{685,620},{625,620},{565,620},
//     {505,620},{445,620},{385,620},{300,620},{265,620},
//     {265,560},{265,500},{265,440},{265,380},{265,320},
//     {265,260},{265,200},{265,140},{265,80},{265,20},
//     {325,20},{385,20},{445,20},{505,20},{565,20},
//     {625,20},{685,20},{745,20},{805,20},{890,20},
//     {890,80},{890,140},{890,200},{890,260},{890,320},
//     {890,380},{890,440},{890,500},{890,560},{890,620}
// };

int player2vect[40][2] = {
    {835,620},{775,620},{715,620},{655,620},{595,620},
    {535,620},{475,620},{415,620},{355,620},{295,620},
    {295,560},{295,500},{295,440},{295,380},{295,320},
    {295,260},{295,200},{295,140},{295,80},{295,20},
    {355,20},{415,20},{475,20},{535,20},{595,20},
    {655,20},{715,20},{775,20},{835,20},{920,20},
    {920,80},{920,140},{920,200},{920,260},{920,320},
    {920,380},{920,440},{920,500},{920,560},{920,620}
};

    static int player1dice;
    static int player2dice;
    static int player3dice;
    static int player4dice;
    
    bool GameOver = false;

    GameState::State currentState = gamestate.GetCurrentState();
    while(GameOver!=true)
    {
        if (currentState==GameState::State::GameStart) 
        {   
            PlayerMoney[0].SetAmount(1500);
            PlayerMoney[1].SetAmount(1500);
            PlayerMoney[2].SetAmount(1500);
            PlayerMoney[3].SetAmount(1500);
            // SDL_Delay(5000);
            // for(int i=0; i<40; i=i+2)
            // {
            //     SDL_Delay(1000);
            //     gamePieces[0].SetPosition(player1vect[i], player1vect[i+1]);
            // }
            // int rolledValue = RollDice();
            // gamePieces[0].MoveRectx(rolledValue * 60); // Move the piece based on the rolled dice value
            //GameOver=false;
            // DisplayCardForBuy("assets/CommunityChest/CommunityChest0.jpg");
            gamestate.SetState(GameState::State::Player1Turn);
        }
        else if (currentState==GameState::State::Player1Turn) 
        {
            // PlayerMoney[0].SetAmount(1500);
            SDL_Delay(5000);  
            int rolledValue1 = RollDice();
            player1dice+=rolledValue1;
            gamePieces[0].SetPosition(player1vect[player1dice-1][0], player1vect[player1dice-1][1]);
            //decidewhattodo(player1vect[a], player1vect[a+1]);
            // gamePieces[0].MoveRectx(rolledValue * 62);
            // DisplayCardForBuy("assets/CommunityChest/CommunityChest0.jpg");
            gamestate.SetState(GameState::State::Player2Turn);
            // Piece::MoveRect(85);
        } 
        else if (currentState==GameState::State::Player2Turn) 
        {   
            // PlayerMoney[1].SubtractAmount(1500);
            SDL_Delay(5000);
            int rolledValue2 = RollDice();
            player2dice+=rolledValue2;
            int b=player2dice*2;
            gamePieces[1].SetPosition(player2vect[player2dice-1][0], player2vect[player2dice-1][1]);
            // gamePieces[1].MoveRectx(rolledValue * 62);
            // DisplayCardForBuy("assets/CommunityChest/CommunityChest1.jpg");
            gamestate.SetState(GameState::State::Player3Turn);
        }
        else if (currentState==GameState::State::Player3Turn) 
        {   
            // PlayerMoney[2].SetAmount(1500);
            SDL_Delay(5000);
            int rolledValue3 = RollDice();
            player3dice+=rolledValue3;
            // int c=player3dice*2;
            // gamePieces[2].SetPosition(player1vect[c-2], player1vect[c-1]);
            // int rolledValue = RollDice();
            // gamePieces[2].MoveRectx(rolledValue * 62);
            // DisplayCardForBuy("assets/CommunityChest/CommunityChest2.jpg");
            gamestate.SetState(GameState::State::Player4Turn);
        }
        else if (currentState==GameState::State::Player4Turn) 
        {   
            // PlayerMoney[3].SetAmount(1500);
            SDL_Delay(5000);
            int rolledValue3 = RollDice();
            player4dice+=rolledValue3;
            // int d=player4dice*2;
            // gamePieces[3].SetPosition(player1vect[d-2], player1vect[d-1]);
            // int rolledValue = RollDice();
            // gamePieces[3].MoveRecty(rolledValue * 62);
            // DisplayCardForBuy("assets/CommunityChest/CommunityChest3.jpg");
            // gamestate.SetState(GameState::State::Player1Turn);
            gamestate.SetState(GameState::State::Player1Turn);
        }
        // else if (currentState==GameState::State::GameOver)
        // {   
        //     SDL_Delay(3000);
        //     // return GameOver=false;
        // }
    return GameOver;
    }
}