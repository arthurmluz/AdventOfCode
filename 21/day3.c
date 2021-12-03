#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define FILENAME "exinput.txt"

int values[12] = {0};
char allValues[1010][12];

int convert(int vet[], int size){
    int value = 0, j = size-1;
    for( int i = 0; i < size; i++ ){
        value += vet[i] * pow(2, j--);
    }
    return value;
}


int main(){
    FILE* file = fopen (FILENAME, "r");

    if (file == NULL){
        printf("Error! Couldnt open the file!");
        exit(1);
    }

    int lines = 0;

    char tmp[12];
    while(1) {
        if( fscanf(file, "%s", tmp) != 1 ) break;
        
        for(int i = 0; i < strlen(tmp); i++){
           if( tmp[i] == '1' ) values[i]++;
           allValues[lines][i] = tmp[i];
        }

        lines++;

    }

    int gamma[12] = {0};
    for(int i = 0; i < strlen(tmp); i++) {
        if( values[i] > lines/2 ) gamma[i] = 1; 
        else gamma[i] = 0;
        printf("%d ", values[i]);
    }
    printf("\n");

    int gammas = convert(gamma, strlen(tmp));
    int epsi = pow(2, strlen(tmp)) - gammas - 1;
    printf("gamma = %d, epis = %d, answer = %d\n", gammas, epsi, gammas * epsi );

    return 0;
}
