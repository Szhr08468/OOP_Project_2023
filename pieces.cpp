#include "pieces.h"
#include <cstdio>

Piece::Piece(SDL_Renderer* renderer)
    : x(0), y(0), width(0), height(0), PRect({0,0,0,0}) {
    
}

Piece::~Piece() {}


void Piece::SetPosition(int x, int y) {
    this->x = x;
    this->y = y;
    SetRect();
}

void Piece::SetSize(int width, int height) {
    this->width = width;
    this->height = height;
    SetRect();

}

void Piece::SetRect(){
    PRect = {this->x,this->y,this->width,this->height};
}
void Piece::MoveRectx(int deltaX) {
    this->x -= deltaX;
    SetRect();
}
void Piece::MoveRecty(int deltay) {
    this->y -= deltay;
    SetRect();
}

SDL_Rect Piece::GetRect() const {
    return PRect;
}





