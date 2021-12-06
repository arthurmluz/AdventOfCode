#include <stdio.h>
#include <stdlib.h>

int chosen[150];

int matrix[100][5][5];
int sorted[100][5][5] = {0};

int main(){

    FILE* file = fopen ("exinput.txt", "r");

    if (file == NULL){
        printf("Error! Couldnt open the file!");
        exit(1);
    }

    int flag = 0, lin = 0, col = 0, mat = 0, num = 0;
    while(1){
        int tmp;
        if( fscanf(file, "%d,", &tmp) != 1 ) break;

        // change to last digit from input chosen numbers
        if( !flag ){
            chosen[lin++] = tmp;
            if(tmp == 1) {flag = 1; lin = 0;}
            num++;
            continue;
        }
        
        // 5 x 5 matrix
        if( col == 5 ){
            col = 0;
            lin++;
            if ( lin == 5 ){
                lin = 0;
                mat++;
            }
        }

        matrix[mat][lin][col++] = tmp;
    }

    int bingo = 0;
    for(int z = 0; z < num; z++){
        int sort = chosen[z];

        printf("\n---new number %d---\n", sort);

        for(int i = 0; i < 3; i++ ){

            int markedColumn[5] = {0};
            for( int j = 0; j < 5; j++ ){

                int flag = 0;
                int markedLine = 0;
                for( int k = 0; k < 5; k++ ){
                    if( sort == matrix[i][j][k] ) sorted[i][j][k] = 1;
                    if( sorted[i][j][k] == 1) { markedLine++; if( flag == 0 ) {markedColumn[j]++; flag = 1;}}
                    printf("%d ", sorted[i][j][k]);
                }
                printf("\n");

                printf("marked column = %d %d %d %d %d\n", markedColumn[0], markedColumn[1], markedColumn[2], markedColumn[3], markedColumn[4]);

                if( markedLine == 5 ){
                    printf("BINGO!!\n");
                    exit(1);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
