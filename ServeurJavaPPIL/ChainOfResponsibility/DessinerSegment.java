package ChainOfResponsibility;

import Monde.Dessiner.Couple;
import Monde.Dessiner.FenetreDeDessin;
import Monde.Dessiner.OperationMonde;
import Monde.Vecteur2D;

import java.awt.*;

public class DessinerSegment extends ExpertDessiner {
    /**
     * Constructeur de l'expert de dessin
     * @param suivant expert suivant
     */
    public DessinerSegment(Expert suivant) {
        super(suivant);
    }

    @Override
    public boolean dessiner(String requete, FenetreDeDessin fenetreDeDessin, boolean memeFenetre, Vecteur2D Vmin, Vecteur2D Vmax) {
        if(requete.contains("Segment"))
        {
            int crochetDeb = requete.indexOf("[");

            String type = requete.trim().substring(0,crochetDeb);

            // On cherche a savoir si on a un segment ou une forme complexe
            if(type.trim().contains("Segment") && !type.trim().contains("FormeComplexe") )
            {
                // On recupere les coordonnees du segment
                int crochetFin = requete.indexOf("]");
                String coordonnees = requete.substring(crochetDeb+1,crochetFin);
                String couleur = requete.substring(crochetFin+1).trim();


                String[] splited =  coordonnees.split(",");

                // On recupere les coordonnees du segment
                int gauche = (int) Double.parseDouble(splited[0].trim());
                int haut = (int) Double.parseDouble(splited[1].trim());
                int droit = (int) Double.parseDouble(splited[2].trim());
                int bas = (int) Double.parseDouble(splited[3].trim());

                System.out.println("Segment [ " + gauche + " , " + haut + " , " + droit + " , " + bas + " ] " + couleur );

                // On donne la couleur au segment
                fenetreDeDessin.graphics.setColor(Color.decode("#" + couleur));

                // On cherche le point de depart et d'arrivee du segment
                Vecteur2D deb = new Vecteur2D(gauche,haut) ;
                Vecteur2D fin = new Vecteur2D(droit,bas);

                Couple<Vecteur2D> coupleVect;

                /* ***********************************************
                 * On gère la transformation en monde ecran
                 * ***********************************************/

                // On verifie si la figure est dans le groupe ou pas
                // Si oui on doit convertir selon les points bgM et hdM du groupe sinon celui du segment seul
                if(memeFenetre)
                    coupleVect = OperationMonde.basGaucheHautDroitSegment(Vmin,Vmax);
                else
                    coupleVect = OperationMonde.basGaucheHautDroitSegment(deb,fin);


                // On initialise le monde ecran à partir des donnees
                OperationMonde monde = new OperationMonde(coupleVect.getPremier(),
                        coupleVect.getDeuxieme(),
                        new Vecteur2D(0, FenetreDeDessin.HAUTEUR),new Vecteur2D(FenetreDeDessin.LARGEUR,0));

                // On convertit les points du segment en monde ecran
                deb = monde.transforme(deb);
                fin = monde.transforme(fin);

                // On dessine le segment
                fenetreDeDessin.graphics.drawLine((int)deb.getX(),(int)deb.getY(),(int)fin.getX(),(int)fin.getY());

                System.out.println("Segment [ " + deb.getX() + " , " + deb.getY() + " , " + fin.getX() + " , " + fin.getY() + " ] " + couleur );

                return true;

            }
        }
        return false;
    }
}
