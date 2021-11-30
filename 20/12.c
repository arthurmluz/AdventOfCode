#include<stdio.h>
#define MAX 780

typedef struct a{		//letras maiusculas
	char orientation;
	int move;
} dir;


void main(){
	dir vet[780];

	int i = 0;
	for( i; i < MAX; i++ ){
		char letra;
		int tmp;
		if( scanf("%c%d ", &letra, &tmp) != 2 ) break;
		vet[i].orientation = letra;
		vet[i].move = tmp;
	}
	int max = i - 1;
//	printf("max = %d\n", max);
						// directions: 0 = norte, 1 = sul, 2 = leste, 3 = oeste
	int x = 0, y = 0;
	char direction = 'E';
	for( i = 0; i <= max; i++ ){
		if( vet[i].orientation == 'F' ) vet[i].orientation = direction;
		switch( vet[i].orientation ){
			case 'N' : y+= vet[i].move; break; 
			case 'S' : y-= vet[i].move; break;
			case 'E' : x+= vet[i].move; break;
			case 'W' : x-= vet[i].move; break; 
		}
		if( vet[i].orientation == 'R' ){
			int dir = vet[i].move / 90;
			int tmp = 0;
			switch( direction ){
				case 'N' : tmp = 0; break;
				case 'E' : tmp = 1; break;
				case 'S' : tmp = 2; break;
				case 'W' : tmp = 3; break;
			}
			tmp += dir;
			if( tmp >= 4 ) tmp-= 4;
			switch( tmp ){ case 0 : direction = 'N'; break; case 1 : direction = 'E'; break; case 2 : direction = 'S'; break; case 3 : direction = 'W'; break; } 
		}
		if( vet[i].orientation == 'L' ){
			int dir = vet[i].move / 90;
			int tmp = 0;
			switch( direction ){
				case 'N' : tmp = 0; break;
				case 'E' : tmp = 3; break;
				case 'S' : tmp = 2; break;
				case 'W' : tmp = 1; break;
			}
			tmp += dir;
			if( tmp >= 4 ) tmp-= 4;
//			printf("tmp = %d, dir = %d\n", tmp, dir);
//	printf("x = %d, y = %d\n", x, y);
			switch( tmp ){ case 0 : direction = 'N'; break; case 1 : direction = 'W'; break; case 2 : direction = 'S'; break; case 3 : direction = 'E'; break; } 
		}
	}
	printf("x = %d, y = %d\n", x, y);

}
