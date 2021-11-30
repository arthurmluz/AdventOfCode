#include <stdio.h>

char mat[2041][28] = {};

int findLength( int lin ){
  int tmp = 0;
  while( mat[lin][tmp] >= 'a' && mat[lin][tmp] <= 'z' ) tmp++;
	return tmp;
}

int main(){

	int i = 0;
	while( fgets( mat[i++], 28, stdin) );
	int max = i-1;

	int start = 0, stop = 0, count = 0;
	while( start < max-1 ){
		for( i = start; i < max; i++ )
			if( mat[i][0] == '\n' ) { stop = i; break; }
		int people = stop - start;

            int length = findLength ( start );
            for( i = 0; i < length; i++ ) {
                int rep = 1;
                for( int nextLine = start+1; nextLine < stop; nextLine++ ) {
                    int repemnext = 0;
                    int lengthLin = findLength( nextLine );	
                    for( int j = 0; j < lengthLin; j++ )
                        if( mat[start][i] == mat[nextLine][j]) repemnext = 1;
                    rep = rep && repemnext;
                }
                if ( rep ) count++;
            }

		start = stop+1;
	}
  printf("A: %s", mat[0]);
  printf("B: %s", mat[1]);
	printf("count = %d\n",count);
  return 0;
}