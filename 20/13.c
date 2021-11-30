#include <stdio.h>

int LCM( int n1, int n2 ){
    int max = (n1 > n2) ? n1 : n2;

    while (1) {
        if (max % n1 == 0 && max % n2 == 0) {
            return max;
        }
        ++max;
    }
    return 0;
}


void main(){

    int x = 1;
    int vet[8] = {7,13,x,x,59,x,31,19};
//    int mine = 1000511;
//    int vet[102] ={ 29,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,37,x,x,x,x,x,409,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,17,13,19,x,x,x,23,x,x,x,x,x,x,x,353,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,41 };

    int lcm = 91;
    int tam = sizeof(vet)/sizeof(vet[0]);
    for( int i = 2; i < tam; i++ ){
	if( vet[i] == x ) continue;
        for( int acumula = vet[i]; acumula < 10000; acumula+= vet[i] ){
	    if( (acumula-i) % vet[0] == 0 ) {lcm = LCM( vet[i], lcm ); printf("achei %d, lcm = %d\n", acumula, lcm); break;}
	}
    }
    printf("terminei\n");
}
