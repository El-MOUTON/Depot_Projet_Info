
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
 * Implementation des fonction de API_echec
 *
 */

//#Nom1: BERNARD
//#Prenom1: Florian
//#Nom2: VARAUT
//#Prenom2: Charles
//#Groupe: D

#include "api_echec.h"
#include "parseur_mode_interactif.h"
#include "echiquier_deplacement.h"
#include "entree_sortie.h"


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


// Nom du fichier de sauvegarde du jeu courant
const char *fichier_sauvegarde_etat="echec_etat.txt";
const char *fichier_sauvegarde_historique="echec_historique.txt";


void api_echec_lance_mode_interactif()
{

    printf("\n***********************\n");
    printf("Jeu echec mode interactif:\n");
    printf("***********************\n");
    printf("Commandes:\n");
    printf("> #                 : Commentaires, tout ce qui suit # n'est pas analyse.\n");
    printf("> i                 : Initialisation du jeu d'echec.\n");
    printf("> d x0 y0 -> x1 y1  : deplacement piece de (x0,y0) vers (x1,y1).\n");
    printf("> lit NOM_FICHIER   : Chargement etat de l'echiquier a partir du fichier\n");
    printf("> lit_h NOM_FICHIER : Chargement historique a partir du fichier\n");
    printf("***********************\n\n");
    fflush(stdout);

    //
    //Cree nouvel echiquier
    //Ecrit echiquier dans fichier
    //
    //Lance dialogue avec l'utilisateur:
    //Tant que ligne differente de "FIN"
    //  Recuperer ligne de la ligne de commande
    //  Parser ligne de commande
    //  Traiter les cas possible:
    //    */ deplacement de piece
    //    */ lecture fichier
    //    */ ecriture fichier
    //    */ initialisation du jeu
    //    */ fin du jeu
    //Fin Tant Que
    //

    //Initialisation echiquier et fichier
    echiquier echiquier_courant;
    historique_partie historique;

    echiquier_initialiser(&echiquier_courant);
    historique_initialise(&historique);

    api_echec_ecrit_fichier_etat(&echiquier_courant,fichier_sauvegarde_etat);
    api_echec_ecrit_fichier_historique(&historique,fichier_sauvegarde_historique);

    action_a_realiser action;
    action_initialise(&action);


    char buffer_ligne_commande[MAX_NOM_FICHIER_TAILLE];

    //Lecture de la ligne de commande jusqu'au mot cle "FIN"
    while(action.type!=fin)
    {
        printf("> ");
        fflush(stdout);

        //lecture entree de ligne de commande
        fgets(buffer_ligne_commande,MAX_LIGNE_COMMANDE,stdin);

        //parsing de la ligne de commande
        parse_ligne_commande(buffer_ligne_commande,&action);

        //les differents cas possibles
        switch(action.type)
        {
        case rien_a_faire:
            break;
        case deplacement:
            api_echec_deplacer_piece(&echiquier_courant,&historique,action.x_depart,action.y_depart,action.x_arrivee,action.y_arrivee);
            api_echec_ecrit_fichier_etat(&echiquier_courant,fichier_sauvegarde_etat);
            api_echec_ecrit_fichier_historique(&historique,fichier_sauvegarde_historique);

            //a faire: detection echec et mat
            //a faire: detection pat

            break;
        case lecture_fichier:
            if(api_echec_lit_fichier_etat(&echiquier_courant,action.filename)==1)
            {
                printf("Fichier %s lu\n",action.filename);
                api_echec_ecrit_fichier_etat(&echiquier_courant,fichier_sauvegarde_etat);

                historique_initialise(&historique);
                historique.echiquier_initial=echiquier_courant;
                api_echec_ecrit_fichier_historique(&historique,fichier_sauvegarde_historique);
            }
            else
                printf("Erreur lecture fichier %s\n",action.filename);
            fflush(stdout);
            break;
        case lecture_historique:
            if(api_echec_lit_fichier_historique(&historique,action.filename)==1)
            {
                printf("Fichier %s lu\n",action.filename);
                api_echec_ecrit_fichier_historique(&historique,fichier_sauvegarde_historique);
            }
            else
                printf("Erreur lecture fichier %s\n",action.filename);
            fflush(stdout);
            break;
        case initialisation:
            printf("Initialisation echiquier\n");fflush(stdout);
            echiquier_initialiser(&echiquier_courant);
            historique_initialise(&historique);
            api_echec_ecrit_fichier_etat(&echiquier_courant,fichier_sauvegarde_etat);
            api_echec_ecrit_fichier_historique(&historique,fichier_sauvegarde_historique);
            break;
        case fin:
            printf("Fin de la partie\n");fflush(stdout);
            break;
        default:
            printf("Erreur critique lecture ligne de commande");fflush(stdout);
            exit(1);
            break;
        }

    }
}

void api_echec_deplacer_piece(echiquier* echiquier_courant,historique_partie* historique,int x_depart,int y_depart,int x_destination,int y_destination)
{
    // ********************* //
    //Algorithme:
    // ********************* //
    //Verfication de l'echiquier
    //Si coordonnees de depart invalide, alors affiche erreur
    //Si coordonnees d'arrivees invalide, alors affiche erreur
    //Verifier qu'une piece existe aux coordonnees de departs, sinon afficher erreur
    //Verifier qu'il n'y a pas de pieces alliées aux coordonnees d'arrivees, sinon afficher erreur
    //Tenter d'effectuer deplacement
    //  Si deplacement est realise, alors
    //      enregistrer coup dans l'historique
    //      changer joueur courant
    //  Sinon
    //      afficher l'erreur et son code correspondant
    //

    printf("Fonction %s non implementee\n",__FUNCTION__);

}

int api_echec_ecrit_fichier_etat(const echiquier* echiquier_courant,const char* filename)
{
    //
    //Si le fichier designee est accessible
    //  Alors ecrit fichier
    //Sinon
    //  Affiche erreur
    //Fin Si
    //

    assert(echiquier_courant!=NULL);

    if(entree_sortie_est_fichier_accessible(filename)!=1)
    {
        printf("N'arrive pas a sauver l'etat courant dans fichier %s\n",filename);
        return 0;
    }

    entree_sortie_ecrit_fichier_echiquier(filename,echiquier_courant);
    return 1;
}
int api_echec_lit_fichier_etat(echiquier* echiquier_courant,const char* filename)
{
    //
    //Si le fichier designee existe
    //  Alors
    //       invalider ensemble de l'echiquier
    //       lit fichier et remplire l'echiquier
    //Sinon
    //  Affiche erreur
    //Fin Si
    //



    if(entree_sortie_est_fichier_existe(filename)!=1)
    {
        printf("Fichier %s n'existe pas\n",filename);
        return 0;
    }

    echiquier_invalider_jeux(echiquier_courant);
    entree_sortie_lit_fichier_echiquier(filename,echiquier_courant);

    return 1;
}

/*
int api_echec_ajoute_fichier_dernier_coup(int x_depart,int y_depart,int x_arrivee,int y_arrivee,const char* fichier_sauvegarde)
{
    //
    //Si le fichier designee existe et coordonnees valides
    //  Alors ecrit dernier coup joue
    //Sinon
    //  Affiche erreur
    //Fin Si
    //

    if(entree_sortie_est_fichier_existe(fichier_sauvegarde)!=1)
    {
        printf("Fichier %s n'existe pas\n",fichier_sauvegarde);
        return 0;
    }
    if(coordonnee_est_valide(x_depart,y_depart)!=1 || coordonnee_est_valide(x_arrivee,y_arrivee)!=1)
    {
        printf("Coordonnees (%d,%d)->(%d,%d) non valides\n",x_depart,y_depart,x_arrivee,y_arrivee);
        return 0;
    }

    entree_sortie_ajoute_dernier_coup_joue(fichier_sauvegarde,x_depart,y_depart,x_arrivee,y_arrivee);
    return 1;
}
*/


int api_echec_ecrit_fichier_historique(const historique_partie* historique,const char* filename)
{
    //
    //Si le fichier designee est accessible
    //  Alors ecrit fichier
    //Sinon
    //  Affiche erreur
    //Fin Si
    //

    assert(historique!=NULL);

    if(entree_sortie_est_fichier_accessible(filename)!=1)
    {
        printf("N'arrive pas a sauver l'historique dans fichier %s\n",filename);
        return 0;
    }

    entree_sortie_ecrit_fichier_historique(filename,historique);
    return 1;
}

int api_echec_lit_fichier_historique(historique_partie* historique,const char* filename)
{
    //
    //Si le fichier designee existe
    //  Alors lit fichier
    //Sinon
    //  Affiche erreur
    //Fin Si
    //

    if(entree_sortie_est_fichier_existe(filename)!=1)
    {
        printf("Fichier %s n'existe pas\n",filename);
        return 0;
    }

    entree_sortie_lit_fichier_historique(filename,historique);

    return 1;
}

