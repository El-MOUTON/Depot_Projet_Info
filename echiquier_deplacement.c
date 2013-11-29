
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
 * Implementation des fonction de echiquier_deplacement
 *
 */

//#Nom1: BERNARD
//#Prenom1: Florian
//#Nom2: VARAUT
//#Prenom2: Charles
//#Groupe: D


#include "echiquier_deplacement.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


const char* nommer_type_erreur(type_erreur erreur)
{
    switch(erreur)
    {
    case pas_erreur:
        return "pas d'erreur";
    case erreur_deplacement_piece_impossible:
        return "deplacement piece impossible";
    case erreur_absence_de_deplacement:
        return "absence de deplacement";
    case erreur_piece_blocant_trajet:
        return "piece bloquant trajet";
    case erreur_prise_en_passant_non_permise:
        return "prise en passant non permise";
    case erreur_roque_non_permis:
        return "roque non permis";
    case erreur_roi_en_echec:
        return "roi en echec";
    default:
        printf("Erreur [code %d non reconnu] %s,%s \n",erreur,__FILE__,__FUNCTION__);
        abort();
    }

}


void echiquier_deplacement_realise_si_possible(echiquier* echiquier_courant,
                                               int x_depart,int y_depart,
                                               int x_destination,int y_destination,
                                               const historique_partie* historique,
                                               code_erreur_deplacement* erreur,
                                               type_deplacement* coup)
{
    //Verifications prealables
    assert(echiquier_courant!=NULL);
    assert(historique!=NULL);
    assert(erreur!=NULL);
    assert(coup!=NULL);
    assert(coordonnee_est_valide(x_depart,y_depart));
    assert(coordonnee_est_valide(x_destination,y_destination));
    const jeu* jeu_courant=echiquier_recupere_jeu_courant_information(echiquier_courant);
    assert(jeu_courant!=NULL);
    assert(jeu_recuperer_piece_information(jeu_courant,x_depart,y_depart)!=NULL);




    //Verification si un deplacement standard est valide
    int deplacement_valide=echiquier_deplacement_coup_standard_est_valide(echiquier_courant,
                                                                          x_depart,y_depart,
                                                                          x_destination,y_destination,
                                                                          erreur);

    //Copie de l'etat de l'echiquier
    echiquier echiquier_nouveau=*echiquier_courant;

    if(deplacement_valide==1)
    {
        //coup a priori valide
        assert(erreur->type==pas_erreur);
        //le coup correspond a un deplacement standard
        *coup=deplacement_standard;
        //le coup est appliquee sur la copie de l'echiquier
        echiquier_deplacement_realise_coup_standard(&echiquier_nouveau,x_depart,y_depart,x_destination,y_destination);

        // cas des promotions a traiter ...
    }
    // cas des coups speciaux a traiter ...

    // cas de la mise en echec a traiter ...

    //ecriture de la copie de l'echiquier dans l'echiquier courant
    *echiquier_courant=echiquier_nouveau;
}


int echiquier_deplacement_coup_standard_est_valide(const echiquier* echiquier_courant,
                                                   int x_courant,int y_courant,
                                                   int x_destination,int y_destination,
                                                   code_erreur_deplacement *erreur)
{
    // Algorithme:
    // ***********
    // Verifie qu'un mouvement existe, sinon renvoie 0
    // Verifie qu'aucune piece du jeu courant n'est positionne aux coordonnees d'arrivee, sinon renvoie 0
    // Recupere type de piece a deplacer
    // En fonction du type
    //   Appel a la fonction de deplacement specifique: tour, cavalier, etc
    //   Renvoie le retour de l'appel specifique



    // En fonction du type de piece, appel des fonctions de deplacement specifique
    int deplacement_est_valide=0;
    switch(piece_a_deplacer->type)
    {
//    case tour:
//        deplacement_est_valide=echiquier_deplacement_standard_est_valide_tour(echiquier_courant,piece_a_deplacer,x_destination,y_destination,erreur);
//        break;
    case cavalier:
        deplacement_est_valide = echiquier_deplacement_standard_est_valide_cavalier(echiquier_courant, piece_a_deplacer, x_destination, y_destination, erreur);
        break;
//    case fou:
//        deplacement_est_valide=echiquier_deplacement_standard_est_valide_fou(echiquier_courant,piece_a_deplacer,x_destination,y_destination,erreur);
//        break;
//    case dame:
//        deplacement_est_valide=echiquier_deplacement_standard_est_valide_dame(echiquier_courant,piece_a_deplacer,x_destination,y_destination,erreur);
//        break;
//    case roi:
//        deplacement_est_valide=echiquier_deplacement_standard_est_valide_roi(echiquier_courant,piece_a_deplacer,x_destination,y_destination,erreur);
//        break;
//    case pion_blanc:
//        deplacement_est_valide=echiquier_deplacement_standard_est_valide_pion_blanc(echiquier_courant,piece_a_deplacer,x_destination,y_destination,erreur);
//        break;
//    case pion_noir:
//        deplacement_est_valide=echiquier_deplacement_standard_est_valide_pion_noir(echiquier_courant,piece_a_deplacer,x_destination,y_destination,erreur);
//        break;
    default:
        printf("Erreur dans fonction %s\n",__FUNCTION__);
        exit(1);
    }

    printf("Fonction %s non implementee\n",__FUNCTION__);
    return 1;
}

void echiquier_deplacement_realise_coup_standard(echiquier* echiquier_courant,
                                                 int x_courant,int y_courant,
                                                 int x_destination,int y_destination)
{
   printf("Fonction %s non implementee\n",__FUNCTION__);
}

