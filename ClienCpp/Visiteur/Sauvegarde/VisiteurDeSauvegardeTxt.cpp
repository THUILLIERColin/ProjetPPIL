//
// Created by Colin Thuiller on 04/03/2023.
//

#include "VisiteurDeSauvegardeTxt.h"
#include <iostream>
#include <string>
#include <fstream>

const void *VisiteurDeSauvegardeTxt::visite(const Forme *forme) const {
    ofstream file;
    // On charge le fichier de sauvegarde.txt
    file.open("../Sauvegarde/sauvegarde.txt", fstream::app);
    // On envoye la forme dans le fichier
    file << forme << "\n";
    // On ferme le fichier
    file.close();

    return 0;
}
