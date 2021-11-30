#include <stdio.h>
#define MAX 10000

int mat[MAX][MAX] = {};

void printmat ( int mat[MAX][MAX] ){
   for( int i = 0; i < MAX; i++ ){
     for( int j = 0; j < MAX; j++ )
          printf("%d", mat[i][j]);
  printf("\n"); 
  }
}


void main() {
  int lin = MAX/2, col = MAX/2;
  char santa[MAX] = {}, robo[MAX] = {};
  int presents = 0;

  FILE *fp; 
  fp = fopen ( "3.txt", "r" );

  int i;
  for( i = 0; i < MAX; i++ ) {
    if( 1 != fscanf( fp, "%c", &santa[i] ) ) break;
    if( 1 != fscanf( fp, "%c", &robo[i] ) ) break;
  }
  
  for( int tmp = 0; tmp < i; tmp++ ) {
    mat[lin][col]++;
    switch ( santa[tmp] ){
	case '^' : lin++; mat[lin][col]++; break;
        case '>' : col++; mat[lin][col]++; break;
        case '<' : col--; mat[lin][col]++; break;
        case 'v' : lin--; mat[lin][col]++; break;
    }
  }
  lin = MAX/2; col = MAX/2;
  for( int tmp = 0; tmp < i; tmp++ ) {
    mat[lin][col]++;
    switch ( robo[tmp] ){
        case '^' : lin++; mat[lin][col]++; break;
        case '>' : col++; mat[lin][col]++; break;
        case '<' : col--; mat[lin][col]++; break;
        case 'v' : lin--; mat[lin][col]++; break;
    }
  }

//  printmat( mat );
  for( int i = 0; i < MAX; i++ )
   for( int j = 0; j < MAX; j++ )
	if( mat[i][j] != 0 ) presents++;
  
  printf("presents = %d\n", presents);
  fclose(fp);
}
