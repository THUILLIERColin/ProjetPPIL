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
    // Il faut faire la création d'un triangle
    Triangle triangle;
    if (_points.size() < 3)
    {
        return 0;
    }
    else
    {
        double aire = 0;
        for (int i = 0; i < _points.size()-2; ++i)
        {
            Vecteur2D a = *_points[0];
            Vecteur2D b = *_points[i+1];
            Vecteur2D c = *_points[i+2];
            triangle = Triangle(a,b,c);
            aire += triangle.calculerAire();
        }
        return aire;
    }
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

int Polygone::translation(const Vecteur2D &u) {
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
