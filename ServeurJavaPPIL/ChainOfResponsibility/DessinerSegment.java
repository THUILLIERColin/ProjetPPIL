package ChainOfResponsibility;

import Monde.Dessiner.FenetreDeDessin;
import Monde.Vecteur2D;

public class DessinerSegment extends ExpertDessiner {
    /**
     * Constructeur de l'expert de dessin
     * @param suivant expert suivant
     */
    public DessinerSegment(Expert suivant) {
        super(suivant);
    }

    @Override
    public boolean dessiner(String requete, FenetreDeDessin fenetreDeDessin, boolean diffFenetre, Vecteur2D Vmin, Vecteur2D Vmax) {
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

                /*
                // on affecte a la forme la couleur specifique
                cadreDeDessin.graphics.setColor(Color.decode("#" + couleur));

                //origine de la droite
                Vecteur2D deb = new Vecteur2D(gauche,haut) ;
                // fin de la droite
                Vecteur2D fin = new Vecteur2D(droit,bas);

                Pair<Vecteur2D> pairVect;

                // debut de la tranformation monde ecran

                // savoir si le requete vient du geoupe ou pas
                // si oui on converti selon les points bgM et hdM du groupe sinon celui du segment seul
                if(Isgroupe)
                    pairVect = TransfoMondeEcran.basGaucheHautDroitSegment(Vmin,Vmax);
                else
                    pairVect = TransfoMondeEcran.basGaucheHautDroitSegment(deb,fin);




                TransfoMondeEcran t2 = TransfoMondeEcran.creerTransfoMondeEcran(pairVect.getPremier(),
                        pairVect.getDeuxieme(),
                        new Vecteur2D(0, Config.HAUTEUR),new Vecteur2D(Config.LARGEUR,0));

                deb = t2.transforme(deb);
                fin = t2.transforme(fin);

                // fin de la transformation monde ecran

                cadreDessin.graphics.drawLine((int)deb.getX(),(int)deb.getY(),(int)fin.getX(),(int)fin.getY());
                */
                return true;

            }
        }
        return false;
    }
}
