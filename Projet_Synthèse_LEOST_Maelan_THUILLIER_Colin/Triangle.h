/**
 * @author Thuillier Colin
 */

#pragma once

#include "Vecteur2D.h"
#include "Forme.h"
#include "Polygone.h"


class Triangle : public Polygone {
private :
    Vecteur2D _a;
    Vecteur2D _b;
    Vecteur2D _c;

public :
    /**************************************************************************
     * Constructeurs de la classe Triangle
     **************************************************************************/
     /**
      * Constructeur par défaut
      */
     Triangle(const int couleur=0x000000);

     /**
      * Constructeur avec paramètres
      * @param a (Vecteur2D) : le premier point du triangle
      * @param b (Vecteur2D) : le deuxième point du triangle
      * @param c (Vecteur2D) : le troisième point du triangle
      * @param couleur (int) : la couleur du triangle
      */
     Triangle(const Vecteur2D &a, const Vecteur2D &b, const Vecteur2D &c, const int couleur);

     /**
      * Constructeur sans couleur
      * @param a (Vecteur2D) : le premier point du triangle
      * @param b (Vecteur2D) : le deuxième point du triangle
      * @param c (Vecteur2D) : le troisième point du triangle
      */
     Triangle(const Vecteur2D &a, const Vecteur2D &b, const Vecteur2D &c);
     /**
      * Constructeur de copie
      * @param t (Triangle) : le triangle à copier
      */
     Triangle(const Triangle &t);

     /**
      * Méthode clone
      * @return (Triangle *) : un pointeur sur le triangle cloné
      */
    Triangle *clone() const;

    /**
     * Destructeur de la classe Triangle
     */
    ~Triangle();

    Vecteur2D getMinXMinY() const override;
    Vecteur2D getMaxXMaxY() const override;
    double calculerAire() const override;

    Vecteur2D getCentreDeSymetrie() const;
    void translation(const Vecteur2D &u);
    void homothetie(const Vecteur2D &u, double k);
    void rotation(const Vecteur2D &u, double angle);

    /**************************************************************************
     * Getter de la classe Triangle
     **************************************************************************/
    Vecteur2D getA() const;
    Vecteur2D getB() const;
    Vecteur2D getC() const;

    /**************************************************************************
     * Setter de la classe Triangle
     **************************************************************************/
    void setA(const Vecteur2D &a);
    void setB(const Vecteur2D &b);
    void setC(const Vecteur2D &c);
};
