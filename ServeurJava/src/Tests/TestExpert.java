package Tests;

import ChainOfResponsibility.DessinerCercle;
import ChainOfResponsibility.DessinerFormeComplexe;
import ChainOfResponsibility.DessinerPolygone;
import ChainOfResponsibility.DessinerSegment;
import Monde.Dessiner.FenetreDeDessin;

public class TestExpert {
    public static void main(String[] args) throws InterruptedException {
        // Création d'un tableau de String
        String[] requetes = new String[3];

        String requete = "Cercle [ 1 , 2 , 1 ] ffffff";
        String requete2 = "Polygone [ 1 , 1 , 1 , 2 , 2 , 2 ] ff0000";
        String requete3 = "Segment [ 1 , 1 , 2 , 2 ] ff0000";
        //String requete4 = "FormeComplexe : { Cercle [ 1 , 2 , 1 ] ff3f9f ; Segment [ 1 , 1 , 2 , 2 ] ff0f00 ; Polygone [ 1 , 1 , 1 , 2 , 2 , 2 ] fffff5 } (0 ,1) / (2 ,3)";


        requetes[0] = requete;
        requetes[1] = requete2;
        requetes[2] = requete3;
        //requetes[3] = requete4;

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
