//
// Created by rania on 23/12/2020.
//

#include "FamillePiece.h"
#include "Piece.h"


int Lx[] = {0,0,0,0,10};
int Ly[] = {0,10,20,30,30};

int Tx[] = {0,10,20,10,10};
int Ty[] = {0,0,0,10,20};

int Xx[] = {10,0,10,20,10};
int Xy[] = {0,10,10,10,20};

int Ux[] = {0,20,0,10,20};
int Uy[] = {0,0,10,10,10};

int Vx[] = {0,0,0,10,20};
int Vy[] = {0,10,20,20,20};

int Nx[] = {10,10,0,10,0};
int Ny[] = {0,10,20,20,30};

int Ix[] = {0,0,0,0,0};
int Iy[] = {0,10,20,30,40};

int Px[] = {0,10,0,10,0};
int Py[] = {0,0,10,10,20};

int Wx[] = {20,10,20,0,10};
int Wy[] = {0,10,10,20,20};

int Fx[] = {10,20,0,10,10};
int Fy[] = {0,0,10,10,10};

int Yx[] = {0,0,10,0,0};
int Yy[] = {0,10,10,20,30};

int Zx[] = {10,20,10,0,10};
int Zy[] = {0,0,10,0,10};

/*creer une Famille piece à partir d'une premiere piece en (0,0)*/
//TODO méthode de déplacement et de rotation + symétrie

void afficherFamillePiece(FamillePiece *fp, SDL_Renderer *r){
    for(int i= 0; i<5; i++){
        afficherPiece(fp->membre[i],r);
    }
    SDL_RenderPresent(r);
}
/*On deplace et on met a jour*/

//TODO on peux toujours mettre en place un systeme de déplacement "conditionnel"
//les déplacements ne se font qu'en unité de 10 et la map commencera a l'indice 100,100 pour plus de simplicité
void deplacerFamillePiece(int x, int y, FamillePiece *fp){
    for(int i = 0; i<5; i++){
        deplacer(fp->membre[i],x,y);
    }
}
FamillePiece* pieceEnLettre(SDL_Renderer *r,int tabx[], int taby[],int CodeCouleur ){
    FamillePiece* fp = (FamillePiece*) malloc(sizeof(FamillePiece));
    for(int i=0; i<5;i++){
        fp->membre[i] = createPiece(tabx[i],taby[i],CodeCouleur,r);
    }
    return fp;
}
void createFamillePiece(FamillePiece* familleBase[],SDL_Renderer *r){
    familleBase[0] = pieceEnLettre(r,Lx,Ly,1);
    familleBase[1] = pieceEnLettre(r,Xx,Xy,2);
    familleBase[2] = pieceEnLettre(r,Tx,Ty,3);
    familleBase[3] = pieceEnLettre(r,Ux,Uy,4);
    familleBase[4] = pieceEnLettre(r,Vx,Vy,5);
    familleBase[5] = pieceEnLettre(r,Nx,Ny,6);
    familleBase[6] = pieceEnLettre(r,Ix,Iy,7);
    familleBase[7] = pieceEnLettre(r,Px,Py,8);
    familleBase[8] = pieceEnLettre(r,Zx,Zy,9);
    familleBase[9] = pieceEnLettre(r,Fx,Fy,10);
    familleBase[10] = pieceEnLettre(r,Wx,Wy,11);
    familleBase[11] = pieceEnLettre(r,Yx,Yy,12);
}



