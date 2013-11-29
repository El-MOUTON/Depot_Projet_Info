
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
 * Implementation des fonction de echiquier
 *
 */

//#Nom1: BERNARD
//#Prenom1: Florian
//#Nom2: VARAUT
//#Prenom2: Charles
//#Groupe: D


#include "echiquier.h"
#include "constructeur_piece.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


void echiquier_changer_joueur_courant(echiquier* echiquier_courant)
{
    assert(echiquier_courant!=NULL);

    int* joueur=&echiquier_courant->joueur_courant;

    switch(*joueur)
    {
    case 0:
        *joueur=1;
        break;
    case 1:
        *joueur=0;
        break;
    default:
        printf("Erreur integrite du joueur fonction %s \n",__FUNCTION__);
        abort();
    }
}

void echiquier_initialiser(echiquier* echiquier_a_initialiser)
{
    assert(echiquier_a_initialiser!=NULL);

    // Initialise le joueur courant au joueur associee aux pieces blanches (joueur 0)
    // Place les pieces les unes apres les autres dans l'echiquier


    echiquier_a_initialiser->joueur_courant=0;

    //construit les pieces une a une et les stockent pour chaque jeu de pieces

    piece *tableau_pieces_blanches=echiquier_a_initialiser->jeu_de_piece_blanc.ensemble_de_piece;
    piece *tableau_pieces_noires  =echiquier_a_initialiser->jeu_de_piece_noir.ensemble_de_piece;

    //placement des tours
    constructeur_piece_tour(&(tableau_pieces_blanches[0]),0,0);
    constructeur_piece_tour(&(tableau_pieces_blanches[1]),7,0);
    constructeur_piece_tour(&(tableau_pieces_noires[0])  ,0,7);
    constructeur_piece_tour(&(tableau_pieces_noires[1])  ,7,7);

    //placement des cavaliers
    constructeur_piece_cavalier(&(tableau_pieces_blanches[2]),1,0);
    constructeur_piece_cavalier(&(tableau_pieces_blanches[3]),6,0);
    constructeur_piece_cavalier(&(tableau_pieces_noires[2])  ,1,7);
    constructeur_piece_cavalier(&(tableau_pieces_noires[3])  ,6,7);

    //placement des fous
    constructeur_piece_fou(&(tableau_pieces_blanches[4]),2,0);
    constructeur_piece_fou(&(tableau_pieces_blanches[5]),5,0);
    constructeur_piece_fou(&(tableau_pieces_noires[4])  ,2,7);
    constructeur_piece_fou(&(tableau_pieces_noires[5])  ,5,7);

    //placement des reine
    constructeur_piece_dame(&(tableau_pieces_blanches[6]),3,0);
    constructeur_piece_dame(&(tableau_pieces_noires[6])  ,3,7);

    //placement des roi
    constructeur_piece_roi(&(tableau_pieces_blanches[7]),4,0);
    constructeur_piece_roi(&(tableau_pieces_noires[7])  ,4,7);

    //placement des pions
    int k=0;
    for(k=0;k<8;++k)
    {
        constructeur_piece_pion_blanc(&(tableau_pieces_blanches[8+k]),k,1);
        constructeur_piece_pion_noir (&(tableau_pieces_noires[8+k])    ,k,6);
    }

    assert(echiquier_est_integre(echiquier_a_initialiser)==1);
}


void echiquier_afficher_debug(const echiquier* echiquier_a_afficher)
{
    printf("joueur: %d\n",echiquier_a_afficher->joueur_courant);
    jeu_afficher_debug(&echiquier_a_afficher->jeu_de_piece_blanc);
    printf("joueur: %d\n",(echiquier_a_afficher->joueur_courant+1)%2);
    jeu_afficher_debug(&echiquier_a_afficher->jeu_de_piece_noir);
}


void echiquier_invalider_jeux(echiquier* echiquier_a_invalider)
{
    //Pour toutes les pieces du jeu
    // Invalider piece blanche courante
    // Invalider piece noire courante
    //Placer joueur courant a 0
    int k=0;
    for(k=0;k<MAX_PIECE;++k)
    {
        piece_invalider(&echiquier_a_invalider->jeu_de_piece_blanc.ensemble_de_piece[k]);
        piece_invalider(&echiquier_a_invalider->jeu_de_piece_noir.ensemble_de_piece[k]);
    }
    echiquier_a_invalider->joueur_courant=0;
}


int echiquier_est_integre(const echiquier* echiquier_a_verifier)
{
    assert(echiquier_a_verifier!=NULL);

    // Assurer joueur_courant vaut 0 ou 1.
    //
    // Verification de l'unicitee d'une piece sur une meme case:
    // Pour toutes les pieces
    //   Stocker coordonnee dans un tableau
    //   Pour toutes les valeurs deja remplies du tableau
    //      Verifier qu'il n'exite pas de coordonnees deja existantes identiques.

    printf("Fonction %s non implementee\n",__FUNCTION__);
    return 1;
}


const jeu* echiquier_recupere_jeu_courant_information(const echiquier* echiquier_courant)
{
    //coder fonction correspondante !
    return NULL;
}


const jeu* echiquier_recupere_jeu_adverse_information(const echiquier* echiquier_courant)
{
    //coder fonction correspondante !
    return NULL;
}


jeu* echiquier_recupere_jeu_courant(echiquier* echiquier_courant)
{
    //coder fonction correspondante !
    return NULL;
}


jeu* echiquier_recupere_jeu_adverse(echiquier* echiquier_courant)
{
    //coder fonction correspondante !
    return NULL;
}
