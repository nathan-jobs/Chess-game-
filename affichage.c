/* Auteur : MBUMA MONA Nathan
 * création : 26/03/2019
 * modification : 11/04/2019*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "affichage.h"



MLV_Color fabriqueCouleur(void) {
	return MLV_rgba(255, 255, 255, 60);
}

int afficher_menu(void){
	MLV_Event event;
	int i = 1;
	int x, y ;
	MLV_Image *image;
	MLV_Font* font = MLV_load_font( "src/Garuda-Oblique.ttf" , 28 );
	image = MLV_load_image("src/echec.jpg");
	
	MLV_resize_image_with_proportions(image, 1200, 700);

	MLV_draw_image(image, 0, 0);
	MLV_actualise_window();
	
	MLV_draw_filled_rectangle(400, 150, 450, 50,fabriqueCouleur() );
	MLV_draw_text_with_font(430, 150,"JOUER AVEC LES DAMES", font, MLV_COLOR_BLUE);
	MLV_draw_filled_rectangle(400,215, 450, 50,  fabriqueCouleur() );
	MLV_draw_text_with_font(405, 210,"JOUER AVEC LES CAVALIERS", font, MLV_COLOR_BLUE);
	MLV_draw_filled_rectangle(400, 275, 450, 50, fabriqueCouleur());
	MLV_draw_text_with_font(520, 270,"QUITTER", font, MLV_COLOR_BLUE);
	
	
	MLV_actualise_window();
	do{
		event = MLV_get_event(
			NULL,NULL,NULL,
			NULL, NULL,
			&x,&y,NULL,
			NULL
		);
		if(event == MLV_MOUSE_BUTTON ){
			if((x>400 && y> 150) && (x<850 && y> 150) &&  (x> 400 && y< 200) && (x<850 && y< 200))
				return 1;
			else if((x>400 && y> 215) && (x<850 && y>210) &&  (x> 400 && y< 275) && (x<850 && y< 275))
				return 2;
			else if((x>400 && x < 850) && (y < 325 &&  y> 275))
			{
				MLV_clear_window(MLV_COLOR_BLACK);
				MLV_draw_filled_rectangle(1200/2-100, 700/2-50, 250, 50, MLV_COLOR_WHITE);
				MLV_draw_text_with_font(1200/2-85 , 700/2-50 ,"Au revoir  !!!", font, MLV_COLOR_BLUE);
				MLV_actualise_window();
				MLV_wait_seconds(5);
				MLV_free_window();
				exit(EXIT_FAILURE);
			}
		}
	}while(i);
	MLV_free_font( font );
	return 0;
}


int afficher_position(Position pos){
   int i,j;
   
   for(j = 7 ; j>= 0 ; --j){
	   for(i = 0 ;i < 8 ; ++i){
			if(est_case_occupee(pos, i+ j*8))
				printf("+");
			else
				printf("-");
		}
		printf("\n");		
   }
   return 1;
}

void afficher_plateauB(Position pos, MLV_Image *image){
	assert(image != NULL);
    int i;
	int j;
	int hauteur = 0;
	int largeur;
	for ( i = 0 ; i < 8 ; i++){
		largeur = 0;
		for ( j = 0 ; j < 8 ; j++)
		{
			if( (i+j) % 2 == 0 ) 
				MLV_draw_filled_rectangle(17 +largeur, 10 + hauteur, 70, 70, MLV_COLOR_WHITE);
			else
				MLV_draw_filled_rectangle(17 + largeur, 10 + hauteur, 70, 70, MLV_COLOR_GREY);
			largeur += 71;
		}
		hauteur += 71;
	}
	MLV_actualise_window();
	hauteur = 0;
	largeur = 0;
    for(j = 7 ; j>= 0 ; --j){
		largeur = 0;
	   for(i = 0 ;i < 8 ; ++i){
			if(est_case_occupee(pos, i+ j*8)){
				MLV_draw_image(image, 22 + largeur, 22+ hauteur);
				MLV_actualise_window();	
			}
			largeur += 71;
		}		
  	
		hauteur += 71;
    }
	
}


int gestion_souris(int x, int y){
	int px;
	int py;
	px = (x - 17)/70;
	py = 7 - ((y - 10)/70);
	return py * 8 + px;
}


