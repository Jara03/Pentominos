//
// Created by rania on 01/01/2021.
//

#include "../include/Constantes.h"

const int taillePiece = 10;
//Constantes de couleurs
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
int ivoire[] ={218,192,167};

//rectangles pour placement des boutons
SDL_Rect rcBravo = {300,400,200,150};
SDL_Rect deplace = {25,150,100,40};
SDL_Rect annuler = {135,150,100,40};
SDL_Rect rotation = {245,150,100,40};
SDL_Rect symetrie = {355,150,100,40};

//Textures des boutons
SDL_Texture *boutonAnnuler;
SDL_Texture *boutonRotation;
SDL_Texture *boutonSymetrie;
SDL_Texture *boutonDeplacer;
SDL_Texture *bravo;


//chemin des .bmp 
char* annulerPath = "./Boutons/ANULLERBouton.bmp";
char* deplacerPath = "./Boutons/deplacerBouton.bmp";
char* rotationPath = "./Boutons/rotationBouton.bmp";
char* symetriePath = "./Boutons/symetrieBouton.bmp";

char* bravoPath = "./bravoPic.bmp";


//Coordonnées a fournir a FamillePiece pour créer une pièce de  membres
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




