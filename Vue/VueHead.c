//
// Created by rania on 23/12/2020.
//
#include <stdio.h>
#include "VueHead.h"
#include "SDL2/SDL.h"
SDL_Texture* creerTextureHeadGame(SDL_Renderer *r){
     SDL_Surface* s = SDL_LoadBMP("/home/rania/CLionProjects/Pentominos/arrierePlan.bmp");
    SDL_Texture* t = (SDL_Texture*) malloc(sizeof(SDL_Texture*));
            t = SDL_CreateTextureFromSurface(r,s);
     SDL_FreeSurface(s);
     return t;
}
void afficherHeadGame(SDL_Renderer *r){
    //on met le renderer a jour
     SDL_Texture* t = creerTextureHeadGame(r);
    SDL_RenderCopy(r,t,NULL,NULL);
}
