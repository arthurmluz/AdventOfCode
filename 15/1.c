#include <stdio.h>
#define MAX 100000

void main() {
char vet[MAX];
int floor = 0;


  FILE *fp;

  fp = fopen ( "1.txt", "r" );

  if ( fp == NULL )
    printf( "Tá fazendo algo errado\n");

  else {
	int i;
	for( i = 0; i < MAX; i++ ) {
	  if ( 1 != fscanf( fp, "%c ", &vet[i] ) ) break;

	}

	for( int tmp = 0; tmp < i; tmp++ ) {
	  if( vet[tmp] == '(' )	floor++;
	  if( vet[tmp] == ')' ) floor--;
	  if( floor == -1 ) printf( "posição %d, floor %d\n", tmp, floor);
	}

	}
  printf("floor = %d\n", floor);
  fclose ( fp );
}
