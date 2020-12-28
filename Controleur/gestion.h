//
// Created by bs on 20/12/2020.
//

#ifndef PENTOMINOS_GESTION_H
#define PENTOMINOS_GESTION_H


#include "../Map.h"
#include "../Pieces/Piece.h"
#include "../Pieces/FamillePiece.h"


typedef struct gestionnaire{
    FamillePiece* sacDePiece[12] ;
    map* grilleDeJeu;
} gestionnaire;


typedef enum{
    NONE,
    ROTATE,
    SYM,
    POSER,
    DEPLACER

}Pentomino_Action;

void updatePentomino();
void afficherElementsJeu();
void updateRenderer();
void afficherHeader();
void init_all();
void nettoyage();
gestionnaire* initGestionnaire();
void afficherSacDePiece(gestionnaire* g, SDL_Renderer *r);
int piecePosable();
void poserPiece();
void ajouterPieceMap();
void retirerPieceGestion();
void modeDeplacement();

#endif //PENTOMINOS_GESTION_H
