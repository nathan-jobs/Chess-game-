/* Auteur : MBUMA MONA Nathan
 * création : 26/03/2019
 * modification : 09/03/2019*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "affichage.h"
#include "test.h"


int test_est_case_occupee(Position pos ,Case c){
	
	if(pos &(1ull << c))
		return 1;
	return 0;
	
	
}


int test_placer_dame_position(Position *pos , Case c){

		
	*pos = *pos | ( 1ull << c );

	return 1;
	
}

int test_gestion_souris(int x, int y){
	int px;
	int py;
	px = (x - 17)/70;
	py = 7 - ((y - 10)/70);
	return py * 8 + px;
}

int verification(void){
	Position pos = 0ull;
	int x , y;
	test_placer_dame_position(&pos,3);
	
	if(!(test_est_case_occupee(pos,3))){
		
		return 0;
	}
	
	x = 17 ;
	y = 15;
	
	if((test_gestion_souris(x,y)) != 56){
		
		return 0;
	}
		
	return 1;
	
	
}
