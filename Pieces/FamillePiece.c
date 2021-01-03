//
// Created by rania on 23/12/2020.
//

#include "../include/FamillePiece.h"
#include "../include/Piece.h"
#include "../include/Constantes.h"
#include "../include/Vue.h"


//on dit qu'une piece est posable si elle n'est pas en collisionFamille avec une autre piece
//c'est a dire qu'elle ne possède pas la meme position qu'une autre piece
//pour verifier qu'une famille piece est posable, il faut verifier chacune des pieces et changer le
//bool si une seule des pieces est dite "imposable" mdr
int collisionFamille(FamillePiece *fp1, FamillePiece *fp2) {
    int res =0;
    for(int i=0;i<5;i++){ //on parcours chaque piece de fp2
        for(int j=0;j<5;j++){ //on parcours chaque piece de fp1
                if(collision(fp1->membre[j],fp2->membre[i])){
                    res = 1;
            }
        }
    }
    return res;
}
int dansFamille(FamillePiece *fp, SDL_Point *p){
    //on parcours chaque piece de la famillepiece
    int res = 0;
    for(int i=0;i<5;i++){
        if(SDL_PointInRect(p,fp->membre[i]->rectangle) == SDL_TRUE){
            res = 1;
        }
    }
    return res;
}

/*creer une Famille piece à partir d'une premiere piece en (0,0)*/
void faireRotation(FamillePiece *fp){
    //on récupere les coordonées du point pivot
    int pivotX = fp->membre[0]->rectangle->x;
    int pivotY = fp->membre[0]->rectangle->y ;
    int tmp;
    for(int i=1;i<5;i++){
        //on retranche le point pivot (premier point de famille piece)
        fp->membre[i]->rectangle->x -= pivotX;
        fp->membre[i]->rectangle->y -= pivotY;
        //on effectue la rotation
       tmp =  fp->membre[i]->rectangle->x ;
       fp->membre[i]->rectangle->x = -1*fp->membre[i]->rectangle->y;
       fp->membre[i]->rectangle->y = tmp;
       //on réajoute le point pivot
       fp->membre[i]->rectangle->x += pivotX;
       fp->membre[i]->rectangle->y += pivotY ;
    }
}

void faireSymetrie(FamillePiece *fp){
    //on récupere les coordonées du point pivot
    int pivotX = fp->membre[0]->rectangle->x;
    int dist = 0;
    for(int i=1;i<5;i++){
        dist = fp->membre[i]->rectangle->x - pivotX;
        fp->membre[i]->rectangle->x -= 2*dist;
    }
}
void afficherFamillePiece(FamillePiece *fp, SDL_Renderer *r){
    for(int i= 0; i<5; i++){
        afficherPiece(fp->membre[i],r);  //on ajoute un texture unique qu'on ne modifie que si la famille piece
        //a été changée, on vérifie ca grace a un booleen global
    }
}
/*On deplace et on met a jour*/

//les déplacements ne se font qu'en unité de 10 et la map commencera a l'indice 100,100 pour plus de simplicité
void deplacerFamillePiece(int x, int y, FamillePiece *fp){
    for(int i = 0; i<5; i++){
        deplacer(fp->membre[i],x,y);
    }

}
int mouvementPossible(FamillePiece *fp){
    int deplacementIllegal = 1;
    for(int i=0;i<5;i++){
        if(fp->membre[i]->rectangle->x < 205 || fp->membre[i]->rectangle->x >= 205+100 ){
            deplacementIllegal = 0;
        }
        if(fp->membre[i]->rectangle->y < 255 || fp->membre[i]->rectangle->y >= 255+60){
            deplacementIllegal = 0;
        }
    }

    return deplacementIllegal;
/*
    if(deplacementIllegal == 1 ){
        deplacerFamillePiece(-x,-y,fp);
    }
*/
}
FamillePiece* pieceEnLettre(SDL_Renderer *r,int tabx[], int taby[],int CodeCouleur[] ){
    FamillePiece* fp = (FamillePiece*) malloc(sizeof(FamillePiece));
    fp->membre = (piece**) malloc(5*sizeof(piece*));
    SDL_Texture *t = donneTexturePieceColoree(CodeCouleur);
    for(int i=0; i<5;i++){
        fp->membre[i] = createPiece(tabx[i],taby[i],t,r);
    }
    return fp;
}
void createFamillePiece(FamillePiece* familleBase[],SDL_Renderer *r){
    familleBase[0] = pieceEnLettre(r,Lx,Ly,rouge);
    familleBase[1] = pieceEnLettre(r,Xx,Xy,jaune);
    familleBase[2] = pieceEnLettre(r,Tx,Ty,bleu);
    familleBase[3] = pieceEnLettre(r,Ux,Uy,vert);
    familleBase[4] = pieceEnLettre(r,Vx,Vy,orange);
    familleBase[5] = pieceEnLettre(r,Nx,Ny,cyan);
    familleBase[6] = pieceEnLettre(r,Ix,Iy,mauve);
    familleBase[7] = pieceEnLettre(r,Px,Py,blanc);
    familleBase[8] = pieceEnLettre(r,Zx,Zy,noir);
    familleBase[9] = pieceEnLettre(r,Fx,Fy,vertC);
    familleBase[10] = pieceEnLettre(r,Wx,Wy,rose);
    familleBase[11] = pieceEnLettre(r,Yx,Yy,brun);
}



