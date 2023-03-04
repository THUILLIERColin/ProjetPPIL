package Tests;

import ChainOfResponsibility.DessinerCercle;
import ChainOfResponsibility.DessinerFormeComplexe;
import ChainOfResponsibility.DessinerPolygone;
import ChainOfResponsibility.DessinerSegment;
import Monde.Dessiner.Couple;
import Monde.Dessiner.FenetreDeDessin;
import Monde.Dessiner.GenererMonde;
import Monde.Vecteur2D;

import java.awt.*;

public class TestDessin {
    public static void main(String[] args) {
        String requete = "Cercle [ 1 , 20 , 1 ] ff0000";

        try {
            FenetreDeDessin fenetreDeDessin = new FenetreDeDessin("Fenetre de dessin",0,0,FenetreDeDessin.LARGEUR, FenetreDeDessin.HAUTEUR);
            fenetreDeDessin.setResizable(false);

            Vecteur2D centre = new Vecteur2D(5,5);
            int rayon = 3;

            Couple<Vecteur2D> p = GenererMonde.basGaucheHautDroitCercle(centre,rayon);

            GenererMonde t = new GenererMonde(p.getPremier(),p.getDeuxieme(),
                    new Vecteur2D(0,FenetreDeDessin.HAUTEUR),new Vecteur2D(FenetreDeDessin.LARGEUR,0));

            int r = t.convertirRayonDuCercle(centre,rayon,new Vecteur2D(centre.getX()-rayon,centre.getY()-rayon),
                    new Vecteur2D(centre.getX()+rayon,centre.getY()+rayon));

            Vecteur2D c = t.transforme(centre);
            fenetreDeDessin.graphics.setColor(Color.black);
            fenetreDeDessin.graphics.drawOval((int)c.getX(),(int)c.getY(),r,r);
            System.out.println("x = "+centre.getX()+" y = "+centre.getY()+" r = "+rayon);
            System.out.println("x = "+c.getX()+" y ="+c.getY()+" r= "+r);
            fenetreDeDessin.getBufferStrategy().show();

            /*
            DessinerCercle dessinerCercle = new DessinerCercle(new DessinerPolygone(new DessinerSegment(new DessinerFormeComplexe(null))));

            dessinerCercle.envoieAuParseur(requete, fenetreDeDessin, false, null, null);*/
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
