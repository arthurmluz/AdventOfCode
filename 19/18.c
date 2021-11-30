#include<stdio.h>
#include<stdlib.h>

#define DIST_MAX 10000
#define MAX 82

int key_pos_x[26];
int key_pos_y[26];
int door_pos_x[26]= {0};
int door_pos_y[26] = {0};
char Mat[MAX][MAX] = {};

int min( int a, int b) {
    return ( a < b ? a : b );
}

void reachable_keys( int pos_x, int pos_y, int dist, char M[MAX][MAX], int saquinho[26]) {
    char ch = M[pos_x][pos_y];
    
//    printf("Amigo estou aqui %d, %d, %c\n", pos_x, pos_y, ch);
    
    if( ch == '#' || (ch >= 'A' && ch <= 'Z')) return;
    if (ch == '.'){
        Mat[pos_x][pos_y] = '#';
        
        reachable_keys(pos_x-1, pos_y, dist+1, M, saquinho);
        reachable_keys(pos_x+1, pos_y, dist+1, M, saquinho);
        reachable_keys(pos_x, pos_y-1, dist+1, M, saquinho);
        reachable_keys(pos_x, pos_y+1, dist+1, M, saquinho);
        
        Mat[pos_x][pos_y] = '.';
    }
    
    if( ch >= 'a' && ch <= 'z') {
        saquinho[ch - 'a'] = min(saquinho[ch - 'a'], dist);
    }
}

int solucao(int pos_x, int pos_y, char M[MAX][MAX], int cost) {
    
    int saquinho[26];
    for (int i = 0; i < 26; i++) saquinho[i] = DIST_MAX;
    
    reachable_keys(pos_x, pos_y, 0, M, saquinho);
    if(cost > min_cost) continue;   
    int flag = 0;
    int min_cost = 99999;
    for (int i = 0; i < 26; i++) {
        if (saquinho[i] == DIST_MAX) continue;
        flag = 1;
            
        char ch = 'a' + i;
        char dr = 'A' + i;
        
        M[key_pos_x[i]][key_pos_y[i]] = '.';
        if (door_pos_x) M[door_pos_x[i]][door_pos_y[i]] = '.';
        
        int key_cost = solucao(key_pos_x[i], key_pos_y[i], M, cost + saquinho[i]);
        if (key_cost < min_cost) min_cost = key_cost;
        
        M[key_pos_x[i]][key_pos_y[i]] = ch;
        if (door_pos_x) M[door_pos_x[i]][door_pos_y[i]] = dr;
    }
    
    if (!!!flag) {
        return cost;
    }
    
    return min_cost;
}

void main(){
    FILE *fp = fopen( "input.txt", "r" );

    int quant_chaves = 0;
    int Lin = 0, Col = 0;
    int pos_x = 0, pos_y = 0;
    
    if ( fp == NULL ) {
        printf("Deu problema");
        exit(1);
    } else {
        while (1) {
            char ch;
            if ( 1 != fscanf(fp, "%c", &ch) ) break;
           
            if( ch == '@'){
                pos_x = Col;
                pos_y = Lin;
                ch = '.';
            }
            
            if (ch >= 'a' && ch <= 'z') {
                key_pos_x[ch - 'a'] = Col;
                key_pos_y[ch - 'a'] = Lin;
            }
            
            if (ch >= 'A' && ch <= 'Z') {
                door_pos_x[ch - 'A'] = Col;
                door_pos_y[ch - 'A'] = Lin;
            }
            
            if ( ch == '\n') {
                Lin++;
                Col = 0;
            } else {
                Mat[Col][Lin] = ch;
                Col++;
           }
        }

        fclose( fp );
        printf("\n");
    }
    
    /*
    int saquinho[26] = {};
     
    for (int i=0; i<26; i++) saquinho[i] = DIST_MAX;
    */
    
    int resultado = solucao(pos_x, pos_y, Mat, 0); 
    printf("%d\n", resultado);
    
    /*
    reachable_keys(pos_x, pos_y, 0, Mat, saquinho);
    for (int i=0; i<26; i++)
      if ( saquinho[i] < DIST_MAX )
        printf("%c %d\n", 'a' + i, saquinho[i]);
    */

}
