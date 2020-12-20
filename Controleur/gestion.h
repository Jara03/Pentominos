//
// Created by bs on 20/12/2020.
//

#ifndef PENTOMINOS_GESTION_H
#define PENTOMINOS_GESTION_H


#include "../Modele/Map.h"
#include "../Modele/Piece.h"

typedef struct gestionnaire{
    piece* sacDePiece ;
    map* grilleDeJeu;
} gestionnaire;

int piecePosable();
void poserPiece();
void ajouterPieceMap();
void retirerPieceGestion();

#endif //PENTOMINOS_GESTION_H
