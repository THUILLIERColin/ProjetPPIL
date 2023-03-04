package Tests;

import ChainOfResponsibility.DessinerCercle;
import ChainOfResponsibility.DessinerPolygone;
import ChainOfResponsibility.DessinerSegment;
import Monde.Dessiner.FenetreDeDessin;
import Monde.Vecteur2D;

public class TestExpert {
    public static void main(String[] args) throws InterruptedException {
        // Création d'un tableau de String
        String[] requetes = new String[3];
        String requete = "Cercle [ 1 , 2 , 1 ] 16711680";
        String requete2 = "Polygone [ 1 , 2 , 3 , 4 , 5 , 6 ] 16711680";
        String requete3 = "Segment [ 1 , 2 , 1 , 3 ] 16711680";

        requetes[0] = requete;
        requetes[1] = requete2;
        requetes[2] = requete3;

        DessinerCercle dessinerCercle = new DessinerCercle(new DessinerPolygone(new DessinerSegment(null)));
        for (String requete1 : requetes) {
            dessinerCercle.envoieAuParseur(requete1, null, false, null, null);
        }
    }
}
