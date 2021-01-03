//
// Created by rania on 01/01/2021.
//

#ifndef PENTOMINOS_CONSTANTES_H
#define PENTOMINOS_CONSTANTES_H
#include "SDL.h"
const int taillePiece;

int rouge[4];
int bleu[4];
int cyan[4] ;
int blanc[4] ;
int jaune[4] ;
int rose[4] ;
int brun[4] ;
int mauve[4];
int noir[4] ;
int vertC[4];
int vert[4];
int orange[4];
int gris[4];
int ivoire[4];

SDL_Rect rcBravo;
SDL_Rect deplace;
SDL_Rect annuler;
SDL_Rect rotation;
SDL_Rect symetrie;

SDL_Texture *boutonAnnuler;
SDL_Texture *boutonRotation;
SDL_Texture *boutonSymetrie;
SDL_Texture *boutonDeplacer;
SDL_Texture *bravo;


int Lx[5];
int Ly[5];

int Tx[5];
int Ty[5];

int Xx[5];
int Xy[5];

int Ux[5];
int Uy[5];

int Vx[5];
int Vy[5] ;

int Nx[5];
int Ny[5];

int Ix[5];
int Iy[5];

int Px[5];
int Py[5];

int Wx[5];
int Wy[5];

int Fx[5];
int Fy[5];

int Yx[5];
int Yy[5];

int Zx[5];
int Zy[5];

char* annulerPath;
char* deplacerPath;
char* rotationPath;
char* symetriePath;
char* annulerPath;
char* bravoPath;



#endif //PENTOMINOS_CONSTANTES_H
