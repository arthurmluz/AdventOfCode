#include <stdio.h>
#define MAX 820

char mat[MAX][10] = {};

void imprime(){
	for( int i = 0; i < MAX; i++ ){
		for( int j = 0; j < 10; j++ )
			printf("%c", mat[i][j] );
		printf("\n");
	}
}

void main(){
	int max, i = 0;
	while( fgets( mat[i++], 100, stdin ) );
	
	max = i-1;
	printf("max = %d\n", max);

/* 		PARTE 1
	int MAX_seatID, flag = 1;
	for( int i = 0; i < max; i++ ){
		int rows = 128, columns = 8;
		int lowerRows = 0, upperRows = 127, lowerColumns = 0, upperColumns = 7;
		for( int j = 0; j < 10; j++ ){
			if( j < 7 ) rows /= 2;
			else columns /= 2;
			if( mat[i][j] == 'F' ) upperRows -= rows;
			if( mat[i][j] == 'B' ) lowerRows += rows;
			if( mat[i][j] == 'L' ) upperColumns -= columns;
			if( mat[i][j] == 'R' ) lowerColumns += columns;
		}
		int seatID = upperRows * 8 + upperColumns;
		if( flag == 1 ) { MAX_seatID = seatID; flag = 0; }
		 else if( seatID > MAX_seatID ) MAX_seatID = seatID;
//		printf("final row = %d, final column = %d, %d\n", upperRows, upperColumns, seatID);
	}
	printf( "max value = %d\n", MAX_seatID );
*/

// 	PARTE 2
	int vet[818] = {};
	for( int i = 0; i < max; i++ ){
		int rows = 128, columns = 8;
		int lowerRows = 0, upperRows = 127, lowerColumns = 0, upperColumns = 7;
		for( int j = 0; j < 10; j++ ){
			if( j < 7 ) rows /= 2;
			else columns /= 2;
			if( mat[i][j] == 'F' ) upperRows -= rows;
			if( mat[i][j] == 'B' ) lowerRows += rows;
			if( mat[i][j] == 'L' ) upperColumns -= columns;
			if( mat[i][j] == 'R' ) lowerColumns += columns;
		}
		int seatID = upperRows * 8 + upperColumns;
		vet[i] = seatID;
//		printf("final row = %d, final column = %d, %d\n", upperRows, upperColumns, seatID);
	}

	for( i = 0; i < 902; i++ ){
		int flag = 0;
		for( int j = 0; j < 818; j++ ){
			if( i == vet[j] ) { flag = 0; break; }
			if( i == vet[j]+1 ) flag = 1;
			if( i == vet[j]-1 ) flag = 2;
		}
		if( flag == 1 )
		for( int j = 0; j < 818; j++ )
			if( i == vet[j]-1 ) {printf("achei i = %d!\n", i ); break; }
		if( flag == 2 )
		for( int j = 0; j < 818; j++ )
			if( i == vet[j]+1 ) {printf("achei i = %d!\n", i ); break; }
	
	}
}
