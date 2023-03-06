package ChainOfResponsibility;

import Monde.Dessiner.FenetreDeDessin;
import Monde.Vecteur2D;

import java.awt.*;

public class DessinerFormeComplexe extends ExpertDessiner {
    /**
     * Constructeur de la classe DessinerFormeComplexe
     * @param suivant expert suivant
     */
    public DessinerFormeComplexe(Expert suivant) {
        super(suivant);
    }

    @Override
    public boolean dessiner(String requete, FenetreDeDessin fenetreDeDessin, boolean memeFenetre, Vecteur2D Vmin, Vecteur2D Vmax) throws InterruptedException {
        if (requete.contains("FormeComplexe"))
        {
            // FormeComplexe : { Cercle [ 1 , 2 , 1 ] 16711680 ; Cercle [ 2 , 3 , 2 ] 16711680 } ( 0 , 0 ) / ( 10 , 10 )
            int accoladeDeb = requete.indexOf("{");
            String type = requete.substring(0, accoladeDeb).trim();

            if (type.contains("FormeComplexe"))
            {
                int crochetFermant = requete.indexOf("}");

                // On recupere les formes de la forme complexe
                String entreCrochet = requete.substring(accoladeDeb+1,crochetFermant);

                String apresCrochetFermant = requete.substring(crochetFermant+1);
                // On recupere le vecteur min et max du groupe
                String vects[] = apresCrochetFermant.split(" / ");

                // On met toutes les formes dans un tableau
                String formes[] = entreCrochet.split(";");

                // On recupere les coordonnees des vecteurs min et max
                Vecteur2D vmin = new Vecteur2D(vects[0]);
                Vecteur2D vmax = new Vecteur2D(vects[1]);

                // Initialisation des experts
                ExpertDessiner expertFormeInterieur = new DessinerCercle(new DessinerFormeComplexe(new DessinerSegment(new DessinerPolygone(null))));

                // On cree une fenetre de dessin pour le groupe
                FenetreDeDessin fenetreDeDessin2 = new FenetreDeDessin(fenetreDeDessin.getTitle()+"2",fenetreDeDessin.bordGauche,
                        fenetreDeDessin.bordSuperieur, fenetreDeDessin.getWidth(),fenetreDeDessin.getHeight());
                fenetreDeDessin.dispose();
                fenetreDeDessin2.setResizable(false);

                // On va parser les formes de la forme complexe et les dessiner
                for (int i = 0 ; i < formes.length -1 ; i++) {
                    System.out.println(formes[i]);
                    expertFormeInterieur.envoieAuParseur(formes[i],fenetreDeDessin2,true,vmin,vmax);
                }

                // On affiche la fenetre de dessin
                fenetreDeDessin2.strategy.show();
                return true;
            }
        }
        return false;
    }
}
