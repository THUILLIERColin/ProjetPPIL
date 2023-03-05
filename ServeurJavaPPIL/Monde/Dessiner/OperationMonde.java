package Monde.Dessiner;

import Monde.Vecteur2D;

public class OperationMonde {

    public double lambda,eps1,eps2,a,b;
    /* Paramètres du monde :
     * lambda : facteur d'échelle global pour la transformation
     * eps1 : facteur d'échelle pour l'axe des x
     * eps2 : facteur d'échelle pour l'axe des y
     * a : coordonnée x du point d'origine de la transformation
     * b : coordonnée y du point d'origine de la transformation
     */

    public double lambdaEps1 , lambdaEps2 ;

    /**
     * Cette méthode permet de créer un monde à partir de vecteur de coordonnées
     * @param bgM point bas gauche monde
     * @param hdM point haut droit monde
     * @param bgE point bas gauche ecran
     * @param hdE point haut droit ecran
     * @details Cette méthode sert à créer un objet de la classe GenererMonde qui représente la transformation entre le système de coordonnées monde (qui représente les objets que l'on veut dessiner) et le système de coordonnées écran (qui représente la fenêtre de dessin).
     */
    public OperationMonde(Vecteur2D bgM, Vecteur2D hdM, Vecteur2D bgE, Vecteur2D hdE){

        // On calcule la valeur minimale entre la largeur de la fenêtre de dessin divisée par la différence de coordonnées horizontales (abscisses) entre les coins haut-droit et bas-gauche du monde,
        // et la hauteur négative de la fenêtre de dessin divisée par la différence de coordonnées verticales (ordonnées) entre les coins haut-droit et bas-gauche du monde.
        // Cette valeur représente le coefficient de zoom qui permettra de faire correspondre les dimensions du monde à celles de la fenêtre de dessin.
        this.lambda = Math.min(Math.abs(FenetreDeDessin.LARGEUR) / Math.abs(hdM.getX() - bgM.getX()), Math.abs(-FenetreDeDessin.HAUTEUR) / Math.abs(hdM.getY() - bgM.getY()));

        // On détermine si les coins haut-droit et bas-gauche du monde sont du même côté que la largeur de la fenêtre de dessin en comparant les signes de ces valeurs.
        // Cette valeur permettra de savoir dans quel sens les coordonnées du monde seront dessinées.
        if(((FenetreDeDessin.LARGEUR) > 0 && (hdM.getX() - bgM.getX()) > 0) ||((FenetreDeDessin.LARGEUR) < 0 && (hdM.getX() - bgM.getX()) < 0))
            this.eps1 = 1;
        else
            this.eps1 = -1;

        // On détermine si les coins haut-droit et bas-gauche du monde sont du même côté que la hauteur négative de la fenêtre de dessin en comparant les signes de ces valeurs.
        // Cette valeur permettra de savoir dans quel sens les coordonnées du monde seront dessinées.
        if(((0 - FenetreDeDessin.HAUTEUR) > 0 && (hdM.getY() - bgM.getY()) > 0) || ((0 - FenetreDeDessin.HAUTEUR) < 0 && (hdM.getY() - bgM.getY()) < 0))
            this.eps2 = 1;
        else
            this.eps2 = -1;

        // On définit un vecteur C1 qui représente le centre de la fenêtre de dessin en utilisant sa largeur et sa hauteur.
        Vecteur2D C1 = new Vecteur2D((FenetreDeDessin.LARGEUR) / 2, (FenetreDeDessin.HAUTEUR) / 2);

        // On définit un vecteur C2 qui représente le centre du monde en utilisant les coordonnées des coins haut-droit et bas-gauche.
        Vecteur2D C2 = new Vecteur2D((hdM.getX() + bgM.getX()) / 2, (hdM.getY() + bgM.getY()) / 2);

        // On calcule la valeur a qui représente le décalage horizontal à appliquer pour centrer le monde dans la fenêtre de dessin.
        // On soustrait au centre horizontal de la fenêtre de dessin le centre horizontal du monde multiplié par le coefficient de zoom lambda.
        this.a = C1.getX()- this.lambda * this.eps1* C2.getX();

        // On calcule la valeur b qui représente le décalage vertical à appliquer pour centrer le monde dans la fenêtre de dessin.
        // On soustrait au centre vertical de la fenêtre de dessin le centre vertical du monde multiplié par le coefficient de zoom lambda.
        this.b = C1.getY() - this.lambda * this.eps2* C2.getY();

        this.lambdaEps1 = this.lambda * this.eps1;
        this.lambdaEps2 = this.lambda * this.eps2;
    }

    /**
     * Convertit un point du monde en un point de la fenetre de dessin
     * @param v : vecteur a convertir
     * @return Vecteur2D
     * @details Le nouveau Vecteur correspond aux coordonnées du point dans le système de coordonnées écran
     */
    public Vecteur2D transforme(Vecteur2D v)
    {
        return new Vecteur2D((lambdaEps1*v.x + a),(lambdaEps2 * v.y + b));
    }


    /**
     * Permet de convertir le rayon du cercle du monde vers l'ecran
     * @param centre centre du cercle
     * @param r rayon du cercle
     * @param min point bas gauche de l'ecran
     * @param max point haut droit de l'ecran
     * @return double rayon du cercle dans le monde
     */
    public int convertirRayonDuCercle( Vecteur2D centre, double r,Vecteur2D min,Vecteur2D max) {
        // On calcule le vecteur qui va du centre du cercle à un point à distance r (rayon) sur le cercle
        Vecteur2D v = new Vecteur2D(centre.getX() + r, centre.getY());
        // On applique la transformation géométrique sur le vecteur
        v = transforme(v).soustraction(transforme(centre));
        // On récupère la coordonnée x du vecteur transformé, que l'on retourne sous forme d'un entier
        return (int) v.getX();
    }


    /**
     * Trouve le point bas gauche et le point haut droit du plan selon le cercle
     * @param centre : centre du cercle
     * @param rayon  : rayon du cercle
     * @return Pair<Vecteur2D> : une paire de vecteur2D qui sont
     * le point bas gauche et le point haut droit du plan selon le cercle
     */
    public static Couple<Vecteur2D> basGaucheHautDroitCercle(Vecteur2D centre, double rayon){
        // Créer un vecteur2D contenant le point en bas à gauche de l'écran
        Vecteur2D v1 = new Vecteur2D(centre.getX()-rayon,centre.getY()-rayon);
        // Créer un vecteur2D contenant le point en haut à droite de l'écran
        Vecteur2D v2 = new Vecteur2D(centre.getX()+rayon,centre.getY()+rayon);
        // Retourne une paire de vecteur2D qui contient les deux points trouvés
        return new Couple<Vecteur2D>(v1,v2);
    }

    /**
     * Trouve le point bas gauche et le point haut droit du plan selon le segment
     * @param point1 : point d'origine du segment
     * @param point2  : point de fin sdu segment
     * @return Pair<Vecteur2D> : une paire de vecteur2D qui sont
     * le point bas gauche et le point haut droit du plan selon le segment
     */
    public static Couple<Vecteur2D> basGaucheHautDroitSegment(Vecteur2D point1,Vecteur2D point2){

        double minX = Math.min(point1.x, point2.x);
        double minY = Math.min(point1.y, point2.y);

        double maxX = Math.max(point1.x, point2.x);
        double maxY = Math.max(point1.y, point2.y);

        Vecteur2D bgm = new Vecteur2D(minX,minY);
        Vecteur2D hdm = new Vecteur2D(maxX,maxY);

        return new Couple<Vecteur2D>(bgm,hdm);
    }

    /**
     * Trouve le point bas gauche et le point haut droit du plan selon le tableau de points de la figure
     * qu'elle soit un triangle ou un polygone
     * @param x : tableau de points x de la figure
     * @param y  : tableau de points y de la figure
     * @return Pair<Vecteur2D> : une paire de vecteur2D qui sont
     * le point bas gauche et le point haut droit du plan selon le triangle ou le polygone
     */
    public static Couple<Vecteur2D> basGaucheHautDroitPolygone(int x[] , int y[]){

        // On initialise les variables avec les valeurs maximales et minimales possibles pour x et y
        double minX = Integer.MAX_VALUE  , minY = Integer.MAX_VALUE;
        double maxX = Integer.MIN_VALUE , maxY = Integer.MIN_VALUE;

        // On parcourt le tableau x pour trouver le point le plus à gauche (minimum) et le plus à droite (maximum)
        for(int i = 0 ; i < x.length ; i++)
        {
            if(x[i] < minX)
                minX = x[i];

            if(x[i] > maxX)
                maxX = x[i];
        }

        // On parcourt le tableau y pour trouver le point le plus en bas (minimum) et le plus en haut (maximum)
        for(int i = 0 ; i < y.length ; i++)
        {
            if(y[i] < minY)
                minY = y[i];
            if(y[i] > maxY)
                maxY=y[i];
        }

        // On crée deux vecteurs2D contenant les coordonnées du point bas gauche et du point haut droit
        Vecteur2D bgm = new Vecteur2D(minX,minY);
        Vecteur2D hdm = new Vecteur2D(maxX,maxY);

        // On retourne un objet Couple contenant les deux vecteurs2D
        return new Couple<Vecteur2D>(bgm,hdm);
    }

}
