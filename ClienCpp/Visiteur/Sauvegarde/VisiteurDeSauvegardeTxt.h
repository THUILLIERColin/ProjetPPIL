/**
 * @author THUILLIER Colin
 */

#pragma once

#include "VisiteurDeSauvegarde.h"

class VisiteurDeSauvegardeTxt : public VisiteurDeSauvegarde {
public:
    /**
    * @brief Visiteur qui permettre de sauvegarder une forme dans un fichier de sauvegarde
    * @param forme (Forme*) la forme à sauvegarder
    */
    virtual const void *visite(const Forme *forme) const;
};