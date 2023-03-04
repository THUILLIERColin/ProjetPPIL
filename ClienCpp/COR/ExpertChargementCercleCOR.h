/**
 * @author LEOST Maelan
*/

#pragma once

#include <vector>
#include "ExpertChargementCOR.h"
#include "../Formes/Forme.h"
#include "../Formes/Cercle.h"

using namespace std;
/**
 * \Description      Classe ExpertChargementCercleCOR
 * \details    Cette classe permet de créer un expert chargement de cercle.
 */
class ExpertChargementCercleCOR : public ExpertChargementCOR
{
public:
    ExpertChargementCercleCOR(ExpertChargementCOR *expertSuivant) : ExpertChargementCOR(expertSuivant) {}

    /**
     * \Description      Méthode du Design Pattern Chain of Responsibility
     * \details    Cette méthode resoudre1() permet de céterminer la forme lue en le passant à l'expert adéquat grâce au Design Pattern Chain of Responsibility.
     * @param      *ligne le problème à résoudre, ici une ligne lue depuis le fichier de sauvegarde réprésentant une forme
     * @return    la forme lue
     */
    Forme *resoudre1(const string &ligne) const
    {
        const string cherche = "Cercle";
        string::size_type pos = ligne.find(cherche);
        while (pos != string::npos) // tant que "cercle" est trouvé
        {
            // "Cercle" trouvé
            vector<double> points;

            // on extrait tout ce qui se trouve entre les parenthèses
            unsigned firstParenthesis = ligne.find("[");
            unsigned lastParenthesis = ligne.find("]");
            string coordonnees = ligne.substr (firstParenthesis + 1, lastParenthesis - firstParenthesis - 1);
            istringstream is(coordonnees );

            // on enlève toutes les virgules et on stocke les nombres dans un vecteur
            string t;
            while ( getline( is, t, ',' ) ) points.push_back(stod(t));

            // récupération de la couleur qui est un int en hexadecimal dans la ligne note #FF0000
            int couleur;
            //couleur est stocké dans la ligne sous la forme FF0000 ( en string) il faut donc la passé en string
            istringstream iss(ligne.substr(lastParenthesis + 1, ligne.size()));// on crée un flux de lecture à partir de la chaine de caractère ligne
            iss >> hex >> couleur; // on lit le flux iss et on stocke la valeur dans la variable couleur

            // création de la forme en des données du fichier de visite
            return new Cercle (points[0], points[1], points[2], couleur);
        }
        return NULL;
    };
};


