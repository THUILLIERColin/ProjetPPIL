/**
 * @author THUILLIER Colin
 */

package Monde.Dessiner;

import java.awt.*;
import java.awt.event.*;

public class FenetreDeDessin extends Frame {
    public Graphics graphics;      // pour dessiner sur this
    public final int bordGauche, bordSuperieur;

    /**
     * Constructeur de la fenetre de dessin
     * @param titre titre de la fenetre
     * @param ox abscisse souhaite pour le bord gauche de la fenetre
     * @param oy ordonnee souhaitee pour le bord superieur de la fenetre
     * @param largeur largeur souhaitee pour la fenetre
     * @param hauteur hauteur souhaitee pour la fenetre
     * @throws InterruptedException si le thread est interrompu
     * @detail Du à la librairie utilisé
     * l'unite pour les 4 parametres est le pixel
     */
    public FenetreDeDessin(String titre, int ox, int oy, int largeur, int hauteur) throws InterruptedException
    {
        super(titre); // appel du constructeur de la classe mère Frame et on lui passe lE titre de la fenêtre
        /* *************************************************************
         * On parametre la position et les dimensions de la fenetre
         ***************************************************************/
        Toolkit tk = Toolkit.getDefaultToolkit(); // on récupère l'outil de gestion de la fenêtre

        int lE, hE; // largeur ecran, hauteur ecran

        Dimension dim = tk.getScreenSize(); // dimensions de l'ecran

        lE = (int) dim.getWidth();
        hE = (int) dim.getHeight();

        int  l, h ;

        bordGauche = Math.max(0, ox); // on récupère la valeur maximale entre 0 et ox
        bordSuperieur = Math.max(0, oy); // on récupère la valeur maximale entre 0 et oy
        l = Math.min(largeur, lE - bordGauche); // on prend la plus petite valeur entre la largeur de la fenêtre et la largeur de l'écran - le bord gauche
        h = Math.min(hauteur, hE - bordSuperieur); // on prend la plus petite valeur entre la hauteur de la fenêtre et la hauteur de l'écran - le bord supérieur
        // Tout ça pour éviter que la fenêtre dépasse de l'écran

        this.setBounds(bordGauche, bordSuperieur, l, h); // on définit les dimensions de la fenêtre

        this.setVisible(true); // on rend la fenêtre visible

        /* *************************************************************
         * Initialisation de l'active rendering
         ***************************************************************/

        this.setIgnoreRepaint(true);  // on ignore le repaint
        int nombreBuffers = 2; // on définit le nombre de buffer
        this.createBufferStrategy(nombreBuffers); // on crée le buffer

        // il faut attendre un minimum de 50 ms pour que lE buffer soit operationnel
        Thread.sleep(100);

        // on récupère le graphics de la fenêtre pour pouvoir dessiner dessus
        this.graphics = this.getBufferStrategy().getDrawGraphics();

        /* *************************************************************
         * Permet la fermeture de la fenetre quand on appuie sur la croix
         ***************************************************************/
        addWindowListener (new WindowAdapter() {
            public void windowClosing (WindowEvent e) {
                dispose();
            }
        });
    }
}
