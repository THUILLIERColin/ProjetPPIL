//
// Created by Maelan Leost on 02/03/2023.
//

#ifndef PROJET_SYNTHÈSE_LEOST_MAELAN_THUILLIER_COLIN_CERCLE_H
#define PROJET_SYNTHÈSE_LEOST_MAELAN_THUILLIER_COLIN_CERCLE_H

#include "Forme.h"
#include "Constante.h"
#include "Vecteur2D.h"

using namespace std;

class Cercle : public Forme
{
private :
    Vecteur2D v; //centre du cercle
    double rayon; //rayon du cercle

public :
    /**  \brief  Constructeur  */
    Cercle(int x, int y, double rayon, const string& couleur = " ") : Forme(_couleur), rayon(rayon),v(x,y) {}
    /**  \brief  Constructeur  */
    Cercle(Vecteur2D v, double rayon, const string& couleur = " ") : Forme(_couleur), rayon(rayon),v(v) {}


    /**  \Description  Destructeur
     */
    virtual ~Cercle() {}


    /** \Description  Clone la forme
    */
    Cercle* clone() const{ return new Cercle(*this); }

    /**  \brief  Opération de rotation */

    /** \Description Avoir le point X minimal et point Y minimal  du plan selon la figure
 * @return un vecteur2D qui contient le le point min x et le point min Y
 */
    virtual Vecteur2D getMinXMinY() const =0;

    /** \Description  Avoir le point X maximal et point Y maximal  du plan selon la figure
     * @return un vecteur2D qui contient le le point max x et le point max Y
     */
    virtual Vecteur2D getMaxXMaxY() const =0;

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

    /** \Description  Calculer l'aire de la figure
    */
    double calculerAire() const;

    /** \Description  Avoir le centre de symétrie de la figure
     */
    Vecteur2D getCentreSymetrie() const { return v; }

    /** \Description  Opérateur de conversion d'objet en chaîne de caractères.
    */
    operator string() const;

    /** \Description  Opérateur d'affichage.
    */
    friend ostream& operator << (ostream& os, const Cercle& s);

};


inline ostream& operator << (ostream& os, const Cercle& s)
{
    return os << (string)s;
}



#endif //PROJET_SYNTHÈSE_LEOST_MAELAN_THUILLIER_COLIN_CERCLE_H
