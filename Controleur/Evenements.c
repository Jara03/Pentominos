//
// Created by rania on 25/12/2020.
//

#include "Evenements.h"
#include "SDL2/SDL.h"
#include "gestion.h"

Pentomino_Action FAMILLEPIECE_ACTION;
void evenements(){
    SDL_Event ev;

    while(SDL_PollEvent(&ev)){
        switch(ev.type){
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN: //dans le cas ou le bouton de la souris est pressé
            //on vérifie que ca soit le bouton gauche
                break;
        }
    }
}
