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
     cout << "                   RESEAU                   "         << endl;
     cout << "****************************************************" << endl;
    Cercle cercleEnvoyee(300, 550, 50, 0x000000);
    Cercle cercleEnvoyee2(500, 550, 50, 0x000000);
    Polygone polygoneEnvoye(0x000000);
    polygoneEnvoye.addPoint(Vecteur2D(350,600));
    polygoneEnvoye.addPoint(Vecteur2D(450,650));
    polygoneEnvoye.addPoint(Vecteur2D(450,200));
    polygoneEnvoye.addPoint(Vecteur2D(350,200));
    Cercle cercleEnvoyee3(400, 200, 50, 0x000000);
    FormeComplexe formeComplexeEnvoyee(0xFF00FF);
    formeComplexeEnvoyee.ajouterForme(&cercleEnvoyee);
    formeComplexeEnvoyee.ajouterForme(&cercleEnvoyee2);
    formeComplexeEnvoyee.ajouterForme(&polygoneEnvoye);
    formeComplexeEnvoyee.ajouterForme(&cercleEnvoyee3);
     try{
         InitCommunication::getInstance()->demarrerConnection(9111, "0.0.0.0");
         // On attend que le client se connecte

         formeComplexeEnvoyee.dessine(new VisiteurDeLibrairieJava(), InitCommunication::getInstance()->getSocket());

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

    ExpertChargementCOR* expertSegment; // expert du DP COR
    ExpertChargementCOR* expertCercle;
    ExpertChargementCOR* expertPolygone;
    ExpertChargementCOR* expertFormeComplexe;

    expertSegment = new ExpertChargementSegmentCOR(NULL);
    expertPolygone = new ExpertChargementPolygoneCOR(expertSegment);
    expertCercle = new ExpertChargementCercleCOR(expertPolygone);
    expertFormeComplexe = new ExpertChargementFormeComplexeCOR(expertCercle);

    ExpertChargement* expert = expertFormeComplexe;

    //test rapide sur le COR segment
    printf("********************test sur le COR  segment********************\n");
    try{
        string texte = " Segment [ 1 , 1 , 2 , 2 ] ff0000";
        Forme* forme = expert->resoudre(texte);
        cout << " texte a parser : "<< texte <<"\n on obtient  "<<*forme << endl;

    }
    catch (Erreur e) {
        cout << "erreur" << endl;
    }
    //test rapide sur le COR cercle
    printf("\n********************test sur le COR  cerlce********************\n");
    try{
        string texte = "Cercle [ 1 , 2 , 1 ] ff0000";
        Forme* forme2 = expert->resoudre(texte);
        cout << " texte a parser : "<< texte <<"\n on obtient   "<<*forme2 << endl;

    }
    catch (Erreur e) {
        cout << "erreur" << endl;
    }

    //test rapide sur le COR polygone
    printf("\n********************test sur le COR  polygone********************\n");
    try{
        string texte = " Polygone [ 1 , 1 , 1 , 2 , 2 , 2 ] ff0000";
        Forme* forme3 = expert->resoudre(texte);
        cout << " texte a parser : "<< texte <<"\n on obtient  "<<*forme3 << endl;

    }
    catch (Erreur e) {
        cout << "erreur" << endl;
    }

    //test rapide sur le COR
    printf("\n********************test sur le COR  forme complexe********************\n");
    try{
        string texte = " FormeComplexe : { Cercle [ 1 , 2 , 1 ] 0 ; Segment [ 1 , 1 , 2 , 2 ] 0 ; Polygone [ 1 , 1 , 1 , 2 , 2 , 2 ] 0 } (0, 1) / (2, 3)";
        Forme* forme4 = expert->resoudre(texte);
        cout << " texte a parser : "<< texte <<"\n on obtient   "<<*forme4 << endl;

    }
    catch (Erreur e) {
        cout << "erreur" << endl;
    }
    
    /**************************************************************************
    *  FIN
    *************************************************************************/
    return 0;
}