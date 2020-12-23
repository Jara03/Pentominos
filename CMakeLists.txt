cmake_minimum_required(VERSION 3.17)
project(Pentominos C)

set(CMAKE_C_STANDARD 99)


find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(Pentominos Pentominos.c Pentominos.h Modele/Map.c Modele/Map.h Modele/Piece.c Modele/Piece.h Controleur/gestion.c Controleur/gestion.h Vue/VueDePiece.c Vue/VueDePiece.h)


target_link_libraries(Pentominos ${SDL2_LIBRARIES})