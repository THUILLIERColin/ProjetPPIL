/**
 * @author LEOST Maelan
 */

#pragma once

#include "Forme.h"

class Segment : public Forme
{
private :
    Vecteur2D Vecteur1; //points du segment
    Vecteur2D Vecteur2; //points du segment

public :
    /************************************************************************
     *
     * Constructeurs et destructeur
     *
     * **********************************************************************/

    /**  \Description  Constructeur
    */
    Segment(double g, double h, double d, double b, const int& couleur) : Forme(couleur) , Vecteur1(g, h), Vecteur2(d, b) {}

    /**  \Description  Deconstructeur
     * sert à détruire l'objet
    */
    virtual ~Segment() {}


    /************************************************************************
     *
     * GETTER ET SETTER
     *
     * **********************************************************************/
    const Vecteur2D &getVecteur1() const;

    void setVecteur1(const Vecteur2D &vecteur);

    const Vecteur2D &getVecteur2() const;

    void setVecteur2(const Vecteur2D &vecteur);
    /************************************************************************
     *
     * Clone
     *
     * **********************************************************************/

    /**  \Description  clone de la classe
     * @return Segment
     */
    Segment* clone() const { return new Segment(*this); }

    /************************************************************************
     *
     * Methodes pour les opérations géométriques translation, homothétie, rotation
     *
     * **********************************************************************/

    /**
    * \Descprition Opération de translation
    * @param u est le vecteur de translation
     * sert a déplacer la figure
    */
    virtual void translation(const Vecteur2D& u) ;

    /** \Description Opération d'homothétie
    * @param u est le centre de l'homothétie
    * @param k est le coefficient d'homothétie
     * sert a agrandir ou rétrécir la figure
    **/
    virtual void homothetie(const Vecteur2D& u,double k);

    /**  \Description  Opération de rotation
     * @param u est le centre de la rotation
     * sert a faire tourner la figure
     */
    virtual void rotation(const Vecteur2D &u, const double angle );

    /************************************************************************
    *
    * Methodes pour calculerAire et getCentreDeSymetrie
    *
    * **********************************************************************/

    /** \Description  Calculer l'aire du segment (0)
     * @return 0
    */
    double calculerAire() const;

    /** \Description  Avoir le centre de symétrie du segment
     */
    Vecteur2D getCentreDeSymetrie() const;

    /************************************************************************
     *
     * methodes getMinXMinY et getMaxXMaxY
     *
     * **********************************************************************/

    /** @Description Avoir le point X minimal et point Y minimal  du plan selon la figure
    * @return un vecteur2D qui contient le le point min x et le point min Y
    */
    Vecteur2D getMinXMinY() const ;

    /** @Description  Avoir le point X maximal et point Y maximal  du plan selon la figure
     * @return un vecteur2D qui contient le le point max x et le point max Y
     */
    Vecteur2D getMaxXMaxY() const ;

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
    friend inline ostream& operator << (ostream& os, const Segment& m);


};

inline ostream& operator << (ostream& os, const Segment& s)
{
    return os << (string)s;
}



