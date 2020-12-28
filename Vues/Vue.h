//
// Created by rania on 23/12/2020.
//

#include <SDL2/SDL.h>

#ifndef PENTOMINOS_VUEDEPIECE_H
#define PENTOMINOS_VUEDEPIECE_H

SDL_Texture* donneTexturePieceColoree(int CodeCouleur, SDL_Renderer *r );
SDL_Texture* creerTextureHeadGame(SDL_Renderer *r);
void afficherHeadGame(SDL_Renderer *r);

#endif //PENTOMINOS_VUEDEPIECE_H
