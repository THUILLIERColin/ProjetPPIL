/**
 * @author LEOST Maelan
 */

#include "segment.h"


using namespace std;

/************************************************************************
 *
 * GETTER ET SETTER
 *
 * **********************************************************************/

const Vecteur2D &Segment::getVecteur1() const {
    return Vecteur1;
}

void Segment::setVecteur1(const Vecteur2D &vecteur) {
    Segment::Vecteur1 = vecteur;
}

const Vecteur2D &Segment::getVecteur2() const {
    return Vecteur2;
}

void Segment::setVecteur2(const Vecteur2D &vecteur) {
    Segment::Vecteur2 = vecteur;
}

/************************************************************************
 *
 * Methodes pour avoir les points min et max
 *
 * **********************************************************************/
Vecteur2D Segment::getMinXMinY() const {

    double minX = Vecteur1.x < Vecteur2.x ? Vecteur1.x : Vecteur2.x;
    double minY = Vecteur1.y < Vecteur2.y ? Vecteur1.y : Vecteur2.y;
    return Vecteur2D(minX,minY);
}

Vecteur2D Segment::getMaxXMaxY() const {

    double maxX = Vecteur1.x > Vecteur2.x ? Vecteur1.x : Vecteur2.x;
    double maxY = Vecteur1.y > Vecteur2.y ? Vecteur1.y : Vecteur2.y;
    return Vecteur2D(maxX,maxY);
}

    /************************************************************************
     *
     * Methodes pour les opérations géométriques translation, homothétie, rotation
     *
     * **********************************************************************/

/**
 * \brief    Opération de translation
 */
void Segment::translation(const Vecteur2D &u)
{
    Vecteur1 = Vecteur1 + u;
    Vecteur2 = Vecteur2 + u;
}

/**
 * \brief    Opération d'homothétie
 */
void Segment::homothetie(const Vecteur2D &u, double k)
{
    Vecteur1 =  (Vecteur1 - u)*k  + u;
    Vecteur2 =  (Vecteur2 - u)*k  + u;
}

/************************************************************************
*
* Methodes pour calculerAire et getCentreDeSymetrie
*
* **********************************************************************/

double Segment::calculerAire() const
{
    return 0;
}

Vecteur2D Segment::getCentreDeSymetrie() const
{
    Vecteur2D g = (Vecteur1+Vecteur2)*(1/2.0);
    return g;
}