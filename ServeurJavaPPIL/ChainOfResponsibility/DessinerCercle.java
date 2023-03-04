package ChainOfResponsibility;

import Monde.Dessiner.Couple;
import Monde.Dessiner.FenetreDeDessin;
import Monde.Dessiner.GenererMonde;
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
    public boolean dessiner(String requete, FenetreDeDessin fenetreDeDessin, boolean diffFenetre, Vecteur2D Vmin, Vecteur2D Vmax) {
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

                // On donne la couleur au cercle
                fenetreDeDessin.graphics.setColor(Color.decode("#" + couleur));

                // On va convertir les coordonnees du cercle du monde vers le monde ecran
                Vecteur2D centre = new Vecteur2D(Xcentre,Ycentre);

                // On verifie si la figure est dans le groupe ou pas
                if(diffFenetre){
                    GenererMonde monde = new GenererMonde(Vmin, Vmax, new Vecteur2D(0,-fenetreDeDessin.HAUTEUR), new Vecteur2D(fenetreDeDessin.LARGEUR,0));

                    centre = monde.transforme(centre);

                    r = monde.convertirRayonDuCercle(centre,r,Vmin, Vmax );  // rayon converti en monde ecran


                }
                else {

                    Couple<Vecteur2D> p = GenererMonde.basGaucheHautDroitCercle(centre,r);

                    GenererMonde monde = new GenererMonde(
                            p.getPremier(),p.getDeuxieme(),
                            new Vecteur2D(0, fenetreDeDessin.HAUTEUR),
                            new Vecteur2D(fenetreDeDessin.LARGEUR,0));

                    // On convertit le rayon du cercle du monde vers le monde ecran
                    r = monde.convertirRayonDuCercle(centre,r,new Vecteur2D(centre.getX()-r,centre.getY()-r),
                            new Vecteur2D(centre.getX()+r,centre.getY()+r));

                    centre = monde.transforme(centre);

                }
                // On dessine le cercle
                fenetreDeDessin.graphics.drawOval((int)centre.getX(),(int)centre.getY(),r,r);
                System.out.println("Cercle [ " + centre.getX() + " , " + centre.getY() + " , " + r + " ] " + couleur );
                return true;
            }
        }
        return false;
    }
}
