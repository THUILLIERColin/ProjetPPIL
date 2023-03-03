/**
 * @author Thuillier Colin
 */

#include "Polygone.h"

Polygone::Polygone(const int couleur) {
    _couleur = couleur;
}

Polygone::Polygone(vector<Vecteur2D *> points, const int couleur) {
    _points = points;
    _couleur = couleur;
}

Polygone::Polygone(const Polygone &p) {
    removeAllPoints();

    _points = p._points;
    _couleur = p._couleur;
}

Polygone *Polygone::clone() const {
    return new Polygone(*this);
}

Polygone::~Polygone() {
    removeAllPoints();
}

Vecteur2D Polygone::getMinXMinY() const {
    return Vecteur2D();
}

Vecteur2D Polygone::getMaxXMaxY() const {
    return Vecteur2D();
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
    return Vecteur2D();
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
    return;
}

Polygone::operator string() const {
    ostringstream os;
    os << "Polygone ( ";
    int i;
    for ( i = 0; i < _points.size()-1; i++)
    {
        os << _points[i]->x << " , " << _points[i]->y << " , ";
    }
    os << _points[i]->x << " , " << _points[i]->y;
    os << " ) " << _couleur;
    return os.str();
}
