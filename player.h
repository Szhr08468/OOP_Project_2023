#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include<string>
#include "game.h"
#include "pieces.h"
#include "money.h"

// class Game;

class Player : public Game
{ 
    public:
    Player(std::string n);
    ~Player();

    void Intialize_piece_money();
    Money GetMoneyObject();
    Piece GetPieceObject();
    int GetPlayerPosition();
    void ChangePosition(int x);
    void SendJail();
    void AddMoney(int m);
    void SubMoney(int m);
    void DoCommunityChest(int x);
    void DoChance(int x);


    private:
    std::string name; 
    int position;
    Piece piece;
    Money money;
    bool GetOutJailCard[2]; //First Card is of ComuunityChest and the second is of Chance
    bool InJail;

};

#endif // PLAYER_H