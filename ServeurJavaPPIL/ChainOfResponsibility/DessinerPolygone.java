package ChainOfResponsibility;

import Monde.Dessiner.FenetreDeDessin;
import Monde.Vecteur2D;

import java.awt.*;

public class DessinerPolygone extends ExpertDessiner {
    /**
     * Constructeur de l'expert de dessin
     * @param suivant expert suivant
     */
    public DessinerPolygone(Expert suivant) {
        super(suivant);
    }

    @Override
    public boolean dessiner(String requete, FenetreDeDessin cadreDeDessin, boolean memeFenetre, Vecteur2D Vmin, Vecteur2D Vmax) {
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
                /*
                // on lui affcete sa couleur
                cadreDeDessin.graphics.setColor(Color.decode("#" + Integer.toHexString(Integer.parseInt(couleur))));

                // debut de la tranformation monde ecran

                Pair<Vecteur2D> pairVect;

                // savoir si le requete vient du geoupe ou pas
                // si oui on converti selon les points bgM et hdM du groupe sinon celui de la figule seule
                if(Isgroupe)
                    pairVect = new Pair<Vecteur2D>(Vmin,Vmax);
                else
                    pairVect = TransfoMondeEcran.basGaucheHautDroitTriangleEtPolygone(x,y);

                TransfoMondeEcran t = TransfoMondeEcran.creerTransfoMondeEcran(pairVect.getPremier(),
                        pairVect.getDeuxieme(),
                        new Vecteur2D(0, Config.HAUTEUR),
                        new Vecteur2D(Config.LARGEUR,0));

                // fin de la transormation monde ecran

                ArrayList<Vecteur2D> pointss = Vecteur2D.pointsToVect(x,y);

                // recuperation des points tranformees dans les tebleaux x[] et y[]

                for(int i = 0 ; i < pointss.size() ; i++ ) {
                    Vecteur2D v = pointss.get(i);
                    v = t.transforme(v);
                    pointss.set(i,v);
                }

                for(int i = 0 ; i < x.length ; i++){
                    x[i] = (int)pointss.get(i).getX();
                    y[i] = (int)pointss.get(i).getY();
                }


                // creation du polygone a dessiner
                Polygon p = new Polygon(y,x,x.length/2);

                // dessin du plugone
                cadreDessin.graphics.fillPolygon(p);;*/

                return true;
            }
        }
        return false;
    }
}
