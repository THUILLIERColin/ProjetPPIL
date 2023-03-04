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
            int crochetDeb = requete.indexOf(": [");
            String type = requete.substring(0, crochetDeb).trim();

            if (type.contains("FormeComplexe"))
            {
                int crochetOuvrant = requete.indexOf("(");
                int crochetFermant = requete.indexOf(")");
                String part1= requete.substring(crochetDeb+1).trim().toLowerCase();
                String entreCrochet = requete.substring(crochetOuvrant+1,crochetFermant);

                //System.out.println("type = "+type);
                //System.out.println("part1 ="+part1);
                // System.out.println("entre crochet ="+entreCrochet);

                String apresCrochetFermant = requete.substring(crochetFermant+1);
                String vects[] = apresCrochetFermant.split(" I ");

                /*
                Vecteur2D vmin = new Vecteur2D(vects[1]);
                Vecteur2D vmax = new Vecteur2D(vects[2]);


                String formes[] = entreCrochet.split(";");

                Handler h1 = new DrawCircleHandler();
                Handler h2 = new DrawLineHandler();
                Handler h3 = new DrawPolygonHandler();
                Handler h4 = new DrawGroupeHandler();
                h1.setNextChain(h2);
                h2.setNextChain(h3);
                h3.setNextChain(h4);

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
