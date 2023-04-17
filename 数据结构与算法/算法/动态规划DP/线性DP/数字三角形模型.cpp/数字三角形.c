//https://www.acwing.com/problem/content/900/

//����dp
/*
״̬��ʾ��dp[i][j]��ʾ�������㵽���(i, j)������·����ɵļ���������·�����ֺ�
״̬���֣�
    1.ǰһ����������.
    2.ǰһ����������.
    3. dp[i][j] = max( dp[i-1][j], dp[i-1][j-1] ) + c[i][j];  ע�� j == 1 �� j == i �����
*/
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 505

int n, ans, c[N][N];
int dp[N][N];

int main ( int argc, char argv[] )
{   
    scanf( "%d", &n );
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= i; j++ )
            scanf( "%d", &c[i][j] );

    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= i; j++ )
        {
            if ( j == 1 ) dp[i][j] = dp[i-1][j] + c[i][j];
            else if ( j == i ) dp[i][j] = dp[i-1][j-1] + c[i][j];
            else dp[i][j] = max( dp[i-1][j], dp[i-1][j-1] ) + c[i][j];
        }

    ans = -0x3f3f3f3f;
    for ( int i = 1; i <= n; i++ ) ans = max( ans, dp[n][i] );

    printf( "%d\n", ans );

    return 0;
}
