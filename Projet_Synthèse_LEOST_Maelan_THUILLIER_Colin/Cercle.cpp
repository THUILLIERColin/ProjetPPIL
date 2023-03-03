/**
 * @author LEOST Maelan
 */

#include "Cercle.h"
#include "Constante.h"
#include "Erreur.h"
#include <cmath>


using namespace std;

/************************************************************************
 *
 * GETTER ET SETTER
 *
 * **********************************************************************/

const Vecteur2D &Cercle::getCentre() const {
    return _centre;
}

void Cercle::setCentre(const Vecteur2D &centre) {
    _centre = centre;
}

double Cercle::getRayon() const {
    return _rayon;
}

void Cercle::setRayon(double rayon) {
    if(rayon < 0)
        throw Erreur("Le rayon doit être positif");
    _rayon = rayon;
}

/************************************************************************
 *
 *constructeur par copie et clone
 *
 * **********************************************************************/

/** \Description  Clone la forme
* @return Cercle
* sert à cloner un cercle
*/

Cercle* Cercle::clone() const
{
    return new Cercle(*this);
}

/**
 * \Description Constructeur par recopie.
 * @param op Cercle Une instance du cercle à copier.
 * @detail Il s'agit d'une allocation dynamique (new).
 * se sert pour copier un cercle
 */

Cercle::Cercle(const Cercle& op) : Forme(op)
{
    _centre = op.getCentre();
    _rayon = op.getRayon();
}

/************************************************************************
 *
 * Methodes pour avoir les points min et max
 *
 * **********************************************************************/

/** \Description Avoir le point X minimal et point Y minimal  du plan selon la figure
* @return un vecteur2D qui contient le le point min x et le point min Y
 * sert à avoir le point min x et le point min Y
*/
Vecteur2D Cercle::getMinXMinY() const
{
    return Vecteur2D(_centre.x-_rayon,_centre.y-_rayon);
}

/** \Description  Avoir le point X maximal et point Y maximal  du plan selon la figure
 * @return un vecteur2D qui contient le le point max x et le point max Y
 * sert à avoir le point max x et le point max Y
 */
Vecteur2D Cercle::getMaxXMaxY() const
{
    return Vecteur2D(_centre.x+_rayon,_centre.y+_rayon);
}

/************************************************************************
 *
 * Methodes pour les opérations géométriques translation, homothétie, rotation
 *
 * **********************************************************************/


/**
* \Descprition Opération de translation
* @param u est le vecteur de translation
 * sert à déplacer le cercle
*/
void Cercle::translation(const Vecteur2D& u)
{
    _centre = _centre + u;
}

/** \Description Opération d'homothétie
* @param u est le centre de l'homothétie
* @param k est le coefficient d'homothétie
 * sert à agrandir ou rétrécir le cercle
**/
void Cercle::homothetie( const Vecteur2D &u, const double& k)
{
    _centre = (_centre - u)*k  + u;
    _rayon *= k;
}

/**  \Description  Opération de rotation
   * @param u est le centre de la rotation
   * @param angle est l'angle de rotation
   * sert à faire tourner le cercle
   */
void Cercle::rotation(const Vecteur2D &u, const double angle)
{

    double m11 = cos(angle);
    double m21 = sin(angle);
    double m12 = -m21;
    double m22 = m11;

    Matrices2x2 M(m11,m12,m21,m22);

    _centre =  M * (_centre - u) + u ;
}

/************************************************************************
 *
 * Methodes pour calculerAire et getCentreDeSymetrie
 *
 * **********************************************************************/
/**
 * \Description      Méthode qui retourne l'aire du rond
 * @return     Un double
 * sert à calculer l'aire du cercle
 */
double Cercle::calculerAire() const
{
    return _rayon * _rayon * M_PI;
}


/************************************************************************
 *
 * operator
 *
 * **********************************************************************/

/**
* * \brief Surcharge de l'opérateur =.
* \detail Affectation par recopie d'un vecteur passé en paramètre.
* \param op Cercle Le cercle à copier.
* \return Cercle
 * sert à copier un cercle
*/
const Cercle& Cercle::operator = (const Cercle& op)
{
    if (this != &op)
    {
        _centre = op._centre;
        _rayon = op._rayon;
        operator=(op);
    }
    return *this;
}


/**
 * \Description Surcharge de l'opérateur !=.
 * @detail Vérifie si l'instance et le vecteur passé en paramètre sont égaux.
 * @param op Cercle
 * @return bool
 * sert à vérifier si deux cercles sont égaux
 */
bool Cercle::operator != (const Cercle& op)const
{
    return !(*this == op);
}

/**
 * \Description Surcharge de l'opérateur ==.
 * @detail Compare l'instance avec le vecteur passé en paramètre.
 * @param op Cercle
 * @return bool
 */
bool Cercle::operator == (const Cercle& op)const
{
    return (_centre == op._centre) && (_rayon == op._rayon);
}
/************************************************************************
 *
 * Methodes pour l'affichage
 *
 * **********************************************************************/

/**
 * \Description Surcharge de l'opérateur <<.
 * @detail Affiche le cercle.
 * @return
 * sert à afficher
 */
Cercle::operator string()const
{
    ostringstream os;
    os << "Cercle [ "
       << "Centre : " << _centre << ", "
       << "Rayon: " << _rayon << ", "
       << Forme::operator string() << ", "
       << "Aire : " << calculerAire()
       << " ] " << endl;
    return os.str();
}