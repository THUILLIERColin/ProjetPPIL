package Monde;

public class Vecteur2D {
    public double x, y;

    public Vecteur2D(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public Vecteur2D clone() {
        return new Vecteur2D(x, y);
    }

    public Vecteur2D addition(Vecteur2D u) {
        return new Vecteur2D(x + u.x, y + u.y);
    }

    public Vecteur2D multiplication(double a) {
        return new Vecteur2D(x * a, y * a);
    }

    public Vecteur2D inverse() {
        return new Vecteur2D(-x, -y);
    }

    public Vecteur2D soustraction(Vecteur2D u) {
        return new Vecteur2D(x - u.x, y - u.y);
    }

    public double norm() {
        return Math.sqrt(x * x + y * y);
    }

    public double produitScalaire(Vecteur2D u) {
        return x * u.x + y * u.y;
    }

    public double distance(Vecteur2D b) {
        return Math.sqrt(Math.pow(x - b.x, 2) + Math.pow(y - b.y, 2));
    }

    public boolean equals(Vecteur2D u) {
        return (x == u.x && y == u.y);
    }

    @Override
    public String toString() {
        return "(" + x + ", " + y + ")";
    }

    public static Vecteur2D multiplication(double a, Vecteur2D u) {
        return u.multiplication(a);
    }
}
