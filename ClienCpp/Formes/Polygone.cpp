/**
 * @author THUILLIER Colin
 */

#include "Polygone.h"
#include "../Visiteur/Librairie/VisiteurDeLibrairie.h"
#include "../Visiteur/Sauvegarde/VisiteurDeSauvegarde.h"


Polygone::Polygone(const int couleur) : Forme(couleur) {}

Polygone::Polygone(vector<Vecteur2D *> points, const int couleur) : Forme(couleur) {
    _points = points;
}

Polygone::Polygone(const Polygone &p) : Forme(p.getCouleur()) {
    removeAllPoints();
    for (int i = 0; i < p.getNbPoints(); i++) {
        addPoint(*(p.getPoint(i)->clone()));
    }
}

Polygone *Polygone::clone() const {
    return new Polygone(*this);
}

Polygone::~Polygone() {
    removeAllPoints();
}

Vecteur2D Polygone::getMinXMinY() const {
    double minX = _points[0]->x , minY = _points[0]->y;

    for(int i = 0 ; i < _points.size() ; i++){
        if ( _points[i]->x < minX ) minX =_points[i]->x;
        if ( _points[i]->y < minY ) minY =_points[i]->y;
    }

    return Vecteur2D(minX,minY);
}

Vecteur2D Polygone::getMaxXMaxY() const {
    double maxX = _points[0]->x , maxY = _points[0]->y;

    for(int i = 0 ; i < _points.size() ; i++){
        if ( _points[i]->x > maxX ) maxX =_points[i]->x;
        if ( _points[i]->y > maxY ) maxY =_points[i]->y;
    }

    return Vecteur2D(maxX,maxY);
}

double Polygone::calculerAire() const {
    // Calcul de l'aire d'un polygone à partir de ses points
    double aire = 0.0;
    const int n = _points.size();

    // On considère le premier point comme point de référence
    Vecteur2D p0 = *_points[0];

    // On parcourt les côtés du polygone
    for (int i = 1; i < n - 1; ++i) {
        Vecteur2D p1 = *_points[i];
        Vecteur2D p2 = *_points[i + 1];

        // On calcule les longueurs des côtés du triangle formé par les trois points
        double a = (p1 - p0).norm();
        double b = (p2 - p1).norm();
        double c = (p2 - p0).norm();

        // On calcule le demi-périmètre
        double s = (a + b + c) / 2.0;

        // On applique la formule de Héron pour calculer l'aire du triangle
        aire += sqrt(s * (s - a) * (s - b) * (s - c));
    }
    return aire;
}

Vecteur2D Polygone::getCentreDeSymetrie() const {
    double x =  0 , y = 0;

    // On parcourt tous les points du polygone
    for (int i = 0; i < _points.size(); ++i)
    {
        // On additionne les coordonnées de tous les points
        x += _points[i]->x;
        y += _points[i]->y;
    }
    // On divise par le nombre de points pour obtenir la moyenne et donc le centre de symétrie
    return Vecteur2D(x/_points.size(),y/_points.size());
}

int Polygone::getNbPoints() const {
    return _points.size();
}

Vecteur2D* Polygone::getPoint(const int &i) const {
    return _points[i];
}

Polygone& Polygone::addPoint(const Vecteur2D &p) {
    _points.push_back(new Vecteur2D(p));
    return *this;
}

void Polygone::removePoint(const int &i) {
    delete _points[i];
}

void Polygone::removeAllPoints() {
    for (int i = 0; i < _points.size(); ++i) {
        delete _points[i];
    }
    _points.clear();
}

void Polygone::translation(const Vecteur2D &u) {
    for (int i = 0; i < _points.size(); i++)
    {
        *_points[i] = *_points[i] + u;
    }
}

void Polygone::homothetie(const Vecteur2D &u, const double &k) {
    for (int i = 0; i < _points.size(); i++)
    {
        *_points[i] =  ( *_points[i] - u )*k  + u ;
    }
}

void Polygone::rotation(const Vecteur2D &u, const double angle) {
    // On convertit l'angle en radians
    double m11 = cos(angle);
    double m21 = sin(angle);
    double m12 = -m21;
    double m22 = m11;
    // Le nom des variables est veut dire par exemple m11 est la valeur de la matrice de rotation en 1,1
    
    Matrices2x2 M(m11,m12,m21,m22); // On crée la matrice de rotation
    
    // On parcourt tous les points du polygone
    for (int i = 0; i < _points.size(); i++)
    {
        *_points[i] = M * ( *_points[i] - u ) + u ; // On applique la formule de rotation
    }
}

Polygone::operator string() const {
    ostringstream os;
    os << "Polygone [ ";
    int i;
    for ( i = 0; i < _points.size()-1; i++)
    {
        os << _points[i]->x << " , " << _points[i]->y << " , ";
    }
    os << _points[i]->x << " , " << _points[i]->y << " ] ";
    os << _couleur;
    return os.str();
}

/****************************************************************************************
 * Implementation des visiteurs
 ****************************************************************************************/

const void *Polygone::dessine(const VisiteurDeLibrairie *visiteur, SOCKET *s) const
{
    return visiteur->visite(this, s);
}

const void *Polygone::sauvegarde(const VisiteurDeSauvegarde *visiteur) const {
    return visiteur->visite(this);
}
