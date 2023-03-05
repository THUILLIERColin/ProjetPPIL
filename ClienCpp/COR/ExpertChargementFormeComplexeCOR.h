/**
 * @author LEOST Maelan
*/

#pragma once

#include "ExpertChargementCOR.h"
#include "../Formes/Forme.h"
#include "../Formes/FormeComplexe.h"

#include "ExpertChargementSegmentCOR.h"
#include "ExpertChargementCercleCOR.h"
#include "ExpertChargementPolygoneCOR.h"

using namespace std;
/**
 * \Description    Classe qui permet de charger une forme complexe
 */

class ExpertChargementFormeComplexeCOR : public ExpertChargementCOR
{
public:
    /**
     * \Description      Constructeur de la classe ExpertChargementFormeComplexeCOR
     * \details    Ce constructeur permet de créer un expert chargement de forme complexe.
     * \param      *expertSuivant l'expert chargement suivant dans la chaîne
     */
    ExpertChargementFormeComplexeCOR(ExpertChargementCOR *expertSuivant);

    /**
     * \Description      Méthode du Design Pattern Chain of Responsibility
     * \details    Cette méthode resoudre1() permet de céterminer la forme lue en le passant à l'expert adéquat grâce au Design Pattern Chain of Responsibility.
     * @param      *ligne le problème à résoudre, ici une ligne lue depuis le fichier de sauvegarde réprésentant une forme
     * @return    la forme lue
     */
    Forme *resoudre1(const string &ligne) const;
};
