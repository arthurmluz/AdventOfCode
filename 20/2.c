#include <stdio.h>
#include <string.h>

void main(){
	int cont = 0;
	int lim1 = 0, lim2 = 0;
	char let, string[60] ={};
	for( int i = 0; i <= 1000; i++ ){
		int cont2 = 0;
		if( scanf("%d-%d %c: %s", &lim1, &lim2, &let, &string) != 4 ) break;
//		for(int j = 0; j < strlen(string); j++){							//	parte 1
			if( lim2 <= strlen(string) ){
			if( string[lim1-1] == let ) cont2++;						///	parte 1 era j
			if( string[lim2-1] == let ) cont2++;
			}
			if( cont2 == 1 ) cont++;
//		}										//	parte 1
//		if( cont2 >= lim1 && cont2 <= lim2 ) { cont++;}					//				parte 1
//		printf("%d-%d %c: %s\n", lim1, lim2, let, string); printf("to verificando: pos %d = %c e pos %d = %c\n", lim1-1, string[lim1-1], lim2-1, string[lim2-1]);		//teste
	}
	printf("%d\n", cont);
}
