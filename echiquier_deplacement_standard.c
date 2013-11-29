
/**
 * **************************************************
 * **************************************************
 *   _____ _____  ______   _
 *  / ____|  __ \|  ____| | |
 * | |    | |__) | |__    | |    _   _  ___  _ __
 * | |    |  ___/|  __|   | |   | | | |/ _ \| '_ \
 * | |____| |    | |____  | |___| |_| | (_) | | | |
 *  \_____|_|    |______| |______\__, |\___/|_| |_|
 *                                __/ |
 *                               |___/
 * **************************************************
 * **************************************************
 *
 *
 * Fonctions de gestion du deplacement standard des pieces du jeu d'echec.
 *
 */

//#Nom1: BERNARD
//#Prenom1: Florian
//#Nom2: VARAUT
//#Prenom2: Charles
//#Groupe: D

#include "echiquier_deplacement_standard.h"
#include "echiquier_deplacement.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int echiquier_deplacement_standard_est_valide_cavalier(const echiquier* echiquier_courant,
                                                       piece* cavalier_a_deplacer,
                                                       int x_destination, int y_destination,
                                                       code_erreur_deplacement* erreur)
{
    assert(echiquier_courant != NULL);
    assert(cavalier_a_deplacer != NULL);
    assert(coordonnee_est_valide(x_destination, y_destination) != 0);

    const jeu* jeu_courant=echiquier_recupere_jeu_courant_information(echiquier_courant);
    const piece *piece_au_depart=jeu_recuperer_piece_information(jeu_courant,
                                                                 cavalier_a_deplacer->coord_x,
                                                                 cavalier_a_deplacer->coord_y);
    int dx, dy,
            deplacement_valide=1, /* Le déplacement est considéré initialement comme valide */
            piece_a_destination=jeu_existe_piece(jeu_courant, x_destination, y_destination);

    // On vérifie qu'il y a bien un roi aux coordonnées de départ dans le jeu courant
    assert(piece_au_depart->type == cavalier);

    // On part du principe qu'il n'y à pas d'erreur dans le deplacement
    erreur->type = pas_erreur;
    erreur->coord_x = -1;
    erreur->coord_y = -1;

    dx = x_destination - cavalier_a_deplacer->coord_x;
    if(dx < 0)
        dx = -dx;
    dy = y_destination - cavalier_a_deplacer->coord_y;
    if(dy < 0)
        dy = -dy;

    if(dx == 0 && dy == 0)
    {
       deplacement_valide = 0;
       erreur->type = erreur_absence_de_deplacement;
    }
    else if((dx != 1 && dy != 2) || (dx != 2 && dy != 1))
    {
        deplacement_valide = 0;
        erreur->type = erreur_deplacement_piece_impossible;
    }
    else if(piece_a_destination == 1)
    {
        deplacement_valide = 0;
        erreur->type = erreur_piece_blocant_trajet;
        erreur->coord_x = x_destination;
        erreur->coord_y = y_destination;
    }

    return deplacement_valide;
}

int echiquier_deplacement_standard_est_valide_roi(const echiquier* echiquier_courant,
                                                       piece* roi_a_deplacer,
                                                       int x_destination, int y_destination,
                                                       code_erreur_deplacement* erreur)
{
    assert(echiquier_courant != NULL);
    assert(roi_a_deplacer != NULL);
    assert(coordonnee_est_valide(x_destination, y_destination) != 0);

    const jeu *jeu_courant=echiquier_recupere_jeu_courant_information(echiquier_courant);
    const piece *piece_au_depart=jeu_recuperer_piece_information(jeu_courant,
                                                                 roi_a_deplacer->coord_x,
                                                                 roi_a_deplacer->coord_y);
    int dx, dy,
            deplacement_valide=1, /* Le déplacement est considéré initialement comme valide */
            piece_a_destination=jeu_existe_piece(jeu_courant, x_destination, y_destination);

    // On vérifie qu'il y a bien un roi aux coordonnées de départ dans le jeu courant
    assert(piece_au_depart->type == roi);

    // On part du principe qu'il n'y à pas d'erreur dans le deplacement
    erreur->type = pas_erreur;
    erreur->coord_x = -1;
    erreur->coord_y = -1;

    dx = x_destination - roi_a_deplacer->coord_x;
    if(dx < 0)
        dx = -dx;
    dy = y_destination - roi_a_deplacer->coord_y;
    if(dy < 0)
        dy = -dy;

    if(dx == 0 && dy == 0)
    {
       deplacement_valide = 0;
       erreur->type = erreur_absence_de_deplacement;
    }
    else if(dx > 1 && dy > 1)
    {
        deplacement_valide = 0;
        erreur->type = erreur_deplacement_piece_impossible;
    }
    else if(piece_a_destination == 1)
    {
        deplacement_valide = 0;
        erreur->type = erreur_piece_blocant_trajet;
        erreur->coord_x = x_destination;
        erreur->coord_y = y_destination;
    }

    return deplacement_valide;
}
