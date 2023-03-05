/**
 * @author LEOST Maelan
*/

#include "ExpertChargementFormeComplexeCOR.h"

/**
    * \Description      Constructeur de la classe ExpertChargementFormeComplexeCOR
    * \details    Ce constructeur permet de créer un expert chargement de forme complexe.
    * \param      *expertSuivant l'expert chargement suivant dans la chaîne
    */
ExpertChargementFormeComplexeCOR::ExpertChargementFormeComplexeCOR(ExpertChargementCOR *expertSuivant):ExpertChargementCOR(expertSuivant) { }

/**
    * \Description      Méthode du Design Pattern Chain of Responsibility
    * \details    Cette méthode resoudre1() permet de céterminer la forme lue en le passant à l'expert adéquat grâce au Design Pattern Chain of Responsibility.
    * @param      *ligne le problème à résoudre, ici une ligne lue depuis le fichier de sauvegarde réprésentant une forme
    * @return    la forme lue
    */

Forme *ExpertChargementFormeComplexeCOR::resoudre1(const string &ligne) const
{
    const string cherche = "FormeComplexe";
    string::size_type pos = ligne.find(cherche); // on cherche le mot "formecomplexe" dans la ligne lue
    while (pos != string::npos)
    {
        // "formecomplexe" trouvé

        // on extrait tout ce qui se trouve entre les crochets => liste des formes du groupe
        unsigned accoladeDeDebut = ligne.find("{");
        unsigned accoladeDeFin = ligne.find("}");
        string coordonnees = ligne.substr (accoladeDeDebut + 1, accoladeDeFin - accoladeDeDebut - 1); // on récupère la liste des formes du groupe
        istringstream is(coordonnees );// on crée un flux de lecture à partir de la chaine de caractère coordonnees

        // String lue entre les crochets
        // cout << "string lue : " << coordonnees << endl; //  triangle ( -0.3 , 1.7 , 2.8 , -2.5 , 4.3 , 5.2 ) purple, rond ( 5 , -3 , 1.2 ) purple,

        std::istringstream iss(coordonnees);
        std::vector<std::string> lesFormes;
        std::string token;

        while (std::getline(iss, token, ';')) {
            lesFormes.push_back(token);
        }

        vector<Forme*> formeComplexe; // vecteur de forme qui contiendra les formes du groupe de forme
        ExpertChargementCOR* expertSuivant; // expert qui permettra de charger les formes du groupe de forme
        expertSuivant = new ExpertChargementSegmentCOR(NULL);
        expertSuivant = new ExpertChargementPolygoneCOR(expertSuivant);
        expertSuivant = new ExpertChargementCercleCOR(expertSuivant);

        // affichage des strings des formes du groupe de forme lue
        for (const auto &str : lesFormes)  // on parcourt le vecteur lesformes, const auto signifie que str est une constante de type auto/ auto  etant
        {
            //cout << "string : " << str << endl;
            Forme* forme = expertSuivant->resoudre(str);// on charge la forme lue grâce à l'expert
            // groupe de forme de groupe de forme ICI
            if (forme != NULL)
            {
                formeComplexe.push_back(forme);// on ajoute la forme lue dans le vecteur de forme du groupe de forme
            }
        }


        // Retour du groupe de Forme
        return new FormeComplexe(formeComplexe, formeComplexe[0]->getCouleur());
    }
    return NULL;
}

