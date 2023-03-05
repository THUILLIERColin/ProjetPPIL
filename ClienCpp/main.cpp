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

int main(){

    /**************************************************************************
     *  Partie 1 : Les tests
     *************************************************************************/
     /*
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
    printf("test sur le Cercle\n");
    Cercle cercle(1, 2, 1, 0x000000);
    cout << cercle.calculerAire() << endl;
    cout << cercle.getCentreDeSymetrie() << endl;
    cout << cercle.getMinXMinY() << endl;
    cout << cercle.getMaxXMaxY() << endl;

    cercle.translation(Vecteur2D(2,1));

    printf("\n");
    */
    printf("test sur le segment\n");
    Segment segment(1, 1, 2,2, 0xFF0000);
    cout << segment << endl;
    //on fait la meme pour un cercle
    Cercle cercle(1, 2, 1, 0xFF0000);
    cout << cercle << endl;
    //on fait la meme pour un polygone
    Polygone p(0xFF0000);
    p.addPoint(Vecteur2D(1,1));
    p.addPoint(Vecteur2D(1,2));
    p.addPoint(Vecteur2D(2,2));
    cout << p << endl;
    //on fait un essai de forme complexe
    FormeComplexe formeComplexe(0x000000);
    formeComplexe.ajouterForme(&cercle);
    formeComplexe.ajouterForme(&segment);
    formeComplexe.ajouterForme(&p);
    cout << formeComplexe << endl;
    /*
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
*/
    /**************************************************************************
     *  Partie 2 : Le réseau
     *************************************************************************/
     /*
    // Initialisation de la communication
    // prendre l'instance dans InitCommunication
     */
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
    /*

     cout << "On sauvegarde les formes" << endl;

    // On sauvegarde le polygone
    p.sauvegarde(new VisiteurDeSauvegardeTxt);
    cercle.sauvegarde(new VisiteurDeSauvegardeTxt);
    segment.sauvegarde(new VisiteurDeSauvegardeTxt);
    formeComplexe.sauvegarde(new VisiteurDeSauvegardeTxt);

     */

    return 0;
}