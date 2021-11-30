#include<stdio.h>
#define MAX 780

typedef struct a{               //letras maiusculas
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
        int x = 0, y = 0;
	int wayX = 10, wayY = 1;
        for( i = 0; i <= max; i++ ){
                 switch( vet[i].orientation ){
                        case 'N' : wayY+= vet[i].move; break;
                        case 'S' : wayY-= vet[i].move; break;
                        case 'E' : wayX+= vet[i].move; break;
                        case 'W' : wayX-= vet[i].move; break;
			case 'F' : x+= wayX*vet[i].move; y+= wayY*vet[i].move;  
                }
		if( vet[i].orientation == 'R' ){
			int tmp = vet[i].move / 90;
			for( int j = 0; j < tmp; j++ ){
				int aux;
				aux = wayY;
				wayY = wayX*-1;
				wayX = aux;
			}
		}
		if( vet[i].orientation == 'L' ){
			int tmp = vet[i].move / 90;
			for( int j = 0; j < tmp; j++ ){
				int aux;
				aux = wayX;
				wayX = wayY*-1;
				wayY = aux;
			}
		}
        }
        printf("x = %d, y = %d\n", x, y);

}
