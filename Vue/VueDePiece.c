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
int blanc[] = {255,255,255,255};
int jaune[] = {0,255,255,255};
int rose[] = {253,108,158,255};
int brun[] = {91,60,17,255};
int mauve[] = {161,113,117,255};
int noir[] = {0,0,0,255};
int vertC[] = {52,201,36,255};
int vert[] = {9,82,40,255};
int orange[] = {255,131,0,255};
int gris[] = {127,127,127,255};


//on crée un surface
//on colore la surface avec une const
//texture a partir de surface
SDL_Texture* donneTexturePieceColoree(int CodeCouleur, SDL_Renderer *r){
SDL_Surface *sur = SDL_CreateRGBSurface(0,10,10,32,0,0,0,0);
     switch(CodeCouleur){

         case 1:
           SDL_FillRect(sur,NULL,SDL_MapRGB(sur->format,rouge[0],rouge[1],rouge[2]));
             break;
         case 3:
             SDL_FillRect(sur,NULL,SDL_MapRGB(sur->format,jaune[0],jaune[1],jaune[2]));
             break;
         case 2:
           SDL_FillRect(sur,NULL,SDL_MapRGB(sur->format,bleu[0],bleu[1],bleu[2]));
             break;
         case 4:
             SDL_FillRect(sur,NULL,SDL_MapRGB(sur->format,vert[0],vert[1],vert[2]));
             break;
         case 5:
             SDL_FillRect(sur,NULL,SDL_MapRGB(sur->format,orange[0],orange[1],orange[2]));
             break;
         case 6:
             SDL_FillRect(sur,NULL,SDL_MapRGB(sur->format,cyan[0],cyan[1],cyan[2]));
             break;
         case 7:
             SDL_FillRect(sur,NULL,SDL_MapRGB(sur->format,mauve[0],mauve[1],mauve[2]));
             break;
         case 8:
             SDL_FillRect(sur,NULL,SDL_MapRGB(sur->format,blanc[0],blanc[1],blanc[2]));
             break;
         case 9:
             SDL_FillRect(sur,NULL,SDL_MapRGB(sur->format,noir[0],noir[1],noir[2]));
             break;
         case 10:
             SDL_FillRect(sur,NULL,SDL_MapRGB(sur->format,vertC[0],vertC[1],vertC[2]));
             break;
         case 11:
             SDL_FillRect(sur,NULL,SDL_MapRGB(sur->format,rose[0],rose[1],rose[2]));
             break;
         case 12:
             SDL_FillRect(sur,NULL,SDL_MapRGB(sur->format,brun[0],brun[1],brun[2]));
             break;
         default:
             SDL_FillRect(sur,NULL,SDL_MapRGB(sur->format,gris[0],gris[1],gris[2]));
             break;
     }
     //on donne la surface a la texture et on retourne la texture
     SDL_Texture* t = (SDL_Texture*) malloc(sizeof(SDL_Texture*));
     t = SDL_CreateTextureFromSurface(r,sur);
     SDL_FreeSurface(sur);
     return t;
}