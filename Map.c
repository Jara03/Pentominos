//
// Created by bs on 20/12/2020.
//

#include "Map.h"
#include "SDL2/SDL.h"
#include "Pieces/FamillePiece.h"
SDL_Texture* donneTextureMap(SDL_Renderer *r){
    SDL_Surface* s = SDL_LoadBMP("jsp");
    struct SDL_Texture *t = SDL_CreateTextureFromSurface(r,s);
    return t;
}
void mapInit(map* m, SDL_Renderer *r){
    //on malloc
    m = (map*) malloc(sizeof(map));
    //on utilisera une image pour la déco
    //TODO creer une texture BMP pour Map
     m->deco = (SDL_Texture*) malloc(sizeof(struct SDL_Texture*));
     m->rcMap = (SDL_Rect*) malloc(sizeof(SDL_Rect));
     m->deco = donneTextureMap(r);
     m->rcMap->x = 50 ;
     m->rcMap->y = 200 ;
     m->rcMap->w = 100 ;
     m->rcMap->h = 60 ;


}