//
// Created by rania on 23/12/2020.
//
#include <stdio.h>
#include "VueHead.h"
#include "SDL2/SDL.h"
SDL_Surface* background = NULL ;

SDL_Surface* load_image(char* filename){

}
void afficherHeadGame(SDL_Texture *t ,SDL_Renderer *r){
    //on met le renderer a jour
 SDL_RenderCopy(r,t,NULL,NULL);
}
