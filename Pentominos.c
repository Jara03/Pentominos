#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include <stdbool.h>
#include "include/gestion.h"
#include "include/Vue.h"
#include "include/Evenements.h"



int main(int argc, char* argv[]){
    //on initialise le pointeur de fenetre
    bool run = true;

    //initialisation de la SDL
    if(SDL_Init(SDL_INIT_EVENTS) != 0){
        fprintf(stderr, "Erreur dans l'initialisation : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    init_all();

    atexit(nettoyage);

   while(run){
        //prerender
       afficherHeader();
       //gestion des evenements
       evenements();
       //affiche les pieces dans le rendu
       afficherElementsJeu();
       updateRenderer();
        SDL_Delay(64); //ms pour avoir du 15 fps, largement suffisant pour ce type de d'application
      }
    return 0;
}

