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
    FormeComplexe(const int couleur=0xFFFFFF);
    FormeComplexe(vector<Forme*> listeFormes, const int couleur=0xFFFFFF);
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

    /**
     * @brief Méthode qui permet de modifier la couleur de toutes les formes de la liste des formes
     * @param couleur
     * @return la forme complexe pour pouvoir chaîner les méthodes
     */
    FormeComplexe& setCouleurListeFormes(const int couleur);

    /**
     * @brief Méthode qui permet d'obtenir le nombre de formes
     * @return le nombre de formes
     */
     int getNombreFormes() const;
    /**
     * @brief Méthode qui permet d'obtenir la liste des formes
     * @return la liste des formes
     */
    vector<Forme*> getListeFormes() const;

    virtual Vecteur2D getMinXMinY() const;

    virtual Vecteur2D getMaxXMaxY() const;

    virtual double calculerAire() const;

    virtual Vecteur2D getCentreDeSymetrie() const;

    virtual void translation(const Vecteur2D &u);

    virtual void homothetie(const Vecteur2D &d, const double &k);

    virtual void rotation(const Vecteur2D &u, const double angle);

    virtual operator string() const;

    friend inline ostream& operator<<(ostream& os, const FormeComplexe& formeComplexe);

    /*
     * Visiteur
     */
    const void* dessine(const VisiteurDeLibrairie *visiteur, SOCKET s) const;
    const void* sauvegarde(const VisiteurDeSauvegarde *visiteur) const;

};
inline ostream& operator<<(ostream& os, const FormeComplexe& formeComplexe) {
    os << (string) formeComplexe;
    return os;
}