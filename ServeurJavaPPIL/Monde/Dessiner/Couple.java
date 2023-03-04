/**
 * @details Classe Couple : classe de base pour les couples de points
 * ici on a un couple de points de type Vecteur2D
 */

package Monde.Dessiner;

import Monde.Vecteur2D;

public class Couple<Vecteur2D> {
    private Vecteur2D premier;
    private Vecteur2D deuxieme;

    public Couple(Vecteur2D premier , Vecteur2D deuxieme){
        this.premier = premier;
        this.deuxieme = deuxieme;
    }

    public void setPremier(Vecteur2D premier) {
        this.premier = premier;
    }

    public void setDeuxieme(Vecteur2D deuxieme) {
        this.deuxieme = deuxieme;
    }

    public Vecteur2D getDeuxieme() {
        return deuxieme;
    }

    public Vecteur2D getPremier() {
        return premier;
    }
}
