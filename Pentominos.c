#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "Modele/Piece.h"
#include <stdbool.h>
#include "Controleur/gestion.h"
#include "Vue/VueHead.h"
#include "Modele/FamillePiece.h"

/*fonction qui lance le jeu : elle initialise les vues */


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
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    // TODO regler le probleme de renderDrawColor

    //on creer un gestionnaire qui initialise son paquet de piece et affiche l'univers du jeu
    gestionnaire *gest = initGestionnaire(renderer);


    SDL_Event ev;
   while(run){
        SDL_WaitEvent(&ev);
        if(ev.type == SDL_QUIT){
            run = SDL_FALSE ;
        }
       SDL_SetRenderDrawColor(renderer,brun.r,brun.g,brun.b,brun.a);
       SDL_RenderClear(renderer);
       SDL_RenderPresent(renderer);

      }
        SDL_DestroyWindow(window);


    SDL_Quit();
    return EXIT_SUCCESS;
}

