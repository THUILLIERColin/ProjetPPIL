/**
 * @author LEOST Maelan
 */
#pragma once
#include <string>

using namespace std;
//on fait class Forme pour éviter les erreurs de compilation
class Forme;

class ExpertChargement
{
protected ://protected pour que les classes filles puissent y accéder
    /** \Description  Méthode virtuelle pure
     * @param ligne
     * @return Forme*
     * sert à résoudre le problème de la ligne lue
     * -->resoudre1 est une méthode virtuelle pure car elle doit être implémentée dans les classes filles
     */
    virtual Forme * resoudre(const string &ligne) const = 0;
};

