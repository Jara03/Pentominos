//
// Created by rania on 23/12/2020.
//
/*Cette fonction sert essentiellement a retourner des Textures constantes pour chaque piece
 * on a ici pour l'instant des pieces 1.rouges, 2.bleues, 3.jaunes, 4.vertes, 5.orange, 6.cyan, 7.mauve,
 * 8.blanches, 9.noires, 10.vertes claires, 11.roses et 12.brunes
 * Ce qui constitue 12 pieces au total*/
#include "../include/Vue.h"
#include "SDL2/SDL.h"
#include "../include/gestion.h"
#include "../include/Constantes.h"

SDL_Renderer *renderer;
SDL_Texture* arrierePlan;


//on crée un surface
//on colore la surface avec une const
//texture a partir de surface
SDL_Texture* donneTexturePieceColoree(int CodeCouleur[]){
SDL_Surface *sur = SDL_CreateRGBSurface(0,10,10,32,0,0,0,0);
SDL_FillRect(sur,NULL,SDL_MapRGB(sur->format,CodeCouleur[0],CodeCouleur[1],CodeCouleur[2]));
     //on donne la surface a la texture et on retourne la texture
     SDL_Texture* t;
     t = SDL_CreateTextureFromSurface(renderer,sur);
     SDL_FreeSurface(sur);
     return t;
}

SDL_Texture* creerTextureHeadGame(char* filename){
    SDL_Surface* s = SDL_LoadBMP(filename);
    SDL_Texture* t ;
    t = SDL_CreateTextureFromSurface(renderer,s);
    SDL_FreeSurface(s);
    return t;
}
void initTextureDeJeu(){
    arrierePlan = creerTextureHeadGame("./arrierePlan.bmp");
    boutonAnnuler = creerTextureHeadGame(annulerPath);
    boutonSymetrie = creerTextureHeadGame(rotationPath);
    boutonDeplacer = creerTextureHeadGame(deplacerPath);
    boutonRotation = creerTextureHeadGame(symetriePath);
    bravo = creerTextureHeadGame(bravoPath);
}
void afficherHeadGame(){
    //on met le renderer a jour
    SDL_RenderCopy(renderer,arrierePlan,NULL,NULL);
}

void afficherBravo(){
    SDL_RenderCopy(renderer,bravo,NULL,&rcBravo);
}

void afficherBoutons(){
   SDL_RenderCopy(renderer,boutonDeplacer,NULL,&deplace);
   SDL_RenderCopy(renderer,boutonAnnuler,NULL,&annuler);
   SDL_RenderCopy(renderer,boutonRotation,NULL,&rotation);
   SDL_RenderCopy(renderer,boutonSymetrie,NULL,&symetrie);
}
