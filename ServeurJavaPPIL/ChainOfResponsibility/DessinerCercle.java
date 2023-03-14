package ChainOfResponsibility;

import Monde.Dessiner.Couple;
import Monde.Dessiner.FenetreDeDessin;
import Monde.Dessiner.OperationMonde;
import Monde.Vecteur2D;

import java.awt.*;

public class DessinerCercle extends ExpertDessiner{
    /**
     * Constructeur de l'expert de dessin
     * @param suivant expert suivant
     */
    public DessinerCercle(Expert suivant) {
        super(suivant);
    }

    @Override
    public boolean dessiner(String requete, FenetreDeDessin fenetreDeDessin, boolean memeFenetre, Vecteur2D Vmin, Vecteur2D Vmax) {
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

                // On va stocke les coordonnees du centre du cercle dans un vecteur2D
                Vecteur2D centre = new Vecteur2D(Xcentre,Ycentre);


                /* ***********************************************
                 * On gère la transformation en monde ecran
                 * ***********************************************/

                // On donne la couleur au cercle
                fenetreDeDessin.graphics.setColor(Color.decode("#" + couleur));

                // On verifie si la figure est dans le groupe ou pas
                if(memeFenetre){
                    // On cree le monde ecran
                    OperationMonde monde = new OperationMonde(Vmin, Vmax, new Vecteur2D(0,-fenetreDeDessin.HAUTEUR), new Vecteur2D(fenetreDeDessin.LARGEUR,0));

                    centre = monde.transforme(centre);

                    // On convertit le rayon du cercle vers le monde ecran du groupe
                    r = monde.convertirRayonDuCercle(centre,r,Vmin, Vmax );

                }
                else {

                    Couple<Vecteur2D> p = OperationMonde.basGaucheHautDroitCercle(centre,r);
                    System.out.println("p = " + p.getPremier() + " , " + p.getDeuxieme());

                    // On cree le monde ecran
                    OperationMonde monde = new OperationMonde(
                            p.getPremier(),p.getDeuxieme(),
                            new Vecteur2D(0, fenetreDeDessin.HAUTEUR),
                            new Vecteur2D(fenetreDeDessin.LARGEUR,0));

                    // On convertit le rayon du cercle du monde vers le monde ecran
                    r = monde.convertirRayonDuCercle(centre,r,new Vecteur2D(centre.getX()-r,centre.getY()-r),
                            new Vecteur2D(centre.getX()+r,centre.getY()+r));

                    System.out.println("r = " + r);

                    centre = monde.transforme(centre);
                    System.out.println("centre = " + centre);

                }

                // On dessine le cercle
                fenetreDeDessin.graphics.fillOval((int)centre.getX(),(int)centre.getY(),r,r);

                return true;
            }
        }
        return false;
    }
}
