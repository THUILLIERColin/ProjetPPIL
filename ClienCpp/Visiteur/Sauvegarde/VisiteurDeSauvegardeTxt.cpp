//
// Created by Colin Thuiller on 04/03/2023.
//

#include "VisiteurDeSauvegardeTxt.h"
#include <iostream>
#include <string>
#include <fstream>

// Si on a le temps ajouter un paramètre pour le nom du fichier
const void *VisiteurDeSauvegardeTxt::visite(const Forme *forme) const {
    char ligne[100];
    ifstream fichier("Sauvegarde/sauvegarde.txt", fstream::app);

    if(fichier)  // si l'ouverture a réussi
    {
        fichier.getline(ligne, 99);  // on met dans "contenu" la ligne
        cout << ligne << endl;  // on l'affiche
        fichier.close();  // on ferme le fichier
    }
    else  // sinon
        cerr << "Impossible d'ouvrir le fichier !" << endl;

    /*
    ofstream file("sauvegarde.txt", fstream::app);
    if (file.is_open()) {
        cout << "Sauvegarde de la forme " << *forme << " dans le fichier de sauvegarde" << endl;
        file << *forme << "\n";
        file.close();
    } else {
        cerr << "Impossible d'ouvrir le fichier de sauvegarde" << endl;
    }*/

    /*
    ofstream file;
    // On charge le fichier de sauvegarde.txt si il existe
    // Sinon on le crée
    file.open("sauvegarde.txt", fstream::app);

    cout << "Sauvegarde de la forme " << *forme << " dans le fichier de sauvegarde" << endl;
    // On envoye la forme dans le fichier
    file << *forme << "\n";
    // On ferme le fichier
    file.close();
    */
    return 0;
}
