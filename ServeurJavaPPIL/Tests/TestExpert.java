package Tests;

import ChainOfResponsibility.DessinerCercle;
import ChainOfResponsibility.DessinerPolygone;
import ChainOfResponsibility.DessinerSegment;
import ChainOfResponsibility.DessinerFormeComplexe;
import Monde.Dessiner.FenetreDeDessin;
import Monde.Vecteur2D;

public class TestExpert {
    public static void main(String[] args) throws InterruptedException {
        // Création d'un tableau de String
        String[] requetes = new String[4];

        String requete = "Cercle [ 1 , 2 , 1 ] ff0000";
        String requete2 = "Polygone [ 1 , 1 , 1 , 2 , 2 , 2 ] ff0000";
        String requete3 = "Segment [ 1 , 1 , 2 , 2 ] ff0000";
        String requete4 = "FormeComplexe : { Cercle [ 1 , 2 , 1 ] 0 ; Segment [ 1 , 1 , 2 , 2 ] 0 ; Polygone [ 1 , 1 , 1 , 2 , 2 , 2 ] 0 } (0 ,1) / (2 ,3)";


        requetes[0] = requete;
        requetes[1] = requete2;
        requetes[2] = requete3;
        requetes[3] = requete4;

        DessinerCercle dessinerCercle = new DessinerCercle(new DessinerPolygone(new DessinerSegment(new DessinerFormeComplexe(null))));
        for (String requete1 : requetes) {
            dessinerCercle.envoieAuParseur(requete1, null, false, null, null);
        }
    }
}
