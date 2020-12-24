#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "Modele/Piece.h"
#include <stdbool.h>
#include "Modele/FamillePiece.h"

/*fonction qui lance le jeu : elle initialise les vues */


void testAffichagePiece(SDL_Renderer *r){

    //la piece est créee
    //création de piece OPE
    piece *p = createPiece(20, 20, 1, r);
    //deplacement de piece OPE
    deplacer(p,150,150);
    //Affichage de piece OPE

    afficherPiece(p,r);


    //On veux afficher une famille piece maintenant

    FamillePiece *fp = createFamillePiece('x',r);
    FamillePiece *fp1 = createFamillePiece('l',r);
    deplacerFamillePiece(100,100,fp);
    deplacerFamillePiece(-50,0,fp);
    afficherFamillePiece(fp,r);
    afficherFamillePiece(fp1,r);

}


int main(int argc, char* argv[]){
    //on initialise le pointeur de fenetre
    bool run = true;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Color brun = {100,50,40,255};

    //initialisation de la SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        fprintf(stderr, "Erreur dans l'initialisation : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    //apres initialisation on assigne une fenetre au pointeur
    window = SDL_CreateWindow("Pentominos", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,800,600,  SDL_WINDOW_OPENGL);
    //gestion d'erreur sur la fenetre
    if(window == NULL){
        fprintf(stderr,"fenetre non créee : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);


    SDL_Event ev;
    while(run){
        SDL_WaitEvent(&ev);
        if(ev.type == SDL_QUIT){
            run = SDL_FALSE ;
        }
        //effectuer les action de jeu ici
        SDL_SetRenderDrawColor(renderer,brun.r,brun.g,brun.b,brun.a);
        SDL_RenderClear(renderer);
        testAffichagePiece(renderer);
        SDL_Delay(20);
    }
        SDL_DestroyWindow(window);


    SDL_Quit();
    return EXIT_SUCCESS;
}

