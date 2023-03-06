/**
 * @author LEOST Maelan
*/

#pragma once
#include "ExpertChargementCOR.h"
#include "../Formes/Polygone.h"
#include "../Formes/Forme.h"



using namespace std;
/**
 * @brief    Classe qui sert à résoudre le problème de la ligne lue
 */

class ExpertChargementPolygoneCOR : public ExpertChargementCOR
{
public:
    /**
     * @brief      Constructeur de la classe ExpertChargementPolygoneCOR
     * \details    Ce constructeur permet de créer un expert chargement de polygone.
     * @param      *expertSuivant l'expert chargement suivant dans la chaîne
     */
    ExpertChargementPolygoneCOR(ExpertChargementCOR *expertSuivant);


    /**
     * @brief      Méthode du Design Pattern Chain of Responsibility
     * \details    Cette méthode resoudre1() permet de céterminer la forme lue en le passant à l'expert adéquat grâce au Design Pattern Chain of Responsibility.
     * @param      *ligne le problème à résoudre, ici une ligne lue depuis le fichier de sauvegarde réprésentant une forme
     * @return    la forme lue
     */
    Forme *resoudre1(const string &ligne) const;
};

