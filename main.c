/* Auteur : MBUMA MONA Nathan
 * création : 26/03/2019
 * modification : 09/03/2019*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "affichage.h"
#include "test.h"


/* fontion : jouer_le_jeu
 * paramètre :un pointeur sur une position et deux images
 * retour : rien
 * description : cette fonction prend en paramètre deux images(cavalier et dame) et un pointeur
 * sur une position , elle fait appel à toutes les fonctions du projet sauf le menu 
 * elle gère les clics de l'utilisateur ,l'affichage graphique et ascii et s'assure du bon
 * déroulement du jeu avec des messages en cas de collision.*/
 void jouer_le_jeu(Position* pos , MLV_Image *image1 , MLV_Image *image2);

int main(void){
	Position pos;
	pos = 0ull;
	MLV_create_window("ECHEC", "ECHEC",1200,700);
	MLV_Font* font = MLV_load_font( "src/Garuda-Oblique.ttf" , 25 );
	int retour;
	MLV_Image * image1;
	MLV_Image * image2;
	
	
	/* on effectue le test */
	if(verification()){
		MLV_draw_filled_rectangle(700/2-100, 700/2-50, 800, 50, MLV_COLOR_WHITE);
		MLV_draw_text_with_font(700/2-85 , 700/2-50 ,"AUCUNE ERREUR DETECTEE VOS FONCTIONS SONT PRETES !", font, MLV_COLOR_BLUE);
		MLV_actualise_window();
		MLV_wait_seconds( 2 );
	}
	/* le test echoue */
	else{
		MLV_draw_filled_rectangle(800/2-100, 700/2-50, 500, 50, MLV_COLOR_WHITE);
		MLV_draw_text_with_font(800/2-85 , 700/2-50 ,"VEUILLEZ REVOIR VOS FONCTIONS", font, MLV_COLOR_BLUE);
		MLV_actualise_window();
		MLV_wait_seconds( 7 );
		MLV_free_font( font );
		MLV_free_window();
		return 0;
	}
	MLV_clear_window(MLV_COLOR_BLACK);
	
	/* LE MENU */
	retour = afficher_menu();
	
	switch(retour){
		
		case 1 :
			MLV_clear_window(MLV_COLOR_BLACK);
			image1 = MLV_load_image("src/200.png");
			image2 = NULL;
			jouer_le_jeu(&pos, image1 , image2);
			break;
		case 2 :
			MLV_clear_window(MLV_COLOR_BLACK);
			image1 = NULL;
			image2 = MLV_load_image("src/cheval.png");
			jouer_le_jeu(&pos, image1 , image2);
			break;
		
	}
		
	
	MLV_wait_seconds( 5 );
	MLV_free_font( font );
	MLV_free_window();
	return 0;
	
	
}


void jouer_le_jeu(Position* pos , MLV_Image *image1 , MLV_Image *image2){
	assert(pos != NULL);
	int pas_attaque_mutuelle = 0;
	int localisation = 0,drapeau = 0,arret = 0,compteur = 0;
	int souris_x;
	int souris_y;
	MLV_Font* font = MLV_load_font( "src/Garuda-Oblique.ttf" , 25 );
	
	if(image2 == NULL){
		drapeau =1;
		arret = 8;
	}
	
	if(image1 == NULL){
		drapeau =2;
		image1 = image2;
		arret = 32;
		image2 = NULL;
	}
	
	MLV_resize_image(image1, 60, 60);
	do{
		
		afficher_plateauB(*pos, image1);
		
		afficher_position(*pos);
	
		do{
			do{
				MLV_wait_mouse(&souris_x, &souris_y);
			}while(!((17 <= souris_x && souris_x <= 585) && (10 <= souris_y && souris_y <= 578))); 
			localisation = gestion_souris(souris_x , souris_y);
		}while(est_case_occupee(*pos, localisation) == 1);
		printf("position = %d\n",localisation);
		placer_dame_position(pos, localisation);
		
		if(drapeau == 2){
				calculer_cases_attaquees_cavalier(&(tab_cases_attaquees[localisation]), localisation);
				
			}
		
			
		if(drapeau == 1){
			calculer_cases_attaquees(&(tab_cases_attaquees[localisation]), localisation);
			
		}
		
		
		pas_attaque_mutuelle = est_sans_attaque_mutuelle(*pos);
		
		if (pas_attaque_mutuelle == 0){
			MLV_draw_adapted_text_box_with_font(250, 290,"PLACEMENT ILLEGAL !",font,15,	MLV_COLOR_GREEN, MLV_COLOR_RED, MLV_COLOR_BLACK,MLV_TEXT_CENTER);
			MLV_actualise_window();
			*pos = 0ull;
			compteur = 0;
			MLV_wait_seconds( 2 );
		}
		else
			compteur++;
		
	
	}while(compteur != arret);
	
	
	afficher_plateauB(*pos, image1);
	
		
	MLV_draw_filled_rectangle(700/2-100, 700/2-50, 800, 50, MLV_COLOR_WHITE);
	MLV_draw_text_with_font(1000/2-85 , 700/2-50 ,"FÉLICITATION VOUS AVEZ GAGNÉ!!!", font, MLV_COLOR_BLUE);	
	MLV_actualise_window();
	MLV_free_font( font );
}


