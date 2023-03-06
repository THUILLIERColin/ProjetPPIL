package Tests;

import ChainOfResponsibility.DessinerCercle;
import ChainOfResponsibility.DessinerPolygone;
import ChainOfResponsibility.DessinerSegment;
import ChainOfResponsibility.DessinerFormeComplexe;
import Monde.Dessiner.FenetreDeDessin;

public class TestExpert {
    public static void main(String[] args) throws InterruptedException {
        // Création d'un tableau de String
        String[] requetes = new String[3];


        requetes[0] = "Cercle [ 300, 550, 50 ] ffffff";
        requetes[1] = "Cercle [ 500, 550, 50 ] ff0000";
        requetes[2] = "Polygone [ 350, 600, 450, 650, 450, 200 ] ff0000";

        String requete ="FormeComplexe : { " + requetes[0] + " ; " + requetes[1] + " ; " + requetes[2] + " } ( 0 , 0 ) / ( 1000 , 1000 )";

        //String requete4 = "FormeComplexe : { Cercle [ 300, 550, 50 ] ff0000 ; Cercle [ 500, 550, 50 ] ff0000 ; Polygone [ 350, 600, 450, 650, 450, 200 ] ff0000 } (0 ,1) / (2 ,3)";

        try {
            FenetreDeDessin fenetreDeDessin = new FenetreDeDessin("Fenetre de dessin",60,60,FenetreDeDessin.LARGEUR, FenetreDeDessin.HAUTEUR);

            DessinerCercle dessinerCercle = new DessinerCercle(new DessinerPolygone(new DessinerSegment(new DessinerFormeComplexe(null))));
            for (String requete1 : requetes) {
                dessinerCercle.envoieAuParseur(requete1, fenetreDeDessin, false, null, null);
            }
            fenetreDeDessin.strategy.show();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
