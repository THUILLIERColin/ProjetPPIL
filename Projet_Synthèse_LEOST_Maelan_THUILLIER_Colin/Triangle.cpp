#include "Triangle.h"

/**
 * @author Thuillier Colin
 */

#include "Triangle.h"

Triangle::Triangle(const int couleur) : Polygone(couleur) {
}

Triangle::Triangle(const Vecteur2D &a, const Vecteur2D &b, const Vecteur2D &c, const int couleur) : Polygone(couleur) {
    _a = a;
    _b = b;
    _c = c;
}

Triangle::Triangle(const Triangle &t) : {
    _a = t._a;
    _b = t._b;
    _c = t._c;
}

Triangle *Triangle::clone() const {
    return Polygone::clone();
}

Triangle::~Triangle() {

}

Vecteur2D Triangle::getMinXMinY() const {
    return Polygone::getMinXMinY();
}

Vecteur2D Triangle::getMaxXMaxY() const {
    return Polygone::getMaxXMaxY();
}

double Triangle::calculerAire() const {
    return Polygone::calculerAire();
}

Vecteur2D Triangle::getCentreDeSymetrie() const {
    return Polygone::getCentreDeSymetrie();
}

void Triangle::translation(const Vecteur2D &u) {
    Polygone::translation(u);
}

void Triangle::homothetie(const Vecteur2D &u, double k) {

}

void Triangle::rotation(const Vecteur2D &u, double angle) {
    Polygone::rotation(u, angle);
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