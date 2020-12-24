//
// Created by rania on 23/12/2020.
//
/*Cette fonction sert essentiellement a retourner des Textures constantes pour chaque piece
 * on a ici pour l'instant des pieces 1.rouges, 2.bleues, 3.jaunes, 4.vertes, 5.orange, 6.cyan, 7.mauve,
 * 8.blanches, 9.noires, 10.vertes claires, 11.roses et 12.brunes
 * Ce qui constitue 12 pieces au total*/
#include "VueDePiece.h"
#include "SDL2/SDL.h"
int rouge[] = {255,0,0,255};
int bleu[] = {0,0,255,255};
int cyan[] = {0,150,150,255};
//on crée un surface
//on colore la surface avec une const
//texture a partir de surface
SDL_Texture* donneTexturePieceColoree(int CodeCouleur, SDL_Renderer *r){
SDL_Surface *sur = SDL_CreateRGBSurface(0,10,10,32,0,0,0,0);
     switch(CodeCouleur){
         //rouge
         case 1:
           SDL_FillRect(sur,NULL,SDL_MapRGB(sur->format,rouge[0],rouge[1],rouge[2]));
             break;
             //bleu
         case 2:
           SDL_FillRect(sur,NULL,SDL_MapRGB(sur->format,bleu[0],bleu[1],bleu[2]));
             break;
         case 6:
             SDL_FillRect(sur,NULL,SDL_MapRGB(sur->format,cyan[0],cyan[1],cyan[2]));
             break;
         default:
             break;
     }
     //on donne la surface a la texture et on retourne la texture
     SDL_Texture* t = (SDL_Texture*) malloc(sizeof(SDL_Texture*));
     t = SDL_CreateTextureFromSurface(r,sur);
     SDL_FreeSurface(sur);
     return t;
}