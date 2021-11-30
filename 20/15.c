#include <stdio.h>
//    long int vet[30000010] = {0,3,6};
    long int vet[30000010] = {13,16,0,12,15,1};

void main(){
    for( long int i = 6; i < 30000001; i++ ){
        if( i % 1000000 == 0 ) printf("%ld\n", i);
        for( long int j = i-2; j >= 0; j-- )
            if( vet[j] == vet[i-1] ) { vet[i] = (i-1) - (j); break;}
    }
      printf("%ld\n", vet[30000000-1]);
}
