#include <stdio.h>
#include <stdlib.h>
#define MAX 12

void paths ( char matriz[MAX][MAX], char direction, int path, int lin, int col, int local[2] ) {
  if ( lin != MAX/2 || col != MAX/2) matriz[lin][col] = '+';
  switch ( direction ) {
    case 'U' :
	    for( int i = 0; i < path; i++ ) {
	      lin--;
	      if( matriz[lin][col] != 0 ) matriz[lin][col] = 'X';
	      else matriz[lin][col] = '|';
	    }
	    break;

    case 'D' :
            for( int i = 0; i < path; i++ ) {
              lin++;
              if( matriz[lin][col] != 0 ) matriz[lin][col] = 'X';
	      else matriz[lin][col] = '|';
	    }
            break;

    case 'R' :
	    for( int i = 0; i < path; i++ ) {
	     col++;
	     if( matriz[lin][col] != 0 ) matriz[lin][col] = 'X';
	     else matriz[lin][col] = '-';
	    }
	    break;

    case 'L' :
            for( int i = 0; i < path; i++ ) {
             col--;
             if( matriz[lin][col] != 0 ) matriz[lin][col] = 'X';
	     else matriz[lin][col] = '-';
            }
            break;
  }

  local[0] = lin;
  local[1] = col;
}

void procuraX ( char matriz[MAX][MAX] ){
int p = 0, q = 0;
int curta = 2309130;

  for ( int i = 0; i < MAX; i++ )
    for ( int j = 0; j < MAX; j++ )
	if ( matriz[i][j] == 'X' ) {
		p = (MAX/2) - j;
		q = (MAX/2) - i ;
		if( p < 0 ) p *= -1;
		if( q < 0 ) q *= -1;
		if( p+q < curta ) curta = p+q;
	}
printf( "%d\n", curta );

}

void main() {

   char (*p_matriz)[MAX][MAX]=malloc(sizeof *p_matriz);
    if(p_matriz==NULL){
        fprintf(stderr, "Alocação de memória para matriz falhou.\n");
        exit(1);
    }

  char direction[MAX] = {0}, direction2[MAX]={0};
  int  path[MAX]={0}, path2[MAX]={0};
  int local[2] = {MAX/2, MAX/2};
  *p_matriz[MAX/2][MAX/2] = 'O';

  FILE *fp;
  fp = fopen ( "3.txt", "r" );

  if ( fp == NULL )
    printf( "socorro meu pai\n" );

  else {

	long int i; //PEGA O PRIMEIRO CAMINHO
	for ( i = 0; i < MAX; i++ ){
	  if ( 1 != fscanf( fp, "%c", &direction[i] ) ) break;
	  if ( 1 != fscanf( fp, "%d,", &path[i] ) ) break;
	}

	long int j; // PEGA O SEGUNDO CAMINHO
	for ( j = 0; j < MAX; j++ ){
	  if ( 1 != fscanf( fp, "%c", &direction2[j] ) ) break;
	  if ( 1 != fscanf( fp, "%d,", &path2[j] ) ) break;
	}

	for ( long int atual = 0; atual < i; atual++ ) //COLOCA O 1° CAMINHO
		paths ( &p_matriz[MAX][MAX], direction[atual], path[atual], local[0], local[1], local );

	local[0] = MAX/2; local[1] = MAX/2;
	for ( long int atual = 0; atual < j; atual++ ) //COLOCA O 2° CAMINHO
		paths ( &p_matriz[MAX][MAX], direction2[atual], path2[atual], local[0], local[1], local );

	procuraX( &p_matriz[MAX][MAX] ); //CALCULA A DISTANCIA
  }
 free(p_matriz);
fclose (fp);  
}
