package Monde.Dessiner;


/**
 * Classe Couple : classe de base pour les couples de points
 * ici on a un couple de points de type Vecteur2D
 * @param <Vecteur2D>> type de la classe (ici on veut un couple de Vecteur2D)
 */
public class Couple<Vecteur2D> {
    private Vecteur2D premier;
    private Vecteur2D deuxieme;

    /**
     * Constructeur de la classe Couple
     * @param premier premier element du couple (ici un Vecteur2D)
     * @param deuxieme deuxieme element du couple (ici un Vecteur2D)
     */
    public Couple(Vecteur2D premier , Vecteur2D deuxieme){
        this.premier = premier;
        this.deuxieme = deuxieme;
    }

    /**
     * Setter du premier element du couple
     * @return premier element du couple
     */
    public void setPremier(Vecteur2D premier) {
        this.premier = premier;
    }

    /**
     * Setter du deuxieme element du couple
     * @return deuxieme element du couple
     */
    public void setDeuxieme(Vecteur2D deuxieme) {
        this.deuxieme = deuxieme;
    }

    /**
     * Getter du premier element du couple
     * @return premier element du couple
     */
    public Vecteur2D getPremier() {
        return premier;
    }

    /**
     * Getter du deuxieme element du couple
     * @return deuxieme element du couple
     */
    public Vecteur2D getDeuxieme() {
        return deuxieme;
    }
}