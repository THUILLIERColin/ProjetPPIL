/**
* @author LEOST Maelan
*/


#include "ExpertChargementCOR.h"


/**
    * \Description      Constructeur de la classe ExpertChargementCOR
    * \details    Ce constructeur permet de créer un expert chargement de la forme lue.
    * @param      *expertSuivant l'expert chargement suivant dans la chaîne
    */
ExpertChargementCOR::ExpertChargementCOR(ExpertChargementCOR * expertSuivant):_suivant(expertSuivant) { }

Forme* ExpertChargementCOR::resoudre(const string& ligne) const
{
    Forme * forme = resoudre1(ligne); // cet expert tente de résoudre le problème
    //probleme
    if (forme != NULL) // cet expert a trouvé une solution
        return forme;

    if (_suivant != NULL) // le problème est transmis à l'expert suivant
        return _suivant->resoudre(ligne);

    else // cet expert est le dernier de la chaîne
        throw Erreur("Erreur lors du chargement de la forme");
}