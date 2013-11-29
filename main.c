
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
 * Point d'entree du programme du jeu d'echec.
 *
 */

//#Nom1: BERNARD
//#Prenom1: Florian
//#Nom2: VARAUT
//#Prenom2: Charles
//#Groupe: D


#include <string.h>
#include <stdio.h>

#include "echiquier.h"
#include "entree_sortie.h"
#include "api_echec.h"
#include "piece.h"


int main()
{
    puts("");

//    int i, nb_pieces_valides;
//    jeu jeu_test;
//    piece piece0={fou,3,4}, piece1={roi,2,5}, piece2={tour,-1,1}, piece3={15,1,5}, piece4={dame,2,-4};

//    jeu_test.ensemble_de_piece[0] = piece0;
//    jeu_test.ensemble_de_piece[1] = piece1;
//    jeu_test.ensemble_de_piece[2] = piece2;
//    jeu_test.ensemble_de_piece[3] = piece3;
//    jeu_test.ensemble_de_piece[4] = piece4;
//    for(i=5;i<MAX_PIECE;i++)
//    {
//        jeu_test.ensemble_de_piece[i].type = invalide;
//        jeu_test.ensemble_de_piece[i].coord_x = -1;
//        jeu_test.ensemble_de_piece[i].coord_y = -1;
//    }

//    // Test de la fonction "jeu_compter_nombre_piece" :
//    nb_pieces_valides = jeu_compter_nombre_piece(&jeu_test);
//    printf(" Il y a %d pieces valides dans ce jeu\n", nb_pieces_valides);
//    // On doit avoir 2 pieces valides

//    // Tests de la fonction "jeu_existe_piece" :
//    // Tests valides
//    if(jeu_existe_piece(&jeu_test, 3, 4) == 1)  puts(" Il y a bien une piece en [3,4]");
//    if(jeu_existe_piece(&jeu_test, 2, 5) == 1)  puts(" Il y a bien une piece en [2,5]");
//    if(jeu_existe_piece(&jeu_test, 1, 5) != 1)  puts(" Il y a bien une piece en [1,5]");
//    // Tests invalides car les coordonnées de sont pas bonnes ou que le pointeur sur jeu est NULL
//    if(jeu_existe_piece(&jeu_test, 3, 3) != 1)  puts(" Il n'y a pas de piece en [3,3]");
//    if(jeu_existe_piece(&jeu_test, 0, 2) == 0)  puts(" Il n'y a pas de piece en [0,2]");
//    //if(jeu_existe_piece(NULL, 0, 2) == 0)

//    puts("");

//    // Tests de la fonction "jeu_recuperer_piece" :
//    // Tests valides
//    piece0 = *jeu_recuperer_piece(&jeu_test, 3, 4);
//    printf(" Piece de type %d, de coordonnees (%d,%d)\n", piece0.type, piece0.coord_x, piece0.coord_y);
//    piece1 = *jeu_recuperer_piece(&jeu_test, 2, 5);
//    printf(" Piece de type %d, de coordonnees (%d,%d)\n", piece1.type, piece1.coord_x, piece1.coord_y);

//    puts("");
//    // Tests de la fonction "jeu_recuperer_piece_information" :
//    // Tests valides
//    piece0 = *jeu_recuperer_piece_information(&jeu_test, 3, 4);
//    printf(" Piece de type %d, de coordonnees (%d,%d)\n", piece0.type, piece0.coord_x, piece0.coord_y);
//    piece1 = *jeu_recuperer_piece_information(&jeu_test, 2, 5);
//    printf(" Piece de type %d, de coordonnees (%d,%d)\n", piece1.type, piece1.coord_x, piece1.coord_y);

    api_echec_lance_mode_interactif();

    puts("");
    return 0;
}
