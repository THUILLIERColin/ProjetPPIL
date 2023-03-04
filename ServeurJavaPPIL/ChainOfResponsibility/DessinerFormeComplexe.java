package ChainOfResponsibility;

import Monde.Dessiner.FenetreDeDessin;
import Monde.Vecteur2D;

public class DessinerFormeComplexe extends ExpertDessiner {
    public DessinerFormeComplexe(Expert suivant) {
        super(suivant);
    }

    @Override
    public boolean dessiner(String requete, FenetreDeDessin fenetreDeDessin, boolean diffFenetre, Vecteur2D Vmin, Vecteur2D Vmax) throws InterruptedException {
        if (requete.contains("FormeComplexe"))
        {
            // FormeComplexe : { Cercle [ 1 , 2 , 1 ] 16711680 ; Cercle [ 2 , 3 , 2 ] 16711680 } ( 0 , 0 ) / ( 10 , 10 )
            int accoladeDeb = requete.indexOf("{");
            String type = requete.substring(0, accoladeDeb).trim();

            if (type.contains("FormeComplexe"))
            {
                int crochetFermant = requete.indexOf("}");
                String entreCrochet = requete.substring(accoladeDeb+1,crochetFermant);

                String apresCrochetFermant = requete.substring(crochetFermant+1);
                String vects[] = apresCrochetFermant.split(" / ");

                String formes[] = entreCrochet.split(";");

                // On recupere les coordonnees du vecteur
                Vecteur2D vmin = new Vecteur2D(vects[0]);
                Vecteur2D vmax = new Vecteur2D(vects[1]);


                ExpertDessiner expertFormeInterieur = new DessinerCercle(new DessinerFormeComplexe(new DessinerSegment(new DessinerPolygone(null))));



                FenetreDeDessin fenetreDeDessin2 = new FenetreDeDessin(fenetreDeDessin.getTitle()+"2",fenetreDeDessin.bordGauche,
                        fenetreDeDessin.bordSuperieur, fenetreDeDessin.getWidth(),fenetreDeDessin.getHeight());
                fenetreDeDessin.dispose();
                fenetreDeDessin2.setResizable(false);

                for (int i = 0 ; i < formes.length -1 ; i++) {
                    System.out.println(formes[i]);
                    expertFormeInterieur.envoieAuParseur(formes[i],fenetreDeDessin2,true,vmin,vmax);
                }

                fenetreDeDessin2.getBufferStrategy().show();
                return true;
            }
        }
        return false;
    }
}
