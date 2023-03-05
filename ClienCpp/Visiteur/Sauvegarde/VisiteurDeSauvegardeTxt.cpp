//
// Created by Colin Thuiller on 04/03/2023.
//

#include "VisiteurDeSauvegardeTxt.h"
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

using namespace std;

// Si on a le temps ajouter un paramètre pour le nom du fichier
const void *VisiteurDeSauvegardeTxt::visite(const Forme *forme) const {

    ofstream file("../Sauvegarde/sauvegarde.txt", fstream::app);
    if (file.is_open()) {
        file << *forme << "\n";
        file.close();
    } else {
        cerr << "Impossible d'ouvrir le fichier de sauvegarde" << endl;
    }

    return 0;
}
