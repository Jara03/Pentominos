//
// Created by bs on 20/12/2020.
//

#ifndef PENTOMINOS_GESTION_H
#define PENTOMINOS_GESTION_H


#include "../Modele/Map.h"
#include "../Modele/Piece.h"
#include "../Modele/FamillePiece.h"

extern SDL_Window *window;
extern SDL_Renderer *renderer;

typedef struct gestionnaire{
    FamillePiece* sacDePiece[12] ;
    map* grilleDeJeu;
} gestionnaire;

gestionnaire* initGestionnaire(SDL_Renderer *r);
void afficherSacDePiece(gestionnaire* g, SDL_Renderer *r);
int piecePosable();
void poserPiece();
void ajouterPieceMap();
void retirerPieceGestion();
void modeDeplacement();

#endif //PENTOMINOS_GESTION_H
