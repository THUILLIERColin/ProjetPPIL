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

    /*

    cout << "****************************************************" << endl;
    cout << "                   LES TESTS                   "      << endl;
    cout << "****************************************************" << endl;

    cout << "\n\n" << endl;

    cout << "-----   Test des calculs sur un Segment  -----" << endl;
    Segment segment(1, 1, 2,2, 0xFF0000);
    cout << segment << endl;

    cout << "\t - Calcule de l'aire : " << segment.calculerAire() << endl;
    cout << "\t - Calcule du centre de symétrie : " << segment.getCentreDeSymetrie() << endl;
    cout << "\t - Calcule du point le plus à gauche et le plus en bas : " << segment.getMinXMinY() << endl;
    cout << "\t - Calcule du point le plus à droite et le plus en haut : " << segment.getMaxXMaxY() << endl;
    segment.translation(Vecteur2D(2,1));
    cout << "\tOn applique la translation (2,1) : " << segment << endl;

    cout << "\t - Calcule du centre de symétrie après translation : " << segment.getCentreDeSymetrie() << endl;
    cout << "\t - Calcule du point le plus à gauche et le plus en bas après translation : " << segment.getMinXMinY() << endl;
    cout << "\t - Calcule du point le plus à droite et le plus en haut après translation : " << segment.getMaxXMaxY() << endl;
    segment.homothetie(Vecteur2D(2,1),5);
    cout << "\tOn applique la homothétie (2,1) avec zoom de 5 : " << segment << endl;

    cout << "\t - Calcule du centre de symétrie après homothétie : " << segment.getCentreDeSymetrie() << endl;
    cout << "\t - Calcule du point le plus à gauche et le plus en bas après homothétie : " << segment.getMinXMinY() << endl;
    cout << "\t - Calcule du point le plus à droite et le plus en haut après homothétie : " << segment.getMaxXMaxY() << endl;
    segment.rotation(Vecteur2D(2,1),90);
    cout << "\tOn applique la rotation de 90° à partir des coordonées (2,1) : " << segment << endl;


    cout << "\t - Calcule du centre de symétrie après rotation : " << segment.getCentreDeSymetrie() << endl;
    cout << "\t - Calcule du point le plus à gauche et le plus en bas après rotation : " << segment.getMinXMinY() << endl;
    cout << "\t - Calcule du point le plus à droite et le plus en haut après rotation : " << segment.getMaxXMaxY() << endl;

    cout << "\n\n" << endl;
    cout << "-----   Test des calculs sur un Cercle  -----" << endl;
    Cercle cercle(1, 2, 1, 0x000000);
    cout << cercle << endl ;

    cout << "\t - Calcul de l'aire : " << cercle.calculerAire() << endl;
    cout << "\t - Calcul du centre de symétrie : " << cercle.getCentreDeSymetrie() << endl;
    cout << "\t - Calcul du point le plus à gauche et le plus en bas : " << cercle.getMinXMinY() << endl;
    cout << "\t - Calcul du point le plus à droite et le plus en haut : " << cercle.getMaxXMaxY() << endl;
    cercle.translation(Vecteur2D(2,1));
    cout << "\tOn applique la translation (2,1) : " << cercle << endl;

    cout << "\t - Calcul du centre de symétrie après translation : " << cercle.getCentreDeSymetrie() << endl;
    cout << "\t - Calcul du point le plus à gauche et le plus en bas après translation : " << cercle.getMinXMinY() << endl;
    cout << "\t - Calcul du point le plus à droite et le plus en haut après translation : " << cercle.getMaxXMaxY() << endl;
    cercle.homothetie(Vecteur2D(2,1),5);
    cout << "\tOn applique la homothétie (2,1) avec zoom de 5 : " << cercle << endl;

    cout << "\t - Calcul du centre de symétrie après homothétie : " << cercle.getCentreDeSymetrie() << endl;
    cout << "\t - Calcul du point le plus à gauche et le plus en bas après homothétie : " << cercle.getMinXMinY() << endl;
    cout << "\t - Calcul du point le plus à droite et le plus en haut après homothétie : " << cercle.getMaxXMaxY() << endl;

    cercle.rotation(Vecteur2D(2,1),90);
    cout << "\tOn applique la rotation de 90° à partir des coordonées (2,1) : " << cercle << endl;
    cout << "\t - Calcul du centre de symétrie après rotation : " << cercle.getCentreDeSymetrie() << endl;
    cout << "\t - Calcul du point le plus à gauche et le plus en bas après rotation : " << cercle.getMinXMinY() << endl;
    cout << "\t - Calcul du point le plus à droite et le plus en haut après rotation : " << cercle.getMaxXMaxY() << endl;

    cout << "\n\n" << endl;
    cout << "-----   Test des calculs sur un Polygone  -----" << endl;
    Polygone p((int) Couleur::ROUGE);
    p.addPoint(Vecteur2D(1,1));
    p.addPoint(Vecteur2D(1,2));
    p.addPoint(Vecteur2D(2,2));
    cout << p << endl;

    cout << "\t - Calcul de l'aire : " << p.calculerAire() << endl;
    cout << "\t - Calcul du centre de symétrie : " << p.getCentreDeSymetrie() << endl;
    cout << "\t - Nombre de points : " << p.getNbPoints() << endl;
    cout << "\t - Calcul du point le plus à gauche et le plus en bas : " << p.getMinXMinY() << endl;
    cout << "\t - Calcul du point le plus à droite et le plus en haut : " << p.getMaxXMaxY() << endl;
    p.translation(Vecteur2D(2,1));
    cout << "On applique la translation (2,1) : " << p << endl;
    cout << "\t - Calcul du centre de symétrie après translation : " << p.getCentreDeSymetrie() << endl;
    cout << "\t - Calcul du point le plus à gauche et le plus en bas après translation : " << p.getMinXMinY() << endl;
    cout << "\t - Calcul du point le plus à droite et le plus en haut après translation : " << p.getMaxXMaxY() << endl;
    p.homothetie(Vecteur2D(2,1),5);
    cout << "\tOn applique la homothétie (2,1) avec zoom de 5 : " << p << endl;
    cout << "\t - Calcul du centre de symétrie après homothétie : " << p.getCentreDeSymetrie() << endl;
    cout << "\t - Calcul du point le plus à gauche et le plus en bas après homothétie : " << p.getMinXMinY() << endl;
    cout << "\t - Calcul du point le plus à droite et le plus en haut après homothétie : " << p.getMaxXMaxY() << endl;
    p.rotation(Vecteur2D(2,1),90);
    cout << "\tOn applique la rotation de 90° à partir des coordonées (2,1) : " << p << endl;
    cout << "\t - Calcul du centre de symétrie après rotation : " << p.getCentreDeSymetrie() << endl;
    cout << "\t - Calcul du point le plus à gauche et le plus en bas après rotation : " << p.getMinXMinY() << endl;
    cout << "\t - Calcul du point le plus à droite et le plus en haut après rotation : " << p.getMaxXMaxY() << endl;

    cout << "\n\n" << endl;
    cout << "-----   Test des calculs sur ue forme complexe  -----" << endl;
    FormeComplexe formeComplexe(0xFF0000);
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

    cout << "\t - Calcul de l'aire : " << formeComplexe.calculerAire() << endl;
    cout << "\t - Calcul du centre de symétrie : " << formeComplexe.getCentreDeSymetrie() << endl;
    cout << "\t - Nombre de formes dans le groupe : " << formeComplexe.getNombreFormes() << endl;
    cout << "\t - Calcul du point le plus à gauche et le plus en bas : " << formeComplexe.getMinXMinY() << endl;
    formeComplexe.translation(Vecteur2D(2,1));
    cout << "On applique la translation (2,1) : " << formeComplexe << endl;
    cout << "\t - Calcul du centre de symétrie après translation : " << formeComplexe.getCentreDeSymetrie() << endl;
    cout << "\t - Calcul du point le plus à gauche et le plus en bas après translation : " << formeComplexe.getMinXMinY() << endl;
    formeComplexe.homothetie(Vecteur2D(2,1),5);
    cout << "\tOn applique la homothétie (2,1) avec zoom de 5 : " << formeComplexe << endl;
    cout << "\t - Calcul du centre de symétrie après homothétie : " << formeComplexe.getCentreDeSymetrie() << endl;
    cout << "\t - Calcul du point le plus à gauche et le plus en bas après homothétie : " << formeComplexe.getMinXMinY() << endl;
    formeComplexe.rotation(Vecteur2D(2,1),90);
    cout << "\tOn applique la rotation de 90° à partir des coordonées (2,1) : " << formeComplexe << endl;
    cout << "\t - Calcul du centre de symétrie après rotation : " << formeComplexe.getCentreDeSymetrie() << endl;
    cout << "\t - Calcul du point le plus à gauche et le plus en bas après rotation : " << formeComplexe.getMinXMinY() << endl;
    cout << "\n\n" << endl;

     */
    /**************************************************************************
     *  Partie 2 : Le réseau
     *************************************************************************/

    /*

     cout << "****************************************************" << endl;
     cout << "                   RESEAU                   "         << endl;
     cout << "****************************************************" << endl;
     try{
         InitCommunication::getInstance()->demarrerConnection(9111, "0.0.0.0");
         // On instancie les objets à envoyer
         Cercle cercleEnvoyee(300, 550, 50, 0x000000);
         Cercle cercleEnvoyee2(500, 550, 50, 0x000000);

         Polygone polygoneEnvoye(0x000000);
         polygoneEnvoye.addPoint(Vecteur2D(350,500));
         polygoneEnvoye.addPoint(Vecteur2D(450,500));
         polygoneEnvoye.addPoint(Vecteur2D(450,200));
         polygoneEnvoye.addPoint(Vecteur2D(350,200));

         Cercle cercleEnvoyee3(400, 200, 50, 0x000000);

         // On les veut sur la même fenetre alors on les met dans une forme complexe
         FormeComplexe formeComplexeEnvoyee(0xFF00FF);
         formeComplexeEnvoyee.ajouterForme(&cercleEnvoyee);
         formeComplexeEnvoyee.ajouterForme(&cercleEnvoyee2);
         formeComplexeEnvoyee.ajouterForme(&polygoneEnvoye);
         formeComplexeEnvoyee.ajouterForme(&cercleEnvoyee3);

         formeComplexeEnvoyee.dessine(new VisiteurDeLibrairieJava(), InitCommunication::getInstance()->getSocket());
         cout << "Requete envoyee : " << formeComplexeEnvoyee << endl;

         InitCommunication::getInstance()->deconnexion();
     }
     catch (Erreur e) {
         cout << e << endl;
     }
    cout << "\n\n" << endl;

     */

    /**************************************************************************
     *  Partie 3 : La sauvegarde
     *************************************************************************/

    /*
    cout << "\n\n" << endl;
    cout << "****************************************************" << endl;
    cout << "                   LA SAUVEGARDE                   "  << endl;
    cout << "****************************************************" << endl;
    cout << "\n\n" << endl;
    cout << "On sauvegarde les formes" << endl;

    // On sauvegarde le polygone
    p.sauvegarde(new VisiteurDeSauvegardeTxt);
    cercle.sauvegarde(new VisiteurDeSauvegardeTxt);
    segment.sauvegarde(new VisiteurDeSauvegardeTxt);
    formeComplexe.sauvegarde(new VisiteurDeSauvegardeTxt);
    cout << "\n\n" << endl;

    */
    /**************************************************************************
     *  Partie 4: Les test sur le COR
     *************************************************************************/
    /*

    cout << "\n\n" << endl;
    cout << "****************************************************" << endl;
    cout << "                   COR                   "         << endl;
    cout << "****************************************************" << endl;
    cout << "\n\n" << endl;
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
    cout << "------------  test sur le COR  segment  ------------" << endl;
    try{
        string texte = " Segment [ 1 , 1 , 2 , 2 ] ff0000";
        Forme* forme = expert->resoudre(texte);
        cout << " texte a parser : "<< texte << endl;
        cout << "on obtient : " << *forme << endl;

    }
    catch (Erreur e) {
        cout << e << endl;
    }

    cout << "\n\n" << endl;
    //test rapide sur le COR cercle
    cout << "------------  test sur le COR  cercle  ------------" << endl;
    try{
        string texte = "Cercle [ 1 , 2 , 1 ] ff0000";
        Forme* forme = expert->resoudre(texte);
        cout << " texte a parser : "<< texte << endl;
        cout << "on obtient : " << *forme << endl;

    }
    catch (Erreur e) {
        cout << e << endl;
    }

    cout << "\n\n" << endl;
    //test rapide sur le COR polygone
    cout << "------------  test sur le COR  polygone  ------------" << endl;
    try{
        string texte = " Polygone [ 1 , 1 , 1 , 2 , 2 , 2 ] ff0000";
        Forme* forme = expert->resoudre(texte);
        cout << " texte a parser : "<< texte << endl;
        cout << "on obtient : " << *forme << endl;

    }
    catch (Erreur e) {
        cout << "erreur" << endl;
    }

    cout << "\n\n" << endl;
    //test rapide sur le COR forme complexe
    cout << "------------  test sur le COR  formeComplexe  ------------" << endl;
    try{
        string texte = " FormeComplexe : { Cercle [ 1 , 2 , 1 ] 0 ; Segment [ 1 , 1 , 2 , 2 ] 0 ; Polygone [ 1 , 1 , 1 , 2 , 2 , 2 ] 0 } (0, 1) / (2, 3)";
        Forme* forme = expert->resoudre(texte);
        cout << " texte a parser : "<< texte << endl;
        cout << "on obtient : " << *forme << endl;

    }
    catch (Erreur e) {
        cout << e << endl;
    }

    cout << "\n\n" << endl;

    cout << "****************************************************" << endl;
    cout << "               TEST COR SUR FICHIER                 "<< endl;
    cout << "****************************************************" << endl;

    cout << "\n\n" << endl;
    cout << "On charge les formes : " << endl;
    cout << "\n\n" << endl;
    ifstream fichier("../Sauvegarde/sauvegarde.txt");
    vector<Forme*> vec_fractions = ChargeurListeForme::charge(fichier);
    for (unsigned int i = 0; i < vec_fractions.size(); i++) {
        cout << *vec_fractions[i] << endl;
    }

    cout << "\n\n" << endl;
    cout << "****************************************************" << endl;
    cout << "               FIN DES TESTS                 "<< endl;
    cout << "****************************************************" << endl;
    cout << "\n\n" << endl;
    */

    try{
        InitCommunication::getInstance()->demarrerConnection(9111, "0.0.0.0");

        cout << "Création d'un rectangle bleu" << endl;
        Polygone rectangle(0x0000FF);
        rectangle.addPoint(Vecteur2D(1, -1));
        rectangle.addPoint(Vecteur2D(5, -1));
        rectangle.addPoint(Vecteur2D(5, 1));
        rectangle.addPoint(Vecteur2D(1, 1));
        cout << "   - " << rectangle << endl;

        cout << "Création d'un triangle vert" << endl;
        Polygone triangle(0x00FF00);
        triangle.addPoint(Vecteur2D(6, -1));
        triangle.addPoint(Vecteur2D(8, 0));
        triangle.addPoint(Vecteur2D(6, 1));
        cout << "   - " << triangle << endl;

        cout << "Création d'un cercle jaune" << endl;
        Cercle cercle(11, 0, 2, 0xFFFF00);
        cout << "   - " << cercle << endl;

        cout << "On ajoute les formes précédentes dans un groupe\n" << endl;
        FormeComplexe groupe(0xFF0000);
        groupe.ajouterForme(&rectangle);
        groupe.ajouterForme(&triangle);
        groupe.ajouterForme(&cercle);

        cout << "On effectue des transformations sur le groupe" << endl;
        cout << " - On applique une translation de (1, 0)" << endl;
        groupe.translation(Vecteur2D(-1, 0));
        cout << " - On applique une rotation de 45°" << endl;
        groupe.rotation(Vecteur2D(0,0), M_PI/4);

        cout << "Calcul et affichage de l'aire du groupe" << endl;
        cout << "Aire du groupe : " << groupe.calculerAire() << "\n" << endl;

        cout << "On dessine le groupe\n" << endl;
        groupe.dessine(new VisiteurDeLibrairieJava(), InitCommunication::getInstance()->getSocket());

        cout << "Sauvegarde du groupe dans un fichier\n" << endl;
        groupe.sauvegarde(new VisiteurDeSauvegardeTxt);

        ifstream fichier("../Sauvegarde/mabellefigure1.txt");
        vector<Forme*> vec_fractions = ChargeurListeForme::charge(fichier);
        FormeComplexe groupe2 = *dynamic_cast<FormeComplexe*>(vec_fractions[0]);
        cout << "On dessine le groupe2" << endl;

        groupe2.dessine(new VisiteurDeLibrairieJava(), InitCommunication::getInstance()->getSocket());

        InitCommunication::getInstance()->deconnexion();

    }
    catch (Erreur e) {
        cout << e << endl;
    }

    return 0;
}