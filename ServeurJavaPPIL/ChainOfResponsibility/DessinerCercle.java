package ChainOfResponsibility;

import Monde.Dessiner.FenetreDeDessin;
import Monde.Vecteur2D;

import java.awt.*;

public class DessinerCercle extends ExpertDessiner{
    /**
     * Constructeur de l'expert de dessin
     *
     * @param suivant expert suivant
     */
    public DessinerCercle(Expert suivant) {
        super(suivant);
    }

    @Override
    public boolean dessiner(String requete, FenetreDeDessin cadreDeDessin, boolean memeFenetre, Vecteur2D Vmin, Vecteur2D Vmax) {
        if(requete.contains("Cercle"))
        {
            int crochetDeb = requete.indexOf("[");

            String type = requete.substring(0,crochetDeb);

            // On verifie que le type est bien Cercle et pas un Cercle d'une autre forme
            if(type.trim().contains("Cercle") && !type.trim().contains("FormeComplexe"))
            {

                // On recupere les coordonnees du centre du cercle
                int crochetFin = requete.indexOf("]");
                // On recupere les coordonnees du centre du cercle
                String coordonnees = requete.substring(crochetDeb+1,crochetFin).trim();
                // On recupere la couleur du cercle
                String couleur = requete.substring(crochetFin+1).trim();

                String[] coordonneesTab = coordonnees.split(",");

                // On recupere les coordonnees du centre du cercle et le rayon
                // Qu'on convertit en double
                double Xcentre = Double.parseDouble(coordonneesTab[0].trim());
                double Ycentre = Double.parseDouble(coordonneesTab[1].trim());
                double rayon = Double.parseDouble(coordonneesTab[2].trim());

                int x = (int)Xcentre;
                int y = (int)Ycentre;
                int r = (int)rayon;

                System.out.println("Cercle [ " + x + " , " + y + " , " + r + " ] " + couleur );

                /*
                // on affecte a la forme la couleur specifique
                cadreDeDessin.graphics.setColor(Color.decode("#" + Integer.toHexString(Integer.parseInt(couleur))));

                // debut de la tranformation monde ecran

                TransfoMondeEcran t;
                Vecteur2D centre = new Vecteur2D(Xcentre,Ycentre);

                // savoir si le message vient du groupe ou pas
                if(memeFenetre){

                    t = TransfoMondeEcran.creerTransfoMondeEcran(
                            Vmin, Vmax,
                            new Vecteur2D(0,-cadreDeDessin.HAUTEUR),
                            new Vecteur2D(cadreDeDessin.LARGEUR,0));

                    centre = t.transforme(centre);

                    r = t.convertirRayonDuCercle(centre,r,Vmin, Vmax );  // rayon converti en monde ecran


                }
                else {

                    Pair<Vecteur2D> p = TransfoMondeEcran.basGaucheHautDroitCercle(centre,r);

                    t = TransfoMondeEcran.creerTransfoMondeEcran(
                            p.getPremier(),p.getDeuxieme(),
                            new Vecteur2D(0, cadreDeDessin.HAUTEUR),
                            new Vecteur2D(cadreDeDessin.LARGEUR,0));

                    // on convertis le rayon du cercle en monde ecran
                    r = t.convertirRayonDuCercle(centre,r,new Vecteur2D(centre.getX()-r,centre.getY()-r),
                            new Vecteur2D(centre.getX()+r,centre.getY()+r));

                    centre = t.transforme(centre);

                }
                // fin de la tranformation monde ecran
                cadreDessin.graphics.fillOval((int)centre.getX(),(int)centre.getY(),r,r);*/

                return true;
            }
        }
        return false;
    }
}
