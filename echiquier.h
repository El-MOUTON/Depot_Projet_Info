
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
 *
 * Un echiquier possede l'information d'un jeu de pieces blanches et d'un jeu de pieces noires.
 * Il possede egalement l'information du joueur pouvant jouer son tour.
 * L'echiquier peut gerer l'initialisation du placement des pieces, et peut verifier l'integritee d'un jeu complet.
 *
 * L'echiquier n'a pas connaissances des regles algorithmiques de deplacement des pieces, il ne s'en charge pas.
 *  Cette partie est deleguee au niveau d'abstraction denommee "algorithmique_echec"
 * L'echiquier ne gere pas l'aspect entree/sortie dans un fichier ou a l'ecran.
 *  Cette partie est deleguee au niveau d'abstraction denomee "entree_sortie"
 *
 */

//#Nom1: BERNARD
//#Prenom1: Florian
//#Nom2: VARAUT
//#Prenom2: Charles
//#Groupe: D

#ifndef ECHIQUIER_H
#define ECHIQUIER_H

#include "jeu.h"

/**
 * **************************************************
 * **************************************************
 *
 * DECLARATION DES TYPES ET ENUMERATIONS DE ECHIQUIER
 *
 * **************************************************
 * **************************************************
 */

/** Structure d'un echiquier:
 *   - 2 jeux de pieces et le joueur courant
 */
typedef struct
{
    jeu jeu_de_piece_blanc; //le jeu de pieces blanches.
    jeu jeu_de_piece_noir;  //le jeu de pieces noires.
    int joueur_courant;     //le tour du joueur actuel (0 pour les pieces blanches, 1 pour les pieces noires).
}echiquier;

/**
 * **************************************************
 * **************************************************
 *
 * DECLARATION DES FONCTIONS DE ECHIQUIER
 *
 * **************************************************
 * **************************************************
 */


/**
 * Fonction echiquier_changer_joueur_courant:
 * ********************************
 *   Change le joueur courant de l'echiquier.
 *
 *   Necessite:
 *     - Un pointeur non constant vers un echiquier. Pointeur non NULL.
 *   Garantie:
 *     - Si le joueur courant vaut 0 (pieces blanches), alors il passe a 1 (pieces noires)
 *     - Si le joueur courant vaut 1 (pieces noires), alors il passe a 0 (pieces blanches)
 */
void echiquier_changer_joueur_courant(echiquier* echiquier_courant);


/**
 * Fonction echiquier_initialise:
 * ********************************
 *   Initialise l'echiquier complet tel que les pieces soient en position standard
 *      du debut d'un jeu d'echec. Le joueur blanc commence toujours.
 *
 *   Necessite:
 *     - Un pointeur non constant vers un echiquier. Pointeur non NULL.
 *   Garantie:
 *     - Les jeux de pieces blanches et noires sont en position de depart d'un nouveau jeu.
 *     - Le tour est au joueur blanc.
 *     - L'integritee de l'echiquier est valide.
 */
void echiquier_initialiser(echiquier* echiquier_a_initialiser);


/**
 * Fonction echiquier_afficher_debug:
 * *************************
 *    Affiche sur la sortie standard l'ensemble des informations d'un echiquier: pieces et joueur courant
 *    Utile pour des fins de debug.
 *
 *   Necessite:
 *      - Un pointeur constant non NULL vers un echiquier valide ou non.
 *   Garantie:
 *      - L'affichage des donnees de chaque piece du jeu blanc et noir ainsi que le joueur courant.
 */
void echiquier_afficher_debug(const echiquier* echiquier_a_afficher);


/**
 * Fonction echiquier_invalider:
 * ********************************
 *   Place l'ensemble des pieces de l'echiquier a l'etat invalide.
 *
 *   Necessite:
 *     - Un pointeur non constant vers un echiquier. Pointeur non NULL.
 *   Garantie:
 *     - Les jeux de pieces blanches et noires sont invalides.
 *     - Le tour est aux pieces blanches
 */
void echiquier_invalider_jeux(echiquier* echiquier_a_invalider);


/**
 * Fonction echiquier_est_integre:
 * ********************************
 *   Verifie qu'un echiquier contient des donnees plausibles pour une partie d'echec.
 *
 *   Necessite:
 *     - Un pointeur constant vers un echiquier. Pointeur non NULL.
 *   Garantie:
 *     - Le type de non integrite detectee est ecrite textuellement sur la ligne de commande.
 *     - Renvoie 1 si:
 *        - L'echiquier possede une configuration possible.
 *        - Aucune piece n'est dispose sur une meme case valide de l'echiquier.
 *        - Le tour du joueur est soit pour les pieces blanches, soit pour les pieces noires.
 *     - Renvoie 0 sinon.
 */
int echiquier_est_integre(const echiquier* echiquier_a_verifier);


/**
 * Fonction echiquier_recupere_jeu_courant_information
 * ********************************
 *   Recupere un pointeur (non modifiable) sur le jeu courant ou adverse.
 *
 *   Necessite:
 *     - Un pointeur constant vers un echiquier valide. Pointeur non NULL.
 *   Garantie:
 *     - Renvoie un pointeur constant vers: jeu_de_piece_blanc si joueur_courant=0
 *                                          jeu_de piece_noir  si joueur_courant=1
 *
 */
const jeu* echiquier_recupere_jeu_courant_information(const echiquier* echiquier_courant);


/**
 * Fonction echiquier_recupere_jeu_adverse_information:
 * ********************************
 *   Recupere un pointeur (non modifiable) sur le jeu courant ou adverse.
 *
 *   Necessite:
 *     - Un pointeur constant vers un echiquier valide. Pointeur non NULL.
 *   Garantie:
 *     - Renvoie un pointeur constant vers: jeu_de_piece_noir  si joueur_courant=0
 *                                          jeu_de piece_blanc si joueur_courant=1
 *
 */
const jeu* echiquier_recupere_jeu_adverse_information(const echiquier* echiquier_courant);


/**
 * Fonction echiquier_recupere_jeu_courant
 * ********************************
 *   Recupere un pointeur (modifiable) sur le jeu courant ou adverse.
 *
 *   Necessite:
 *     - Un pointeur non consant vers un echiquier valide. Pointeur non NULL.
 *   Garantie:
 *
 *
 *     - Renvoie un pointeur vers: jeu_de_piece_blanc si joueur_courant=0
 *                                 jeu_de piece_noir  si joueur_courant=1
 *
 */
jeu* echiquier_recupere_jeu_courant(echiquier* echiquier_courant);


/**
 * Fonction echiquier_recupere_jeu_adverse
 * ********************************
 *   Recupere un pointeur (modifiable) sur le jeu courant ou adverse.
 *
 *   Necessite:
 *     - Un pointeur non consant vers un echiquier valide. Pointeur non NULL.
 *   Garantie:
 *
 *
 *     - Renvoie un pointeur vers: jeu_de_piece_noir  si joueur_courant=0
 *                                 jeu_de piece_blanc si joueur_courant=1
 *
 */
jeu* echiquier_recupere_jeu_adverse(echiquier* echiquier_courant);


#endif
