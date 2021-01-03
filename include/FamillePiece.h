//
// Created by rania on 23/12/2020.
//

#ifndef PENTOMINOS_FAMILLEPIECE_H
#define PENTOMINOS_FAMILLEPIECE_H
#include "Piece.h"

typedef struct FamillePiece{
    piece** membre;
} FamillePiece;

int collisionFamille(FamillePiece *fp1, FamillePiece *fp2);
int mouvementPossible(FamillePiece *fp);
void faireRotation(FamillePiece *fp);
void faireSymetrie(FamillePiece *fp);
int dansFamille(FamillePiece *fp, SDL_Point *p);
void deplacerFamillePiece(int x, int y,FamillePiece *fp);
void afficherFamillePiece(FamillePiece *fp, SDL_Renderer *r);
void createFamillePiece(FamillePiece* FamilleBase[],SDL_Renderer *r);

FamillePiece* pieceEnLettre( SDL_Renderer *r, int tabx[], int taby[],int CodeCouleur[]);


#endif //PENTOMINOS_FAMILLEPIECE_H
