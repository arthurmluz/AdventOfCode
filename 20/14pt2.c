#include <stdio.h>
#include <string.h>
void junta( char mask[], char end[], int pos, char res[], int val ){
    if( pos >= strlen(mask) ) {
        printf("%s, %d\n", res, val);
    }
    char cm = mask[pos];
    char ce = end[pos];
//    printf("cm = %c, ce = %c\n", cm, ce);
    if( cm == 'X' ){
        res[pos] = '0';
        junta( mask, end, pos + 1, res, 2*val );
        res[pos] = '1';
        junta( mask, end, pos + 1, res, 2*val + 1 );
        return;
    }
    if( cm == '0' ) { res[pos] = ce; val = 2*val + ce-'0'; }
    if( cm == '1' ) { res[pos] = '1'; val = 2*val + 1; }
    junta( mask, end, pos + 1, res, val );
    return;
}

void main(){
   char mask[15] = "0010x010x01x01";    
   char end[15] = "01101000101100";
   char res[15] = {};
   junta( mask, end, 0, res, 0 );

}
