/* Auteur : MBUMA MONA Nathan
 * création : 26/03/2019
 * modification : 09/03/2019*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "position.h"

int est_case_occupee(Position pos ,Case c){
	
	if(pos &(1ull << c))
		return 1;
	return 0;
	
	
}


int placer_dame_position(Position *pos , Case c){
	assert(pos != NULL);
		
	*pos = *pos | ( 1ull << c );

	return 1;
	
}


int calculer_cases_attaquees_cavalier(Position* pos, Case c){
	assert(pos != NULL);
	
	int i,tmp = c , modulo;
	/*ligne*/
	
	tmp = c +15;
	for(i = 0 ;i < 2; i++){
		modulo = tmp % 8;
		if( tmp -(i*15) > 0 && tmp -(i*15) < 63 && (modulo < 15)){
			
			if((placer_dame_position(pos, tmp - (i*15)) == 0))
					return 0;
			}
	tmp = c;
	}
	
	
	tmp = c +17;
	for(i = 0 ; i < 2 ; i += 1){
		modulo = tmp % 8;
		if( tmp -(i*17) > 0 && tmp -(i*17) < 63 && (modulo < 17) ){
		
			if((placer_dame_position(pos, tmp - (i*17)) == 0))
				return 0;
		}	
		tmp = c;
	}
	/*diagonale1*/
	
	tmp = c +10;
	for(i = 0 ; i < 2 ; i += 1){
		modulo = tmp % 8;
		if( tmp -(i*10) > 0 && tmp -(i*10) < 63 && (modulo <10)){
			
			if((placer_dame_position(pos, tmp - (i*10)) == 0))
				return 0;
			}
				
		tmp = c;
	}
	
	/* diagonale2 */
	
	tmp = c +6;
	for(i = 0 ; i < 2 ; i += 1){

	modulo = tmp % 8;
		if( tmp -(i*6) > 0 && tmp -(i*6) < 63 && ( modulo < 6) ){
		
			if((placer_dame_position(pos, tmp - (i*6)) == 0))
			
				return 0;
			}
				
		tmp = c;
	}
	
	return 1;
}

int calculer_cases_attaquees(Position* pos, Case c){
	assert(pos != NULL);
	int i,tmp,j = 0;
	tmp = c % 8;
	
	/*ligne*/
	
	for(i = c - tmp ; i < (c - tmp)+8 ; i++){
		if (i != c){
			if((placer_dame_position(pos,i)) == 0)
				return 0;
			}
		
	}
	/*colonne*/
	for(i = tmp ; i < N ; i += 8){
		if (i != c){
			
			if((placer_dame_position(pos, i) == 0))
				return 0;
				
		}
	}
	/*diagonale1*/
	for(i = c - 9*tmp ; (i < N  && j < 8)  ; i += 9){
		j++;
		if (i != c && i >= 0 ){
			
			if((placer_dame_position(pos, i) == 0))
				return 0;
				
		}
	}
	
	
	/* diagonale2 */
	j = 0;
	for(i = (c + 7*tmp)  ; (i > 0 && j < 8) ; i -= 7){
		j++;
		
		if (i != c && 63 >= i){
			
			if((placer_dame_position(pos, i) == 0))
				return 0;
				
		}
	}
		
	return 1;
}



int est_sans_attaque_mutuelle(Position pos){
	int i;
	for(i = 0 ; i < N ; i++){
		if((est_case_occupee(pos ,i)== 1)){
			if(((tab_cases_attaquees[i]) & pos) >= 1)
				return 0;
					
				}
	}		
				
	return 1;
}


