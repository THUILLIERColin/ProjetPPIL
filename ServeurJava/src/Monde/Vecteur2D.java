/**
 * @author THUILLIER Colin
 */

package Monde;

/**
 * Implementation d'un vecteur 2D
 */
public class Vecteur2D {
    public double x, y;

    /**
     * Constructeur d'un vecteur 2D
     * @param x coordonnée x du vecteur
     * @param y coordonnée y du vecteur
     */
    public Vecteur2D(double x, double y) {
        this.x = x;
        this.y = y;
    }

    /**
     * Constructeur d'un vecteur 2D à partir d'un string
     * @param s string de la forme "(x,y)"
     */
    public Vecteur2D(String s) {
        String[] tokens = s.split("[(), ]+");
        this.x = Double.parseDouble(tokens[1]);
        this.y = Double.parseDouble(tokens[2]);
    }

    /**
     * Clone un vecteur
     * @return un nouveau vecteur identique
     */
    public Vecteur2D clone() {
        return new Vecteur2D(x, y);
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    /**
     * Additionne deux vecteurs
     * @param u vecteur à additionner
     * @return un nouveau vecteur résultant de l'addition
     */
    public Vecteur2D addition(Vecteur2D u) {
        return new Vecteur2D(x + u.x, y + u.y);
    }

    /**
     * Multiplie un vecteur par un scalaire
     * @param a scalaire à multiplier
     * @return un nouveau vecteur résultant de la multiplication
     */
    public Vecteur2D multiplication(double a) {
        return new Vecteur2D(x * a, y * a);
    }

    /**
     * Inverse un vecteur
     * @return un nouveau vecteur résultant de l'inversion
     */
    public Vecteur2D inverse() {
        return new Vecteur2D(-x, -y);
    }

    /**
     * Soustrait deux vecteurs
     * @param u vecteur à soustraire
     * @return un nouveau vecteur résultant de la soustraction
     */
    public Vecteur2D soustraction(Vecteur2D u) {
        return new Vecteur2D(x - u.x, y - u.y);
    }

    /**
     * Calcule la norme d'un vecteur
     * @return la norme du vecteur
     * @detail La norme d'un vecteur est la distance entre deux points
     */
    public double norm() {
        return Math.sqrt(x * x + y * y);
    }

    /**
     * Calcule le produit scalaire de deux vecteurs
     * @param u vecteur à multiplier
     * @return le produit scalaire des deux vecteurs
     */
    public double produitScalaire(Vecteur2D u) {
        return x * u.x + y * u.y;
    }

    /**
     * Calcule la distance entre deux vecteurs
     * @param b vecteur à comparer
     * @return la distance entre les deux vecteurs
     */
    public double distance(Vecteur2D b) {
        return Math.sqrt(Math.pow(x - b.x, 2) + Math.pow(y - b.y, 2));
    }

    /**
     * Compare deux vecteurs
     * @param u vecteur à comparer
     * @return true si les deux vecteurs sont identiques, false sinon
     */
    public boolean equals(Vecteur2D u) {
        return (x == u.x && y == u.y);
    }

    /**
     * Convertit un vecteur en chaîne de caractères
     * @return une chaîne de caractères représentant le vecteur
     */
    @Override
    public String toString() {
        return "(" + x + ", " + y + ")";
    }

    /**
     * Multiplie un vecteur par un scalaire (alias de multiplication)
     * @param a scalaire à multiplier
     * @param u vecteur à multiplier
     * @return un nouveau vecteur résultant de la multiplication
     */
    public static Vecteur2D multiplication(double a, Vecteur2D u) {
        return u.multiplication(a);
    }
}