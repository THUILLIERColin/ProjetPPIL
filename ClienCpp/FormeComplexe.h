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

    virtual Vecteur2D getMinXMinY() const;

    virtual Vecteur2D getMaxXMaxY() const;

    virtual double calculerAire() const;

    virtual Vecteur2D getCentreDeSymetrie() const;

    virtual void translation(const Vecteur2D &u);

    virtual void homothetie(const Vecteur2D &d, const double &k);

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