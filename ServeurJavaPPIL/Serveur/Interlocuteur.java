package Serveur;

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
    public Interlocuteur(Socket socket, int noClient) throws IOException
    {
        this.fluxEntrant = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        this.fluxSortant = new PrintStream(socket.getOutputStream());
        this.noClient = noClient;
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
                String reponse = requete.toUpperCase();
                this.fluxSortant.println(reponse);
            }
        }
        catch (IOException e)
        {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        catch(NullPointerException e)
        {
            System.out.println("le client n° "+ this.noClient + " a mis fin ŕ la conversation");
        }
        System.out.println("arręt du thread n° " + this.noClient);
    }
}
