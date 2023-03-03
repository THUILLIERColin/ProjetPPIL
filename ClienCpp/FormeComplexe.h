/**
 * @author THUILLIER Colin
 */
#pragma once

#include "Forme.h"

#include <vector>


class FormeComplexe: public Forme{
private :
    vector<Forme*> listeFormes;
public :
    /************************************************************************
    *
    * Constructeurs et destructeur
    *
    * **********************************************************************/
    /*** Constructeur ***/
    FormeComplexe(const int couleur=0x000000);
    FormeComplexe(vector<Forme*> listeFormes, const int couleur=0x000000);
    FormeComplexe(const FormeComplexe& formeComplexe);
    virtual FormeComplexe* clone() const;

    /*** Destructeur ***/
    virtual ~FormeComplexe();

    /**
     * @brief Méthode qui permet d'ajouter une forme à la liste des formes
     * @param forme (Forme*) : la forme à ajouter
     */
    FormeComplexe& ajouterForme(Forme* forme);

    /**
     * @brief Méthode qui permet de supprimer une forme de la liste des formes
     * @param forme (Forme*) : la forme à supprimer
     */
    void supprimerForme(Forme* forme);

    /**
     * @brief Méthode qui supprime toutes les formes de la liste des formes
     */
     void supprimerListeFormes();

    /**
     * @brief Méthode qui permet d'obtenir la forme a l'indice i
     * @param i
     * @return la forme a l'indice i
     */
    Forme* getForme(const int& i) const;

    FormeComplexe& setCouleurListeFormes(const int couleur);


    /************************************************************************
    *
    * methodes getMinXMinY et getMaxXMaxY
    *
    * **********************************************************************/

    /** \Description getMinXMinY
     * @return un vecteur2D qui contient le le point min x et le point min Y
     *sert a avoir le point X minimal et point Y minimal  du plan selon la figure
     */
    virtual Vecteur2D getMinXMinY() const;

    /** \Description getMaxXMaxY
     * @return un vecteur2D qui contient le le point max x et le point max Y
     * sert a avoir le point X maximal et point Y maximal  du plan selon la figure
     */
    virtual Vecteur2D getMaxXMaxY() const;


    /************************************************************************
    *
    * Methodes pour calculerAire et getCentreDeSymetrie
    *
    * **********************************************************************/

    /** \Description  Calculer l'aire de la figure
    */
    virtual double calculerAire() const;

    /** \Description  Avoir le centre de symétrie de la figure
    */
    virtual Vecteur2D getCentreDeSymetrie() const;


    /************************************************************************
    *
    * Methodes pour les opérations géométriques translation, homothétie, rotation
    *
    * **********************************************************************/

    /**
    * \Descprition Opération de translation
    * @param u est le vecteur de translation
    */
    virtual void translation(const Vecteur2D &u);

    /** \Description Opération d'homothétie
    * @param u est le centre de l'homothétie
    * @param k est le coefficient d'homothétie
    **/
    virtual void homothetie(const Vecteur2D &d, const double &k);

     /**  \Description  Opération de rotation
    * @param u est le centre de la rotation
    */
    virtual void rotation(const Vecteur2D &u, const double angle);

    virtual operator string() const;

    friend inline ostream& operator<<(ostream& os, const FormeComplexe& formeComplexe);

};
inline ostream& operator<<(ostream& os, const FormeComplexe& formeComplexe){
    os << "FormeComplexe : " << endl;
    for (int i = 0; i < formeComplexe.listeFormes.size(); i++) {
        os << *formeComplexe.listeFormes[i] << endl;
    }
    return os;
}