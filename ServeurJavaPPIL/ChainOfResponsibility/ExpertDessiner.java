package ChainOfResponsibility;

import Monde.Dessiner.FenetreDeDessin;
import Monde.Vecteur2D;

public abstract class ExpertDessiner extends Expert {
    private Expert _suivant;

    /**
     * Constructeur de l'expert de dessin
     * @param suivant expert suivant
     */
    public ExpertDessiner(Expert suivant) {
        _suivant = suivant;
    }

    /**
     * Méthode qui return l'expert suivant
     * @return l'expert suivant
     */
    public Expert get_suivant() {
        return _suivant;
    }

    @Override
    public boolean envoieAuParseur(String requete, FenetreDeDessin cadreDeDessin, boolean memeFenetre, Vecteur2D Vmin, Vecteur2D Vmax) throws InterruptedException {
        if(! dessiner(requete, cadreDeDessin, memeFenetre, Vmin, Vmax)){
            if (_suivant != null)
                return _suivant.envoieAuParseur(requete, cadreDeDessin, memeFenetre, Vmin, Vmax);
            else
                return false;
        }
        return true;
    }

    public abstract boolean dessiner(String requete, FenetreDeDessin cadreDeDessin, boolean memeFenetre, Vecteur2D Vmin, Vecteur2D Vmax);
}