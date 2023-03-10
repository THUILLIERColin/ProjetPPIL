/**
 * @author LEOST Maelan
*/

#include "ExpertChargementPolygoneCOR.h"



/**
  * @brief      Constructeur de la classe ExpertChargementPolygoneCOR
  * \details    Ce constructeur permet de créer un expert chargement de polygone.
  * @param      *expertSuivant l'expert chargement suivant dans la chaîne
  */
ExpertChargementPolygoneCOR::ExpertChargementPolygoneCOR(ExpertChargementCOR *expertSuivant):ExpertChargementCOR(expertSuivant) { }


/**
 * @brief      Méthode du Design Pattern Chain of Responsibility
 * \details    Cette méthode resoudre1() permet de céterminer la forme lue en le passant à l'expert adéquat grâce au Design Pattern Chain of Responsibility.
 * @param      *ligne le problème à résoudre, ici une ligne lue depuis le fichier de sauvegarde réprésentant une forme
 * @return    la forme lue
 */
Forme *ExpertChargementPolygoneCOR::resoudre1(const string &ligne) const
{
    const string cherche = "Polygone";
    string::size_type pos = ligne.find(cherche);// on cherche le mot "polygone" dans la ligne lue
    while (pos != string::npos)
    {
        // "polygone" trouvé
        vector<double> points; // vecteur de double qui contiendra les coordonnées des points du polygone

        // on extrait tout ce qui se trouve entre les parenthèses
        unsigned crochetDuDebut = ligne.find("[");// on cherche la position de la parenthese ouvrante
        unsigned crochetDeLaFin = ligne.find("]"); // on cherche la position de la parenthese fermante
        string coordonnees = ligne.substr (crochetDuDebut + 1, crochetDeLaFin - crochetDuDebut - 1);
        istringstream is(coordonnees ); // on crée un flux de lecture à partir de la chaine de caractère coordonnees

        // on enlève toutes les virgules et on stocke les nombres dans un vecteur
        string valeurLues;
        while ( getline( is, valeurLues, ',' ) ) points.push_back(stod(valeurLues)); // on lit le flux is et on stocke la valeur dans la variable valeurLues

        // tab de vecteurs
        vector<Vecteur2D*> vecteur;

        for(int x=0, y=1; y < points.size(); x+=2, y+=2) // on crée un vecteur de vecteur2D à partir des points du polygone
            vecteur.push_back(new Vecteur2D(points[x], points[y]));// on crée un vecteur2D à partir des points du polygone

        // récupération de la couleur qui est un int en hexadecimal dans la ligne note #FF0000
        int couleur;
        //couleur est stocké dans la ligne sous la forme FF0000 ( en string) il faut donc la passé en string
        istringstream iss(ligne.substr(crochetDeLaFin + 1, ligne.size()));// on crée un flux de lecture à partir de la chaine de caractère ligne
        iss >> hex >> couleur; // on lit le flux iss et on stocke la valeur dans la variable couleur

        // création de la forme en des données du fichier de visite
        return new Polygone(vecteur, couleur);
    }
    return NULL;
}
