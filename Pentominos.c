#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "Pieces/Piece.h"
#include <stdbool.h>
#include "Controleur/gestion.h"
#include "Vues/Vue.h"
#include "Pieces/FamillePiece.h"
#include "Controleur/Evenements.h"



int main(int argc, char* argv[]){
    //on initialise le pointeur de fenetre
    bool run = true;

    //initialisation de la SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
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
       //met a jour les éléments du jeu en fonction des evenements requis
       updatePentomino();
       //affiche les pieces dans le rendue
       afficherElementsJeu();
        //créer une fonction de gestion de rendu dite "flemmarde"
        updateRenderer();
        SDL_Delay(16); //ms pour avoir du 60 fps
      }
    return 0;
}

