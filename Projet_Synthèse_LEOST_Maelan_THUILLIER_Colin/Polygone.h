/**
 * @author Thuillier Colin
 */

#pragma once
using namespace std;

#include <vector>
#include "Forme.h"
#include "Vecteur2D.h"
#include "Triangle.h"

class Polygone: public Forme {
private :
    vector<Vecteur2D*> _points;
public :

    Polygone(const int couleur);

    Polygone(vector<Vecteur2D*> points, const int couleur);

    Polygone(const Polygone& p);

    virtual Polygone* clone() const;

    virtual ~Polygone();

    /**
     * @brief Avoir le point X minimal et point Y minimal  du plan selon la figure
     * @return un vecteur2D qui contient le le point min x et le point min Y
     */
    virtual Vecteur2D getMinXMinY() const;

    /**
     * @brief Avoir le point X maximal et point Y maximal  du plan selon la figure
     * @return un vecteur2D qui contient le le point max x et le point max Y
     */
    virtual Vecteur2D getMaxXMaxY() const;

    /**
     * @brief Calculer l'aire de la figure
     */
    virtual double calculerAire() const;

    /**
     * @brief Avoir le centre de symétrie de la figure
     */
    virtual Vecteur2D getCentreDeSymetrie() const;

    /**
     * @brief Avoir le nombre de points du polygone
     */
    int getNbPoints() const;

    /**
     * @brief Avoir le point d'indice i
     */
    Vecteur2D* getPoint(const int& i) const;

    /**
     * @brief Ajouter un point au polygone
     */
    Polygone& addPoint(const Vecteur2D& p);

    /**
     * @brief Supprimer un point du polygone
     */
    void removePoint(const int& i);

    /**
     * @brief Supprimer tous les points du polygone
     */
    void removeAllPoints();

    /**
     * @brief Opération de translation
     * @param u est le vecteur de translation
     * @return un nouveau polygone
     */
    virtual void translation(const Vecteur2D& u);

    /**
     * @brief Opération d'homothétie
     * @param u est le centre de l'homothétie
     * @param k est le coefficient d'homothétie
     */
    virtual void homothetie(const Vecteur2D& u, const double& k);

    /**
     * @brief Opération de rotation
     * @param u est le centre de la rotation
     * @param angle est l'angle de rotation
     */
    virtual void rotation(const Vecteur2D &u, const double angle);

    /**
     * @brief Surcharge de l'opérateur string
     */
    virtual operator string() const;

};