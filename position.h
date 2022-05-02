/* Auteur : MBUMA MONA Nathan
 * création : 26/03/2019
 * modification : 7/04/2019*/


#ifndef __position__
#define __position__

#include "case.h"


#define N 64


typedef unsigned long long Position;
 



Position tab_cases_attaquees[N];



/* fonction :est_case_occupee
 * parametres : une position pos ,et une case
 * retour : un entier 
 * description  :renvoie 1 si la case de la position pos 
 * est occupée par une dame et 0 sinon. */

int est_case_occupee(Position pos ,Case c);

/* fonction :placer_dame_position
 * parametres : un pointeur sur unr position pos et une case
 * retour : un entier 
 * description  :renvoie 1 si la valeur de l'adresse de la position pos 
 * a été modifié 0 sinon . */


int placer_dame_position(Position *pos , Case c);

/* fonction : calculer_cases_attaquees
 * paramtetres : un pointeur sur une position pos et une case
 * retour : un entier
 * description ; cette fonction prend une position de la dame
 * et place le 1 sur toutes les cases qui peuvent être attaqués
 * par la dame elle renvoie 1 si les modifications sont
 * possibles et 0 sinon*/

int calculer_cases_attaquees(Position* pos, Case c);

/* fonction : calculer_cases_attaquees_cavalier
 * paramtetres : un pointeur sur une position pos et une case
 * retour : un entier
 * description ; cette fonction prend une position du cavalier
 * et place le 1 sur toutes les cases qui peuvent être attaqués
 * par le cavalier elle renvoie 1 si les modifications sont
 * possibles et 0 sinon*/

int calculer_cases_attaquees_cavalier(Position* pos, Case c);

/* fonction : est_sans_attaque_mutuelle
 * paramtetres : une position
 * retour : un entier
 * description ; cette fonction prend une position et renvoie 1 si les
 * cases s'attaquent mutuellemnent 0 sinon */


int est_sans_attaque_mutuelle(Position pos);






#endif
