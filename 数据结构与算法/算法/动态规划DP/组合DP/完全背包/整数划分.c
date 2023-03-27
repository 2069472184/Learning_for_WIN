//https://www.acwing.com/problem/content/902/

//��ȫ����DP�ⷨ
/*
״̬���壺��ǰi����Ʒ��ѡ�������������Ϊj�����з������ļ���
״̬���㣺�ο���ȫ��������
*/
//���ذ汾
#include<stdio.h>
#define N 1010
#define mod 1000000007

int n;
int dp[N][N];

int main ( int argc, char *argv[] )
{
    scanf( "%d", &n );

    dp[0][0] = 1;

    for ( int i = 1; i <= n; i++ )
        for ( int j = 0; j <= n; j++ )
        {
            //��ѡ
            dp[i][j] = ( dp[i][j] + dp[i-1][j] ) % mod;
            //ѡ����1��
            for ( int k = 1; k * i <= j; k++ )
                dp[i][j] = ( dp[i][j] + dp[i-1][j-k*i] ) % mod;
        }

    printf( "%d\n", dp[n][n] );

    return 0;
}

//����kѭ���Ż�
#include<stdio.h>
#define N 1010
#define mod 1000000007

int n;
int dp[N][N];

int main ( int argc, char *argv[] )
{
    scanf( "%d", &n );

    dp[0][0] = 1;

    for ( int i = 1; i <= n; i++ )
        for ( int j = 0; j <= n; j++ )
        {
            //��ѡ
            dp[i][j] = ( dp[i][j] + dp[i-1][j] ) % mod;
            //ѡ����1��
            if ( j >= i ) dp[i][j] = ( dp[i-1][j] + dp[i][j-i] ) % mod;
        }

    printf( "%d\n", dp[n][n] );

    return 0;
}

//һάdp�Ż�
#include<stdio.h>
#define N 1010
#define mod 1000000007

int n, dp[N];

int main ( int argc, char *argv[] )
{
    scanf( "%d", &n );

    dp[0] = 1;
    for ( int i = 1; i <= n; i++ )
        for ( int j = i; j <= n; j++ )
            dp[j] = ( dp[j] + dp[j-i] ) % mod;

    printf( "%d\n", dp[n] ); 

    return 0;
}

//�ڶ��ֽⷨ
/*
״̬��ʾ���ܺ���i����ǡ���ܱ�ʾ��j�����ĺͷ����ļ���
״̬���֣�
    1.j��������СֵΪ1��dp[i][j] += dp[i-1][j-1]
    2.j��������Сֵ����1��
        1.��ÿ������-1������-j
        2.dp[i][j] += dp[i-j][j]
    3.������ܺͣ�ans = dp[n][1] + dp[n][2] + ���� + dp[n][n]
*/
#include<stdio.h>
#define N 1010
#define mod 1000000007

int n, ans;
int dp[N][N];

int main ( int argc, char *argv[] )
{
    scanf( "%d", &n );

    dp[0][0] = 1;
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= i; j++ )
            dp[i][j] = ( dp[i-j][j] + dp[i-1][j-1] ) % mod;

    for ( int i = 1; i <= n; i++ ) ans = ( ans + dp[n][i] ) % mod;

    printf( "%d\n", ans );

    return 0;
}