//
// Created by bs on 20/12/2020.
//

#ifndef PENTOMINOS_PIECE_H
#define PENTOMINOS_PIECE_H


typedef struct pieces {
    //la forme est une chaine de caractère en deux dimensions
    char** forme;
    //texture venant de la bibliothèque SDL
    SDLTexture texture;

} piece;

void symetrie(piece* p);
void rotation(piece* p);

#endif //PENTOMINOS_PIECE_H
