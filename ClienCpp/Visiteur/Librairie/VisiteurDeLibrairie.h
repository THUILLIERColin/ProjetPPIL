/**
* @author THUILLIER Colin
*/

#pragma once

#include "../../Formes/Forme.h"
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

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1

typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;

class VisiteurDeLibrairie {
public:
    /**
     * @brief Visite qui permet de dessiner une forme avec une librairie graphique
     * @param forme (Forme*) la forme à dessiner
     * @param s (Socket*) le socket de communication avec le serveur
     * @return 0 si tout s'est bien passé
     * @throw Erreur si l'envoi de la requete a échoué
     */
    virtual const void *visite(const Forme *forme, SOCKET s) const = 0;

};