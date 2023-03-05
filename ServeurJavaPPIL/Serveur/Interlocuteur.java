package Serveur;

import ChainOfResponsibility.Expert;
import ChainOfResponsibility.ExpertDessiner;
import Monde.Dessiner.FenetreDeDessin;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;

public class Interlocuteur extends Thread
{
    int noClient;
    private BufferedReader fluxEntrant;
    private PrintStream fluxSortant;
    private ExpertDessiner expert;
    public String[] formes = {};
    public Interlocuteur(Socket socket, int noClient, ExpertDessiner expert) throws IOException
    {
        this.fluxEntrant = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        this.fluxSortant = new PrintStream(socket.getOutputStream());
        this.noClient = noClient;
        this.expert = expert;
    }

    @Override
    public void run()
    {
        boolean fin = false;
        try
        {
            while(!this.isInterrupted() || !fin)
            {
                String requete = this.fluxEntrant.readLine();
                if(requete == null)
                {
                    fin = true;
                }
                else
                {
                    System.out.println("Requete du client " + this.noClient + " : " + requete);
                    FenetreDeDessin fenetreDeDessin = new FenetreDeDessin("Fenetre de dessin",0,0,FenetreDeDessin.LARGEUR, FenetreDeDessin.HAUTEUR);
                    this.expert.envoieAuParseur(requete, fenetreDeDessin, false, null, null);
                    fenetreDeDessin.getBufferStrategy().show();
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
