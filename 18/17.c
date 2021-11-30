#include <stdio.h>
#include <unistd.h>

#define MAX 2000

int y_max = 0;
int y_min = MAX;
int x_max = 0;

int max( int a, int b ) {
	return ( a > b ? a : b );
}

int min( int a, int b ) {
	return ( a < b ? a : b );
}

char mat[MAX][MAX] = {};

void imprimemat(){
	FILE *fp = fopen( "arq.txt", "w");
//	printf("\033[H");
	for( int i = 0; i <= y_max+2; i++ ){
  		for( int j = 430; j < x_max; j++ ){
//  			if( mat[i][j] == '|' || mat[i][j] == '~' ) fprintf(fp, "\033[1;34;44m \033[0m" );
 //				else if( mat[i][j] == '#' ) fprintf(fp, "\033[1;37;47m \033[0m" );
  //					else fprintf(fp, " ");
			if( mat[i][j] != 0 ) fprintf(fp, "%c", mat[i][j]);
			else fprintf(fp, ".");
		}
  	usleep(3000);
	fprintf(fp,"\n");
	}
  	fprintf(fp,"\n");
	fclose( fp );
}					// x = col y = lin
					//1537 linhas o meu input
void imprimemat2(){
	printf("\033[H");
	for( int i = 0; i <= y_max+2; i++ ){
  		for( int j = 430; j < x_max; j++ ){
//  			if( mat[i][j] == '|' || mat[i][j] == '~' ) printf("\033[1;34;44m \033[0m" );
 //				else if( mat[i][j] == '#' ) printf("\033[1;37;47m \033[0m" );
  //					else printf(fp, " ");
			if( mat[i][j] != 0 ) printf("%c", mat[i][j]);
			else printf(".");
		}
  	usleep(3000);
	printf("\n");
	}
  	printf("\n");
}

int aguinha( int y, int x ){

  if ( y > y_max ) return 1;
  if( mat[y][x] != 0 ) return 0;
  mat[y][x] = '|';
   
// imprimemat2();

  // chama pra baixo
  int baixo = aguinha(y + 1, x);
  
  // chama pros lados
  if ( baixo == 0 ) {
	int esquerda = 0, direita = 0;
	esquerda = aguinha(y, x - 1);
	direita = aguinha(y, x + 1);
    	return esquerda || direita;
  }

	return baixo;
}

int main() {
	mat[0][500] = '+';
	for( int i = 0; i < 1537; i++ ){
		char c, h;
		int x, y, aux;
		scanf( "%c=", &c );
		if( c == 'x' ) { 
			scanf( "%d, %c=%d..%d\n", &x, &h, &y, &aux );
      y_min = min(y, y_min);
      x_max = max(x, x_max);
			for( ; y <= aux; y++ )
				mat[y][x] = '#';
		}
		else {
			scanf( "%d, %c=%d..%d\n", &y, &h, &x, &aux ); 
      y_max = max(y, y_max);
			for( ; x <= aux; x++ )
				mat[y][x] = '#';
	  }
	}      
	printf("\033[2J");
               
  aguinha( 1, 500 );  
	imprimemat();
  int agua = 0;
  for( int i = 0; i < x_max; i++ )
    for( int j = y_min; j <= y_max; j++)
      if( mat[j][i] == '|' ) agua++;

        printf("y max = %d, y min = %d, x max = %d\n", y_max, y_min, x_max );
  printf("agua = %d\n", agua );
        
	return 0;
}
