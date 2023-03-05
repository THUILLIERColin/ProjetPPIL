package ChainOfResponsibility;

import Monde.Dessiner.FenetreDeDessin;
import Monde.Vecteur2D;

public abstract class Expert {
    /**
     * Envoie la requête au parseur
     * @param requete requete de la forme dessiner
     * @param fenetreDeDessin cadre de dessin
     * @param memeFenetre sert a savoir si on dessine dans la meme fenetre si on est dans un groupe
     * @param Vmin vecteur minimum
     * @param Vmax vecteur maximum
     * @throws except programme
     * @return vrai si la requete a été traitée, faux sinon
     */
    public abstract boolean envoieAuParseur(String requete, FenetreDeDessin fenetreDeDessin, boolean memeFenetre, Vecteur2D Vmin, Vecteur2D Vmax) throws InterruptedException;
}
