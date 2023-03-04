/**
* @author LEOST Maelan
*/

#pragma once
#include <stdlib.h>
#include "ExpertChargementCOR.h"

ExpertChargementCOR::ExpertChargementCOR(ExpertChargementCOR * expertSuivant):suivant(suivant) { }

Forme* resoudre(const string& ligne) const
{
    Forme * forme = this->resoudre1(ligne); // cet expert tente de résoudre le problème
    //probleme
    if (forme != NULL) // cet expert a trouvé une solution
        return forme;

    if (this->suivant != NULL) // le problème est transmis à l'expert suivant
        return this->suivant->resoudre(ligne);

    else // cet expert est le dernier de la chaîne
        throw Erreur("Erreur lors du chargement de la forme")
}