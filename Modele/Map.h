//
// Created by bs on 20/12/2020.
//

#ifndef PENTOMINOS_MAP_H
#define PENTOMINOS_MAP_H

#include "Piece.h"

typedef struct map{
    piece* tabPiece ;
    char** grille;
    SDLTexture texture;
} map;
#endif //PENTOMINOS_MAP_H

/*fonction permettant de créer une map*/
map createMap(){
    //on initialise la structure
    //on créer une liste de piece avec une fonction annexe
    //on assigne la texture a la SDL
}

/*fonction indiquant a la vue comment afficher (dans quel ordre etc) les différents éléments de la map*/
void afficherMap(){
    //on affiche la map
    //on affiche les pièces par dessus a leur positions réspectives
}