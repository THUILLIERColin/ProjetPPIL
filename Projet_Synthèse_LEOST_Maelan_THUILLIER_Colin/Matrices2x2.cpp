/**
 * @author LEOST Maelan
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

const Matrices2x2 Matrices2x2::operator-(const Matrices2x2 &m) const
{
    return Matrices2x2(Vecteur1-m.Vecteur1,Vecteur2-m.Vecteur2);
}

const Matrices2x2 Matrices2x2::operator-() const
{
    return Matrices2x2(-Vecteur1,-Vecteur2);
}

const Matrices2x2 Matrices2x2::operator*(const double &a) const
{
    return Matrices2x2(Vecteur1*a,Vecteur2*a);
}

const Vecteur2D Matrices2x2::operator*(const Vecteur2D &vecteur) const
{
    double l1 = Vecteur1.x*vecteur.x + Vecteur1.y*vecteur.y;
    double l2 =  Vecteur2.x*vecteur.x + Vecteur2.y*vecteur.y;
    return Vecteur2D(l1,l2);
}

const Matrices2x2 Matrices2x2::operator*(const Matrices2x2 &m) const
{
    return Matrices2x2();
}

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



