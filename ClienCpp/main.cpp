/**
 * @authors LEOST Maelan et THUILLIER Colin
 */

#include "Formes/Polygone.h"
#include "Formes/Cercle.h"
#include "Formes/Segment.h"
#include "Formes/Couleur.h"
#include "Visiteur/Sauvegarde/VisiteurDeSauvegardeTxt.h"
#include "Visiteur/Librairie/VisiteurDeLibrairieJava.h"
#include "Communication/InitCommunication.h"
#include "Formes/FormeComplexe.h"
#include "COR/ExpertChargementCOR.h"
#include "COR/ChargeurListeForme.h"

int main(){

    /**************************************************************************
     *  Partie 1 :                   Les tests
     *************************************************************************/
    printf("****************************************************\n                   TESTS                   \n****************************************************\n\n\n");


    printf("********************test sur le segment********************\n");
    Segment segment(1, 1, 2,2, 0xFF0000);
    cout << segment << endl;

    cout << segment.calculerAire() << endl;
    cout << segment.getCentreDeSymetrie() << endl;
    cout << segment.getMinXMinY() << endl;
    cout << segment.getMaxXMaxY() << endl;
    segment.translation(Vecteur2D(2,1));
    printf("\ntest sur le Segment apres translation\n");
    cout << segment.getCentreDeSymetrie() << endl;
    cout << segment.getMinXMinY() << endl;
    cout << segment.getMaxXMaxY() << endl;
    printf("\ntest sur le Segment apres homothetie\n");
    segment.homothetie(Vecteur2D(2,1),5);
    cout << segment.getCentreDeSymetrie() << endl;
    cout << segment.getMinXMinY() << endl;
    cout << segment.getMaxXMaxY() << endl;
    printf("\ntest sur le Segment apres rotation\n");
    cout << segment.getCentreDeSymetrie() << endl;
    cout << segment.getMinXMinY() << endl;
    cout << segment.getMaxXMaxY() << endl;

    printf("\n");

    //test cercle
    printf("\n");
    printf("********************test sur le Cercle********************\n");
    Cercle cercle(1, 2, 1, 0x000000);
    cout << cercle.calculerAire() << endl;
    cout << cercle.getCentreDeSymetrie() << endl;
    cout << cercle.getMinXMinY() << endl;
    cout << cercle.getMaxXMaxY() << endl;
    cout << cercle << endl ;
    //test transaltion
    cercle.translation(Vecteur2D(2,1));
    printf("\ntest sur le Cercle apres translation\n");
    cout << cercle.getCentreDeSymetrie() << endl;
    cout << cercle.getMinXMinY() << endl;
    cout << cercle.getMaxXMaxY() << endl;
    //test homothetie
    printf("\ntest sur le Cercle apres homothetie\n");
    cercle.homothetie(Vecteur2D(2,1),5);
    cout << cercle.getCentreDeSymetrie() << endl;
    cout << cercle.getMinXMinY() << endl;
    cout << cercle.getMaxXMaxY() << endl;
    //test rotation
    printf("\ntest sur le Cercle apres rotation\n");
    cercle.rotation(Vecteur2D(2,1),90);
    cout << cercle.getCentreDeSymetrie() << endl;
    cout << cercle.getMinXMinY() << endl;
    cout << cercle.getMaxXMaxY() << endl;

    //on fait la meme pour un polygone
    printf("\n");
    printf("********************test sur le polygone********************\n");
    Polygone p((int) Couleur::ROUGE); // il faudra la retransformer en hexa
    cout << "Couleur du polygone (int) : " << p.getCouleur() << endl;
    cout << "Couleur du polygone (hexa) : " << std::hex << p.getCouleur() << endl;
    p.addPoint(Vecteur2D(1,1));
    p.addPoint(Vecteur2D(1,2));
    p.addPoint(Vecteur2D(2,2));

    cout << p.calculerAire() << endl;
    cout << p.getCentreDeSymetrie() << endl;
    cout << p.getNbPoints() << endl;
    cout << p << endl;
    //test transaltion
    p.translation(Vecteur2D(2,1));
    printf("\ntest sur le polygone apres translation\n");
    cout << p.getCentreDeSymetrie() << endl;
    cout << p.getMinXMinY() << endl;
    cout << p.getMaxXMaxY() << endl;
    //test homothetie
    printf("\ntest sur le polygone apres homothetie\n");
    p.homothetie(Vecteur2D(2,1),5);
    cout << p.getCentreDeSymetrie() << endl;
    cout << p.getMinXMinY() << endl;
    cout << p.getMaxXMaxY() << endl;
    //test rotation
    printf("\ntest sur le polygone apres rotation\n");
    p.rotation(Vecteur2D(2,1),90);
    cout << p.getCentreDeSymetrie() << endl;
    cout << p.getMinXMinY() << endl;
    cout << p.getMaxXMaxY() << endl;

    //on fait un essai de forme complexe
    printf("\n");
    printf("********************test sur la forme complexe********************\n");
    FormeComplexe formeComplexe(0x000000);
    Polygone p2((int) Couleur::ROUGE);
    p2.addPoint(Vecteur2D(1,1));
    p2.addPoint(Vecteur2D(1,2));
    p2.addPoint(Vecteur2D(2,2));
    Segment segment2(1, 1, 2,2, 0xFF0000);
    Cercle cercle2(1, 2, 1, 0x000000);
    formeComplexe.ajouterForme(&cercle2);
    formeComplexe.ajouterForme(&segment2);
    formeComplexe.ajouterForme(&p2);
    cout << formeComplexe << endl;
    printf("\n");

    /**************************************************************************
     *  Partie 2 : Le réseau
     *************************************************************************/

     cout << "****************************************************" << endl;
     cout << "                   RESEAU                   " << endl;
     cout << "****************************************************" << endl;
     try{
         InitCommunication::getInstance()->demarrerConnection(9111, "0.0.0.0");
         // On attend que le client se connecte
         cercle.dessine(new VisiteurDeLibrairieJava(), InitCommunication::getInstance()->getSocket());
         segment.dessine(new VisiteurDeLibrairieJava(), InitCommunication::getInstance()->getSocket());
         formeComplexe.dessine(new VisiteurDeLibrairieJava(), InitCommunication::getInstance()->getSocket());
         InitCommunication::getInstance()->deconnexion();
     }
     catch (Erreur e) {
         cout << e << endl;
     }



    /**************************************************************************
     *  Partie 3 : La sauvegarde
     *************************************************************************/

    printf("****************************************************\n                   TESTS SAUVEGARDE                   \n****************************************************\n\n\n");

     cout << "On sauvegarde les formes" << endl;

    // On sauvegarde le polygone
    p.sauvegarde(new VisiteurDeSauvegardeTxt);
    cercle.sauvegarde(new VisiteurDeSauvegardeTxt);
    segment.sauvegarde(new VisiteurDeSauvegardeTxt);
    formeComplexe.sauvegarde(new VisiteurDeSauvegardeTxt);



    /**************************************************************************
     *  Partie 4: Les test sur le COR
     *************************************************************************/
    printf("****************************************************\n                   TESTS COR                   \n****************************************************\n\n\n");
    ExpertChargementCOR* expert; // expert du DP COR
    expert = new ExpertChargementSegmentCOR(NULL);
    expert = new ExpertChargementPolygoneCOR(expert);
    expert = new ExpertChargementCercleCOR(expert);
    expert = new ExpertChargementFormeComplexeCOR(expert);

    //test segment
    printf("********************test sur le COR  segment********************\n");
    Segment segmentCOR(1, 1, 2,2, 0xFF0000);
    cout << segmentCOR << endl;
    ifstream fichier("COR/FichiersTest/TestCORSegment.txt");
    vector<Forme*> formesegment = ChargeurListeForme::charge(fichier);
    for (Forme* f : formesegment){
        cout << *f << endl;
    }

    //test cercle
    printf("\n");
    printf("********************test sur le COR  cerlce********************\n");
    Cercle cercleCOR(1, 2, 1, 0xFF0000);
    cout <<cercleCOR << endl;
    ifstream fichier2("COR/FichiersTest/TestCORCercle.txt");
    vector<Forme*> formecercle = ChargeurListeForme::charge(fichier2);
    for (Forme* f : formecercle){
        cout << *f << endl;
    }

    //test polygone
    printf("\n");
    printf("********************test sur le COR  polygone********************\n");
    Polygone polygoneCOR(0xFF0000);
    polygoneCOR.addPoint(Vecteur2D(1,1));
    polygoneCOR.addPoint(Vecteur2D(1,2));
    polygoneCOR.addPoint(Vecteur2D(2,2));
    cout << polygoneCOR << endl;
    ifstream fichier3("COR/FichiersTest/TestCORPolygone.txt");
    vector<Forme*> formepolygone = ChargeurListeForme::charge(fichier3); //on charge le polygone
    for (Forme* f : formepolygone) // on affiche le polygone
    {
        cout << *f << endl; // on affiche le polygone
    }

    //test forme complexe
    printf("\n");
    printf("********************test sur le COR  forme complexe********************\n");
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

    /**************************************************************************
    *  FIN
    *************************************************************************/
    return 0;
}