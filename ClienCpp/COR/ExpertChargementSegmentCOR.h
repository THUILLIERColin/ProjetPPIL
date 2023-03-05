/**
 * @author LEOST Maelan
*/

#pragma once

#include <vector>
#include "ExpertChargementCOR.h"
#include "../Formes/Forme.h"
#include "../Formes/Segment.h"

using namespace std;
/**
 * \Description    Classe ExpertChargementSegmentCOR qui hérite de la classe ExpertChargementCOR
 * \details    Cette classe permet de charger un segment depuis un fichier texte
 */
class ExpertChargementSegmentCOR  : public ExpertChargementCOR {
public:
    /**
     * \Description      Constructeur de la classe ExpertChargementSegmentCOR
     * \details    Ce constructeur permet de créer un expert chargement de segment.
     * \param      *expertSuivant l'expert chargement suivant dans la chaîne
     */
    ExpertChargementSegmentCOR(ExpertChargementCOR *expertSuivant);

    /**
     * \Description      Méthode du Design Pattern Chain of Responsibility
     * \details    Cette méthode resoudre1() permet de céterminer la forme lue en le passant à l'expert adéquat grâce au Design Pattern Chain of Responsibility.
     * @param      *ligne le problème à résoudre, ici une ligne lue depuis le fichier de sauvegarde réprésentant une forme
     * @return    la forme lue
     */
    Forme *resoudre1(const string &ligne) const;
};

