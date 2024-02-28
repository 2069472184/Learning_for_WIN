//https://www.acwing.com/problem/content/3/

//��ȫ����DP
/*
״̬���壺dp[i][j]��ʾһ����������ǰi����Ʒ��ѡ���������������j�������з������ܼ�ֵ�ļ��ϣ�
         ������max��ע�⣬�˴�����һ��ѡi����Ʒ
״̬���֣�
    1.��i����ѡ��dp[i][j] = dp[i-1][j]
    2.��i��ѡ��k��(k>=1)��
        ѡ1����dp[i][j] = dp[i-1][j-v[i]] + w[i]
        ѡk����dp[i][j] = dp[i-1][j-v[i]*k] + w[i]*k
    3.���ȡ���ֵ����
*/

//����д��---TLE
/* #include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 1010

int n, V, w[N], v[N];
int dp[N][N];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &V );
    for ( int i = 1; i <= n; i++ ) 
        scanf( "%d%d", &v[i], &w[i] );
    
    for ( int i = 1; i <= n; i++ )
        for ( int j = 0; j <= V; j++ )
            for ( int k = 0; k*v[i] <= j; k++ )
                dp[i][j] = max( dp[i][j], dp[i-1][j-k*v[i]] + w[i]*k );

    printf( "%d\n", dp[n][V] );
    
    return 0;
} */

//�Ż���k��ѭ��
/*
dp[i][j] = max( dp[i-1][j], dp[i-1][j-v[i]]+w[i], dp[i-1][j-2*v[i]]+2*w[i],����, dp[i-1][0]+j )
dp[i][j-v[i]] = max(        dp[i-1][j-v[i]]     , dp[i-1][j-2*v[i]]+  w[i],����, dp[i-1][0]+j-w[i] )
��ʽ���ϣ�dp[i][j] = max( dp[i-1][j], dp[i][j-v[i]]+w[i] ).���������Ż���k��ѭ��
*/
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 1010

int n, V, w[N], v[N];
int dp[N][N];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &V );
    for ( int i = 1; i <= n; i++ ) 
        scanf( "%d%d", &v[i], &w[i] );
    
    for ( int i = 1; i <= n; i++ )
        for ( int j = 0; j <= V ; j++ )
        {
            //for ( int k = 0; k*v[i] <= j; k++ )
                //dp[i][j] = max( dp[i][j], dp[i-1][j-k*v[i]] + w[i]*k );
            //�˴���Ϊʡ����k��ѭ�������Բ�ѡ�����û�취�� k = 0 ʱ dp[i][j] = do[i-1][j] ˳�����㣬�ʱ�����д���Ա�������max�Ƚ�
            //��ѡ
            dp[i][j] = dp[i-1][j];
            //ѡk��
            if ( j >= v[i] ) dp[i][j] = max( dp[i][j], dp[i][j-v[i]] + w[i] );
        }  

    printf( "%d\n", dp[n][V] );
    
    return 0;
}

//�Ż���v,w����
/*
������һ���Ż������ǿ��Է��֣�ÿ��iѭ��ֻ�õ���v[i],w[i]�����Կ���ʡ�Ե���������������Ĳ�����ֱ����ÿ��iѭ��������i��Ӧ�ļ�ֵ�����
*/
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 1010

int n, V, w, v;
int dp[N][N];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &V );
    
    for ( int i = 1; i <= n; i++ )
    {
        scanf( "%d%d", &v, &w );
        for ( int j = 0; j <= V ; j++ )
        {
            //for ( int k = 0; k*v[i] <= j; k++ )
                //dp[i][j] = max( dp[i][j], dp[i-1][j-k*v[i]] + w[i]*k );
            //�˴���Ϊʡ����k��ѭ�������Բ�ѡ�����û�취�� k = 0 ʱ dp[i][j] = do[i-1][j] ˳�����㣬�ʱ�����д���Ա�������max�Ƚ�
            //��ѡ
            dp[i][j] = dp[i-1][j];
            //ѡk��
            if ( j >= v ) dp[i][j] = max( dp[i][j], dp[i][j-v] + w ); 
        } 
    } 

    printf( "%d\n", dp[n][V] );
    
    return 0;
}

//���������Ż��ռ�
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 1010

int n, V, w, v;
int dp[2][N];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &V );

    for ( int i = 1; i <= n; i++ )
    {
        scanf( "%d%d", &v, &w );
        for ( int j = 0; j <= V ; j++ )
        {
            //for ( int k = 0; k*v[i] <= j; k++ )
                //dp[i][j] = max( dp[i][j], dp[i-1][j-k*v[i]] + w[i]*k );
            //�˴���Ϊʡ����k��ѭ�������Բ�ѡ�����û�취�� k = 0 ʱ dp[i][j] = do[i-1][j] ˳�����㣬�ʱ�����д���Ա�������max�Ƚ�
            //��ѡ
            dp[i&1][j] = dp[(i-1)&1][j];
            //ѡk��
            if ( j >= v ) dp[i&1][j] = max( dp[i&1][j], dp[i&1][j-v] + w );
        }  
    }

    printf( "%d\n", dp[n&1][V] );
    
    return 0;
}

//��άתһά�Ż�
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 1010

int n, V, w, v;
int dp[N];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &V );
    
    for ( int i = 1; i <= n; i++ )
    {
        scanf( "%d%d", &v, &w );
        /*ע������j�Ǵ�С����ѭ������0-1���������Ż���ͬ
        ��Ϊ�滻������dp[i][j-v]����ȫ��������Ҫ���i��ÿ��j�ļ������õ��Ķ��Ǳ��������
        ��С����ѭ�����Ա�֤�ڼ���ϴ��jʱ j - v �Ѿ������¹�*/
        for ( int j = v; j <= V ; j++ )   
        {                                 
            //dp[i][j] = dp[i-1][j];
            //��ѡ�������Ϊ��dp[j] = dp[j]������ֱ��ʡ��

            //ѡk��
            dp[j] = max( dp[j], dp[j-v] + w );
            //dp[i][j] = max( dp[i][j], dp[i][j-v] + w );
            //����dp[j]��ʱ��dp[j-v]�Ѿ���������ˣ��Ҿ��ڵ�i�㣬�����ǵȼ۱任
        }
    }

    printf( "%d\n", dp[V] );
    
    return 0;
}

//���մ���
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 1010

int n, V, w, v;
int dp[N];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &V );
    
    for ( int i = 1; i <= n; i++ )
    {
        scanf( "%d%d", &v, &w );
        for ( int j = v; j <= V ; j++ ) 
            dp[j] = max( dp[j], dp[j-v] + w );
    }

    printf( "%d\n", dp[V] );
    
    return 0;
}