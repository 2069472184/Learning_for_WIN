#include<stdio.h>

#define N 10
int a[N][N];

int main ( int argc, char * argv[] ) 
{
	int n,t;
	
	while ( scanf( "%d",&n )!=EOF ) {
		int i, j, num = 0, count = 1;
		if ( n == 1 ) {
			a[0][0] = 1;
		} else {
			while ( count <= n*n ) {
				for ( i = num; i < n-1; i++ ) {
					a[i][n-1-num] = count++;     //β�б���
				}

				for ( j = n-1-num; j > 0; j-- ) {
					a[n-1-num][j] = count++;     //β�б���
				}

				for ( i = n-1-num; i > 0 ; i-- ) {
					a[i][num] = count++;         //ͷ�б���
				}
				 
				for ( j = num; j < n-num-1; j++) {
					a[num][j] = count++;         //ͷ�б���
				}
				num++;
			}
		}
		if ( n%2 ) {
			a[n/2][n/2] = count;
		}
		for ( i = 0; i < n; i++ ) {
			for ( j = 0; j < n; j++ ) {
				printf( "%d ",a[i][j] );
			}
			printf( "\n" );
		}
	}

	return 0;
}
