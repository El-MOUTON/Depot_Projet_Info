
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
 * Fonctions de gestion du deplacement standard des pieces du jeu d'echec.
 */

//#Nom1: BERNARD
//#Prenom1: Florian
//#Nom2: VARAUT
//#Prenom2: Charles
//#Groupe: D

#ifndef ECHIQUIER_DEPLACEMENT_STANDARD_H
#define ECHIQUIER_DEPLACEMENT_STANDARD_H

#include "echiquier_deplacement.h"
#include "echiquier.h"
#include "historique_partie.h"


/**
 * Fonction echiquier_deplacement_coup_standard_est_valide_cavalier:
 * *****************************************************************
 *   Verifie si un deplacement de cavalier est valide ou non en dehors des coups speciaux.
 *   Seul le deplacement de base "standard" des pieces est verifie et la mise en echec n'est pas prise en compte dans le resultat.
 *
 *   Note: Un coup "standard" est defini comme le deplacement d'une seule piece des coordonnees (x0,y0) vers les
 *    coordonnees (x1,y1). Les coups standards ne transforment pas le type de piece (pas de promotion du pion) et
 *    ne tiennent pas compte du fait que le roi soit en echec ou non.
 *
 *   Les coups speciaux consideres comme invalides sont: le roque, la prise en passant du pion
 *   Les coups speciaux traites comme des deplacements standards sont: les promotions du pion
 *   Il n'y a pas d'etude de la mise en echec a ce niveau: un coup amenant le joueur a etre en echec sera
 *     tout de meme considere comme valide a ce niveau.
 *
 *   Si le deplacement n'est pas valide, un code d'erreur decrivant la situation est retourne dans la variable d'erreur.
 *
 *   Necessite:
 *     - Un pointeur constant vers un echiquier valide non NULL.
 *     - Un pointeur vers le cavalier à déplacer non NULL.
 *     - Deux coordonnees (x,y) de destination valide.
 *     - Les coordonnes de depart doivent designer un cavalier existant du jeu courant.
 *     - Un pointeur non constant permettant de stocker si une erreur empeche le deplacement. Pointeur non NULL.
 *   Garantie:
 *     - Renvoie de la valeur 0 si le deplacement n'est pas valide (en dehors des coups speciaux).
 *        Le code d'erreur est alors mis a jour avec le type d'erreur correspondant.
 *     - Renvoie de la valeur 1 si le deplacement est valide (meme si le coup laisse le roi en echec).
 *        Le code d'erreur possede un type valant "pas_erreur"
 */
int echiquier_deplacement_standard_est_valide_cavalier(const echiquier* echiquier_courant,
                                                       piece* cavalier_a_deplacer,
                                                       int x_destination, int y_destination,
                                                       code_erreur_deplacement* erreur);


/**
 * Fonction echiquier_deplacement_coup_standard_est_valide_roi:
 * ************************************************************
 *   Verifie si un deplacement de roi est valide ou non en dehors des coups speciaux.
 *   Seul le deplacement de base "standard" des pieces est verifie et la mise en echec n'est pas prise en compte dans le resultat.
 *
 *   Note: Un coup "standard" est defini comme le deplacement d'une seule piece des coordonnees (x0,y0) vers les
 *    coordonnees (x1,y1). Les coups standards ne transforment pas le type de piece (pas de promotion du pion) et
 *    ne tiennent pas compte du fait que le roi soit en echec ou non.
 *
 *   Les coups speciaux consideres comme invalides sont: le roque, la prise en passant du pion
 *   Les coups speciaux traites comme des deplacements standards sont: les promotions du pion
 *   Il n'y a pas d'etude de la mise en echec a ce niveau: un coup amenant le joueur a etre en echec sera
 *     tout de meme considere comme valide a ce niveau.
 *
 *   Si le deplacement n'est pas valide, un code d'erreur decrivant la situation est retourne dans la variable d'erreur.
 *
 *   Necessite:
 *     - Un pointeur constant vers un echiquier valide non NULL.
 *     - Un pointeur vers le roi à déplacer non NULL.
 *     - Deux coordonnees (x,y) de destination valide.
 *     - Les coordonnes de depart doivent designer un roi existant du jeu courant.
 *     - Un pointeur non constant permettant de stocker si une erreur empeche le deplacement. Pointeur non NULL.
 *   Garantie:
 *     - Renvoie de la valeur 0 si le deplacement n'est pas valide (en dehors des coups speciaux).
 *        Le code d'erreur est alors mis a jour avec le type d'erreur correspondant.
 *     - Renvoie de la valeur 1 si le deplacement est valide (meme si le coup laisse le roi en echec).
 *        Le code d'erreur possede un type valant "pas_erreur"
 */
int echiquier_deplacement_standard_est_valide_cavalier(const echiquier* echiquier_courant,
                                                       piece* roi_a_deplacer,
                                                       int x_destination, int y_destination,
                                                       code_erreur_deplacement* erreur);
#endif
