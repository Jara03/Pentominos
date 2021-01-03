//
// Created by rania on 25/12/2020.
//

#include "../include/Evenements.h"
#include "SDL2/SDL.h"
#include "../include/gestion.h"
int MODE_DEPLACEMENT;
Pentomino_Action FAMILLEPIECE_ACTION;
int CURSORposX;
int CURSORposY;

void evenements(){
    SDL_Event ev;

    while(SDL_PollEvent(&ev)){
        switch(ev.type){
            case SDL_QUIT:
                nettoyage();
                exit(0);
                break;
            case SDL_KEYDOWN:
                switch(ev.key.keysym.sym){ //Contrôle de pentomino action
                    case SDLK_DOWN :
                        FAMILLEPIECE_ACTION = BAS ;
                        break;
                    case SDLK_UP :
                        FAMILLEPIECE_ACTION = HAUT;
                        break;
                    case SDLK_RIGHT:
                        FAMILLEPIECE_ACTION = DROITE;
                        break;
                    case SDLK_LEFT:
                        FAMILLEPIECE_ACTION = GAUCHE;
                        break;
                }
                exec_FAMILLEPIECEACTION();
            case SDL_MOUSEBUTTONDOWN:
                //on lance le vérificateur de position
                CURSORposX = ev.motion.x;
                CURSORposY = ev.motion.y;
                SDL_Point p = {CURSORposX,CURSORposY};
              if(clickPos(p) == 1){ //verifie le click sur une piece et met la piece en cours a jours en meme temps
                    printf("PIECE\n");
                }else if(clickPos(p) == 2){
                    //printf("DEPLACER\n");
                  if(MODE_DEPLACEMENT == 1){
                      poserPiece();
                  }else{
                      if(is_PieceEnCours()){
                          setBacker();
                          MODE_DEPLACEMENT = 1;
                          pieceOrigine();
                      }
                  }

                }else if(clickPos(p) == 3){
                  //  printf("rotation\n");
                    FAMILLEPIECE_ACTION = ROTATE;
                    exec_FAMILLEPIECEACTION();
                }else if(clickPos(p) == 5){
                    //printf("symetrie\n");
                    FAMILLEPIECE_ACTION = SYM;
                    exec_FAMILLEPIECEACTION();
                }else if(clickPos(p) == 4){
                  printf("ANNULER\n");  //on redéplace la piece en cours à sa position initiale
                  pieceBack();
                  MODE_DEPLACEMENT = 0;
              }
                break;
        }
    }
}
