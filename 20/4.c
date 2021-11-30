#include <stdio.h>
#define MAX 1097		//1096

char mat[MAX][90] ={};

void main(){
	int max, i = 0;
	while( fgets( mat[i++], 90, stdin) );
	max = i-1;

//	printf("max = %d\n", max);

	int cont = 0;
	for( i = 0; i < max; i++ ){
 		int byr, iyr, eyr, hgt, hcl, ecl, pid, cid;
		if( i == 0 ){ byr = 0; iyr = 0; eyr = 0; hgt = 0; hcl = 0; ecl = 0; pid = 0; cid = 0; }

 		if( mat[i][0] == ' ' || mat[i][0] == '\n'){ byr = 0; iyr = 0; eyr = 0; hgt = 0; hcl = 0; ecl = 0; pid = 0; cid = 0; i++; }

		for( int j = 0; j < 90; j++ ){
			if( mat[i][j] == 'b' && mat[i][j+1] == 'y' && mat[i][j+2] == 'r' ) { 
				int a = mat[i][j+4];
				int b = mat[i][j+5];
				int c = mat[i][j+6];
				int d = mat[i][j+7];
				if( a != 49 && a != 50 ) break;
				if( a == 49 && b < 57 ) break;
				if( a == 49 && b == 57 && c < 50 ) break;

				if( a == 50 && b > 48 ) break;
				if( a == 50 && b == 48 && c > 48 ) break;
				if( a == 50 && b == 48 && c == 48 && d > 50 ) break;
				byr++;
			}
			if( mat[i][j] == 'i' && mat[i][j+1] == 'y' && mat[i][j+2] == 'r' ) { //2010 2020
				int a = mat[i][j+4];
				int b = mat[i][j+5];
				int c = mat[i][j+6];
				int d = mat[i][j+7];
				if( a != 50 ) break;

				if( a == 50 && b > 48 ) break;
				if( a == 50 && b == 48 && c < 49 ) break;
				if( a == 50 && b == 48 && c > 50 ) break;
				if( a == 50 && b == 48 && c == 50 && d > 48 ) break;
				iyr++;
			}
			if( mat[i][j] == 'e' && mat[i][j+1] == 'y' && mat[i][j+2] == 'r' ){ //2020 2030
				int a = mat[i][j+4];
				int b = mat[i][j+5];
				int c = mat[i][j+6];
				int d = mat[i][j+7];
				if( a != 50 ) break;

				if( a == 50 && b > 48 ) break;
				if( a == 50 && b == 48 && c < 50 ) break;
				if( a == 50 && b == 48 && c > 51 ) break;
				if( a == 50 && b == 48 && c == 51 && d > 48 ) break;
				eyr++;
			}
			if( mat[i][j] == 'h' && mat[i][j+1] == 'g' && mat[i][j+2] == 't' ){ // cm 150 e 193 in 59 e 76
				int a = mat[i][j+4];
				int b = mat[i][j+5];
				int c = mat[i][j+6];
				int d = mat[i][j+7];
				int e = mat[i][j+8];
				if( d == 'c' && e == 'm' ){
					if( a != '1' ) break;
					if( b < '5' ) break;
					hgt++;	
				}
				else if ( c == 'i' && d == 'n') {
					if( a < '5' || a > '7' ) break;
					if( a == '7' && b > '6' ) break;
					hgt++;
				}
			}			
			if( mat[i][j] == 'h' && mat[i][j+1] == 'c' && mat[i][j+2] == 'l' ) {
				int a = mat[i][j+4];
				if( a != '#' ) break;
				int flag = 0;
				for( int k = 0; k < 6; k++ ){
					a = mat[i][j+5+k];
					if( a < '0' ) { flag = 1; break; }
					if( a > '9' && a < 'a' ) {flag =1; break; }
					if( a > 'f' ) {flag = 1; break; }
				}
				if( flag == 1 ) break;
				hcl++;
			}
			if( mat[i][j] == 'e' && mat[i][j+1] == 'c' && mat[i][j+2] == 'l' ) { //			amb blu brn gry grn hzl oth
				int a = mat[i][j+4];
				int b = mat[i][j+5];
				int c = mat[i][j+6];
				if( a == 'a' && b == 'm' && c == 'b' ) ecl++;
				if( a == 'b' && b == 'l' && c == 'u' ) ecl++;
				if( a == 'b' && b == 'r' && c == 'n' ) ecl++;
				if( a == 'g' && b == 'r' && c == 'y' ) ecl++;
				if( a == 'g' && b == 'r' && c == 'n' ) ecl++;
				if( a == 'h' && b == 'z' && c == 'l' ) ecl++;
				if( a == 'o' && b == 't' && c == 'h' ) ecl++;
			}
			if( mat[i][j] == 'p' && mat[i][j+1] == 'i' && mat[i][j+2] == 'd' ) {
				int flag = 0;
				for( int k = 0; k < 9; k++ )
					if( mat[i][j+4+k] < '0' || mat[i][j+4+k] > '9' ) flag = 1;

				if( flag == 0 ) pid++;
			}
		}
		if( mat[i+1][0] == '\n' )
			if( byr == 1 && iyr== 1 && eyr == 1 && hgt ==1 && hcl==1 && ecl==1 && pid==1  ) cont++;
		
	}
	printf("cont = %d\n", cont);

}
