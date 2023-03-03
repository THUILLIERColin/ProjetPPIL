/**
 * @author LEOST Maelan
 * updated by THUILLIER Colin
 */
#pragma once

#include "Matrices2x2.h"
#include "../Erreur/Erreur.h"
#include <pcap/socket.h>

class VisiteurDeLibrairie;

class Forme {
protected :
    //couleur doit etre en hexadécimal
    int _couleur;
public :

    /**  Constructeur vide */
    Forme();

    /**  Constructeur */
    Forme(const int& couleur) : _couleur(couleur) {}

    /** \Description  Clone la forme
    */
    virtual Forme* clone() const = 0;

    /**
     * @brief Constructeur de copie
     */
    Forme(const Forme& forme){
        _couleur = forme._couleur;
    }

    /** \Description  Destructeur
     */
    virtual ~Forme() {}

    /** \Description Avoir le point X minimal et point Y minimal  du plan selon la figure
     * @return un vecteur2D qui contient le le point min x et le point min Y
     */
    virtual Vecteur2D getMinXMinY() const =0;

    /** \Description  Avoir le point X maximal et point Y maximal  du plan selon la figure
     * @return un vecteur2D qui contient le le point max x et le point max Y
     */
    virtual Vecteur2D getMaxXMaxY() const =0;

    /** \Description  Setter de la couleur
     */
    void setCouleur(const int& c){ _couleur = c;}

    /** \Description  Getter de la couleur
     */
    int getCouleur() const{ return _couleur;}

    /** \Description  Calculer l'aire de la figure
     */
    virtual double calculerAire() const = 0;

    /** \Description  Avoir le centre de symétrie de la figure
     */
    virtual Vecteur2D getCentreDeSymetrie() const = 0;

    /**
     * \Descprition Opération de translation
     * @param u est le vecteur de translation
     */
    virtual void translation(const Vecteur2D& u) = 0;

    /** \Description Opération d'homothétie
    * @param u est le centre de l'homothétie
    * @param k est le coefficient d'homothétie
    **/
    virtual void homothetie(const Vecteur2D&, const double& k) = 0;

    /**  \Description  Opération de rotation
     * @param u est le centre de la rotation
     */
    virtual void rotation(const Vecteur2D &u, const double angle ) = 0;


    /** \Description  Opérateur de conversion d'objet en chaîne de caractères.
     */
    virtual operator string() const{
        ostringstream os;
        os << "Couleur : " << _couleur << endl;
        return os.str();
    }

    /** \Description  Opérateur d'affichage
     */
    friend inline ostream& operator<<(ostream& os, const Forme& forme) {
        os << (string) forme;
        return os;
    }

    /**
     * @author THUILLIER Colin
     * @brief Visiteur de librairie qui va se charger de dessiner le polygone
     * @param visiteur (VisiteurDeLibrairie) visiteur de la librairie qui va dessiner le polygone
     * @param s (SOCKET) socket de communication avec le client
     * @return void (le visiteur dessine le polygone)
     */
    virtual const void* dessine(const VisiteurDeLibrairie *visiteur, SOCKET *s) const=0;
};


