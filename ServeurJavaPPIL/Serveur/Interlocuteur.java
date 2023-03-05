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
        try
        {
            while(!this.isInterrupted())
            {
                String requete = this.fluxEntrant.readLine();
                System.out.println("le client n° " + this.noClient + "a envoyé : " + requete);

                FenetreDeDessin fenetreDeDessin = new FenetreDeDessin("cadre dessin",60,60, FenetreDeDessin.LARGEUR,FenetreDeDessin.HAUTEUR);
                fenetreDeDessin.setResizable(false);

                expert.envoieAuParseur(requete,fenetreDeDessin,false,null,null);

                fenetreDeDessin.getBufferStrategy().show();
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
