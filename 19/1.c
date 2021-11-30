#include <stdio.h>
#define MAX 100

void main() {
int vet[MAX];
int i = 0;
int somador = 0;
int fuel = 0;
int combustivel = 0;

  FILE *fp;

  fp = fopen ( "1.txt", "r" );

  if ( fp == NULL )
    printf( "Tá fazendo algo errado\n");

  else {

	for( i = 0; i < MAX; i++ ) {
	  if ( 1 != fscanf( fp, "%d ", &vet[i] ) ) break;

	}

	for( int tmp = 0; tmp < i; tmp++ ) {
	 fuel = ( vet[tmp] / 3 ) - 2;
	 if( ( fuel / 3 ) -2 <= 0 ) somador += fuel;

	 else {
	   while( fuel > 0 ) {
		somador += fuel;
		fuel = ( fuel / 3 ) -2;
		
		}

	}


	}
	printf( "somador = %d\n", somador );
  }
}
