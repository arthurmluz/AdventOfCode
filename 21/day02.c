#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* file = fopen ("day2.txt", "r");

    if (file == NULL){
        printf("Error! Couldnt open the file!");
        exit(1);
    }

    int x = 0, y = 0;

    int depth = 0, aim = 0;
    while(1){
        char str[20];
        int tmp;
        if(fscanf(file, "%s %d", str, &tmp) != 2) break;
        
        switch(str[0]){
            case 'f':
                x += tmp;
                depth += aim * tmp;
                break;
            case 'd':
                y += tmp;
                aim += tmp;
                break;
            case 'u':
                y -= tmp;
                aim -= tmp;
                break;
        }

    }
    printf("part 1: %d\n", x * y);

    printf("part 2: %d\n", x * depth);
    return 0;
}
