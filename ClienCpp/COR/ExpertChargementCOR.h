/**
 * @author LEOST Maelan
/**
* @author LEOST Maelan
*/

#pragma once
#include <string>
#include "ExpertChargement.h"
#include "../Erreur/Erreur.h"
#include

using namespace std;


class ExpertChargementCOR :public ExpertChargement {
    ExpertChargementCOR * _suivant;

protected :
    /**
     * \Description      Méthode du Design Pattern Chain of Responsibility
     * \details    Cette méthode resoudre1() permet de céterminer la forme lue en le passant à l'expert adéquat grâce au Design Pattern Chain of Responsibility.
     * @param      *d le problème à résoudre, ici une ligne lue depuis le fichier de sauvegarde réprésentant une forme
     * @return    *s la solution, ici une forme
     */
    virtual Forme *resoudre1(const string &ligne) const = 0;

public :
    /**
     * \Description      Constructeur de la classe ExpertChargementCOR
     * \details    Ce constructeur permet de créer un expert chargement de la forme lue.
     * \param      *suivant l'expert chargement suivant dans la chaîne
     */
    ExpertChargementCOR(ExpertChargementCOR *suivant) : _suivant(suivant) {}

    /**
     * \Description      Méthode du Design Pattern Chain of Responsibility
     * \details    Cette méthode resoudre() permet de céterminer la forme lue en le passant à l'expert adéquat grâce au Design Pattern Chain of Responsibility.
     * \param      *d le problème à résoudre, ici une ligne lue depuis le fichier de sauvegarde réprésentant une forme
     * @return    *s la solution, ici une forme
     */
    Forme* resoudre(const string& ligne) const
    {
        Forme * forme = resoudre1(ligne);
        if (forme != NULL)
            return forme;

        if (_suivant != NULL)
            return _suivant->resoudre(ligne);

        throw Erreur("Erreur lors du chargement de la forme")
    }
}

