## **Pentominos**

Cette application est un projet pour le module de programmation avancée en C. C'est un petit jeu du style puzzle qui respecte les règles du Pentomino. 
L'application à été produite par Rania Ben Said groupe TP1.

Lien Git : https://github.com/Jara03/Pentominos

## Règles
Le but du jeu est simple : remplir entièrement la zone quadrillée avec toutes les pièces disponibles. Il ne doit pas y avoir de trou ou de pièces dépassant de la zone. 
le Joueur peux translater et transformer chacune des pièces (rotation et symétrie). Néanmoins lorsqu'une pièces est posée, celle-ci n'a plus le droit de bouger ce qui rend ainsi le puzzle très compliqué. 
Pour jouer, cliquer sur une pièce au choix et sélectionnez la avec le bouton *déplacer*. 
Vous pouvez déplacer la pièce à l'aide des touches *gauche*, *droite*, *haut* et *bas* du clavier. Vous pouvez effectuer des *rotations* ainsi que des *symétries* de la pièce à condition que celle ci ne sorte pas du cadre de la zone. Lorsque vous souhaitez poser votre pièce, il vous faudra appuyer une seconde fois sur *déplacer*.
 Si la pièce peux être posée, elle deviendra inamovible sinon, vous resterez en mode déplacement. Si vous souhaitez changer de pièce, appuyez sur *annuler*.

## Structure du projet
Le projet respecte une architecture MVC, c'est-à-dire qu'il comporte un **Contrôleur** (*gestion*) qui va gérer le fonctionnement du jeu et l'interaction avec le joueur(*Événements*), un **Modèle** (*Pièce* et *FamillePiece*) qui gère la modification des structure du jeu et une **Vue** qui se charge simplement de gérer la partie affichage et chargement d'image du jeu. 
Un fichier de ***Constantes*** rend facile la modification des paramètres du jeu et leur stockage. Il permet également de ne pas envahir les autres fichiers et de les garder lisible au maximum.
L'allocation dynamique de mémoire à été systématiquement utilisée et une attention particulière à été portée sur l'optimisation des fuites mémoire grâce a *Valgrind*. 

## Complication
Malheureusement le projet ne possède pas de système de sauvegarde de partie, ce qui aurait été souhaitable au vu de la longueur et de la complexité de celles-ci. 

