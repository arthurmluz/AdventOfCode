#include <stdio.h>
#include <math.h>
#include <stdlib.h>


typedef struct a{
  char string[40];
} mask;

typedef struct b{
  int dest_mask;
  int value;
  int memory;
  char binary[36];
} ops;

typedef struct c{
  long int value_left;
  int address;
  int flag;
} memory;

void main(){
    ops operation[550];
    mask masks[300];
    memory memories[550];
    int count_masks = 0, count_operation = 0, count_memories = 0;
    //Input reader
    while( 1 ){
        char letra;
        scanf("m%c", &letra);
	
        //Mask
        if( letra == 'a' ){
            if( scanf("sk = %s ", &(masks[count_masks].string)) != 1 ) break;
            count_masks++;
        }
        //operation
        if( letra == 'e' ){
            if( scanf("m[%d] = %d ", &(operation[count_operation].memory), &(operation[count_operation].value)) != 2 ) break;
            operation[count_operation].dest_mask = count_masks-1;
            int flag = 0;
            for( int j = 0; j < count_memories; j++ ) if( memories[j].address == operation[count_operation].memory ) flag = 1;
            if ( flag == 0 ) memories[count_memories++].address = operation[count_operation].memory;

            int tmp = operation[count_operation].value;
            for( int i = 35; i >= 0; i-- ){
                operation[count_operation].binary[i] =  ( operation[count_operation].value % 2) +'0';
                operation[count_operation].value /=2;
            }
            operation[count_operation].value = tmp;
            count_operation++;
        }
    }
    //faz as mágica dele
    for( int i = 0; i < count_operation; i++ ){
        char result[35] = {};
        for( int j = 0; j < 36; j++ ){
            if( masks[operation[i].dest_mask].string[j] == 'X' ) result[j] = operation[i].binary[j];
                 else result[j] = masks[operation[i].dest_mask].string[j];
        }
       long int parcial_sum = 0;
       for( int j = 35; j >= 0; j-- ){
           parcial_sum += (result[j]-'0') * pow(2, 35-j);
       }
       for( int tmp = 0; tmp < count_memories; tmp++ )
           if( memories[tmp].address == operation[i].memory ) memories[tmp].value_left = parcial_sum;
    }

    long int sum = 0;
    for( int i = 0; i < count_memories; i++ ) sum += memories[i].value_left;
    printf("sum = %ld\n", sum);
}
