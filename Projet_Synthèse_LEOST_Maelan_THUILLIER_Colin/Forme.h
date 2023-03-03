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
    Forme(); // Pourquoi ?

    /**  Constructeur */
    Forme(const int& couleur) : _couleur(couleur) {}

    /** \Description  Clone la forme
    */
    virtual Forme* clone() const = 0;

    /** \Description  Destructeur
     */
    virtual ~Forme() {}

    /** \Description Avoir le point X minimal et point Y minimal  du plan selon la figure
     * @return un vecteur2D qui contient le le point min x et le point min Y
     */
    virtual Vecteur2D getMinXMinY() const =0;

    /** \Description  Avoir le point X maximal et point Y maximal  du plan selon la figure
     * @return un vecteur2D qui contient le le point max x et le point max Y
     */
    virtual Vecteur2D getMaxXMaxY() const =0;

    /** \Description  Setter de la couleur
     */
    void setCouleur(const int& c){ _couleur = c;}

    /** \Description  Getter de la couleur
     */
    int getCouleur() const{ return _couleur;}

    /** \Description  Calculer l'aire de la figure
     */
    virtual double calculerAire() const = 0;

    /** \Description  Avoir le centre de symétrie de la figure
     */
    virtual Vecteur2D getCentreDeSymetrie() const = 0;

    /**
     * \Descprition Opération de translation
     * @param u est le vecteur de translation
     */
    virtual void translation(const Vecteur2D& u) = 0;

    /** \Description Opération d'homothétie
    * @param u est le centre de l'homothétie
    * @param k est le coefficient d'homothétie
    **/
    virtual void homothetie(const Vecteur2D& u,double k) = 0;

    /**  \Description  Opération de rotation
     * @param u est le centre de la rotation
     */
    virtual void rotation(const Vecteur2D &u, const double angle ) = 0;


    /** \Description  Opérateur d'affichage en friend car on a besoin de la classe fille
     */
    inline friend ostream& operator << (ostream& os, const Forme* s);

    /** \Description  Opérateur de conversion d'objet en chaîne de caractères.
     */
    virtual operator string() const = 0;
};

/** \Description  Opérateur d'affichage
   */
inline ostream& operator << (ostream& os, const Forme* s)
{
    os << (string)(*s);
    return os;
}


#endif //PROJET_SYNTHÈSE_LEOST_MAELAN_THUILLIER_COLIN_FORME_H
