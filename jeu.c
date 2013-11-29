
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
 * Implementation des fonction de jeu.
 *
 */


//#Nom1: BERNARD
//#Prenom1: Florian
//#Nom2: VARAUT
//#Prenom2: Charles
//#Groupe: D


#include "jeu.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


int jeu_compter_nombre_piece(const jeu* jeu_de_piece)
{
    assert(jeu_de_piece != NULL);

    //Initialiser compteur <- 0
    //Tant que compteur < MAX_PIECE et piece courante est valide
    //  Incremente compteur si piece courante est valide
    //Retourne compteur

    const piece* piece_courante=&jeu_de_piece->ensemble_de_piece[0];
    int compteur=0, piece_valide=piece_est_valide(piece_courante);

    while(piece_valide == 1 && compteur < MAX_PIECE)
    {
        compteur++;
        piece_courante = &jeu_de_piece->ensemble_de_piece[compteur];
        piece_valide = piece_est_valide(piece_courante);
    }

    return compteur;
}


int jeu_existe_piece(const jeu* jeu_de_piece,int coordonnee_x,int coordonnee_y)
{
    assert(jeu_de_piece != NULL);
    assert(coordonnee_est_valide(coordonnee_x, coordonnee_y) != 0);

    //Initialiser piece_presente <- 0
    //Tant que compteur < MAX_PIECE et que la piece n'a pas ces coordonnées
    //  Compare les coordonnées passées en entrées avec celle de la piece courante
    //Retourne piece_presente

    int piece_presente=0, compteur=0;
    const piece* piece_courante;

    while(piece_presente != 1 && compteur < MAX_PIECE)
    {
        piece_courante = &jeu_de_piece->ensemble_de_piece[compteur];
        if(piece_courante->coord_x == coordonnee_x)
        {
            if(piece_courante->coord_y == coordonnee_y)
            {
                piece_presente = 1;
            }
        }

        compteur++;
    }

    return piece_presente;
}


piece *jeu_recuperer_piece(const jeu *jeu_de_piece, int coordonnee_x, int coordonnee_y)
{
    assert(jeu_de_piece != NULL);
    assert(coordonnee_est_valide(coordonnee_x, coordonnee_y) != 0);

    int piece_presente=0, compteur=0;
    piece *piece_courante;
    piece *piece_recherchee=NULL;

    while(piece_presente != 1 && compteur < MAX_PIECE)
    {
        piece_courante = &jeu_de_piece->ensemble_de_piece[compteur];
        if(piece_courante->coord_x == coordonnee_x)
        {
            if(piece_courante->coord_y == coordonnee_y)
            {
                piece_recherchee = piece_courante;
                piece_presente = 1;
            }
        }

        compteur++;
    }

    return piece_recherchee;
}


const piece *jeu_recuperer_piece_information(const jeu* jeu_de_piece,int coordonnee_x,int coordonnee_y)
{
    assert(jeu_de_piece != NULL);
    assert(coordonnee_est_valide(coordonnee_x, coordonnee_y) != 0);

    const piece* piece_recherchee;

    piece_recherchee = jeu_recuperer_piece(jeu_de_piece, coordonnee_x, coordonnee_y);

    return piece_recherchee;
}


const piece *jeu_recuperer_roi_information(const jeu* jeu_de_piece)
{
    assert(jeu_de_piece != NULL);

    const piece* piece_roi=NULL;
    const piece* piece_courante;
    int compteur=0, roi_present=0;

    while(roi_present != 1 && compteur < MAX_PIECE)
    {
        piece_courante = &jeu_de_piece->ensemble_de_piece[compteur];

        if(piece_courante->type == roi)  piece_roi = piece_courante;

        compteur++;
    }

    return piece_roi;
}


int jeu_est_integre(const jeu* jeu_de_piece)
{
    assert(jeu_de_piece != NULL);

    int piece_valide=1;
    int indice_piece=0;

    //Parcours toutes les pieces valides jusqu'à rencontrer piece invalide ou fin de tableau
    do
    {
        const piece *piece_courante=&jeu_de_piece->ensemble_de_piece[indice_piece];
        if(piece_est_valide(piece_courante))
            indice_piece++;
        else
            piece_valide=0;

    }while(piece_valide==1 && indice_piece<MAX_PIECE);

    //Pour tout le reste du tableau
    //  Si rencontre piece invalide
    //    Alors retourne 0
    //Retourne 1
    while(indice_piece<MAX_PIECE)
    {
        const piece *piece_courante=&jeu_de_piece->ensemble_de_piece[indice_piece];

        if(piece_est_valide(piece_courante))
            return 0;

        indice_piece++;
    }


    //Recherche d'un roi unique:
    //
    //Initialise roi_unique <- faux
    //Pour toute les pieces
    //  Si piece courante est un roi
    //     Si roi_unique==vrai, Alors Renvoie 0
    //     Si roi_unique==faux, Alors roi_unique<-vrai
    //Si roi_unique==faux, Alors Renvoie 0
    int roi_unique=0;
    for(indice_piece=0;indice_piece<MAX_PIECE;++indice_piece)
    {
        const piece* piece_courante=&jeu_de_piece->ensemble_de_piece[indice_piece];
        if(piece_courante->type == roi)
        {
            if(roi_unique == 1)
                return 0;
            roi_unique = 1;
        }
    }
    if(roi_unique==0)
        return 0;


    return 1;
}


void jeu_supprimer_piece(jeu *jeu_de_piece,int coordonnee_x,int coordonnee_y)
{
    assert(jeu_de_piece!=NULL);
    assert(coordonnee_est_valide(coordonnee_x,coordonnee_y)==1);

    int i;

    //Parcours tableau jusqu'a trouver la piece designee
    //Pour les pieces suivantes jusqu'a l'avant derniere
    //    copier chaque pieces d'une position vers l'avant dans le tableau
    //Invalider la  derniere piece

    for(i=0;i<MAX_PIECE;i++)
    {
        if(jeu_de_piece->ensemble_de_piece[i].coord_x == coordonnee_x)
        {
            if(jeu_de_piece->ensemble_de_piece[i].coord_y == coordonnee_y)
            {
                while(i < MAX_PIECE - 1)
                {
                    jeu_de_piece->ensemble_de_piece[i] = jeu_de_piece->ensemble_de_piece[i+1];
                    i++;
                }
                jeu_de_piece->ensemble_de_piece[i].type = invalide;
                jeu_de_piece->ensemble_de_piece[i].coord_x = -1;
                jeu_de_piece->ensemble_de_piece[i].coord_y = -1;
            }
        }
    }
}


void jeu_afficher_debug(const jeu* jeu_de_piece)
{
    assert(jeu_de_piece!=NULL);

    int k=0;
    int N=jeu_compter_nombre_piece(jeu_de_piece);

    for(k=0;k<N;++k)
        piece_afficher_debug(&jeu_de_piece->ensemble_de_piece[k]);
}
