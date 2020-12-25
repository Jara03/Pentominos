//
// Created by bs on 20/12/2020.
//

#include "gestion.h"
#include "../Modele/FamillePiece.h"
#include "../Modele/Map.h"
#include "SDL2/SDL.h"

void modeDeplacement(){
//le mode déplacement survient lorsque l'on a séléctionné une piece dans le sac de piece (ce qui est a vérfiier)
//il permet a l'utilisateur de bouger la piece dans la map (ou d'effectuer une rotation ou symétrie) jusqu'a ce qu'il
//trouve une place adéquate pour sa piece. si la piece est dite posable, le bouton poser devient clickable et il est donc
//possible de changer la piece de structure, c'est a dire de la faire passer du sac de piece a la structure map.
//lorsqu'une piece est posée ou annulée, on sort du mode déplacement
}
int piecePosable(){
//on dit qu'une piece est posable si elle n'est pas en collision avec une autre piece
//c'est a dire qu'elle ne possède pas la meme position qu'une autre piece
//pour verifier qu'une famille piece est posable, il faut verifier chacune des pieces et changer le
//bool si une seule des pieces est dite "imposable" mdr
}

void poserPiece(){
//fait changer la piece de structure (sac de piece a map)
}

void ajouterPieceMap(){
//fonction pour poserPiece
}

void retirerPieceGestion(){
//fonction pour poserPiece
}


void afficherSacDePiece(gestionnaire *g, SDL_Renderer *r){
    for(int i = 0; i<12;i++){
        if(g->sacDePiece[i] != NULL){
            afficherFamillePiece(g->sacDePiece[0],r);
        }
    }

}

gestionnaire* initGestionnaire(SDL_Renderer *r){
    //on ajoute les 12 pieces dans le sac de gestion
    gestionnaire *g = (struct gestionnaire*)malloc(sizeof(struct gestionnaire));
    createFamillePiece(g->sacDePiece,r);
     mapInit(g->grilleDeJeu,r);
    //TODO déplacer les pieces sur un carré divisé en 12 a coté de la Map
    int localInitialeX = 515;
    int localInitialeY = 155;
    int i = 0;
        for(int y=0;y<4;y++){
            for(int x=0;x<3;x++){
                deplacerFamillePiece(localInitialeX + (50*x),localInitialeY + (50*y),g->sacDePiece[i]);
                i++;
            }
        }
    return g;
}






