//
// Created by bs on 20/12/2020.
//

#include "../include/gestion.h"
#include "../include/FamillePiece.h"
#include "SDL2/SDL.h"
#include "../include/Vue.h"
#include "../include/Constantes.h"

SDL_Window *window;
SDL_Renderer *renderer;
gestionnaire *gest;
FamillePiece *pieceEnCours;
int backer[2] = {0,0};
int nbPiecePosee = 0;
Pentomino_Action FAMILLEPIECE_ACTION;
int MODE_DEPLACEMENT;

void init_all(){
    //apres initialisation on assigne une fenetre au pointeur
    window = SDL_CreateWindow("Pentominos", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,800,600,  SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    gest = initGestionnaire();     //on creer un gestionnaire qui initialise son paquet de piece et affiche l'univers du jeu
    pieceEnCours = NULL;
    initTextureDeJeu();
    FAMILLEPIECE_ACTION = NONE;
    MODE_DEPLACEMENT = 0;
}

map* mapInit( SDL_Renderer *r) {
    //on malloc
    map *m = (map*) malloc(sizeof(map));
    m->pieceMortes = (piece**) malloc(60*sizeof(piece*));
    m->pieceVivantes = (FamillePiece**) malloc(12*sizeof(FamillePiece*));
    //on créer 12*5 pieces "mortes" avec des couleurs quadrillées
    int coulQuadr = 0;
    int k= 0;
    SDL_Texture *tgris = donneTexturePieceColoree(gris);
    SDL_Texture *tivoire = donneTexturePieceColoree(ivoire);
    for (int i=0;i<10;i++) {
        for(int j=0;j<6;j++){
            if(coulQuadr == 0){
                m->pieceMortes[k] = createPiece(205 + (i * 10),255 + (j * 10), tgris, r);
            }else{
                m->pieceMortes[k] = createPiece(205 + (i * 10),255 + (j * 10), tivoire, r);
            }
            k++;
            //alternance de couleur
            if(coulQuadr == 0){
                coulQuadr = 1;
            }else{
                coulQuadr = 0;
            }
        }
        if(coulQuadr == 0){
            coulQuadr = 1;
        }else{
            coulQuadr = 0;
        }
    }
    return m;
}

void afficherHeader(){
    afficherHeadGame();
    //on affiche les Boutons
    afficherBoutons();
    afficherMap(gest,renderer);
    if(nbPiecePosee == 12){
        afficherBravo();
    }
}

void afficherElementsJeu(){
    //il faut afficher le sac de piece et la map + ses pieces
    afficherSacDePiece(gest,renderer);
}

void updateRenderer(){
    SDL_RenderPresent(renderer);
}


int clickPos(SDL_Point p){
    int res = 0;
    if(surUnePiece(p)){  //si on est sur FamillePiece
       res = 1;
    }else if(surBoutonDeplacer(p)){
        res = 2;
    }else if(surBoutonAnnuler(p)){
        res = 4;
    }else if(surBoutonRotation(p)){
        res = 3;
    }else if(surBoutonSymetrie(p)){
        res = 5;
    }
    return res;
}
//fonction qui vérifie la collisionFamille avec les SDL_Rect de chaque piece des familles pieces de gestion
int surUnePiece(SDL_Point p){
    //on va loop chaque FamillePiece
    int res = 0;
    for(int i=0;i<12;i++){
        if(gest->sacDePiece[i] != NULL){
            if(dansFamille(gest->sacDePiece[i],&p) == SDL_TRUE){ //fonction de FamillePiece qui vérifie si le point est dans fp
                res = 1;
                //on modifie la piece courante que si il n'y a deja pas de piece courante
                if(pieceEnCours == NULL || MODE_DEPLACEMENT == 0){
                    pieceEnCours = gest->sacDePiece[i];
                }
            }
        }
    }
    return res;
}
int surBoutonSymetrie(SDL_Point p){
    SDL_Rect r = {245,150,100,40};
    return SDL_PointInRect(&p,&r);
}
int surBoutonAnnuler(SDL_Point p){
    SDL_Rect r = {135,150,100,40};
    return SDL_PointInRect(&p,&r);
}
int surBoutonRotation(SDL_Point p){
    SDL_Rect r = {355,150,100,40};
    return SDL_PointInRect(&p,&r);
}
int surBoutonDeplacer(SDL_Point p){
    SDL_Rect r = {25,150,100,50};
    return SDL_PointInRect(&p,&r);
}

void pieceOrigine(){
    int x = -1*(pieceEnCours->membre[0]->rectangle->x)+235;
    int y = -1*(pieceEnCours->membre[0]->rectangle->y)+255;
    deplacerFamillePiece(x,y,pieceEnCours);
}
void exec_FAMILLEPIECEACTION(){
    if(MODE_DEPLACEMENT == 1){
        Pentomino_Action current = FAMILLEPIECE_ACTION;
        switch(current){
            case GAUCHE:
                deplacerFamillePiece(-10,0,pieceEnCours);
                if(!mouvementPossible(pieceEnCours)){
                    deplacerFamillePiece(10,0,pieceEnCours);
                }
                break;
            case DROITE:
                deplacerFamillePiece(10,0,pieceEnCours);
                if(!mouvementPossible(pieceEnCours)){
                    deplacerFamillePiece(-10,0,pieceEnCours);
                }
                break;
            case HAUT:
                deplacerFamillePiece(0,-10,pieceEnCours);
                if(!mouvementPossible(pieceEnCours)){
                    deplacerFamillePiece(0,10,pieceEnCours);
                }
                break;
            case BAS:
                deplacerFamillePiece(0,10,pieceEnCours);
                if(!mouvementPossible(pieceEnCours)){
                    deplacerFamillePiece(0,-10,pieceEnCours);
                }
                break;
            case ROTATE:
                faireRotation(pieceEnCours);
                if(!mouvementPossible(pieceEnCours)){
                    for(int i=0;i<3;i++){
                        faireRotation(pieceEnCours);
                    }
                }
                break;
            case SYM:
                faireSymetrie(pieceEnCours);
                if(!mouvementPossible(pieceEnCours)){
                   faireSymetrie(pieceEnCours);
                }
            default:
                break;
        }
    }
}
void setBacker(){
    backer[0] = pieceEnCours->membre[0]->rectangle->x ;
    backer[1] = pieceEnCours->membre[0]->rectangle->y;
}
void pieceBack(){
    int x = pieceEnCours->membre[0]->rectangle->x;
    int y = pieceEnCours->membre[0]->rectangle->y;
    deplacerFamillePiece(-x+backer[0],-y+backer[1],pieceEnCours);

    //les rotations et symétries restent effectives

}
int is_PieceEnCours(){
    return pieceEnCours != NULL;
}
int poseLicite(){
    int res = 1;
    //va verifier que l'on est pas sur d'autres pieces de la map
    //on parcours toute la map
    for(int i=0;i<nbPiecePosee;i++){
            if(collisionFamille(pieceEnCours,gest->grilleDeJeu->pieceVivantes[i])){
                res = 0;
        }

    }
    return res;
}
void poserPiece(){
    //verifie que la pose est autorisée
    if(poseLicite()) {
//fait changer la piece de structure (sac de piece a map)
//on la met dabord dans la map
        gest->grilleDeJeu->pieceVivantes[nbPiecePosee] = pieceEnCours;
        nbPiecePosee++;
//on retire du sac de piece la piecePosée
        retirerSacDePiece();
//on arrete le modeDeplacement
        pieceEnCours = NULL;
        MODE_DEPLACEMENT = 0;
    }
}

void retirerSacDePiece(){
    //on cherche la famillepiece en cours dans le sac de piece
    // de gest et on la retire avec un free ?
    int i =0;
    int trouve = 0;
    while(!trouve && i<12){
        if(gest->sacDePiece[i] == pieceEnCours){
            gest->sacDePiece[i] = NULL;
            free(gest->sacDePiece[i]);  //on libere la mémoire allouée
            trouve = 1;
        }
        i++;
    }
}
void afficherMap(gestionnaire *g,SDL_Renderer *r){
    for(int i=0;i<60;i++){
        afficherPiece(g->grilleDeJeu->pieceMortes[i],r);
    }
    for(int j=0;j<nbPiecePosee;j++){
        afficherFamillePiece(g->grilleDeJeu->pieceVivantes[j],r);
    }

}
void afficherSacDePiece(gestionnaire *g, SDL_Renderer *r){
    for(int i = 0; i<12;i++){
        if(g->sacDePiece[i] != NULL){
            afficherFamillePiece(g->sacDePiece[i],r);
        }
    }
}

gestionnaire* initGestionnaire(){
    //on ajoute les 12 pieces dans le sac de gestion
    gestionnaire *g = (struct gestionnaire*)malloc(sizeof(struct gestionnaire));
    g->sacDePiece = (FamillePiece**) malloc(12*sizeof(FamillePiece*));
    createFamillePiece(g->sacDePiece,renderer);
    int localInitialeX = 515;
    int localInitialeY = 155;
    int i = 0;
    for(int y=0; y<4;y++){
        for(int x=0;x<3;x++){
            deplacerFamillePiece(localInitialeX + (100*x),localInitialeY + (100*y),g->sacDePiece[i]);
            i++;
        }
    }

    g->grilleDeJeu = mapInit(renderer);
    return g;
}

void destroyGestionnaire(){
    //free la map
}
/*nettoyage de la fenetre au bouton de sortie*/
void nettoyage(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    destroyGestionnaire();
    //sors de la SDL
    SDL_Quit();
}





