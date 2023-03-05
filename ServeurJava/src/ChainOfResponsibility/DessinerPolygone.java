package ChainOfResponsibility;

import Monde.Dessiner.Couple;
import Monde.Dessiner.FenetreDeDessin;
import Monde.Vecteur2D;

import java.awt.*;
import java.util.ArrayList;

public class DessinerPolygone extends ExpertDessiner {
    /**
     * Constructeur de l'expert de dessin
     * @param suivant expert suivant
     */
    public DessinerPolygone(Expert suivant) {
        super(suivant);
    }

    @Override
    public boolean dessiner(String requete, FenetreDeDessin fenetreDeDessin, boolean memeFenetre, Vecteur2D Vmin, Vecteur2D Vmax) {
        //savoir si on va parser un polygone/triangle
        if(requete.contains("Polygone"))
        {
            int crochetDeb = requete.indexOf("[");

            String type = requete.substring(0,crochetDeb);


            if(type.trim().contains("Polygone") && !type.trim().contains("FormeComplexe"))
            {

                int crochetFin = requete.indexOf("]");
                String coordonnees = requete.substring(crochetDeb+1,crochetFin);
                String couleur = requete.substring(crochetFin+1).trim();


                String cords[] = coordonnees.split(",");
                int[] x = new int[cords.length]; // creation d'un tableau pour les abscisses
                int[] y = new int[cords.length];

                // On recupere les coordonnees du polygone

                for(int i = 0 ,j=0,k=1 ; i < cords.length ; i+=2,j++,k+=2){
                    x[j]= (int) Double.parseDouble(cords[i].trim()); // on recupere les abscisses
                    y[j]= (int) Double.parseDouble(cords[k].trim());
                }

                // On affiche le polygone
                System.out.println("Polygone [ " + coordonnees + " ] " + couleur );

                // On donne la couleur au polygone
                fenetreDeDessin.graphics.setColor(Color.decode("#" + couleur));

                //
                Polygon poly = new Polygon(x,y,cords.length/2);

                // On dessine le polygone
                fenetreDeDessin.graphics.fillPolygon(poly);

                // On affiche le polygone avec System.out.println
                for(int i = 0 ; i < x.length ; i+=2)
                    System.out.println("Point " + i/2 + " : " + x[i] + " " + y[i]);
                return true;
            }
        }
        return false;
    }
}
