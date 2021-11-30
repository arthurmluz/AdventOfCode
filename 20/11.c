#include <stdio.h>
#include <string.h>

char mat[100][100] = {};

int olhaVizinhos( int lin, int col, int maxL, int maxCol ){
	int vizinho = 0;
	for( int i = lin-1; i <= lin+1; i++ ){
		for( int j = col-1; j <= col+1; j++ ){
			if( i < 0 || i >= maxL || j >= maxCol || j < 0  ) continue;
			if( i == lin && j == col ) continue;
			if( mat[i][j] == '#' ) vizinho++;
		}
	}
	return vizinho;
}

int olhaVizinhosAvancada( int lin, int col, int maxL, int maxCol ){
	int vizinho = 0;
		for( int i = lin+1; i < maxL; i++ ){
			if( mat[i][col] == 'L' ) break;
			if( mat[i][col] == '#' ) {vizinho++; break;}				//olha pra baixo
		}
		for( int i = lin-1; i >= 0 ; i-- ){
			if( mat[i][col] == 'L' ) break;
			if( mat[i][col] == '#' ) {vizinho++; break;}				//olha pra cima
		}
		for( int j = col+1; j < maxCol ; j++ ){
			if( mat[lin][j] == 'L' ) break;
			if( mat[lin][j] == '#' ) {vizinho++; break;}				//olha pra direita
		}
		for( int j = col-1; j >= 0; j-- ){
			if( mat[lin][j] == 'L' ) break;
			if( mat[lin][j] == '#' ) {vizinho++; break;}				//olha pra esquerda
		}

		for( int i = lin+1, j = col+1; i < maxL && j < maxCol; i++, j++ ){
			if( mat[i][j] == 'L' ) break;
			if( mat[i][j] == '#' ) {vizinho++; break;}		//olha pra diagonal direita inferior
		}
		for( int i = lin-1, j = col+1; i >= 0 && j <= maxCol; i--, j++ ){
			if( mat[i][j] == 'L' ) break;
			if( mat[i][j] == '#' ) {vizinho++; break;}		//olha pra diagonal direita superior
		}
		for( int i = lin+1, j = col-1; i < maxL && j >= 0 ; i++, j-- ){
			if( mat[i][j] == 'L' ) break;
			if( mat[i][j] == '#' ) {vizinho++; break;}		//olha pra diagonal esquerda inferior
		}
		for( int i = lin-1, j = col-1; i >= 0 && j >= 0; i--, j-- ){
			if( mat[i][j] == 'L' ) break;
			if( mat[i][j] == '#' ) {vizinho++; break;}		//olha pra diagonal esquerda superior
		}
	

	return vizinho;
}

void main(){

	int i = 0;
	while( fgets( mat[i++], 100, stdin ) );
	int maxL = i-1;
	int maxCol = strlen(mat[0]);

	printf("max = %d, maxCol = %d\n", maxL, maxCol);
	
	int count = 0, ocupados = 0;
	while ( count < 200 ){
		ocupados = 0;
		char new[100][100] = {};
		for( int i = 0; i < maxL; i++ )
			for( int j = 0; j < maxCol; j++)
				new[i][j] = mat[i][j];

		for( int i = 0; i < maxL; i++ ){
			for( int j = 0; j < maxCol; j++ ){
				int vizinhos = olhaVizinhosAvancada( i, j, maxL, maxCol );
				if( mat[i][j] == 'L' && vizinhos == 0 ) new[i][j] = '#';
				if( mat[i][j] == '#' && vizinhos >= 5 ) new[i][j] = 'L';	// mudar pra 4 no 1°
			}
		}
		for( int i = 0; i < maxL; i++ ){
			for( int j = 0; j < maxCol; j++){
				if( new[i][j] == '#' ) ocupados++;
				mat[i][j] = new[i][j];
		//		printf("%c", mat[i][j]);
			}
		}
	//		printf("\n");
		count++;
	}
	printf("ocupados = %d\n", ocupados);
}
