/**
 * @authors LEOST Maelan et THUILLIER Colin
 */

#include "Formes/Polygone.h"
#include "Formes/Cercle.h"
#include "Formes/Segment.h"
#include "Formes/Couleur.h"
#include "Visiteur/Sauvegarde/VisiteurDeSauvegardeTxt.h"
#include "Communication/InitCommunication.h"
#include "Formes/FormeComplexe.h"
#include "COR/ExpertChargementCOR.h"
#include "COR/ChargeurListeForme.h"

int main(){

    /**************************************************************************
     *  Partie 1 : Les tests
     *************************************************************************/

    printf("Test sur le polygone\n");
    Polygone p((int) Couleur::ROUGE); // il faudra la retransformer en hexa
    cout << "Couleur du polygone (int) : " << p.getCouleur() << endl;
    cout << "Couleur du polygone (hexa) : " << std::hex << p.getCouleur() << endl;
    p.addPoint(Vecteur2D(1,1));
    p.addPoint(Vecteur2D(1,2));
    p.addPoint(Vecteur2D(2,2));

    cout << p.calculerAire() << endl;
    cout << p.getCentreDeSymetrie() << endl;
    cout << p.getNbPoints() << endl;


    printf("\n");
    printf("test sur le segment\n");
    Segment segment(1, 1, 2,2, 0xFF0000);
    cout << segment << endl;

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

    //test cercle
    printf("\n");
    printf("test sur le Cercle\n");
    Cercle cercle(1, 2, 1, 0x000000);
    cout << cercle.calculerAire() << endl;
    cout << cercle.getCentreDeSymetrie() << endl;
    cout << cercle.getMinXMinY() << endl;
    cout << cercle.getMaxXMaxY() << endl;
    cout << cercle << endl ;

    //on fait la meme pour un polygone
    printf("\n");
    printf("test sur le polygone\n");
    Polygone p2(0xFF0000);
    p2.addPoint(Vecteur2D(1,1));
    p2.addPoint(Vecteur2D(1,2));
    p2.addPoint(Vecteur2D(2,2));
    cout << p2 << endl;

    //on fait un essai de forme complexe
    printf("\n");
    printf("test sur la forme complexe\n");
    FormeComplexe formeComplexe(0x000000);
    formeComplexe.ajouterForme(&cercle);
    formeComplexe.ajouterForme(&segment);
    formeComplexe.ajouterForme(&p);
    cout << formeComplexe << endl;


    /**************************************************************************
     *  Partie 2 : Le réseau
     *************************************************************************/
     /**
    // Initialisation de la communication
    // prendre l'instance dans InitCommunication
    InitCommunication *initCommunication = InitCommunication::getInstance();
      */


    /**************************************************************************
     *  Partie 3 : La sauvegarde
     *************************************************************************/
    /**

     cout << "On sauvegarde les formes" << endl;

    // On sauvegarde le polygone
    p.sauvegarde(new VisiteurDeSauvegardeTxt);
    cercle.sauvegarde(new VisiteurDeSauvegardeTxt);
    segment.sauvegarde(new VisiteurDeSauvegardeTxt);
    formeComplexe.sauvegarde(new VisiteurDeSauvegardeTxt);

     */

    /**************************************************************************
     *  Partie 4: Les test sur le COR
     *************************************************************************/
    printf("*************test sur le COR***********");
    //test segment
    ExpertChargementCOR* expertSuivant ;
    printf("\n");
    printf("test sur le COR  segment\n");
    Segment segmentCOR(1, 1, 2,2, 0xFF0000);
    cout << segmentCOR << endl;
    ifstream fichier("COR/FichiersTest/TestCORSegment.txt");
    vector<Forme*> formesegment = ChargeurListeForme::charge(fichier);
    for (Forme* f : formesegment){
        cout << *f << endl;
    }

    //test cercle
    printf("\n");
    printf("test sur le COR  cerlce\n");
    Cercle cercleCOR(1, 2, 1, 0xFF0000);
    cout <<cercleCOR << endl;
    ifstream fichier2("COR/FichiersTest/TestCORCercle.txt");
    vector<Forme*> formecercle = ChargeurListeForme::charge(fichier2);
    for (Forme* f : formecercle){
        cout << *f << endl;
    }

    //test polygone
    printf("\n");
    printf("test sur le COR  polygone\n");
    Polygone polygoneCOR(0xFF0000);
    polygoneCOR.addPoint(Vecteur2D(1,1));
    polygoneCOR.addPoint(Vecteur2D(1,2));
    polygoneCOR.addPoint(Vecteur2D(2,2));
    cout << polygoneCOR << endl;
    ifstream fichier3("COR/FichiersTest/TestCORPolygone.txt");
    vector<Forme*> formepolygone = ChargeurListeForme::charge(fichier3);
    for (Forme* f : formepolygone){
        cout << *f << endl;
    }

    //test forme complexe
    printf("\n");
    printf("test sur le COR  forme complexe\n");
    FormeComplexe formeComplexeCOR(0x000000);
    formeComplexeCOR.ajouterForme(&cercleCOR);
    formeComplexeCOR.ajouterForme(&segmentCOR);
    formeComplexeCOR.ajouterForme(&polygoneCOR);
    cout << formeComplexeCOR << endl;
    ifstream fichier4("COR/FichiersTest/TestCORFormeComplexe.txt");
    vector<Forme*> formecomplexe = ChargeurListeForme::charge(fichier4);
    for (Forme* f : formecomplexe){
        cout << *f << endl;
    }

    return 0;
}