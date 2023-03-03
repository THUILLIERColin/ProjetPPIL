/**
 * @authors LEOST Maelan et THUILLIER Colin
 */

#include "Polygone.h"
#include "Cercle.h"
#include "Segment.h"
#include "Communication/InitCommunication.h"

int main(){

    /**************************************************************************
     *  Partie 1 : Les tests
     *************************************************************************/
    printf("Test sur le polygone\n");
    Polygone p(0x000000);
    p.addPoint(Vecteur2D(1,1));
    p.addPoint(Vecteur2D(1,2));
    p.addPoint(Vecteur2D(2,2));

    cout << p.calculerAire() << endl;
    cout << p.getCentreDeSymetrie() << endl;
    cout << p.getNbPoints() << endl;

    printf("\n");
    printf("test sur le Cercle\n");
    Cercle cercle(1, 2, 1, 0x000000);
    cout << cercle.calculerAire() << endl;
    cout << cercle.getCentreDeSymetrie() << endl;
    cout << cercle.getMinXMinY() << endl;
    cout << cercle.getMaxXMaxY() << endl;

    /**
    cout << cercle.translation(Vecteur2D(2,1)) << endl;
    cout << cercle.homothetie(Vecteur2D(2,1),5) << endl;
    cout << cercle.rotation(Vecteur2D(1,1),10) << endl;
    */
    printf("\n");
    printf("test sur le Segment\n");
    Segment segment(1, 1, 2,2, 0x000000);
    cout << segment.calculerAire() << endl;
    cout << segment.getCentreDeSymetrie() << endl;
    cout << segment.getMinXMinY() << endl;
    cout << segment.getMaxXMaxY() << endl;
    segment.translation(Vecteur2D(2,1));
    printf("test sur le Segment apres translation\n");
    cout << segment.getCentreDeSymetrie() << endl;
    cout << segment.getMinXMinY() << endl;
    cout << segment.getMaxXMaxY() << endl;
    printf("test sur le Segment apres homothetie\n");
    segment.homothetie(Vecteur2D(2,1),5);
    cout << segment.getCentreDeSymetrie() << endl;
    cout << segment.getMinXMinY() << endl;
    cout << segment.getMaxXMaxY() << endl;
    printf("test sur le Segment apres rotation\n");
    cout << segment.getCentreDeSymetrie() << endl;
    cout << segment.getMinXMinY() << endl;
    cout << segment.getMaxXMaxY() << endl;

    printf("\n");

    /**************************************************************************
     *  Partie 2 : Le réseau
     *************************************************************************/
    // Initialisation de la communication
    // prendre l'instance dans InitCommunication
    InitCommunication *initCommunication = InitCommunication::getInstance();


    return 0;
}