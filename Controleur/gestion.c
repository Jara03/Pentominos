//
// Created by bs on 20/12/2020.
//

#include "gestion.h"
#include "../Modele/FamillePiece.h"
#include "SDL2/SDL.h"

int piecePosable(){

}

void poserPiece(){

}

void ajouterPieceMap(){

}

void retirerPieceGestion(){

}
void createSacDePieceLectureFichier(FILE *f,SDL_Renderer *r){
    int x = 0, y = 0, i = 0, j = 0;
    gestionnaire *g = (struct gestionnaire*) malloc(sizeof(struct gestionnaire));
   // FamillePiece *fp = (FamillePiece*) malloc(sizeof(FamillePiece));
    //verifier ce qui ne va pas avec fopen
    char* ligne;
    size_t longueur;
    ssize_t res = 0;
    while((res = getline(&ligne,&longueur,f)) != -1) {
        if(res == 0){
            i++;
        }else{
            for(x = 0; x<res; x++ ){
                g->sacDePiece[i]->membre[j] = createPiece(x,y,i,r);
            }
        }
        y++;
    }

}
void initPiecesSac(SDL_Renderer *r){
    //on ajoute les 12 pieces dans le sac de gestion
    gestionnaire g;

    g.sacDePiece[0] = createFamillePiece('x',r);

}




