//
// Created by bs on 20/12/2020.
//

#include "../include/Piece.h"
#include "SDL2/SDL.h"
#include "../include/Vue.h"
#include "../include/Constantes.h"

/*le char donne le symbole de la forme de la piece a creer*/
//on alloue dynamiquement de la mémoire pour la pièce
//en fonction du char on créer une pièce avec des # qu'on mettra dans forme
// on assigne egalement un couleur pour la texture choisie avec une dimension fixée
//(il faut créer une texture)
piece* createPiece(int x, int y, SDL_Texture *text, SDL_Renderer *rend){
    SDL_Texture *t = NULL;
    SDL_Rect *r = (SDL_Rect*) malloc(sizeof(SDL_Rect));
    r->x = x;
    r->y = y;
    r->h = taillePiece ;
    r->w = taillePiece ;
    t =  text;
    piece* p = (piece*) malloc(sizeof(struct pieces));
    p->rectangle = r;
    p->texture = t;

    return p;

}

/*fonction d'affichage de piece*/
//on part du principe que la texture provient d'une constante et que l'on a pas besoin de dessiner dessus
void afficherPiece(piece *p, SDL_Renderer *r){
 SDL_RenderCopy(r,p->texture,NULL,p->rectangle);
}
/*deplacement d'une piece en incrémentant ou décrémentant*/
void deplacer(piece* p, int x, int y){
    p->rectangle->x += x ;
    p->rectangle->y += y ;
}
/*Collision d'une piece
 * permet de verifier si la la case a remplir n'est pas deja occupée*/
int collision(piece *p1, piece *p2){
    int res = 0;
    SDL_Point p = {p1->rectangle->x,p1->rectangle->y};
    if(SDL_PointInRect(&p,p2->rectangle)){
        res = 1;
    }
    return res;
}
/*liberation de la memoire allouée pour une piece*/
void free_piece(piece *p){
    free(p);
}



