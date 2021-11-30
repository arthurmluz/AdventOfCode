#include <stdio.h>
#define MAX 1010
#define PASSOS 25 

void main() {

	long int vet[MAX] = {}, resp1;
	int i = 0;
	while( scanf("%ld", &vet[i]) == 1 ) i++;
	int max = i -1;

	for( int anda = 0; anda < max; ){
		int flag = 0;
		for( i = anda; i < anda+PASSOS; i++ ) {
			for( int j = anda; j < anda+PASSOS; j++ )
				if( vet[i] + vet[j] == vet[anda+PASSOS] && vet[i] != vet[j] ) { anda++; flag = 1; break; }
			if( flag ) break;
		}
		if( !flag ) { printf( "pt1 = %ld\n", vet[anda+PASSOS] ); resp1 = vet[anda+PASSOS]; break;}
	}
	// PARTE 2
	for( int anda = 0; anda < max; anda++ ){
		int flag = 0;
		long int acumula = 0, maior = vet[anda], menor= vet[anda];
		for( i = anda; i < max; i++ ){
			if( acumula > resp1 || vet[i] == resp1) break;
			if( vet[i] > maior ) maior = vet[i];
			if( vet[i] < menor ) menor = vet[i];
			acumula += vet[i];
			if( acumula == resp1 ) { flag = 1; break; }
		}
		if( flag ) { 
			printf("pt2 = %ld\n", maior + menor);
			break;
		}
	}
}
