#include <stdio.h>
#include <string.h>

char mat[400][400] = {};

void imprime( int lin, int col ){
	for( int i = 0; i < lin; i++ ){
		for( int j = 0; j < col; j++ )
			printf("%c", mat[i][j]);
		printf("\n");
	}
}

int slopes( int c, int l, int linMAX, int colMAX ){
	int ground = 1, lin = 0, col = 0, contTrees = 0;
	
	while( ground ) {
		lin+= l;
		col+= c;
		if( col >= colMAX ) col -= colMAX;
		if( lin >= linMAX ) ground = 0;
		if( mat[lin][col] == '#' ) { contTrees++; }// mat[lin][col] = 'X'; }
//		else mat[lin][col] = 'O';
//		imprime( colMAX, linMAX );
//		printf("\n\n");
	}
	return contTrees;
}

void main(){
	int linMAX= 0;

	while( fgets( mat[linMAX++], 100, stdin ));
	linMAX--;
	int colMAX = strlen(mat[0])-1;
	
	int c1 = slopes( 1, 1, linMAX, colMAX );
	int c2 = slopes( 3, 1, linMAX, colMAX );
	int c3 = slopes( 5, 1, linMAX, colMAX );
	int c4 = slopes( 7, 1, linMAX, colMAX );
	int c5 = slopes( 1, 2, linMAX, colMAX );

	long long int mult = c1*c2*c3*c4*c5;	
	printf( "Arvere = %d, %d, %d, %d, %d, mult = %lld\n", c1, c2, c3, c4, c5, mult );
}
