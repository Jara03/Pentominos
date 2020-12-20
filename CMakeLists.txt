cmake_minimum_required(VERSION 3.17)
project(Pentominos C)

set(CMAKE_C_STANDARD 99)

add_executable(Pentominos Pentominos.c Pentominos.h Modele/Map.c Modele/Map.h Modele/Piece.c Modele/Piece.h Controleur/gestion.c Controleur/gestion.h)