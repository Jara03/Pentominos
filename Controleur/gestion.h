//
// Created by bs on 20/12/2020.
//

#ifndef PENTOMINOS_GESTION_H
#define PENTOMINOS_GESTION_H


#include "../Modele/Map.h"
#include "../Modele/Piece.h"
#include "../Modele/FamillePiece.h"

typedef struct gestionnaire{
    FamillePiece* sacDePiece[12] ;
    map* grilleDeJeu;
} gestionnaire;
void initPiecesSac(SDL_Renderer *r);
int piecePosable();
void poserPiece();
void ajouterPieceMap();
void retirerPieceGestion();

#endif //PENTOMINOS_GESTION_H
