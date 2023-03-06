/**
 * @author LEOST Maelan
*/

#include "ExpertChargementCercleCOR.h"


/**
 * @brief      Constructeur de la classe ExpertChargementCercleCOR
 * \details    Ce constructeur permet de créer un expert chargement de cercle.
 * \param      *expertSuivant l'expert chargement suivant dans la chaîne
 */
ExpertChargementCercleCOR::ExpertChargementCercleCOR(ExpertChargementCOR *expertSuivant) : ExpertChargementCOR(expertSuivant) {}


/**
 * @brief      Méthode du Design Pattern Chain of Responsibility
 * \details    Cette méthode resoudre1() permet de céterminer la forme lue en le passant à l'expert adéquat grâce au Design Pattern Chain of Responsibility.
 * @param      *ligne le problème à résoudre, ici une ligne lue depuis le fichier de sauvegarde réprésentant une forme
 * @return    la forme lue
 */
Forme *ExpertChargementCercleCOR::resoudre1(const string &ligne) const
{
    const string cherche = "Cercle";
    string::size_type pos = ligne.find(cherche);
    while (pos != string::npos) // tant que "cercle" est trouvé
    {
        // "Cercle" trouvé
        vector<double> points;

        // on extrait tout ce qui se trouve entre les parenthèses
        unsigned crochetDuDebut = ligne.find("[");// on cherche la première parenthèse
        unsigned crochetDeLaFin = ligne.find("]");// on cherche la dernière parenthèse
        string coordonnees = ligne.substr (crochetDuDebut + 1, crochetDeLaFin - crochetDuDebut - 1);
        istringstream is(coordonnees );// on crée un flux de lecture à partir de la chaine de caractère coordonnees

        // on enlève toutes les virgules et on stocke les nombres dans un vecteur
        string valeurLues;
        while ( getline( is, valeurLues, ',' ) ) points.push_back(stod(valeurLues));

        // récupération de la couleur qui est un int en hexadecimal dans la ligne note #FF0000
        int couleur;
        //couleur est stocké dans la ligne sous la forme FF0000 ( en string) il faut donc la passé en string
        istringstream iss(ligne.substr(crochetDeLaFin + 1, ligne.size()));// on crée un flux de lecture à partir de la chaine de caractère ligne
        iss >> hex >> couleur; // on lit le flux iss et on stocke la valeur dans la variable couleur

        // création de la forme en des données du fichier de visite
        return new Cercle (points[0], points[1], points[2], couleur);
    }
    return NULL;
}
