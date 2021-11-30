#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmpfunc (const void * a, const void * b) {
	return ( *(int*)a - *(int*)b );
}

void main(){
	int vet[110] = {};
	int i = 1;
	while( scanf("%d ", &vet[i++]) == 1 );
	int max = i-1;
	int dif[110] = {};
	qsort( vet, max, sizeof(int), cmpfunc); 		// obg brossard

	int diff1 = 0, diff2 = 0, diff3 = 0;
	for( i = 0; i < max; i++ ){
		if( i == max-1 ) vet[i+1] = vet[i] + 3; 
		if( vet[i] < vet[i+1]+3 ) {
			int tmp = vet[i+1] - vet[i];
			if( tmp == 1 ) diff1++;
			if( tmp == 2 ) diff2++;
			if( tmp == 3 ) diff3++;
			dif[i] = tmp;
		}
		else break;
	}
	int a = 0, b = 0, c = 0;
	i = 0;
	while( i < max ){
		int tmp = 0;
		while( dif[i] != 3 )
			if( dif[i] == 1 ) {i++; tmp++;}
		if( tmp == 4 ) a++;
		if( tmp == 3 ) b++;
		if( tmp == 2 ) c++;
		i++;
	}
	printf("tentativas = %f\n", pow(7,a) * pow(4,b) * pow(2,c));
	printf("achei diff1 = %d, diff2 = %d, diff3 = %d, mult = %d\n", diff1, diff2,  diff3, diff1*diff3);

}
