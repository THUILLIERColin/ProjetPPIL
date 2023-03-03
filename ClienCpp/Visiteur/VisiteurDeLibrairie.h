/**
* @author THUILLIER Colin
*/

#pragma once

#include "Visiteur.h"

class VisiteurDeLibrairie : public Visiteur {
public:
    /**
     * @brief Visite qui permet de dessiner une forme avec une librairie graphique
     * @param forme (Forme*) la forme à dessiner
     * @param s (Socket*) le socket de communication avec le serveur
     * @return 0 si tout s'est bien passé
     * @throw Erreur si l'envoi de la requete a échoué
     */
    const void *visite(const Forme *forme, SOCKET *s) const;

    // Visiteur de sauvegarde
    virtual const void *visite(const Forme *forme) const = 0;
};