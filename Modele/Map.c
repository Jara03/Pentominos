//
// Created by bs on 20/12/2020.
//

#include "Map.h"
#include "SDL2/SDL.h"
#include "FamillePiece.h"

map* createMap(){
    //revoir le fonctionnement de malloc avec les tableaux
    FamillePiece *fp = (FamillePiece*) malloc(12 * sizeof(FamillePiece));
    //on utilisera une image pour la déco
     SDL_Texture* d = NULL;

     map *m;
     m->piecesPosee[0] = fp;
     m->deco = d;
}