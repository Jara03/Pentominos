//
// Created by rania on 23/12/2020.
//

#include "FamillePiece.h"
#include "Piece.h"
/*creer une Famille piece à partir d'une premiere piece en (0,0)*/
//TODO créer chaque sous fonction de famillePiece
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
FamillePiece* createFamillePiece(char c, SDL_Renderer *r){
    FamillePiece* fp = NULL;
    switch(c){
        case 'x':
            fp = pieceEnX(r);
            break;
            /*
        case 'y':
            p = createPiece(0,0,2,r);
            break;
        case 'n':
            p = createPiece(0,0,3,r);
            break;
        case 'i' :
            p = createPiece(0,0,4,r);
            break;
        case 'f' :
            p = createPiece(0,0,5,r);
            break;
             */
        case 'l':
            fp = pieceEnL(r);
                    //createPiece(0,0,6,r);
            break;
            /*
        case 'p':
            p = createPiece(0,0,7,r);
            break;
        case 't':
            p = createPiece(0,0,8,r);
            break;
        case 'u':
            p = createPiece(0,0,9,r);
            break;
         case 'v':
             p = createPiece(0,0,10,r);
            break;
         case 'w':
             p = createPiece(0,0,11,r);
            break;
         case 'z':
             p = createPiece(0,0,12,r);
            break;
        */

        default:
            printf("le caractère est invalide !");
            break;
    }

    return fp;
}
//TODO optimiser le systeme de creation de famille piece avec des tableaux d'int contenant les différentes positions a boucler
int  Xx[] = {10,0,10,20,10};
int  Xy[] = {0,10,10,10,20};
FamillePiece* pieceEnX(SDL_Renderer *r){
    FamillePiece* fp = (FamillePiece*) malloc(sizeof(FamillePiece));
     for(int i=0; i<5;i++){
        fp->membre[i] = createPiece(Xx[i],Xy[i],1,r);
     }
    return fp;
}
int Lx[] = {0,0,0,0,10};
int Ly[] = {0,10,20,30,30};
FamillePiece* pieceEnL(SDL_Renderer *r){
    FamillePiece* fp = (FamillePiece*) malloc(sizeof(FamillePiece));
    for(int i=0; i<5;i++){
        fp->membre[i] = createPiece(Lx[i],Ly[i],6,r);
    }
    return fp;
}

