#include <stdio.h>
#define MAX 10000

void main() {
int length[MAX] = {0}, width[MAX] = {0}, height[MAX] = {0};
int paper = 0, ribbon = 0;


  FILE *fp;

  fp = fopen ( "2.txt", "r" );

  if ( fp == NULL )
    printf( "Tá fazendo algo errado\n");

  else {
	int i;
	for( i = 0; i < MAX; i++ ) {
	  if ( 1 != fscanf( fp, "%dx", &length[i] ) ) break;
	  if ( 1 != fscanf( fp, "%dx", &width[i]  ) ) break;
	  if ( 1 != fscanf( fp, "%d ", &height[i] ) ) break;
	}
	
	for( int tmp = 0; tmp < i; tmp++ ) {
	  int size1 = length[tmp] * width[tmp], size2 = width[tmp] * height[tmp], size3 = height[tmp] * length[tmp], flag = 1;
	  paper += 2 * (size1) + 2 * (size2) + 2 * (size3);

	  int p1 = width[tmp] * 2 + height[tmp] * 2, p2 = length[tmp] * 2 + height[tmp] * 2, p3 = 2 * length[tmp] + 2 * width [tmp];
	   if( p1 <= p2 && p1 <= p3 ) {ribbon += p1; flag = 0;}
           if( p2 <= p1 && p2 <= p3 && flag == 1 ) {ribbon += p2; flag = 0;}
           if( p3 <= p2 && p3 <= p1 && flag == 1 ) {ribbon += p3; flag = 0;}
	
           ribbon += length[tmp] * width [tmp] * height[tmp];

	  if( size1 <= size2 && size1 <= size3 ) {paper+= size1; continue;}
	  if( size2 <= size1 && size2 <= size3 ) {paper+= size2; continue;}
	  if( size3 <= size2 && size3 <= size1 ) {paper+= size3; continue;}


	}
      }
  printf("paper = %d, ribbon = %d\n", paper, ribbon);
  fclose ( fp );
}
