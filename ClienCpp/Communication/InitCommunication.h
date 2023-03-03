/**
* @author THUILLIER Colin
*/

#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <string.h>
#include <pcap/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include "../Erreur/Erreur.h"

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1

typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;

class InitCommunication {
private :
    int r; // variable de retour des fonctions
    SOCKET sock; // informations concernant le socket à créer : famille d'adresses acceptées, mode connecté ou non, protocole
    bool connecter = false; // true si le client est connecté au serveur

    static InitCommunication *instance;


    /**
     * @brief Constructeur de la classe InitCommunication
     * @details Il permet de créer un socket
     */
    InitCommunication() {
        // création du socket
        int familleAdresses = AF_INET; // famille d'adresses acceptées : AF_INET pour IPv4
        int typeSocket = SOCK_STREAM; // mode connecté : SOCK_STREAM pour TCP
        int protocole = IPPROTO_TCP; // protocole : 0 pour TCP ou UDP

        sock = socket(familleAdresses, typeSocket, protocole); // création du socket

        if (sock == INVALID_SOCKET) {
            ostringstream oss;
            oss << "la création du socket a échoué : code d'erreur = " << INVALID_SOCKET << endl;
            throw Erreur(oss.str().c_str());
        }
    }

public:
    /**
     * @brief Permet de récupérer l'instance de la classe InitCommunication
     * @return (InitCommunication*) l'instance de la classe InitCommunication
     */
    static InitCommunication *getInstance() {
        if (instance == nullptr) {
            instance = new InitCommunication();
        }
        return instance;
    }

    /**
     * @brief Détruit l'instance de la classe InitCommunication
     * @details Il se déconnecte également du serveur
     */
    virtual ~InitCommunication() {
        delete instance;
        deconnexion();
    }

    /**
     * @brief Permet de se déconnecter du serveur
     */
    void deconnexion() {
        if (connecter) {
            r = close(sock);
            if (r == SOCKET_ERROR) {
                ostringstream oss;
                oss << "la fermeture du socket a échoué : code d'erreur = " << SOCKET_ERROR << endl;
                throw Erreur(oss.str().c_str());
            }
            connecter = false;
        }
    }

    /**
       *  @brief Permet de créer un socket
       * @param port (int) le port sur lequel le socket sera créé
       * @param adresse (char*) l'adresse sur laquelle le socket sera créé
       */
    void demarrerConnection(int port, const char *adresse) {
        // On vérifie que le client n'est pas déjà connecté
        if (connecter) {
            throw Erreur("Le client est déjà connecté");
        } else {
            connecter = true;
        }

        // Configuration de la connexion
        SOCKADDR_IN sockaddr;
        sockaddr.sin_addr.s_addr = inet_addr(adresse);
        sockaddr.sin_family = AF_INET;
        sockaddr.sin_port = htons(port);
        r = connect(sock, (SOCKADDR *) &sockaddr, sizeof(sockaddr));
        if (r == SOCKET_ERROR) {
            throw Erreur("Erreur lors du bind du socket");
        }
        r = listen(sock, 5);
        if (r == SOCKET_ERROR) {
            throw Erreur("Erreur lors du listen du socket");
        }
    }

    /**
     * @brief Retourn r
     * @return r (int)
     */
    int getR() {
        return r;
    }

    /**
     * @brief Retourne la valeur de connecter
     * @return connecter (bool)
     */
    bool getConnecter() {
        return connecter;
    }

    /**
     * @brief Retourne le socket
     * @return sock (SOCKET)
     */
    SOCKET getSocket() {
        return sock;
    }

};