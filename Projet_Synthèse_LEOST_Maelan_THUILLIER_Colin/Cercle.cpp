/**
 * @author LEOST Maelan
 */

#include "Cercle.h"
#include "Constante.h"
#include "Erreur.h"


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
    _rayon = rayon;
}

/************************************************************************
 *
 *constructeur par copie
 *
 * **********************************************************************/



Cercle::Cercle(const Cercle& op) : Forme(op.getCouleur())
{
    if (op._rayon <= 0)
    {
        throw Erreur("Impossible de construire un cercle avec ce rayon.");
    }
    else
    {
        _centre = op._centre;
        _rayon = op._rayon;
    }
}

/************************************************************************
 *
 * Methodes pour avoir les points min et max
 *
 * **********************************************************************/
Vecteur2D Cercle::getMinXMinY() const {
    return Vecteur2D(_centre.x-_rayon,_centre.y-_rayon);
}

Vecteur2D Cercle::getMaxXMaxY() const {
    return Vecteur2D(_centre.x+_rayon,_centre.y+_rayon);
}

/************************************************************************
 *
 * Methodes pour les opérations géométriques translation, homothétie, rotation
 *
 * **********************************************************************/
void Cercle::translation(const Vecteur2D& u)
{
    _centre = _centre + u;
}

void Cercle::homothetie( const Vecteur2D &u, double k)
{
    _centre = (_centre - u)*k  + u;
    _rayon *= k;
}

/************************************************************************
 *
 * Methodes pour calculerAire et getCentreDeSymetrie
 *
 * **********************************************************************/
/**
 * \brief      Méthode qui retourne l'aire du rond
 * \return     Un double
 */
double Cercle::calculerAire() const
{
    return _rayon * _rayon * PI;
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
 */
bool Cercle::operator != (const Cercle& op)const
{
    return !(*this == op);
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