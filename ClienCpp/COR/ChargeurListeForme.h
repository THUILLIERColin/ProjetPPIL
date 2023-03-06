/**
 * @author LEOST Maelan
*/

#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "../Formes/Forme.h"
#include "ExpertChargementCOR.h"
#include "ExpertChargementSegmentCOR.h"
#include "ExpertChargementCercleCOR.h"
#include "ExpertChargementPolygoneCOR.h"
#include "ExpertChargementFormeComplexeCOR.h"

/**
 * @brief    Classe qui charge un fichier texte et retourne un vecteur de Formes
 */
class ChargeurListeForme {
public:

    /**
     * @brief    Fonction qui charge et appelle le DP COR en appelant tous les Experts
     * @param      fichier   un fichier texte
     * @return     Un vecteur de Formes contenant toutes les formes du fichier texte ifs
     */
    static vector<Forme*> charge(ifstream& fichier); // charge un fichier texte et retourne un vecteur de Formes

};

