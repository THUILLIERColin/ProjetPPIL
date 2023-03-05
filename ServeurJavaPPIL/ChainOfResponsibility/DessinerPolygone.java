package ChainOfResponsibility;

import Monde.Dessiner.Couple;
import Monde.Dessiner.FenetreDeDessin;
import Monde.Dessiner.OperationMonde;
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

                /* ***********************************************
                 * On gère la transformation en monde ecran
                 * ***********************************************/

                // On donne la couleur au polygone
                fenetreDeDessin.graphics.setColor(Color.decode("#" + couleur));

                // On cree un couple de vecteur2D pour stocker les coordonnees du polygone
                Couple<Vecteur2D> coupleVect;

                // On verifie si on doit dessiner le polygone dans la meme fenetre ou non (partie d'un groupe)
                // Si oui on converti selon les points bgM et hdM du groupe sinon celui du polygone
                if(memeFenetre)
                    coupleVect = new Couple<Vecteur2D>(Vmin,Vmax);
                else
                    coupleVect = OperationMonde.basGaucheHautDroitPolygone(x,y);

                OperationMonde t = new OperationMonde(coupleVect.getPremier(),
                        coupleVect.getDeuxieme(),
                        new Vecteur2D(0, FenetreDeDessin.HAUTEUR),
                        new Vecteur2D(FenetreDeDessin.LARGEUR,0));

                // On recupere les abscisses et ordonnees du polygone
                // on les converti en coordonnees ecran et on les met dans une liste de Vecteur2D
                ArrayList<Vecteur2D> lesPoints = new ArrayList<Vecteur2D>();
                for(int i = 0 ; i < x.length ; i++)
                {
                    Vecteur2D vect = new Vecteur2D(x[i],y[i]);
                    vect = t.transforme(vect);
                    x[i] = (int) vect.getX();
                    y[i] = (int) vect.getY();
                    lesPoints.add(new Vecteur2D(x[i],y[i]));
                }

                // On met les nouvelles coordonnees dans les tableaux x et y
                // Pour pouvoir créer un polygone avec la bibliothèque graphique awt
                for(int i = 0 ; i < x.length ; i++){
                    x[i] = (int)lesPoints.get(i).getX();
                    y[i] = (int)lesPoints.get(i).getY();
                }

                // On cree le polygone
                Polygon p = new Polygon(y,x,x.length/2);

                // On dessine le polygone
                fenetreDeDessin.graphics.fillPolygon(p);

                // On affiche le polygone avec System.out.println
                for(int i = 0 ; i < x.length ; i+=2)
                    System.out.println("Point " + i/2 + " : " + x[i] + " " + y[i]);
                return true;
            }
        }
        return false;
    }
}
