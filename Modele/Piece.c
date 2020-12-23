//
// Created by bs on 20/12/2020.
//

#include "Piece.h"
#include "SDL2/SDL.h"

/*le char donne le symbole de la forme de la piece a creer*/
piece createPiece(int x, int y, SDL_Texture *t){
    SDL_Rect *r = (SDL_Rect*) malloc( sizeof(SDL_Rect));
    r->x = x;
    r->y = y;
    r->h = 10 ;
    r->w = 10 ;

    piece p = {r,t};

    return p;
    //on alloue dynamiquement de la mémoire pour la pièce
    //en fonction du char on créer une pièce avec des # qu'on mettra dans forme
    // on assigne egalement un couleur pour la texture choisie avec une dimension fixée
    //(il faut créer une texture)
}

/*fonction d'affichage de piece*/
void afficherPiece(piece p, SDL_Renderer *r){
//on part du principe que la texture provient d'une constante et que l'on a pas besoin de dessiner dessus
 SDL_RenderCopy(r,p.texture,NULL,p.rectangle);
 SDL_RenderPresent(r);
}
/*deplacement d'une piece*/
void deplacer(piece* p){

}
/*Collision d'une piece
 * permet de verifier si la la case a remplir n'est pas deja occupée*/
void collision(piece p1, piece p2){

}



