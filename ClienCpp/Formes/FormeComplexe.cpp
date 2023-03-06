/**
 * @author THUILLIER Colin
 */

#include "FormeComplexe.h"
#include "../Visiteur/Librairie/VisiteurDeLibrairie.h"
#include "../Visiteur/Sauvegarde/VisiteurDeSauvegarde.h"


FormeComplexe::FormeComplexe(const int couleur) : Forme(couleur) {}

FormeComplexe::FormeComplexe(vector<Forme *> listeFormes, const int couleur) : Forme(couleur) {
    for(int i = 0 ; i < listeFormes.size() ; i++) {
        ajouterForme(listeFormes[i]);
    }
}

FormeComplexe *FormeComplexe::clone() const {
    return new FormeComplexe(*this);
}

FormeComplexe::~FormeComplexe() {
    supprimerListeFormes();
}

FormeComplexe& FormeComplexe::ajouterForme(Forme *forme) {
    Forme *f = forme->clone();
    listeFormes.push_back(f);
    listeFormes.back()->setCouleur(_couleur); // On met la couleur de la forme complexe à toutes les formes
    return (*this);
}

int FormeComplexe::getNombreFormes() const {
    return listeFormes.size();
}

void FormeComplexe::supprimerForme(Forme *forme) {
    for(int i = 0; i < listeFormes.size(); i++) {
        if (listeFormes[i] == forme) {
            listeFormes.erase(listeFormes.begin() + i);
        }
    }
}

void FormeComplexe::supprimerListeFormes() {
    for (int i = 0; i < listeFormes.size(); i++) {
        delete listeFormes[i];
    }
    listeFormes.clear();
}

Forme *FormeComplexe::getForme(const int &i) const {
    return listeFormes[i];
}

FormeComplexe& FormeComplexe::setCouleurListeFormes(const int couleur) {
    for (int i = 0; i < listeFormes.size(); i++) {
        listeFormes[i]->setCouleur(couleur);
    }
    return (*this);
}

vector<Forme*> FormeComplexe::getListeFormes() const {
    return listeFormes;
}

Vecteur2D FormeComplexe::getMinXMinY() const {
    if (listeFormes.size() == 0) {
        return Vecteur2D(0, 0);
    }
    double minX = listeFormes[0]->getMinXMinY().x;
    double minY = listeFormes[0]->getMinXMinY().y;

    for (int i = 0; i < listeFormes.size(); ++i) {

        if (listeFormes[i]->getMinXMinY().x < minX ) minX = listeFormes[i]->getMinXMinY().x;
        if (listeFormes[i]->getMinXMinY().y < minY ) minY = listeFormes[i]->getMinXMinY().y;
    }

    return Vecteur2D(minX,minY);
}

Vecteur2D FormeComplexe::getMaxXMaxY() const {
    if (listeFormes.size() == 0) {
        return Vecteur2D(0, 0);
    }
    double maxX = listeFormes[0]->getMaxXMaxY().x;
    double maxY = listeFormes[0]->getMaxXMaxY().y;

    for (int i = 0; i < listeFormes.size(); ++i) {

        if (listeFormes[i]->getMaxXMaxY().x > maxX ) maxX = listeFormes[i]->getMaxXMaxY().x;
        if (listeFormes[i]->getMaxXMaxY().y > maxY ) maxY = listeFormes[i]->getMaxXMaxY().y;
    }

    return Vecteur2D(maxX,maxY);
}

double FormeComplexe::calculerAire() const {
    double aireTotal = 0;
    for (int i = 0; i < listeFormes.size(); ++i)
    {
        aireTotal += listeFormes[i]->calculerAire();
    }
    return aireTotal;
}

Vecteur2D FormeComplexe::getCentreDeSymetrie() const {
    return Vecteur2D();
}

void FormeComplexe::translation(const Vecteur2D &u) {
    for (int i = 0; i < listeFormes.size(); ++i)
    {
        listeFormes[i]->translation(u);
    }
}

void FormeComplexe::homothetie(const Vecteur2D &d, const double &k) {
    for (int i = 0; i < listeFormes.size(); ++i)
    {
        listeFormes[i]->homothetie(d, k);
    }
}

void FormeComplexe::rotation(const Vecteur2D &u, const double angle) {
    for (int i = 0; i < listeFormes.size(); ++i)
    {
        listeFormes[i]->rotation(u, angle);
    }
}

FormeComplexe::operator string() const {
    ostringstream oss;
    oss << "FormeComplexe : { ";
    for (int i = 0; i < listeFormes.size()-1; ++i)
    {
        oss << (string) *listeFormes[i] << " ; ";
    }
    oss << (string) *listeFormes[listeFormes.size()-1] << " } " << this->getMinXMinY() << " / " << this->getMaxXMaxY();
    return oss.str();
}

/*******************************************
 * Implementation des visiteurs
 *******************************************/
const void* FormeComplexe::dessine(const VisiteurDeLibrairie *visiteur, SOCKET s) const{
    return visiteur->visite(this, s);
}

const void *FormeComplexe::sauvegarde(const VisiteurDeSauvegarde *visiteur) const {
    return visiteur->visite(this);
}
