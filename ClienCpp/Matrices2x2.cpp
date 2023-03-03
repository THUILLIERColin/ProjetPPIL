/**
 * @author LEOST Maelan et Colin THUILLIER
 */

#include "Matrices2x2.h"
#include "Vecteur2D.h"


/************************************************************************
*
* Constructeurs et destructeur
*
* **********************************************************************/

/** \Description construteur a partir de 4 reels
 * @param m11
 * @param m12
 * @param m21
 * @param m22
 * sert à construire un objet
 */
Matrices2x2::Matrices2x2(const Vecteur2D &u1, const Vecteur2D &u2) {Vecteur1=u1,Vecteur2=u2;}

/** \Description constructeur a partir de deux vecteur2D
 * @param Vecteur1
 * @param Vecteur2
 * sert à construire un objet
 */
Matrices2x2::Matrices2x2(const double &m11, const double &m12, const double &m21, const double &m22) : Vecteur1(m11,m12), Vecteur2(m21,m22) {}

/************************************************************************
*
* GETTER ET SETTER
*
* **********************************************************************/

const Vecteur2D &Matrices2x2::getVecteur1() const {
    return Vecteur1;
}

void Matrices2x2::setVecteur1(const Vecteur2D &vecteur1) {
    Vecteur1 = vecteur1;
}

const Vecteur2D &Matrices2x2::getVecteur2() const {
    return Vecteur2;
}

void Matrices2x2::setVecteur2(const Vecteur2D &vecteur2) {
    Vecteur2 = vecteur2;
}

/************************************************************************
 *
* Methodes operator
*
* **********************************************************************/

/** \Description operateur binaire +
* @param m
* @return Matrices2x2
* sert a additionner deux matrices
*/
const Matrices2x2 Matrices2x2::operator+(const Matrices2x2 &m) const
{
    return Matrices2x2(Vecteur1+m.Vecteur1,Vecteur2+m.Vecteur2);
}

/** \Description operateur binaire -
    * @param m
    * @return Matrices2x2
    * sert a soustraire deux matrices
    */
const Matrices2x2 Matrices2x2::operator-(const Matrices2x2 &m) const
{
    return Matrices2x2(Vecteur1-m.Vecteur1,Vecteur2-m.Vecteur2);
}

/** \Description operateur unaire -
 * @param
 * @return
 * sert a inverser une matrice
 */
const Matrices2x2 Matrices2x2::operator-() const
{
    return Matrices2x2(-Vecteur1,-Vecteur2);
}

/** \Description operateur binaire *
* @param a
* @return Matrices2x2
* sert a multiplier une matrice par un reel
*/
const Matrices2x2 Matrices2x2::operator*(const double &a) const
{
    return Matrices2x2(Vecteur1*a,Vecteur2*a);
}

/** \Description operateur binaire *
* @param vec
* @return Vecteur2D
* sert a multiplier une matrice par un vecteur
*/
const Vecteur2D Matrices2x2::operator*(const Vecteur2D &vecteur) const
{
    double l1 = Vecteur1.x*vecteur.x + Vecteur1.y*vecteur.y;
    double l2 =  Vecteur2.x*vecteur.x + Vecteur2.y*vecteur.y;
    return Vecteur2D(l1,l2);
}

/** \Description operateur binaire *
* @param vec
* @return Vecteur2D
* sert a multiplier une matrice par un vecteur
*/
const Matrices2x2 Matrices2x2::operator*(const Matrices2x2 &m) const
{
    return Matrices2x2();
}

/** \Description operateur binaire =
* @param a
* @return Matrices2x2
* sert a affecter une matrice a une autre
*/
Matrices2x2& Matrices2x2::operator=(const Matrices2x2 &m)
{
    if (this== &m)
    {
        return *this;
    }

    Vecteur1=m.Vecteur1;
    Vecteur2=m.Vecteur2;
    return *this;
}

/** \Description operateur binaire ==
 * @param matrice
 * @return
 * sert a comparer deux matrices
 */
const bool Matrices2x2::operator==(const Matrices2x2 &m) const
{
    return (Vecteur1==m.Vecteur1 && Vecteur2==m.Vecteur2);
}

/************************************************************************
    *
    * Methodes pour les calculs de matrices  Colin THUILLIER
    *
    * **********************************************************************/


/** \Description methode produitScalaire
 * @param
 */
const double Matrices2x2::produitScalaire() const
{
    return Vecteur1.produitScalaire(Vecteur2);
}

/** \Description methode inverse
 * @param
 * @return Matrices2x2
 * sert a calculer l'inverse d'une matrice
 */
const Matrices2x2 Matrices2x2::inverse() const
{
    return this->comatrice()*(1/this->produitScalaire());
}

/** \Description methode comatrice
 * @param
 * @return Matrices2x2
 * sert a calculer la comatrice d'une matrice
 */
const Matrices2x2 Matrices2x2::comatrice() const
{
    return Matrices2x2(Vecteur2.y,-Vecteur2.x,-Vecteur1.y,Vecteur1.x);
}



/************************************************************************
*
* Methodes pour l'affichage
*
* **********************************************************************/

Matrices2x2::operator string() const
{
    ostringstream os;
    os << "[ " << Vecteur1<< " ]" << endl
       << "[ " << Vecteur2 << " ]";
    return os.str();
}



