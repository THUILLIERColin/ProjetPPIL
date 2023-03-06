/**
 * @author LEOST Maelan
 */

#pragma once

#include "Vecteur2D.h"
#include <sstream>


class Matrices2x2 {
private:
    Vecteur2D Vecteur1;
    Vecteur2D Vecteur2;

public:

    /************************************************************************
    *
    * Constructeurs et destructeur
    *
    * **********************************************************************/

    /** @paramruteur a partir de 4 reels
     * @param m11
     * @param m12
     * @param m21
     * @param m22
     * sert à construire un objet
     */
    explicit Matrices2x2(const double & m11 = 0, const double & m12 = 0, const double & m21 = 0, const double & m22 = 0);
    /** @paramructeur a partir de deux vecteur2D
     * @param Vecteur1
     * @param Vecteur2
     * sert à construire un objet
     */
    explicit Matrices2x2(const Vecteur2D& Vecteur1,const Vecteur2D& Vecteur2);


    /************************************************************************
    *
    * GETTER ET SETTER
    *
    * **********************************************************************/
    const Vecteur2D &getVecteur1() const;

    void setVecteur1(const Vecteur2D &vecteur1);

    const Vecteur2D &getVecteur2() const;

    void setVecteur2(const Vecteur2D &vecteur2);

    /************************************************************************
     *
    * Methodes operator
    *
    * **********************************************************************/

    /** @brief operateur binaire +
        * @param m
        * @return Matrices2x2
        * @detail sert a additionner deux matrices
    */
    const Matrices2x2 operator + (const Matrices2x2 & m) const;

    /** @brief operateur binaire -
    * @param m
    * @return Matrices2x2
    * @detail sert a soustraire deux matrices
    */
    const Matrices2x2 operator - (const Matrices2x2 & m) const;

    /** @brief operateur binaire *
    * @param a
    * @return Matrices2x2
    * @detail sert a multiplier une matrice par un reel
    */
   const Matrices2x2 operator * (const double & a) const;

    /** @brief operateur binaire *
    * @param a
    * @return Matrices2x2
    * @detail sert a multiplier une matrice par un reel
    */
   const Matrices2x2 operator * (const Matrices2x2 & m) const;

    /** @brief operateur binaire =
    * @param a
    * @return Matrices2x2
    * @detail sert a affecter une matrice a une autre
    */
   Matrices2x2& operator = (const Matrices2x2& m) ;

   /** @brief operateur binaire *
   * @param vec
   * @return Vecteur2D
   * @detail sert a multiplier une matrice par un vecteur
   */
   const Vecteur2D operator * (const Vecteur2D & vec) const;

    /** @brief operateur binaire ==
     * @param matrice
     * @return
     * @detail sert a comparer deux matrices
     */
    const bool operator == (const Matrices2x2 & matrice) const;


    /** @brief operateur unaire -
     * @param
     * @return
     * @detail sert a inverser une matrice
     */
    const Matrices2x2 operator - () const;

    /************************************************************************
    *
    * Methodes pour les calculs de matrices
    *
    * **********************************************************************/

    /** @brief methode determinant
     * @param
     * @return double
     * @detail sert a calculer le determinant d'une matrice
     */
    const double produitScalaire() const;

    /** @brief methode inverse
     * @param
     * @return Matrices2x2
     * @detail sert a calculer l'inverse d'une matrice
     */
    const Matrices2x2 inverse() const ;

    /** @brief methode comatrice
     * @param
     * @return Matrices2x2
     * @detail sert a calculer la comatrice d'une matrice
     */
    const Matrices2x2 comatrice() const;
    /************************************************************************
    *
    * Methodes pour l'affichage
    *
    * **********************************************************************/

    /** @brief operateur de conversion en string
     * @param
     * @return string
     * @detail sert a convertir une matrice en string
     */
     operator string() const;

    /** @brief operateur de flux
     * @param os
     * @param s
     * @return
     */
    friend inline ostream & operator << (ostream & os, const Matrices2x2 & s);

};

/** @brief operateur de flux
 * @param os
 * @param s
 * @return
 */
inline ostream & operator << (ostream & os, const Matrices2x2 & s)
{
os << (string) s;
return os;
}

