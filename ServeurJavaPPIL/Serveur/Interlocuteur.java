package Serveur;

import ChainOfResponsibility.ExpertDessiner;
import Monde.Dessiner.FenetreDeDessin;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;

/**
 * Classe qui permet de gérer les requêtes du client et de les envoyer a la chain of responsibility
 */
public class Interlocuteur extends Thread
{
    int noClient;
    private BufferedReader fluxEntrant;
    private PrintStream fluxSortant;
    private ExpertDessiner expert;
    public String[] formes = {};

    /**
     * Constructeur de l'interlocuteur
     * @param socket socket du client
     * @param noClient numero du client
     * @param expert expert de dessin
     * @throws IOException
     */
    public Interlocuteur(Socket socket, int noClient, ExpertDessiner expert) throws IOException
    {
        this.fluxEntrant = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        this.fluxSortant = new PrintStream(socket.getOutputStream());
        this.noClient = noClient;
        this.expert = expert;
    }

    /**
     * Methode run de l'interlocuteur
     * @details permet de lire les requetes du client et de les envoyer a l'expert de dessin
     */
    @Override
    public void run()
    {
        boolean fin = false;
        try
        {
            while(!this.isInterrupted() || !fin)
            {
                String requete = this.fluxEntrant.readLine();
                if(requete == null || requete.trim().equals("quitter"))
                {
                    fin = true;
                }
                else
                {
                    System.out.println("Requete du client " + this.noClient + " : " + requete);
                    FenetreDeDessin fenetreDeDessin = new FenetreDeDessin("Fenetre de dessin",0,0,FenetreDeDessin.LARGEUR, FenetreDeDessin.HAUTEUR);
                    this.expert.envoieAuParseur(requete, fenetreDeDessin, false, null, null);
                    fenetreDeDessin.strategy.show();
                }
            }
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
        catch(NullPointerException e)
        {
            System.out.println("Le client n° "+ this.noClient + " a mis fin a la conversation");
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        System.out.println("Arręt du thread n° " + this.noClient);
    }
}
