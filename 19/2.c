#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

void main() {
int vet[MAX], primeiro[MAX];
int i = 0, pos1, pos2, pos3;

  FILE *fp;

  fp = fopen ( "2.txt", "r" );

  if ( fp == NULL )
    printf( "Ta fazendo algo errado\n");

  else {

	for( i = 0; i < MAX; i++ ) {
	  if ( 1 != fscanf( fp, "%d,", &vet[i] ) ) break;
	  primeiro[i] = vet[i];
	}


	for( int x = 0; x < 100; x++)
	  for( int y = 0; y < 100; y++){
	   primeiro[1] = x; primeiro[2] = y;
	   for ( int tmp = 0; tmp < i; tmp++ )
	     vet[tmp] = primeiro[tmp];


  	   for( int address = 0; address < i; address += 4 ) {

  	     pos1 = vet[address+1]; pos2 = vet[address+2]; pos3 = vet[address+3];
	     switch ( vet[address] ) {
	   	 case 1 :
			vet[pos3] = vet[pos1] + vet[pos2];
			break;

		 case 2 :
			vet[pos3] = vet[pos1] * vet[pos2];
			break;

		 case 99 :
			if( vet[0] == 19690720 ) printf (" 100 * %d + %d\n ", vet[1], vet[2] );
			else break;

  	     }

	   }
          }
  }
  fclose ( fp );
}
