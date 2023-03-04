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
    /*
    char ligne[100];
    ifstream fichier("../Sauvegarde/sauvegarde.txt", ios::app);
    cout << "Sauvegarde de la forme : " ;

    if(fichier)  // si l'ouverture a réussi
    {
        fichier.getline(ligne, 5);  // on met dans "contenu" la ligne
        cout << ligne << endl;  // on l'affiche
        fichier.close();  // on ferme le fichier
    }
    else  // sinon
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    */


    ofstream file("../Sauvegarde/sauvegarde.txt", fstream::app);
    if (file.is_open()) {
        file << *forme << "\n";
        file.close();
    } else {
        cerr << "Impossible d'ouvrir le fichier de sauvegarde" << endl;
    }
    
    return 0;
}
