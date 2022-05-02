/* Auteur : MBUMA MONA Nathan
 * création : 26/03/2019
 * modification : 09/03/2019*/


#ifndef __affichage__
#define __affichage__

#include <MLV/MLV_all.h>
#include "position.h"


#define LARGEUR 600
#define HAUTEUR 600


/* fonction : afficher_position
 * parametre : position
 * retour : un entier
 * description : cette fonction affiche une position
 * sur la sortie standard elle affiche un "+" pour une 
 * case occupée et "." pour une case vide */

int afficher_position(Position pos);

/* fonction : afficher_plateauB
 * parametre : position et une image
 * retour : rien
 * description :cette fonction affiche une position
 * sur l'écran avec une image pour representer une dame  */
void afficher_plateauB(Position pos, MLV_Image *image);

/* fonction : gestion_souris
 * parametre : deux entiers
 * retour : un entier
 * description :cette fonction prend en parametre
 * deux entiers (les coordonnées x et y de l'écran)
 * et le transforme en un nombre entre 0 et 63   */

int gestion_souris(int x, int y);

/* fonction : afficher_menu
 * parametre : rien
 * retour : un entier
 * description : cette fonction affiche un menu en utilisant
 * la bibliothèque MLV */
 
int afficher_menu(void);

/* fonction : fabriqueCouleur
 * parametre : rien
 * retour : une couleur
 * description : cette fonction crée une couleur avec
 * un constraste très faible pour éviter de cacher l'image sur l'arrière plan*/
MLV_Color fabriqueCouleur(void);



#endif
