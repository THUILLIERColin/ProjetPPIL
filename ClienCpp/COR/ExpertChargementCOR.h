/**
 * @author LEOST Maelan
*/

#pragma once
#include <string>
#include "ExpertChargement.h"
#include "../Erreur/Erreur.h"

using namespace std;

/**
 * \Description      Classe ExpertChargementCOR
 * \details    Cette classe ExpertChargementCOR permet de créer un expert chargement de la forme lue.
 */
class ExpertChargementCOR :public ExpertChargement {
private :
    ExpertChargementCOR * _suivant;

protected :
    /**
     * \Description      Constructeur de la classe ExpertChargementCOR
     * \details    Ce constructeur permet de créer un expert chargement de la forme lue.
     * \param      *expertSuivant l'expert chargement suivant dans la chaîne
     */
    ExpertChargementCOR(ExpertChargementCOR * expertSuivant):_suivant(expertSuivant) { }

public :
    Forme* resoudre(const string& ligne) const
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

protected:
    /**
 * \Description      Méthode du Design Pattern Chain of Responsibility
 * \details    Cette méthode resoudre1() permet de céterminer la forme lue en le passant à l'expert adéquat grâce au Design Pattern Chain of Responsibility.
 * @param      *ligne le problème à résoudre, ici une ligne lue depuis le fichier de sauvegarde réprésentant une forme
 * @return    la forme lue
 */
    virtual Forme *resoudre1(const string &ligne) const = 0;

};



