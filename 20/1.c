#include <stdio.h>

#define MAX 220 

void main() {
	int vet[MAX] = {};

	int i = 0;
	for( i ; i < MAX; i++ )
		if( scanf("%d", &vet[i]) != 1 ) break;

	int a, b, c;
	for( i = 0; i < MAX-1; i++ )
		for( int j = i+1; j < MAX-1; j++ )
			for( int k = j+1; k < MAX; k++ )
				if( (vet[i] + vet[j] + vet[k]) == 2020 && vet[k] != 0 ) { a = vet[i]; b = vet[j]; c = vet[k]; break; }

	printf(" a = %d, b = %d, c = %d, mult = %d\n", a, b, c, a*b*c);
}
