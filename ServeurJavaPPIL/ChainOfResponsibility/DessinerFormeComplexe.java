package ChainOfResponsibility;

import Monde.Dessiner.FenetreDeDessin;
import Monde.Vecteur2D;

public class DessinerFormeComplexe extends ExpertDessiner {
    public DessinerFormeComplexe(Expert suivant) {
        super(suivant);
    }

    @Override
    public boolean dessiner(String requete, FenetreDeDessin cadreDeDessin, boolean memeFenetre, Vecteur2D Vmin, Vecteur2D Vmax) {
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


                /*
                Vecteur2D vmin = new Vecteur2D(vects[1]);
                Vecteur2D vmax = new Vecteur2D(vects[2]);



                ExpertDessiner expertFormeInterieur = new DessinerCercle(new DessinerFormeComplexe(new DessinerSegment(new DessinerPolygone(null))));



                CadreDessin cadreDessin2 = new CadreDessin(cadreDessin.getTitle(),cadreDessin.bordGauche,
                        cadreDessin.bordSuperieur, cadreDessin.getWidth(),cadreDessin.getHeight());
                cadreDessin.dispose();
                cadreDessin2.setResizable(false);

                for (int i = 0 ; i < formes.length -1 ; i++) {
                    System.out.println(formes[i]);
                    h1.handle(formes[i],cadreDessin2,true,vmin,vmax);

                }

                cadreDessin2.getBufferStrategy().show();
                */
                return true;
            }
        }

        return false;
    }
}
