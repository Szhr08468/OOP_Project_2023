#include "player.h"

Player::Player(std::string n) : name(n) {}

Player::~Player(){}

void Player::Intialize_piece_money() {

    if (name=="p1") {
        piece.SetPosition(red[0][0],red[0][1]);
    }
    else if (name=="p2") {
        piece.SetPosition(green[0][0],green[0][1]);
    }
    else if (name=="p3") {
        piece.SetPosition(pink[0][0],pink[0][1]);
    }
    else if (name=="p4") {
        piece.SetPosition(blue[0][0],blue[0][1]);
    }

    piece.SetSize(20,20);

    money.SetAmount(10000);

}

Money Player::GetMoneyObject() {
    return money;
}

Piece Player::GetPieceObject() {
    return piece;
}
