/**
 * @author LEOST Maelan
 */

#pragma once

#include "Forme.h"
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
    /**  @brief  Constructeur
     * @param x
     * @param y
     * @param rayon
     * @param couleur
     * @detail sert à construire un cercle
     */
    Cercle(int x, int y, double rayon, const int& couleur) : Forme(couleur),_centre(x,y) {
        setRayon(rayon);
    }

    /**  @brief  Constructeur
     * @param _centre
     * @param _rayon
     * @param couleur
     * @detail sert à construire un cercle
     */
    Cercle(Vecteur2D _centre, double rayon, const int& couleur) : Forme(couleur), _rayon(rayon),_centre(_centre) {}

    /**  @brief  Destructeur
     * @detail sert à détruire l'objet
     */
    virtual ~Cercle() {}


    /************************************************************************
     *
     * GETTER ET SETTER
     *
     * **********************************************************************/


    /**  @brief  getter du centre
     * @return Vecteur2D
     */
    const Vecteur2D &getCentre() const;

    /**  @brief  setter du centre
     * @param centre
     */
    void setCentre(const Vecteur2D &centre);

    /**  @brief  getter du rayon
     * @return double
     */
    double getRayon() const;

    /**  @brief  setter du rayon
     */
    void setRayon(double rayon);

    /************************************************************************
     *
     * Clone et constructeur par copie
     *
     * **********************************************************************/

    /** @brief  Clone la forme
     * @return Cercle
     * @detail sert à cloner un cercle
     */
    Cercle* clone() const;

    /**
	 * @brief Constructeur par recopie.
	 * @param op Cercle Une instance du cercle à copier.
     * @detail Il s'agit d'une allocation dynamique (new).
     *  @detail sert pour copier un cercle
	 */
    Cercle(const Cercle& op);

    /************************************************************************
     *
     * Methodes pour avoir les points min et max
     *
     * **********************************************************************/

    /** @brief Avoir le point X minimal et point Y minimal  du plan selon la figure
    * @return un vecteur2D qui contient le le point min x et le point min Y
     * @detail sert à avoir le point min x et le point min Y
    */
    virtual Vecteur2D getMinXMinY() const;

    /** @brief  Avoir le point X maximal et point Y maximal  du plan selon la figure
     * @return un vecteur2D qui contient le le point max x et le point max Y
     * @detail sert à avoir le point max x et le point max Y
     */
    virtual Vecteur2D getMaxXMaxY() const;

    /************************************************************************
     *
     * Methodes pour les opérations géométriques translation, homothétie, rotation
     *
     * **********************************************************************/

    /**
    * @brief Opération de translation
    * @param u est le vecteur de translation
    */
    virtual void translation(const Vecteur2D& u);

    /** @brief Opération d'homothétie
    * @param u est le centre de l'homothétie
    * @param k est le coefficient d'homothétie
    **/
    virtual void homothetie(const Vecteur2D& u,const double& k);

    /**  @brief  Opération de rotation
     * @param u est le centre de la rotation
     */
    virtual void rotation(const Vecteur2D &u, const double angle );

    /************************************************************************
     *
     * Methodes pour calculerAire et getCentreDeSymetrie
     *
     * **********************************************************************/

    /** @brief  Calculer l'aire de la figure
    */
    double calculerAire() const;

    /** @brief  Avoir le centre de symétrie de la figure
     */
    Vecteur2D getCentreDeSymetrie() const;

    /************************************************************************
     *
     * Methodes operator
     *
     * **********************************************************************/

    /**
	 * @brief Surcharge de l'opérateur =.
	 * @detail Affectation par recopie d'un vecteur passé en paramètre.
	 * @param op Cercle Le cercle à copier.
	 * @return Cercle
	 */
    const Cercle& operator = (const Cercle& op);

    /**
	 * @brief Surcharge de l'opérateur ==.
	 * @detail Compare l'instance avec le vecteur passé en paramètre.
	 * @param op Cercle
	 * @return bool
	 */
    bool operator == (const Cercle& op)const;

    /**
     * @brief Surcharge de l'opérateur !=.
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

    /** @brief  Opérateur de conversion d'objet en chaîne de caractères.
    */
    operator string() const;

    /** @brief  Surcharge de l'opérateur <<.
    */
    friend inline ostream& operator << (ostream& os, const Cercle& c);

    /************************************************************************
     * Visiteurs
     * **********************************************************************/
    const void* dessine(const VisiteurDeLibrairie *visiteur, SOCKET s) const;

    const void* sauvegarde(const VisiteurDeSauvegarde *visiteur) const;
};

/** @brief opérateur d affichage
 * @param os
 * @param s
 * @return
 */
inline ostream& operator << (ostream& os, const Cercle& s)
{
    return os << (string)s;
}


