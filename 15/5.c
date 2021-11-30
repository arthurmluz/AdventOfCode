#include <stdio.h>
#include <string.h>
void main(){
	int nice = 0;
	char string[16];
	while( scanf( "%s", string ) == 1 ){
		int middle = 0;
		int pairs = 0;
		for( int i = 0; i < 16; i++ ){
			if( string[i] == string[i+2] ) middle++;
		}
		for( int j = 0; j < 16; j++ ){
			for( int k = j+2; k < 16; k++ ){
				if( string[j] == string[k] && string[j+1] == string[k+1] ) pairs++;
			}
		}
		if( middle > 0 && pairs > 0 ) nice++;
	}	
	printf("nice = %d\n", nice );
}
