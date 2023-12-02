#include "player.h"

Player::Player(std::string n) : name(n), position(0), GetOutJailCard({false,false}), InJail(false) {}

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

int Player::GetPlayerPosition() 
{
    return position;
}

void Player::ChangePosition(int x) 
{   
    position=x;

    if (name=="p1") {
        piece.SetPosition(red[position][0],red[position][1]);
    }
    else if (name=="p2") {
        piece.SetPosition(green[position][0],green[position][1]);
    }
    else if (name=="p3") {
        piece.SetPosition(pink[position][0],pink[position][1]);
    }
    else if (name=="p4") {
        piece.SetPosition(blue[position][0],blue[position][1]);
    }
}

void Player::SendJail() 
{
    InJail = true;
    position=10;

    if (name=="p1") {
        piece.SetPosition(285,610);
    }
    else if (name=="p2") {
        piece.SetPosition(320,610);
    }
    else if (name=="p3") {
        piece.SetPosition(285,645);
    }
    else if (name=="p4") {
        piece.SetPosition(320,645);
    }

}

void Player::AddMoney(int m)
{
    money.AddAmount(m);
}

void Player::SubMoney(int m)
{
    money.SubtractAmount(m);
}

void Player::DoCommunityChest(int x) 
{   

    // ChangePosition(x);

    if (x==0)
    {
        ChangePosition(0);
        AddMoney(200);
    }
    else if(x==1) 
    {
        AddMoney(100);
    }
    else if(x==2) 
    {
        SubMoney(100);
    }
    else if(x==3) 
    {
        AddMoney(150);
    }
    else if(x==4) 
    {
        GetOutJailCard[0] = true;
    }
    else if(x==5) 
    {
        SendJail();
    }
    else if(x==6) 
    {   
        AddMoney(300);
        if (name=="p1") {
            player[1].SubMoney(100);
            player[2].SubMoney(100);
            player[3].SubMoney(100);
        }
        else if (name=="p2") {
            player[0].SubMoney(100);
            player[2].SubMoney(100);
            player[3].SubMoney(100);
        }
        else if (name=="p3") {
            player[0].SubMoney(100);
            player[1].SubMoney(100);
            player[3].SubMoney(100);
        }
        else if (name=="p4") {
            player[0].SubMoney(100);
            player[1].SubMoney(100);
            player[2].SubMoney(100);
        }
    }
    else if(x==7) 
    {
        AddMoney(300);
    }
    else if(x==8) 
    {
        SubMoney(200);
    }
    else if(x==9) 
    {
        SubMoney(200);
    }
    else if(x==10) 
    {
        SubMoney(200);
    }
    else if(x==11) 
    {
        AddMoney(150);
    }
    else if(x==12) 
    {
        AddMoney(250);
    }
    else if(x==13) 
    {
        SubMoney(200);
    }
    else if(x==14) 
    {
        AddMoney(200);
    }

}


void Player::DoChance(int x) 
{
    if (x==0)
    {
        ChangePosition(0);
        AddMoney(200);
    }
    else if(x==1) 
    {
        ChangePosition(39);
    }
    else if(x==2) 
    {
        ChangePosition(32);
    }
    else if(x==3) 
    {
        if (position==7) {
            ChangePosition(5);
        }
        else if (position==22) {
            ChangePosition(25);
        }
        else if (position==36) {
            ChangePosition(35);
        }

    }
    else if(x==4) 
    {
        if (position==7) {
            ChangePosition(12);
        }
        else 
        {
            ChangePosition(28);
        }

    }
    else if(x==5) 
    {
        ChangePosition(27);
    }
    else if(x==6) 
    {
        ChangePosition(19);
    }
    else if(x==7) 
    {
        SubMoney(300);
        if (name=="p1") {
            player[1].AddMoney(100);
            player[2].AddMoney(100);
            player[3].AddMoney(100);
        }
        else if (name=="p2") {
            player[0].AddMoney(100);
            player[2].AddMoney(100);
            player[3].AddMoney(100);
        }
        else if (name=="p3") {
            player[0].AddMoney(100);
            player[1].AddMoney(100);
            player[3].AddMoney(100);
        }
        else if (name=="p4") {
            player[0].AddMoney(100);
            player[1].AddMoney(100);
            player[2].AddMoney(100);
        }
        
    }
    else if(x==8) 
    {
        GetOutJailCard[1] = true;
    }
    else if(x==9) 
    {
        if (position==7) {
            ChangePosition(4);
        }
        else if (position==22) {
            ChangePosition(19);
        }
        else if (position==36) {
            ChangePosition(33);
        }

    }
    else if(x==10) 
    {
        SendJail();
    }
    else if(x==11) 
    {
        
    }
    else if(x==12) 
    {
        SubMoney(250);
    }
    else if(x==13) 
    {
        ChangePosition(23);
    }
    else if(x==14) 
    {
        ChangePosition(13);
    }

}
