//
// Created by rania on 23/12/2020.
//

#ifndef PENTOMINOS_FAMILLEPIECE_H
#define PENTOMINOS_FAMILLEPIECE_H
#include "Piece.h"

typedef struct FamillePiece{
    piece* membre[5];
} FamillePiece;
void deplacerFamillePiece(int x, int y,FamillePiece *fp);
void afficherFamillePiece(FamillePiece *fp, SDL_Renderer *r);
FamillePiece* createFamillePiece(char c,SDL_Renderer *r);
void rotation(FamillePiece *fp);
void symetrie(FamillePiece *fp);

FamillePiece* pieceEnX( SDL_Renderer *r);
/*
FamillePiece* pieceEnY( SDL_Renderer *r);
FamillePiece* pieceEnZ( SDL_Renderer *r);
FamillePiece* pieceEnN( SDL_Renderer *r);
FamillePiece* pieceEnT( SDL_Renderer *r);
FamillePiece* pieceEnV( SDL_Renderer *r);
FamillePiece* pieceEnW( SDL_Renderer *r);
FamillePiece* pieceEnF( SDL_Renderer *r);
FamillePiece* pieceEnU( SDL_Renderer *r);
 */
FamillePiece* pieceEnL( SDL_Renderer *r);
/*
FamillePiece* pieceEnI( SDL_Renderer *r);
FamillePiece* pieceEnP( SDL_Renderer *r);
*/

#endif //PENTOMINOS_FAMILLEPIECE_H
