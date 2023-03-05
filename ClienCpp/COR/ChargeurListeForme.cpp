/**
 * @author LEOST Maelan
*/

#include "ChargeurListeForme.h"


/**
 * \Description    Fonction qui charge et appelle le DP COR en appelant tous les Experts
 * @param      fichier   un fichier texte
 * @return     Un vecteur de Formes contenant toutes les formes du fichier texte ifs
 */
vector<Forme*> ChargeurListeForme::charge(ifstream& fichier) // charge un fichier texte et retourne un vecteur de Formes
{
    vector<Forme*> res; // vecteur de Forme qui contiendra toutes les formes du fichier texte
    ExpertChargementCOR* expert; // expert du DP COR
    expert = new ExpertChargementSegmentCOR(NULL);
    expert = new ExpertChargementPolygoneCOR(expert);
    expert = new ExpertChargementCercleCOR(expert);
    expert = new ExpertChargementFormeComplexeCOR(expert);

    string temp; // string temporaire pour lire le fichier texte
    while (getline(fichier, temp)) // tant qu'il y a des lignes à lire
    {
        //cout << "ligne lue : " << tmp << endl;

        Forme* forme = expert->resoudre(temp);
        if (forme != NULL)// si la forme n'est pas nulle
        {
            res.push_back(forme);// on l'ajoute au vecteur de Forme
        }
    }
    return res;
};