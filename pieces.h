#ifndef PIECES_H
#define PIECES_H

#include <SDL.h>
#include <SDL_image.h>

class Piece {
public:
    Piece(SDL_Renderer* renderer);
    ~Piece();

    void SetPosition(int x, int y);
    void SetSize(int width, int height);
    void SetRect();
    SDL_Rect GetRect() const;

    
    
private:
    SDL_Rect PRect;
    int x;
    int y;
    int width;
    int height;
};

#endif
