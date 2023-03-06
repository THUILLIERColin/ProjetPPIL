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
 * @brief      Classe ExpertChargementCercleCOR
 * \details    Cette classe permet de créer un expert chargement de cercle.
 */
class ExpertChargementCercleCOR : public ExpertChargementCOR
{
public:
    /**
     * @brief      Constructeur de la classe ExpertChargementCercleCOR
     * \details    Ce constructeur permet de créer un expert chargement de cercle.
     * @param      *expertSuivant l'expert chargement suivant dans la chaîne
     */
    ExpertChargementCercleCOR(ExpertChargementCOR *expertSuivant);

    /**
     * @brief      Méthode du Design Pattern Chain of Responsibility
     * \details    Cette méthode resoudre1() permet de céterminer la forme lue en le passant à l'expert adéquat grâce au Design Pattern Chain of Responsibility.
     * @param      *ligne le problème à résoudre, ici une ligne lue depuis le fichier de sauvegarde réprésentant une forme
     * @return    la forme lue
     */
    Forme *resoudre1(const string &ligne) const;
};


