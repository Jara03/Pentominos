//
// Created by rania on 23/12/2020.
//

#include <SDL2/SDL.h>
#include "gestion.h"


#ifndef PENTOMINOS_VUEDEPIECE_H
#define PENTOMINOS_VUEDEPIECE_H

SDL_Texture* donneTexturePieceColoree(int CodeCouleur[]);
SDL_Texture* creerTextureHeadGame(char* filename);
void afficherHeadGame();
void afficherBoutons();
void afficherBravo();
void initTextureDeJeu();
#endif //PENTOMINOS_VUEDEPIECE_H
