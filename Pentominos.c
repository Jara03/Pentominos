#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "Modele/Piece.h"
#include <stdbool.h>
#include "Controleur/gestion.h"
#include "Vue/VueHead.h"
#include "Modele/FamillePiece.h"

/*nettoyage de la fenetre au bouton de sortie*/
void nettoyage(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    //sors de la SDL
    SDL_Quit();
}

int main(int argc, char* argv[]){
    //on initialise le pointeur de fenetre
    bool run = true;
    window = NULL;
    renderer = NULL;
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

    atexit(nettoyage);

   while(run){
        //prerender
       afficherHeadGame(renderer);
        //afficherSacDePiece(gest,renderer);
        //créer une fonction de gestion de rendu dite "flemmarde"
       SDL_RenderPresent(renderer);
        SDL_Delay(16); //ms pour avoir du 60 fps
      }
    return 0;
}

