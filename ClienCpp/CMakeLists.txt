cmake_minimum_required(VERSION 3.23)
project(ClientCpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(ClientCpp main.cpp Formes/Cercle.cpp Formes/Cercle.h Erreur/Erreur.cpp Erreur/Erreur.h Formes/Forme.cpp Formes/Forme.h Formes/FormeComplexe.cpp Formes/FormeComplexe.h Formes/Matrices2x2.cpp Formes/Matrices2x2.h Formes/Polygone.cpp Formes/Polygone.h Formes/Segment.cpp Formes/Segment.h Formes/Vecteur2D.cpp Formes/Vecteur2D.h Visiteur/VisiteurDeLibrairie.h Visiteur/Visiteur.h Visiteur/Visiteur.cpp Visiteur/VisiteurDeLibrairie.cpp Communication/InitCommunication.cpp Communication/InitCommunication.h COR/ExpertChargement.cpp COR/ExpertChargement.h COR/ExpertChargementCOR.cpp COR/ExpertChargementCOR.h Visiteur/VisiteurDeSauvegardeTxt.cpp Visiteur/VisiteurDeSauvegardeTxt.h)

