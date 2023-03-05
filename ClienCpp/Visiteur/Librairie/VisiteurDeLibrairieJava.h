/**
 * @author THUILLIER Colin
 */

#pragma once

#include "VisiteurDeLibrairie.h"

class VisiteurDeLibrairieJava : public VisiteurDeLibrairie {
public:
    /**
     * @brief Visiteur qui permettra de dessiner une forme avec une librairie graphique
     * @param forme (Forme*) la forme à dessiner
     * @param s (Socket*) le socket de communication avec le serveur
     */
    const void *visite(const Forme * forme, SOCKET s) const;
};