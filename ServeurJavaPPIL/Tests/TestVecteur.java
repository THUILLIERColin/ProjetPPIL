package Tests;

import Monde.Vecteur2D;

public class TestVecteur {
    public static void main(String[] args) {
        Vecteur2D u = new Vecteur2D(1, 2);
        Vecteur2D v = new Vecteur2D(-1, 1);

        System.out.println(u.addition(v)); // (0.0, 3.0)
        System.out.println(u.multiplication(2)); // (2.0, 4.0)
        System.out.println(u.inverse()); // (-1.0, -2.0)
        System.out.println(u.soustraction(v)); // (2.0, 1.0)
        System.out.println(u.norm()); // 2.23606797749979
        System.out.println(u.produitScalaire(v)); // 1.0
        System.out.println(u.distance(v)); // 2.23606797749979
        System.out.println(u.equals(v)); // false
        System.out.println(u.equals(new Vecteur2D(1, 2))); // true
    }
}
