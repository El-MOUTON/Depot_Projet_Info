
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
 * Fonctions de gestion du deplacement des pieces du jeu d'echec.
 * Le niveau d'abstraction de "echiquier_deplacement" a connaissance des regles du jeu d'echec et permet
 *   d'assurer leur suivit lors d'une partie.
 * Les fonctions donnees sont generiques vis a vis du type de piece. L'implementation de ces fonctions est
 *   dependante d'une partie de gestion specifique a chaque piece. Ces fonctions d'aides sont decrite dans
 *   le cadre de "echiquier_deplacement_privee".
 *
 */

//#Nom1: BERNARD
//#Prenom1: Florian
//#Nom2: VARAUT
//#Prenom2: Charles
//#Groupe: D


#ifndef ECHIQUIER_DEPLACEMENT_H
#define ECHIQUIER_DEPLACEMENT_H

#include "echiquier.h"
#include "historique_partie.h"


/**
 * **************************************************
 * **************************************************
 *
 * DECLARATION DES TYPES ET ENUMERATIONS DE ECHIQUIER_DEPLACEMENT
 *
 * **************************************************
 * **************************************************
 */

/** Type d'erreur pouvant se produire lors de la demande d'un deplacement */
typedef enum {pas_erreur,
              erreur_deplacement_piece_impossible,
              erreur_absence_de_deplacement,
              erreur_piece_blocant_trajet,
              erreur_prise_en_passant_non_permise,
              erreur_roque_non_permis,
              erreur_roi_en_echec}
             type_erreur;



/** La structure d'enregistrement des erreurs */
typedef struct
{
    type_erreur type; //le type d'erreur rencontre
    int coord_x;      //la coordonnee x d'ou provient l'erreur (si blocage de piece)
    int coord_y;      //la coordonnee y d'ou provient l'erreur (si blocage de piece)
}code_erreur_deplacement;





/**
 * **************************************************
 * **************************************************
 *
 * DECLARATION DES FONCTIONS DE ECHIQUIER_DEPLACEMENT
 *
 * **************************************************
 * **************************************************
 */


/**
 * Fonction nommer_type_erreur:
 * *************************
 *
 *  Fonction renvoyant la chaine de caractere correspondant au type d'erreur.
 *  Utilisation comme une table de correspondance
 *
 *  Necessite:
 *      - Le type d'erreur (un entier positif)
 *   Garantie:
 *      - Le retour sous forme de chaine de caractere du type d'erreur.
 *      - Termine le programme en erreur si le type_erreur est invalide
 */
const char* nommer_type_erreur(type_erreur erreur);


/**
 * Fonction echiquier_deplacement_realise_si_possible:
 * ***************************************************
 *
 *  Fonction tentant de realiser le coup demande si possible.
 *  Indique le type de coup (standard ou coup special: roque, promotion, ...)
 *  Indique le type d'erreur si le coup n'est pas permis.
 *
 *  Cette fonction gere les deplacements standards, mais egalement l'ensemble des coups speciaux.
 *   - Elle n'autorise pas le deplacement d'une piece laissant le roi en echec
 *   - Elle permet les roques si ceux-ci sont valides
 *   - Elle permet la prise en passant du pion
 *   - Elle indique dans la variable coup si un pion necessite une promotion mais ne traite pas
 *       la promotion elle meme en une autre piece
 *
 *
 *  Necessite:
 *      - Un pointeur non constant vers un echiquier valide. Pointeur non NULL.
 *      - Deux coordonnees valides de departs et d'arrivees.
 *      - Les coordonnes de depart doivent designer une piece existante du jeu courant.
 *      - Un pointeur constant vers un historique des coups. Pointeur non NULL.
 *      - Un pointeur non constant permettant de stocker si une erreur empeche le deplacement. Pointeur non NULL.
 *      - Un pointeur non constant permettant de stocker le type de deplacement. Pointeur non NULL.
 *   Garantie:
 *      - Si le deplacement est realisable:
 *            - L'echiquier est modifie afin de prendre en compte le deplacement.
 *            - Le code d'erreur possede un type valant "pas_erreur".
 *            - Le type de deplacement indique le type de coup realise.
 *      - Si le deplacement n'est pas realisable:
 *            - L'echiquier n'est pas modifiee.
 *            - Le code d'erreur renvoie des information sur la non faisabilite du coup
 *               (c.a.d une valeur d'erreur differente de "pas_erreur")
 */
void echiquier_deplacement_realise_si_possible(echiquier* echiquier_courant,
                                               int x_depart,int y_depart,
                                               int x_destination,int y_destination,
                                               const historique_partie* historique,
                                               code_erreur_deplacement* erreur,
                                               type_deplacement* coup);


/**
 * Fonction echiquier_deplacement_coup_standard_est_valide:
 * ********************************************************
 *   Verifie si un deplacement de piece est valide ou non en dehors des coups speciaux.
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
 *     - Deux coordonnees (x,y) de depart valide.
 *     - Deux coordonnees (x,y) de destination valide.
 *     - Les coordonnes de depart doivent designer une piece existante du jeu courant.
 *     - Un pointeur non constant permettant de stocker si une erreur empeche le deplacement. Pointeur non NULL.
 *   Garantie:
 *     - Renvoie de la valeur 0 si le deplacement n'est pas valide (en dehors des coups speciaux).
 *        Le code d'erreur est alors mis a jour avec le type d'erreur correspondant.
 *     - Renvoie de la valeur 1 si le deplacement est valide (meme si le coup laisse le roi en echec).
 *        Le code d'erreur possede un type valant "pas_erreur"
 */
int echiquier_deplacement_coup_standard_est_valide(const echiquier* echiquier_courant,
                                                   int x_courant,int y_courant,
                                                   int x_destination,int y_destination,
                                                   code_erreur_deplacement *erreur);


/**
 * Fonction echiquier_deplacement_realise_coup_standard:
 * ********************************
 *   Realise le deplacement "standard" d'une piece du jeu d'echec.
 *    C'est a dire modifie les coordonnees d'une piece vers les coordonnees
 *    de destination. Realise egalement la "capture" des pieces adverses si necessaire.
 *
 *   Necessite:
 *     - Un pointeur non constant vers un echiquier valide non NULL.
 *     - Deux coordonnees (x,y) de depart valide.
 *     - Deux coordonnees (x,y) de destination valide.
 *     - Le deplacement "standard" des coordonnees de depart vers la destination est valide.
 *   Garantie:
 *     - La piece designee possede les coordonnees (x_destination,y_destination)
 *     - Si une piece adverse est presente aux coordonnees de destination,
 *             alors elle est supprimee (et devient invalide).
 */
void echiquier_deplacement_realise_coup_standard(echiquier* echiquier_courant,
                                                 int x_courant,int y_courant,
                                                 int x_destination,int y_destination);







#endif
