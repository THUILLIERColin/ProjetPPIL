/**
 * @author THUILLIER Colin
 */

#pragma once

#include "Forme.h"
#include <sstream>
#include <iostream>
#include <vector>

class FormeComplexe  : public Forme
{
private:
    vector<Forme*> formes; //tableau de pointeurs sur des formes
public:

    /************************************************************************
    *
    * Constructeurs et destructeur
    *
    * **********************************************************************/
    virtual ~FormeComplexe();

    /************************************************************************
    *
    * Methodes pour les opérations géométriques translation, homothétie, rotation
    *
    * **********************************************************************/

    /**
    * \Descprition Opération de translation
    * @param u est le vecteur de translation
    */
    void translation(const Vecteur2D& u) ;

    /** \Description Opération d'homothétie
    * @param u est le centre de l'homothétie
    * @param k est le coefficient d'homothétie
    **/
    void homothetie(const Vecteur2D& u,double k) ;

    /**  \Description  Opération de rotation
    * @param u est le centre de la rotation
    */
    void rotation(const Vecteur2D &u, const double angle ) ;


    /************************************************************************
    *
    * methodes getMinXMinY et getMaxXMaxY
    *
    * **********************************************************************/

    /** \Description getMinXMinY
   * @return un vecteur2D qui contient le le point min x et le point min Y
     *sert a avoir le point X minimal et point Y minimal  du plan selon la figure
     */
    Vecteur2D getMinXMinY() const ;
    /** \Description getMaxXMaxY
     * @return un vecteur2D qui contient le le point max x et le point max Y
     * sert a avoir le point X maximal et point Y maximal  du plan selon la figure
     */
    Vecteur2D getMaxXMaxY() const ;

    /************************************************************************
    *
    * Methodes pour calculerAire et getCentreDeSymetrie
    *
    * **********************************************************************/

    /** \Description  Calculer l'aire de la figure
    */
    double calculerAire() const ;

    /** \Description  Avoir le centre de symétrie de la figure
    */
    Vecteur2D getCentreDeSymetrie() const;

};


