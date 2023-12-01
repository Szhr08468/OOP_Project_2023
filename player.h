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
    Player(){}
    Player(std::string n);
    ~Player();

    void Intialize_piece_money();

    Money GetMoneyObject();

    Piece GetPieceObject();

    private:
    std::string name; 
    Piece piece;
    Money money;

};

#endif // PLAYER_H