cmake_minimum_required(VERSION 3.23)
project(ClientCpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(ClientCpp main.cpp Cercle.cpp Cercle.h Erreur.cpp Erreur.h Forme.cpp Forme.h FormeComplexe.cpp FormeComplexe.h Matrices2x2.cpp Matrices2x2.h Polygone.cpp Polygone.h Segment.cpp Segment.h Vecteur2D.cpp Vecteur2D.h Visiteur/VisiteurDeLibrairie.h Visiteur/Visiteur.h Visiteur/Visiteur.cpp Visiteur/VisiteurDeLibrairie.cpp Communication/InitCommunication.cpp Communication/InitCommunication.h)

