/**
 * @author update by THUILLIER Colin
 */

#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <math.h>

#ifndef PROJET_SYNTHÈSE_LEOST_MAELAN_THUILLIER_COLIN_VECTEUR_H
#define PROJET_SYNTHÈSE_LEOST_MAELAN_THUILLIER_COLIN_VECTEUR_H

using namespace std;



class Vecteur2D
{
public:
    double x,y;


    inline explicit Vecteur2D(const double & x = 0, const double & y = 0);

/**
 * DONNEES : s respectant le format "(  nombre réel, nombre réel)"
 *
 * */
    inline Vecteur2D(const char * s);
    inline const Vecteur2D operator + (const Vecteur2D & u) const;
    inline const Vecteur2D operator * (const double & a) const;
/**
 * - unaire (c'est-à- dire opposé d'un vecteur)
 * */
    inline const Vecteur2D operator - () const;

    /**
     * - binaire (c'est-à- dire soustraction de deux vecteurs)
     * @param u
     * @return le vecteur résultant de la soustraction
     */
    inline const Vecteur2D operator - (const Vecteur2D & u) const;

    /**
     * @brief Calcule la norme du vecteur
     * @return la norme du vecteur
     * @details La norme d'un vecteur est sa longueur, c'est la distance euclidienne entre le point d'origine du vecteur et son extrémité
     */
    double norm() const;

    /**
     * @brief Calcule le produit scalaire entre deux vecteurs
     * @param u
     * @return le produit scalaire entre deux vecteurs
     * @details Le produit scalaire est la somme des produits des coordonnées des deux vecteurs
     */
    double produitScalaire(const Vecteur2D & u) const;

    const double distance(const Vecteur2D &b) const;

    inline const bool operator == (const Vecteur2D & u) const;

    operator string() const;

}; // classe Vecteur2D

inline const Vecteur2D operator *(const double & a, const Vecteur2D & u) { return u*a;}

//------------ implémentation des fonctions inline ----------------------

inline  Vecteur2D::
Vecteur2D(const double & x, const double & y): x(x),y(y){}

inline const Vecteur2D Vecteur2D::operator + (const Vecteur2D & u) const
{
    return Vecteur2D( x+u.x, y+u.y);
}

inline const Vecteur2D Vecteur2D::operator * (const double & a) const
{
    return Vecteur2D( x*a, y*a);
}

inline const Vecteur2D Vecteur2D::operator - () const
{
    return Vecteur2D(-x,-y);
}

inline const Vecteur2D Vecteur2D::operator - (const Vecteur2D & u) const
{
    return Vecteur2D( x-u.x, y-u.y);
}

double Vecteur2D::norm() const {
    return abs(sqrt(x*x + y*y));
}

double Vecteur2D::produitScalaire(const Vecteur2D & u) const {
    return x*u.x + y*u.y;
}



inline const bool Vecteur2D::operator == (const Vecteur2D & u) const
{
    return (x==u.x && y==u.y);
}

Vecteur2D::operator string() const
{
    ostringstream os;
    os << "( " << x <<", " << y << ")";
    return os.str();
}

ostream & operator << (ostream & os, const Vecteur2D & u)
{
    os << (string) u;
    return os;
}


#endif //PROJET_SYNTHÈSE_LEOST_MAELAN_THUILLIER_COLIN_VECTEUR_H
