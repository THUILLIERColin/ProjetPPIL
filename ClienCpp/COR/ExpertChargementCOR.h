/**
 * @author LEOST Maelan
*/

#pragma once
#include <string>
#include "ExpertChargement.h"
#include "../Erreur/Erreur.h"

using namespace std;


class ExpertChargementCOR :public ExpertChargement {
private :
    ExpertChargementCOR * suivant;

protected :
    /**
     * \Description      Constructeur de la classe ExpertChargementCOR
     * \details    Ce constructeur permet de créer un expert chargement de la forme lue.
     * \param      *suivant l'expert chargement suivant dans la chaîne
     */
    ExpertChargementCOR(ExpertChargementCOR *expertSuivant);

public :
    Forme* resoudre(const string& ligne)const;

protected:
    /**
 * \Description      Méthode du Design Pattern Chain of Responsibility
 * \details    Cette méthode resoudre1() permet de céterminer la forme lue en le passant à l'expert adéquat grâce au Design Pattern Chain of Responsibility.
 * @param      *d le problème à résoudre, ici une ligne lue depuis le fichier de sauvegarde réprésentant une forme
 * @return    *s la solution, ici une forme
 */
    virtual Forme *resoudre1(const string &ligne) const = 0;

};



