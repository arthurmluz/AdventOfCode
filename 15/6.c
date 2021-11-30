#include <stdio.h>
//					toggle = 1/ off = 2/ on = 3
char mat[1000][1000] = {};

void luzinhas ( int instruction, int x, int y, int x2, int y2 ){ 
		for( int lin = x; lin <= x2; lin++ )
			for( int col = y; col <= y2; col++ )
				switch( instruction ) {
				case 1 : mat[lin][col] += 2; break;
				case 2 : if( mat[lin][col] > 0 ) mat[lin][col] -= 1; break;
				case 3 : mat[lin][col] += 1; break;
				default : printf("%d oq eu to fazendo aqui???\n", instruction);
			}
}

void main(){
	int instruction;
	int x, y, x2, y2;
	while( scanf("%d %d,%d through %d,%d", &instruction, &x, &y, &x2, &y2) == 5 ){
		luzinhas( instruction, x, y, x2, y2 );
	}
	int luz = 0;
	for( int i = 0; i < 1000; i++ )//{
		for( int j = 0; j < 1000; j++ ){
			luz += mat[i][j];
//			if( mat[i][j] == 1 ) printf(".");//printf("\033[1;32;42m \033[0m");
//			if( mat[i][j] == 0 ) printf(" ");
//		}
//		printf("\n");
	}
	printf("luz = %d\n", luz);
}
