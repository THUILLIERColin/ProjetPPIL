/**
 * @author LEOST Maelan
*/

#include "ExpertChargementSegmentCOR.h"


/**
  * \Description      Constructeur de la classe ExpertChargementSegmentCOR
  * \details    Ce constructeur permet de créer un expert chargement de segment.
  * \param      *expertSuivant l'expert chargement suivant dans la chaîne
  */
ExpertChargementSegmentCOR::ExpertChargementSegmentCOR(ExpertChargementCOR *expertSuivant):ExpertChargementCOR(expertSuivant) { }

/**
 * \Description      Méthode du Design Pattern Chain of Responsibility
 * \details    Cette méthode resoudre1() permet de céterminer la forme lue en le passant à l'expert adéquat grâce au Design Pattern Chain of Responsibility.
 * @param      *ligne le problème à résoudre, ici une ligne lue depuis le fichier de sauvegarde réprésentant une forme
 * @return    la forme lue
 */
Forme *ExpertChargementSegmentCOR::resoudre1(const string &ligne) const

{
    const string cherche = "Segment";
    string::size_type pos = ligne.find(cherche); // on cherche le mot "segment" dans la ligne
    while (pos != string::npos) //tant qu on ne le trouve pas
    {
        // "croix" trouvé
        vector<double> points; // ve'cteur de points

        // on extrait tout ce qui se trouve entre les parenthèses
        unsigned crochetDuDebut = ligne.find("["); // on cherche la première parenthèse
        unsigned crochetDeLaFin = ligne.find("]");  // on cherche la dernière parenthèse
        string coordonnees = ligne.substr(crochetDuDebut + 1, crochetDeLaFin - crochetDuDebut -1); // on extrait tout ce qui se trouve entre les parenthèses avec la methode substr
        istringstream is(coordonnees); // on crée un flux de lecture à partir de la chaine de caractère coordonnees

        // on enlève toutes les virgules et on stocke les nombres dans un vecteur
        string valeurLues; // on crée une chaine de caractère
        while (getline(is, valeurLues, ','))
            points.push_back(stod(valeurLues)); // on lit le flux is et on stocke les valeurs dans le vecteur points

        // récupération de la couleur qui est un int en hexadecimal dans la ligne note #FF0000
        int couleur;
        //couleur est stocké dans la ligne sous la forme FF0000 ( en string) il faut donc la passé en string
        istringstream iss(ligne.substr(crochetDeLaFin + 1, ligne.size()));// on crée un flux de lecture à partir de la chaine de caractère ligne
        iss >> hex >> couleur; // on lit le flux iss et on stocke la valeur dans la variable couleur

        // création de la forme en des données du fichier de visite
        return new Segment(points[0], points[1], points[2], points[3], couleur);
    }

    return NULL;
}
