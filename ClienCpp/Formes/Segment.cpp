/**
 * @author LEOST Maelan
 */

#include "Segment.h"
#include "../Visiteur/Librairie/VisiteurDeLibrairie.h"
#include "../Visiteur/Sauvegarde/VisiteurDeSauvegarde.h"


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
   * \Descprition Opération de translation
   * @param u est le vecteur de translation
    * sert a déplacer la figure
   */
void Segment::translation(const Vecteur2D &u)
{
    Vecteur1 = Vecteur1 + u;
    Vecteur2 = Vecteur2 + u;
}

/** \Description Opération d'homothétie
 * @param u est le centre de l'homothétie
 * @param k est le coefficient d'homothétie
  * sert a agrandir ou rétrécir la figure
 **/

void Segment::homothetie(const Vecteur2D &u, const double& k)
{
    Vecteur1 =  (Vecteur1 - u)*k  + u;
    Vecteur2 =  (Vecteur2 - u)*k  + u;
}

/**  \Description  Opération de rotation
* @param u est le centre de la rotation
* sert a faire tourner la figure
*/
void Segment::rotation(const Vecteur2D &u, const double angle)
{
    double m11 = cos(angle);
    double m21 = sin(angle);
    double m12 = -m21;
    double m22 = m11;

    Matrices2x2 M(m11,m12,m21,m22);
    Vecteur1 =  M * (Vecteur1 - u) + u ;
    Vecteur2 =  M * (Vecteur2 - u) + u ;
}

Segment::operator string() const{
    stringstream ss;
    ss << "Segment [ "
       << Vecteur1.x << " , "
       << Vecteur1.y << " , "
       << Vecteur2.x << " , "
       << Vecteur2.y  << "]"
       << hex << _couleur;
    return ss.str();
}

/************************************************************************
*
* Methodes pour calculerAire et getCentreDeSymetrie
*
* **********************************************************************/

/** \Description  Calculer l'aire du segment (0)
 * @return 0
*/
double Segment::calculerAire() const
{
    return 0;
}

/** \Description  Avoir le centre de symétrie du segment
 */
Vecteur2D Segment::getCentreDeSymetrie() const
{
    Vecteur2D g = (Vecteur1+Vecteur2)*(1/2.0);
    return g;
}

/************************************************************************
 * Implémentation des visiteurs
 ***********************************************************************/

const void *Segment::dessine(const VisiteurDeLibrairie *visiteur, SOCKET *s) const {
    return visiteur->visite(this,s);
}

const void *Segment::sauvegarde(const VisiteurDeSauvegarde *visiteur) const {
    return visiteur->visite(this);
}
