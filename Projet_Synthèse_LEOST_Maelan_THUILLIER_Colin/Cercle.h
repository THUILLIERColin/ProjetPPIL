//
// Created by Maelan Leost on 02/03/2023.
//

#ifndef PROJET_SYNTHÈSE_LEOST_MAELAN_THUILLIER_COLIN_CERCLE_H
#define PROJET_SYNTHÈSE_LEOST_MAELAN_THUILLIER_COLIN_CERCLE_H

#include "Forme.h"
#include "Constante.h"
#include "Vecteur2D.h"
#include <sstream>
#include <iostream>

using namespace std;

class Cercle : public Forme
{
private :
    Vecteur2D _centre; //centre du cercle
    double _rayon; //rayon du cercle

public :
    /************************************************************************
    *
    * Constructeurs et destructeur
    *
    * **********************************************************************/
    /**  \brief  Constructeur  */
    Cercle(int x, int y, double _rayon, const int& couleur = " ") : Forme(_couleur), _rayon(_rayon),_centre(x,y) {}

    /**  \brief  Constructeur  */
    Cercle(Vecteur2D _centre, double _rayon, const int& couleur = " ") : Forme(_couleur), _rayon(_rayon),_centre(_centre) {}

    /**  \Description  Destructeur
     * sert à détruire l'objet
     */
    virtual ~Cercle() {}


    /************************************************************************
     *
     * GETTER ET SETTER
     *
     * **********************************************************************/


    /**  \Description  getter du centre
     * @return Vecteur2D
     */
    const Vecteur2D &getCentre() const;

    /**  \Description  setter du centre
     * @param centre
     */
    void setCentre(const Vecteur2D &centre);

    /**  \Description  getter du rayon
     * @return double
     */
    double getRayon() const;

    /**  \Description  setter du rayon
     */
    void setRayon(double rayon);

    /************************************************************************
     *
     * Clone et constructeur par copie
     *
     * **********************************************************************/

    /** \Description  Clone la forme
    */
    /**
     * \Description Clone l'instance courante du cercle.
     * @return Cercle* Un pointeur sur une nouvelle instance d'un cercle.
     * @detail Il s'agit d'une allocation dynamique (new).
     */
    /** \Description  Clone la forme
    */
    Cercle* Cercle::clone() const
    {
        return new Cercle(*this);
    }

    /**
	 * \Description Constructeur par recopie.
	 * @param op Cercle Une instance du cercle à copier.
	 */
    Cercle(const Cercle& op);

    /************************************************************************
     *
     * Methodes pour avoir les points min et max
     *
     * **********************************************************************/

    /** \Description Avoir le point X minimal et point Y minimal  du plan selon la figure
    * @return un vecteur2D qui contient le le point min x et le point min Y
    */
    virtual Vecteur2D getMinXMinY() const =0;

    /** \Description  Avoir le point X maximal et point Y maximal  du plan selon la figure
     * @return un vecteur2D qui contient le le point max x et le point max Y
     */
    virtual Vecteur2D getMaxXMaxY() const =0;

    /************************************************************************
     *
     * Methodes pour les opérations géométriques translation, homothétie, rotation
     *
     * **********************************************************************/

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

    /************************************************************************
     *
     * Methodes pour calculerAire et getCentreDeSymetrie
     *
     * **********************************************************************/

    /** \Description  Calculer l'aire de la figure
    */
    double calculerAire() const;

    /** \Description  Avoir le centre de symétrie de la figure
     */
    Vecteur2D getCentreDeSymetrie() const;

    /************************************************************************
     *
     * Methodes operator
     *
     * **********************************************************************/

    /**
	 * \Description Surcharge de l'opérateur =.
	 * @detail Affectation par recopie d'un vecteur passé en paramètre.
	 * @param op Cercle Le cercle à copier.
	 * @return Cercle
	 */
    const Cercle& operator = (const Cercle& op);

    /**
	 * \Description Surcharge de l'opérateur ==.
	 * @detail Compare l'instance avec le vecteur passé en paramètre.
	 * @param op Cercle
	 * @return bool
	 */
    bool operator == (const Cercle& op)const;

    /**
     * \Description Surcharge de l'opérateur !=.
     * @detail Vérifie si l'instance et le vecteur passé en paramètre sont égaux.
     * @param op Cercle
     * @return bool
     */
    bool operator != (const Cercle& op)const;

    /************************************************************************
     *
     * Methodes pour l'affichage
     *
     * **********************************************************************/

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
