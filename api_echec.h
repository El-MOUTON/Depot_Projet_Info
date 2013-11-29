
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
 * API du jeu d'echec
 * l'API lance une lecture d'actions a realiser en ligne de commande.
 * l'API fournie une interface de haut niveau afin de controler le comportement du jeu.
 * l'API n'a pas connaissance des regles internes du jeu, mais elle appelle les fonctions de controle permettant d'assurer un comportement valide.
 * Elle realiser l'interface entre l'utilisateur et les fonctions internes, les parametres d'entrees sont protegees contre les erreurs d'entrees
 *   sans faire quitter le programme.
 *
 */

//#Nom1: BERNARD
//#Prenom1: Florian
//#Nom2: VARAUT
//#Prenom2: Charles
//#Groupe: D



#ifndef MODE_INTERACTIF_API_H
#define MODE_INTERACTIF_API_H

#include "echiquier.h"
#include "historique_partie.h"


/**
 * Fonction api_echec_lance_mode_interactif:
 * ********************************
 *   Lance le mode interactif du jeu.
 *   Cree un nouvel echiquier et lance la communication en ligne de commande avec l'utilisateur.
 *
 *   Garantie:
 *     - La creation d'un nouvel echiquier.
 *     - La creation d'un dialogue en ligne de commande avec l'utilisateur.
 */
void api_echec_lance_mode_interactif();

/**
 * Fonction api_echec_deplacer_piece:
 * ********************************
 *   Demande le deplacement d'une piece du jeu en donnant ses coordonnees de depart et d'arrivee.
 *
 *   Necessite:
 *     - Un pointeur non constant vers un echiquier valide. Pointeur non NULL.
 *   Garantie:
 *     - Si les coordonnees sont valide, la piece est deplacee et le deplacement est affiche en ligne de commande.
 *     - Si les coordonnes sont invalides, l'echiquier n'est pas modifiee et le probleme rencontree est affichee en ligne de commande.
 */
void api_echec_deplacer_piece(echiquier* echiquier_courant,historique_partie *historique,int x_depart,int y_depart,int x_destination,int y_destination);

/**
 * Fonction api_echec_ecrit_fichier:
 * ********************************
 *   Demande l'ecriture de l'etat de l'echiquier dans le fichier designee.
 *
 *   Necessite:
 *     - Un pointeur constant non NULL vers un echiquier.
 *     - Un nom de fichier dans une chaine de caractere non NULL.
 *   Garantie:
 *     - Si le fichier designee est accessible, celui ci contient l'etat de l'echiquier.
 *     - Si le fichier designee n'est pas accessible, une erreur est affichee.
 */
int api_echec_ecrit_fichier_etat(const echiquier* echiquier_courant,const char* filename);

/**
 * Fonction api_echec_lit_fichier:
 * ********************************
 *   Demande la lecture de l'etat de l'echiquier a partir du fichier designee.
 *
 *   Necessite:
 *     - Un pointeur non constant non NULL vers un echiquier.
 *     - Un nom de fichier dans une chaine de caractere non NULL.
 *   Garantie:
 *     - Si le fichier designee existe et est lisible, l'echiquier courant contient l'etat decrit dans ce fichier.
 *     - Si le fichier designee n'existe pas, une erreur est affichee.
 */
int api_echec_lit_fichier_etat(echiquier* echiquier_courant,const char* filename);

#if 0
/**
 * Fonction api_echec_ajoute_fichier_dernier_coup:
 * ********************************
 *   Ajoute dans le fichier de description le dernier coup joué.
 *
 *   Necessite:
 *     - Les coordonnees valide du point de depart de la derniere piece jouee.
 *     - Les coordonnees valide du point d'arrivee de la derniere piece jouee.
 *     - Un nom de fichier non NULL.
 *   Garantie:
 *     - Si le fichier designee est accessible, celui ci contient le dernier coup joue sur la derniere ligne.
 *     - Si le fichier designee n'existe pas, ou si les coordonnees ne sont pas valide, une erreur est affichee.
 */
int api_echec_ajoute_fichier_dernier_coup(int x_depart,int y_depart,int x_arrivee,int y_arrivee,const char* fichier_sauvegarde);
#endif

int api_echec_ecrit_fichier_historique(const historique_partie* historique,const char* filename);
int api_echec_lit_fichier_historique(historique_partie* historique,const char* filename);

#endif
