#include <stdio.h>
#define MAX 660

typedef struct op{
	char instruction;
	int argument, flag;
} ops;

void main(){		
	ops opera[MAX];
	int i, acumulador = 0;
	for( i = 0; i < MAX; i++ ){
		char trash;
		if( scanf("%c%c%c %d ", &opera[i].instruction, &trash, &trash, &opera[i].argument) != 4 ) break;
		opera[i].flag = 0;
	}

	i = 0;
	while( !opera[i].flag ){
		switch ( opera[i].instruction ){
			case 'a' : acumulador+= opera[i].argument; opera[i].flag = 1; i++; break;
			case 'j' : opera[i].flag = 1; i += opera[i].argument;  break;
			case 'n' : opera[i].flag = 1; i++; break;
		}
	}
		//if i > 656 terminate
	for( int mudando = 0; mudando < 656; mudando++ ){
		ops tmp[MAX];
		for( int j = 0; j < MAX; j++ )tmp[j] = opera[j];	// crio uma copia
		if( tmp[mudando].instruction == 'j' ) tmp[mudando].instruction = 'n';
		else if( tmp[mudando].instruction == 'n' ) tmp[mudando].instruction = 'j';
		i = 0;
		int pls_break = 0, acumulador2 = 0;
		while( pls_break < 5000 ){
			switch ( tmp[i].instruction ){
				case 'a' : acumulador2+= tmp[i].argument; i++; break;
				case 'j' : i += tmp[i].argument;  break;
				case 'n' : i++; break;
			}
			if( i >= 656 ) { printf("terminou, mudando = %d, acumula2 = %d\n", mudando, acumulador2); break; }
			pls_break++;
		}
	}
	printf("acumulador = %d\n", acumulador);
}

