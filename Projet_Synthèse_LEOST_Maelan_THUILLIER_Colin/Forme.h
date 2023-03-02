//
// Created by Maelan Leost on 02/03/2023.
//

#ifndef PROJET_SYNTHÈSE_LEOST_MAELAN_THUILLIER_COLIN_FORME_H
#define PROJET_SYNTHÈSE_LEOST_MAELAN_THUILLIER_COLIN_FORME_H

using namespace std;
#include "Vecteur2D.h"

class Forme {
protected :
    //couleur doit etre en hexadécimal
    int _couleur;
public :

    /**  Constructeur vide */
    Forme();

    /**  Constructeur */
    Forme(const int& couleur) : _couleur(couleur) {}

    /**
     * @brief Clone la forme
    */
    virtual Forme* clone() const = 0;

    /**
     * @brief Destructeur
     */
    virtual ~Forme() {}

    /**
     * @brief Avoir le point X minimal et point Y minimal  du plan selon la figure
     * @return un vecteur2D qui contient le le point min x et le point min Y
     */
    virtual Vecteur2D getMinXMinY() const =0;

    /**
     * @brief Avoir le point X maximal et point Y maximal  du plan selon la figure
     * @return un vecteur2D qui contient le le point max x et le point max Y
     */
    virtual Vecteur2D getMaxXMaxY() const =0;

    /**
     * @brief Setter de la couleur
     */
    void setCouleur(const int& c){ _couleur = c;}

    /**
     * @brief Getter de la couleur
     */
    int getCouleur() const{ return _couleur;}

    /**
     * @brief Calculer l'aire de la figure
     */
    virtual double calculerAire() const = 0;

    /**
     * @brief Avoir le centre de symétrie de la figure
     */
    virtual Vecteur2D getCentreDeSymetrie() const = 0;

    /**
     * @brief Opération de translation
     * @param u est le vecteur de translation
     */
    virtual void translation(const Vecteur2D& u) = 0;

    /**
     * @brief Opération d'homothétie
     * @param u est le centre de l'homothétie
     * @param k est le coefficient d'homothétie
     */
    virtual void homothetie(const Vecteur2D& u,double k) = 0;

    /**
     * @brief  Opération de rotation
     * @param u est le centre de la rotation
     */
    virtual void rotation(const Vecteur2D &u, const double angle ) = 0;


    /**
     * @brief  Opérateur d'affichage en friend car on a besoin de la classe fille
     */
    inline friend ostream& operator << (ostream& os, const Forme* s);

    /**
     * @brief  Opérateur d'affichage
     */
    virtual operator tostring() const = 0;
};

/**
* @brief Opérateur d'affichage
*/
inline ostream& operator << (ostream& os, const Forme* s)
{
    os << (string)(*s);
    return os;
}


#endif //PROJET_SYNTHÈSE_LEOST_MAELAN_THUILLIER_COLIN_FORME_H
