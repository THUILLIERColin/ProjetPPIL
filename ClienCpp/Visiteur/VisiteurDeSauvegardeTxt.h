/**
 * @author THUILLIER Colin
 */

#pragma once

#include "Visiteur.h"

class VisiteurDeSauvegardeTxt : public Visiteur {
public:
    // Visiteur de librairie
    virtual const void *visite(const Forme *forme, int *s) const = 0;

    /**
    * @brief Visiteur qui permettre de sauvegarder une forme dans un fichier de sauvegarde
    * @param forme (Forme*) la forme à sauvegarder
    */
    virtual const void *visite(const Forme *forme) const;
};