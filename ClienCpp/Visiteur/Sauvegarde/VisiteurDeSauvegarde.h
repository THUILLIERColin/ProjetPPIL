/**
* @author THUILLIER Colin
 * @details Pour répondre au mieux au exigeance du sujet,
 * j'ai choisi de distinguer les visiteurs de librairie et de sauvegarde.
 * Pour pouvoir sauvegarder une forme, il faut donc passer par un visiteur de sauvegarde.
 * Ce qui permet de ne pas avoir à modifier sauvegarder dans les classes de formes.
*/

#pragma once

#include "../../Formes/Forme.h"

class VisiteurDeSauvegarde {
public:
    /**
    * @brief Visiteur qui permettre de sauvegarder une forme dans un fichier de sauvegarde
    * @param forme (Forme*) la forme à sauvegarder
    */
    virtual const void *visite(const Forme * forme) const = 0;

};