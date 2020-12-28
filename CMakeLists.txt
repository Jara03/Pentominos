cmake_minimum_required(VERSION 3.17)
project(Pentominos C)

set(CMAKE_C_STANDARD 99)


find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(Pentominos Pentominos.c Pentominos.h Map.c Map.h Pieces/Piece.c Pieces/Piece.h Controleur/gestion.c Controleur/gestion.h Vues/Vue.c Vues/Vue.h Pieces/FamillePiece.c Pieces/FamillePiece.h Controleur/Evenements.c Controleur/Evenements.h)


target_link_libraries(Pentominos ${SDL2_LIBRARIES})