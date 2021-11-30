#include <stdio.h>
#define MAX 2040 //2040

void main(){

	        int flag = 1, cont = 0;
                char questions[26] = {};
		int qntQ = 0;
                for( int i = 0; i < MAX+1; i++ ){
                        char vet[30] = {};
                        fgets( vet, 29, stdin );
			int tam = 0;
			for( int tmp = 0; tmp < 30; tmp++ )
				if( vet[tmp] >= 'a' && vet[tmp] <= 'z' ) tam++;

	                if( vet[0] == '\n' ) { flag = 1; cont += qntQ; qntQ = 0; for( int a = 0; a < 26; a++ ) questions[a] = 0; continue; }
                        if( flag == 1 ){
				for( qntQ; qntQ < tam; qntQ++ )
					questions[qntQ] = vet[qntQ];
				flag = 0;
                        }
			else for( int k = 0; k < tam; k++ ){
				int jatem = 0;
				for( int j = 0; j < 26; j++ )
					if( vet[k] == questions[j] ) jatem = 1;
				if( jatem == 0 ) questions[qntQ++] = vet[k];
			     }
                }
	printf("cont = %d\n", cont); 
}
