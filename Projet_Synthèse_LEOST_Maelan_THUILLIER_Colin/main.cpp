#include <iostream>
#include "Vecteur2D.h"

#include "Cercle.h"
#include "Constante.h"
#include "Erreur.h"
#include "Groupe.h"
#include "Forme.h"
#include "Matrices2x2.h"
#include "Segment.h"
#include "Triangle.h"

#include "Polygone.h"


int main(){
    Polygone p(0xFFFFFF);
    Vecteur2D v1(1,2);
    Vecteur2D v2(3,4);
    Vecteur2D v3(5,6);
    Vecteur2D v4(7,8);
    p.addPoint(v1);
    p.addPoint(v2);
    p.addPoint(v3);
    p.addPoint(v4);
    cout << p << endl;

    p.homothetie(Vecteur2D(0,0),2);
    cout << p << endl;
    return 0;
}