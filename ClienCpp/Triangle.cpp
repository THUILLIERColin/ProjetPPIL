/**
 * @author THUILLIER Colin
 */

#include "Triangle.h"

Triangle::Triangle(const int couleur){
}

Triangle::Triangle(const Vecteur2D &a, const Vecteur2D &b, const Vecteur2D &c, const int couleur) {
    _a = a;
    _b = b;
    _c = c;
}

Triangle::Triangle(const Triangle &t) {
    _a = t._a;
    _b = t._b;
    _c = t._c;
}

Triangle *Triangle::clone() const {
    return new Triangle(*this);
}

Triangle::~Triangle() {

}

Vecteur2D Triangle::getMinXMinY() const {
    return Vecteur2D();
}

Vecteur2D Triangle::getMaxXMaxY() const {
    return Vecteur2D();
}

double Triangle::calculerAire() const {
    // Calcul de la base et de la hauteur du triangle
    double base = (_a - _b).norm();
    double hauteur = distancePointSegment(_c, _a, _b);

    // Calcul de l'aire du triangle
    return 0.5 * base * hauteur;
}

double Triangle::distancePointSegment(const Vecteur2D& p, const Vecteur2D& a, const Vecteur2D& b) {
    // Calcul du vecteur AB et du vecteur AP
    Vecteur2D ab = b - a;
    Vecteur2D ap = p - a;

    // Calcul du coefficient t tel que P soit sur la droite (AB)
    double t = ap.produitScalaire(ab) / ab.produitScalaire(ab);

    // Si t < 0, alors le point P est en dehors du segment et la distance minimale est PA
    if (t < 0.0) {
        return (p - a).norm();
    }
        // Si t > 1, alors le point P est en dehors du segment et la distance minimale est PB
    else if (t > 1.0) {
        return (p - b).norm();
    }
        // Sinon, le point P est sur le segment AB et la distance minimale est la distance entre P et la droite (AB)
    else {
        return (p - (a + t * ab)).norm();
    }
}


Vecteur2D Triangle::getCentreDeSymetrie() const {
    return Vecteur2D();
}

void Triangle::translation(const Vecteur2D &u) {
}

void Triangle::homothetie(const Vecteur2D &u, double k) {

}

void Triangle::rotation(const Vecteur2D &u, double angle) {
}

Vecteur2D Triangle::getA() const {
    return Vecteur2D();
}

Vecteur2D Triangle::getB() const {
    return Vecteur2D();
}

Vecteur2D Triangle::getC() const {
    return Vecteur2D();
}

void Triangle::setA(const Vecteur2D &a) {

}

void Triangle::setB(const Vecteur2D &b) {

}

void Triangle::setC(const Vecteur2D &c) {

}