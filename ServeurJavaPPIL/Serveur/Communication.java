package Serveur;

import ChainOfResponsibility.*;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Communication {
    public static void main(String[] args) {

        try{

            // initialisation de la chaine de responsabilite
            DessinerCercle expertDessiner = new DessinerCercle(new DessinerPolygone(new DessinerSegment(new DessinerFormeComplexe(null))));

            int portServeur=9111;
            ServerSocket serveur = new ServerSocket(portServeur);

            System.out.print("Serveur initialisé "+serveur);
            int noClient = 1;
            while(true)
            {
                Socket socket = serveur.accept();
                System.out.println("Connexion reussi avec le client numero "+noClient);

                //on cree un cadre dessin pour chaque requete
                Interlocuteur interlocuteur = new Interlocuteur(socket, noClient,expertDessiner );
                System.out.println("----------debut requete : -----------------");
                ++noClient;
                interlocuteur.start();

            }
        }catch (IOException  e){
            e.printStackTrace();
        }

        System.out.println("fin du programme");
    }
}
