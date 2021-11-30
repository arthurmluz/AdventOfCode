#include <stdio.h>

void printcasinhas( char cas[100][100], int lin, int col) {
    int i, j;
    printf("\033[H\033[H");
    for(i=0; i<lin; i++) {
      for(j=0; j<col; j++)
	switch ( cas[i][j] ){
	   case '|' :  printf( "\033[1;31;41m \033[0m"); break;
	   case '#' :  printf( "\033[1;32;42m \033[0m"); break;
	   case '.' :  printf( "\033[1;33;43m \033[0m"); break;
	}
      printf("\n");
    }
    printf("\n");
}

int count( int i, int j, char casinha[100][100], char procurando, int Max ){
    int count = 0;
    for(int y= i-1; y <= i+1; y++ ){
        if(y < 0 || y > Max) continue;
        for(int x= j-1; x <= j+1; x++ ){
            if(x < 0 || x > Max) continue;
            if(y == i && x == j) continue;
            if (casinha[y][x] == procurando)
                count++;
        }
    }
    return count;
}

int main() {
    printf("\033[2J");
    char casinha[100][100];
    char foto[100][100];
    int i = 0, j, Max = 0, frame = 1000;

    while ( fgets( casinha[i++], 100, stdin ) );

    Max = i-1;

    for(long long int minute = 0; minute < 1000000000; minute ++){
    	printcasinhas( casinha, Max, Max );
//	printf( "minute = %lld\n", minute );
        char novas_casinhas[100][100];

        for( i=0; i<Max; i++ ){
            for( j=0; j<Max; j++ ){
                int viz;
                novas_casinhas[i][j] = casinha[i][j];
                switch ( casinha[i][j] ) {
                    case '.':

                        viz = count( i, j, casinha, '|', Max );
                        if ( viz >= 3 ) novas_casinhas[i][j] = '|';
                        break;
                    case '|':

                        viz = count( i, j, casinha, '#', Max );
                        if ( viz >= 3 ) novas_casinhas[i][j] = '#';
                        break;
                    case '#':

                        viz = count( i, j, casinha, '#', Max );
                        if ( viz >= 1 ){
                            viz = count( i, j, casinha, '|', Max );
                            if ( viz >= 1 ) novas_casinhas[i][j] = '#';
                            else novas_casinhas[i][j] = '.';
                        }
                        else novas_casinhas[i][j] ='.';
                        break;
                }
            }
        }
        if( minute == frame ) {
          for( i=0; i<Max; i++ )
              for( j=0; j<Max; j++ )
		foto[i][j] = novas_casinhas[i][j];

	}

	if( minute > frame+1 ) {
	  int mudou = 0;
          for( i=0; i<Max; i++ )
             for( j=0; j<Max; j++ )
		if( foto[i][j] != novas_casinhas[i][j] ) mudou = 1;
	  if( mudou == 0 ) {
		int frames = minute - frame, loops;
		loops = ( 1000000000-frame ) / frames;
		loops = ( loops * frames ) + frame;
		minute = loops;

		if(  minute >= 1000000000  ){
//		    int wooden = 0;
//		    int acres = 0;
//		    for(i=0; i<Max; i++)
//		      for(j=0; j<Max; j++) {
//		        if (casinha[i][j] == '|') wooden++;
//		        if (casinha[i][j] == '#') acres++;
//		      }
//		    printf("%d x %d = %d\n", wooden, acres, wooden * acres);
		break;
		}

		}
	}

        for( i=0; i<Max; i++ )
            for( j=0; j<Max; j++ )
                casinha[i][j] = novas_casinhas[i][j];

    }

    int wooden = 0;
    int acres = 0;
    for(i=0; i<Max; i++)
      for(j=0; j<Max; j++) {
        if (casinha[i][j] == '|') wooden++;
        if (casinha[i][j] == '#') acres++;
      }
    printf("%d x %d = %d\n", wooden, acres, wooden * acres);
}
