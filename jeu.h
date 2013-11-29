
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
 * Un Jeu de piece est un ensemble de pieces appartenant a un joueur (soit joueur avec pieces blanches, soit joueur avec pieces noires).
 * Un jeu contient au maximum 16 pieces au depart.
 * Un jeu d'un joueur donne n'a pas connaissance du jeu du joueur adverse.
 * Ici le conteneur de pieces du jeu est implementee sous forme de tableau de taille constante.
 *
 */


//#Nom1: BERNARD
//#Prenom1: Florian
//#Nom2: VARAUT
//#Prenom2: Charles
//#Groupe: D


#ifndef JEU_H
#define JEU_H

#include "piece.h"


/**
 * **************************************************
 * **************************************************
 *
 * DECLARATION DES TYPES ET ENUMERATIONS DE JEU DE PIECES
 *
 * **************************************************
 * **************************************************
 */



/** Un jeu contient au maximum 16 pieces a son initialisation */
#define MAX_PIECE 16

/** La structure de jeu pouvant contenir jusqu'a 16 pieces
    Les pieces seront toujours ordonnees de la maniere suivante:
      - Les pieces valides du jeu seront positionnees a l'avant du tableau
      - Les pieces invalides du jeu (ex. pieces capturees) seront positionnees a l'arriere du tableau
        (Il ne devra jamais y avoir de piece valide situee apres une piece invalide dans le tableau)
      - Un jeu valide devra toujours posseder un roi et un seul.
*/
typedef struct{
  piece ensemble_de_piece[MAX_PIECE]; //l'acces a la piece d'indice k se realise par l'appel <jeu_de_piece>.ensemble_de_piece[k]
}jeu;





/**
 * **************************************************
 * **************************************************
 *
 * DECLARATION DES FONCTIONS DE JEU DE PIECES
 *
 * **************************************************
 * **************************************************
 */



/**
 * Fonction jeu_compter_nombre_piece:
 * ********************************
 *   Renvoie le nombre de pieces valides contenues dans le jeu
 *
 *   Necessite:
 *     - Un pointeur constant vers un jeu de pieces non NULL.
 *   Garantie:
 *     - Renvoie le nombre de pieces valides de ce jeu.
 */
int jeu_compter_nombre_piece(const jeu *jeu_de_piece);


/**
 * Fonction jeu_existe_piece:
 * ********************************
 *   Recherche si il existe une piece aux coordonnees (x,y) indiquees
 *
 *   Necessite:
 *     - Un pointeur constant vers un jeu de pieces non NULL.
 *     - Deux coordonnees entieres valides (comprises entre [0,7]).
 *   Garantie:
 *     - Renvoie 1 si il existe une piece de ce jeu avec ces coordonnees.
 *     - Renvoie 0 sinon.
 *
 */
int jeu_existe_piece(const jeu* jeu_de_piece,int coordonnee_x,int coordonnee_y);


/**
 * Fonction jeu_recuperer_piece:
 * ********************************
 *   Recupere une piece du jeu aux coordonnees (x,y) indiquees si la piece existe
 *
 *   Necessite:
 *     - Un pointeur non constant vers un jeu de pieces non NULL.
 *     - Deux coordonnees entieres valides (comprises entre [0,7]).
 *   Garantie:
 *     - Renvoie un pointeur vers la piece du jeu correspondante si celle-ci existe avec ces coordonnees.
 *        La piece du jeu recuperee peut ensuite etre modifiee ulterieurement.
 *        La piece du jeu retournee est valide.
 *     - Renvoie le pointeur NULL si aucune piece valide n'existe a ces coordonnees
 *
 *     Note(1): Si le pointeur NULL est retourne, alors la fonction jeu_existe_piece() appliquee a ces memes coordonnees doit retourner 0
 *     Note(2): Si une piece du jeu est retournee, alors la fonction jeu_existe_piece() appliquee a ces memes coordonnees doit retourner 1
 *
 */
piece *jeu_recuperer_piece(const jeu *jeu_de_piece,int coordonnee_x,int coordonnee_y);


/**
 * Fonction jeu_recuperer_piece_information:
 * *****************************************
 *   Recupere une piece du jeu aux coordonnees (x,y) indiquees si la piece existe
 *
 *   Necessite:
 *     - Un pointeur constant vers un jeu de pieces non NULL.
 *     - Deux coordonnees entieres valides (comprises entre [0,7]).
 *   Garantie:
 *     - Renvoi un pointeur vers la piece du jeu correspondante si celle-ci existe a ces coordonnees.
 *        La piece du jeu recuperee ne sert que d'information et ne pourra pas etre modifiee ulterieurement.
 *        La piece du jeu retournee est valide.
 *     - Renvoi le pointeur NULL si aucune piece valide n'existe a ces coordonnees
 *
 *     Note(1): Si le pointeur NULL est retournée, alors la fonction jeu_existe_piece() appliquee a ces memes coordonnees doit retourner 0
 *     Note(2): Si une piece du jeu est retournee, alors la fonction jeu_existe_piece() appliquee a ces memes coordonnees doit retourner 1
 *
 */
const piece *jeu_recuperer_piece_information(const jeu *jeu_de_piece,int coordonnee_x,int coordonnee_y);

/**
 * Fonction jeu_recuperer_roi_information:
 * ***************************************
 *   Recupere le roi du jeu
 *
 *   Necessite:
 *     - Un pointeur constant vers un jeu de pieces non NULL.
 *   Garantie:
 *     - Renvoie un pointeur vers le roi du jeu.
 *        La piece du jeu recuperee ne sert que d'information et ne pourra pas etre modifiee ulterieurement.
 *        La piece du jeu retournee est valide.
 *     - Renvoie le pointeur NULL si aucun roi n'est trouve.
 *
 */
const piece* jeu_recuperer_roi_information(const jeu* jeu_de_piece);


/**
 * Fonction jeu_est_integre:
 * *************************
 *   Verifie qu'un jeu suit l'organisation voulue:
 *     - Toutes les pieces valides sont toutes situees a l'avant du tableau
 *         et les pieces invalides sont toutes a l'arriere.
 *     - Un jeu doit posseder un roi, et celui-ci doit etre unique
 *
 *   Necessite:
 *     - Un pointeur constant vers le jeu de pieces. Pointeur non NULL.
 *   Garantie:
 *     - Retourne 1 si le jeu est valide
 *     - Retourne 0 sinon.
 */
int jeu_est_integre(const jeu* jeu_de_piece);


/**
 * Fonction jeu_supprimer_piece:
 * *****************************
 *   Supprime une piece designee par ses coordonnees du jeu adverse
 *
 *   Necessite:
 *     - Un pointeur non constant vers le jeu de pieces. Pointeur non NULL.
 *     - Les coordonnees indiquees sont valides (entiers entre [0,7]).
 *     - Il existe une piece valide dans le jeu aux coordonnees (x,y) indiquees.
 *     - Il n'existe aucune piece valide situee apres une piece invalide dans le tableau de pieces.
 *   Garantie:
 *     - Le jeu de piece ne contient plus la piece designee comme valide.
 *     - Dans le tableau de pieces, la piece devenue invalide est situee apres toutes les autres pieces valides.
 */
void jeu_supprimer_piece(jeu *jeu_de_piece,int coordonnee_x,int coordonnee_y);


/**
 * Fonction jeu_afficher_debug:
 * ****************************
 *    Affiche sur la sortie standard l'ensemble des informations des pieces du jeu
 *    Utile pour des fins de debug.
 *
 *   Necessite:
 *      - Un pointeur constant non NULL vers un jeu valide ou non.
 *   Garantie:
 *      - L'affichage des donnees de chaque piece du jeu.
 */
void jeu_afficher_debug(const jeu* jeu_de_piece);



#endif
