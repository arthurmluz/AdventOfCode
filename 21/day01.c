#include <stdio.h>
#include <stdlib.h>

int first(char name[]){

    FILE* file = fopen (name, "r");

    if (file == NULL){
        printf("Error! Couldnt open the file!");
        exit(1);
    }

    int count = 0;
    int before = 0;
    while(1){
        int now;
        if( fscanf(file, "%d", &now) != 1 ) break;

        if( now > before )
            count++;
        
        before = now;
    }

    return count;

}

int second(char name[]){

    FILE* file = fopen (name, "r");

    int arr[3] = {0,0,0};
    int pos = 0, sum = 0, count = -3;
    while(1){
        int tmp;
        if(fscanf(file, "%d", &tmp) != 1) break;

        arr[pos++] = tmp;
        if( pos == 3 ) pos = 0;
        
        tmp = arr[0] + arr[1] + arr[2];

        if(tmp > sum)
            count++;

        sum = tmp;
    }
    
    return count;
}

int main(){

    char name[] = "day1.txt";

    printf("%d\n", first(name)-1);
    printf("%d\n", second(name));
    return 0;
}
