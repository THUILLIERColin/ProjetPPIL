/**
* @author THUILLIER Colin
*/

#pragma once

#include "../Forme.h"
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

class Visiteur {
public :
    /**
     * @brief Visiteur qui permettra de dessiner une forme avec une librairie graphique
     * @param forme (Forme*) la forme à dessiner
     * @param s (Socket*) le socket de communication avec le serveur
     */
    virtual const void *visite(const Forme * forme, SOCKET * s) const = 0;

    /**
    * @brief Visiteur qui permettre de sauvegarder une forme dans un fichier de sauvegarde
    * @param forme (Forme*) la forme à sauvegarder
    */
    virtual const void *visite(const Forme * forme) const = 0;
};