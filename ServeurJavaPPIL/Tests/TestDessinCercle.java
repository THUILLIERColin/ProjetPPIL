package Tests;

import ChainOfResponsibility.DessinerCercle;
import ChainOfResponsibility.DessinerFormeComplexe;
import ChainOfResponsibility.DessinerPolygone;
import ChainOfResponsibility.DessinerSegment;
import Monde.Dessiner.FenetreDeDessin;

public class TestDessinCercle {
    public static void main(String[] args) throws InterruptedException {
        FenetreDeDessin fenetreDeDessin = new FenetreDeDessin("Fenetre de dessin",0,0,FenetreDeDessin.LARGEUR, FenetreDeDessin.HAUTEUR);

        DessinerCercle dessinerCercle = new DessinerCercle(new DessinerPolygone(new DessinerSegment(new DessinerFormeComplexe(null))));
        String requete = "Cercle [ 1 , 20 , 1 ] ff0000";
        dessinerCercle.envoieAuParseur(requete, fenetreDeDessin, false, null, null);
        fenetreDeDessin.getBufferStrategy().show();
    }
}
