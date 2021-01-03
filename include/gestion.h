//
// Created by bs on 20/12/2020.
//

#ifndef PENTOMINOS_GESTION_H
#define PENTOMINOS_GESTION_H


#include "Piece.h"
#include "FamillePiece.h"

typedef struct map{
    piece** pieceMortes;//toutes les pieces du quadrillage
    FamillePiece **pieceVivantes;
} map;

typedef struct gestionnaire{
    FamillePiece** sacDePiece ;
    map* grilleDeJeu;
} gestionnaire;

typedef enum {
    NONE,
    DROITE,
    GAUCHE,
    HAUT,
    BAS,
    ROTATE,
    SYM,

}Pentomino_Action;

map* mapInit(SDL_Renderer *r);
void exec_FAMILLEPIECEACTION();
void setBacker();
void pieceBack();
int poseLicite();
void retirerSacDePiece();
void afficherMap(gestionnaire *g,SDL_Renderer *r);
void pieceOrigine();
int surBoutonSymetrie(SDL_Point p);
int surBoutonAnnuler(SDL_Point p);
int surBoutonRotation(SDL_Point p);
int clickPos(SDL_Point p);
int surBoutonDeplacer(SDL_Point p);
int is_PieceEnCours();
int surUnePiece(SDL_Point p);
void afficherElementsJeu();
void updateRenderer();
void afficherHeader();
void init_all();
void nettoyage();
gestionnaire* initGestionnaire();
void afficherSacDePiece(gestionnaire* g, SDL_Renderer *r);
void poserPiece();

#endif //PENTOMINOS_GESTION_H
