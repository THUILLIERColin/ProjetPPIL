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
    public boolean envoieAuParseur(String requete, FenetreDeDessin fenetreDeDessin, boolean memeFenetre, Vecteur2D Vmin, Vecteur2D Vmax) throws InterruptedException {
        if(!dessiner(requete, fenetreDeDessin, memeFenetre, Vmin, Vmax)){
            if (_suivant != null)
                return _suivant.envoieAuParseur(requete, fenetreDeDessin, memeFenetre, Vmin, Vmax);
            else
                System.out.println("Erreur : requete non reconnue");
                return false;
        }
        return true;
    }

    /**
     * Méthode qui permet de dessiner la requete dans le cadre de dessin si possible
     * @param requete forme à dessiner
     * @param fenetreDeDessin cadre de dessin
     * @param memeFenetre sert a savoir si on dessine dans la meme fenetre
     * @param Vmin vecteur minimum
     * @param Vmax vecteur maximum
     * @return vrai si la requete a été traitée, faux sinon
     */
    public abstract boolean dessiner(String requete, FenetreDeDessin fenetreDeDessin, boolean memeFenetre, Vecteur2D Vmin, Vecteur2D Vmax) throws InterruptedException;
}