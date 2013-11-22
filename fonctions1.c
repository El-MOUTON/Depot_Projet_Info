
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
 * Ensemble des fonctions créées lors de la scéance n°1.
 *
 */

//#Nom1: BERNARD
//#Prenom1: Florian
//#Nom2: VARAUT
//#Prenom2: Charles
//#Groupe: D


#include "fonctions1.h"
#include "jeu.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


int jeu_compter_nombre_piece(const jeu *jeu_de_piece)
{
    //Initialiser compteur <- 0
    //Tant que compteur < MAX_PIECE et piece courante est valide
    //  Incremente compteur si piece courante est valide
    //Retourne compteur

    int compteur=0, test;
    const piece *piece_courante;

    *piece_courante = *jeu_de_piece->ensemble_de_piece[compteur];
    test = piece_est_valide(piece_courante);

    while(compteur < MAX_PIECE && test == 1)
    {
        compteur++;
        *piece_courante = *jeu_de_piece->ensemble_de_piece[compteur];
        test = piece_est_valide(piece_courante);
    }

    return compteur;
}


