#include "Vecteur2D.h"

const Vecteur2D* Vecteur2D::clone() const {
    return new Vecteur2D(*this);
}

double Vecteur2D::norm() const {
    return abs(sqrt(x*x + y*y));
}

double Vecteur2D::produitScalaire(const Vecteur2D & u) const {
    return x*u.x + y*u.y;
}

Vecteur2D::operator string() const
{
    ostringstream os;
    os << "(" << x <<", " << y << ")";
    return os.str();
}

ostream & operator << (ostream & os, const Vecteur2D & u)
{
    os << (string) u;
    return os;
}