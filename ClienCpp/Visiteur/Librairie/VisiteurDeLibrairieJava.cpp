//
// Created by Colin Thuiller on 04/03/2023.
//

#include "VisiteurDeLibrairieJava.h"

using namespace std;

const void *VisiteurDeLibrairieJava::visite(const Forme *forme, SOCKET *s) const {
    int r;

    ostringstream oss;
    oss << (string)*forme;
    string requete = oss.str();
    r = send(*s, requete.c_str(), requete.size(), 0);
    if (r == SOCKET_ERROR) {
        throw Erreur("Erreur lors de l'envoi de la requete");
    }

    return 0
}