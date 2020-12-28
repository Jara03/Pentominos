//
// Created by bs on 20/12/2020.
//

#ifndef PENTOMINOS_PIECE_H
#define PENTOMINOS_PIECE_H
#include "SDL2/SDL.h"
//une piece est tout simplement un rectangle avec un texture.
//Les Rectangles de SDL possèdent deja des Positions
typedef struct pieces {
    SDL_Rect *rectangle;
    SDL_Texture *texture;

} piece;

piece* createPiece(int x, int y, int codeCouleur, SDL_Renderer *rend);
void deplacer(piece *p, int x, int y);
void collision(piece p1, piece p2);
void afficherPiece(piece *p, SDL_Renderer *r);
#endif //PENTOMINOS_PIECE_H
