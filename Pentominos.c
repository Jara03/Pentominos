#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "Modele/Piece.h"


/*fonction qui lance le jeu : elle initialise les vues */


void testAffichagePiece(SDL_Renderer *r){
    SDL_Texture *text = SDL_CreateTexture(r,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_STATIC,10,10);
    piece p = createPiece(0,0,text);

    SDL_SetRenderTarget(r,text);
}


int main(int argc, char* argv[]){
    //on initialise le pointeur de fenetre
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Color brun = {100,50,40,255};

    //initialisation de la SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        fprintf(stderr, "Erreur dans l'initialisation : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    //apres initialisation on assigne une fenetre au pointeur
    window = SDL_CreateWindow("Pentominos", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,  0);
    //gestion d'erreur sur la fenetre
    if(window == NULL){
        fprintf(stderr,"fenetre non créee : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer,brun.r,brun.g,brun.b,brun.a);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}

