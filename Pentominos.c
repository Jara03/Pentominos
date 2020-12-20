#include <stdio.h>


/*fonction qui lance le jeu : elle initialise les vues */

void init(){

}
void launch(){
    printf("Bienvenue dans Pentominos ! Quelle dimension de carte souhaitez vous ?");
    //scanner la réponse
    int longueur, largeur;
    init(longueur,largeur);
}

int main(){
    launch();
}

