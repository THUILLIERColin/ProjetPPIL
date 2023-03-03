cmake_minimum_required(VERSION 3.23)
project(ClientCpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(ClientCpp main.cpp Vecteur2D.cpp Vecteur2D.h Erreur.cpp Erreur.h Cercle.cpp Cercle.h Forme.cpp Forme.h Segment.cpp Segment.h FormeComplexe.cpp FormeComplexe.h Polygone.cpp Polygone.h Constante.h Matrices2x2.cpp Matrices2x2.h Triangle.cpp Triangle.h)
