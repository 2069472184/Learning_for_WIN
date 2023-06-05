//https://www.acwing.com/problem/content/5/

//���ر���dp��ÿ����Ʒ����������
/*
״̬������dp[i][j]��ʾ�������㡰ֻ��ǰi����Ʒ��ѡ���ܼ�ֵ������j���ķ�������Ʒ�ܼ�ֵ�ļ��ϣ�������max
״̬���֣�
    1.��i����Ʒѡ0��
    2.��i����Ʒѡ1��
    ��������
    n.��i����Ʒѡn-1��
*/
//����д��---TLE
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 105

int n, V, s[N], v[N], w[N];
int dp[N][N];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &V );
    for ( int i = 1; i <= n; i++ ) 
        scanf( "%d%d%d", &v[i], &w[i], &s[i] );

    for ( int i = 1; i <= n; i++ )
        for ( int j = 0; j <= V; j++ )
            for ( int k = 0; k*v[i] <= j && k <= s[i]; k++ )
                dp[i][j] = max( dp[i][j], dp[i-1][j-k*v[i]] + k*w[i] );

    printf( "%d\n", dp[n][V] );

    return 0;
}

//��άתһά�Ż�---TLE
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 1010

int n, V, s, v, w;
int dp[N];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &V );

    for ( int i = 1; i <= n; i++ )
    {
        scanf( "%d%d%d", &v, &w, &s );
        for ( int j = V; j >= 0; j-- )
            for ( int k = 0; k*v <= j && k <= s; k++ )
                dp[j] = max( dp[j], dp[j-k*v] + k*w );
    }

    printf( "%d\n", dp[V] );

    return 0;
}

//�����ݷ���+��άתһά�Ż�
/*
ע�⣺
    ���ر��������޷�����ȫ�����������kѭ�����Ż���ʽ�����Ż�,
    ��Ϊÿһ����Ʒ��������ͬ����kȫ��չ��֮�������ͬ���޷��������
    �κ����������ɶ�������������ӱ�ʾ
�Ż�������
    1.������
        1.����ĳ����Ʒ����1023��.
        2.�����10�飺1,2,4,8,����,512������10�鿴��10������Ʒ��ÿ����Ʒֻ����һ��
    2.������һ����Ʒ��s�����Ȱ���2�������ݷ��飺1,2,4,����,2^k,c  ( 2^k <= s, 0 <= c < s - 2^k )
           Ȼ����Щ��Ʒ��ȡ������������ķ�����������((int)logk)+1����Ʒ�����������Ҫ��ȫ
           ͬʱ��Ҫ����ÿ����Ʒ����������ܼ�ֵ��Ȼ������((int)logk)+1����Ʒ��һ��01�������⼴��
*/
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define M 25000  //ԭ�������1000����Ʒ��ÿ����Ʒ���Ҫ�ֳ� ((int)log2000)+1 ������Ʒ�������¿��������СҪ����1000*(((int)log2000)+1)

int n, V, v[M], w[M], count;  //v��w�ֱ𴢴�������������Ʒ������ͼ�ֵ,count��¼����Ʒ����
int dp[M];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &V );

    for ( int i = 1; i <= n; i++ )   //ԭ�ȵ�ÿ����Ʒ��Ҫ���·ֳ��µ���Ʒ����Щ����Ʒ������ͬ���Ҷ�ֻ��һ��
    {
        int a, b, s;   //a��ʾÿ����Ʒ�ļ�ֵ��b��ʾÿ����Ʒ�������s��ʾÿ����Ʒ������
        scanf( "%d%d%d", &a, &b, &s );
        int k = 1;   //kÿ�δ洢����*2�������������
        //��ʵ���ǽ����д���[k,k*2)֮���������ȡ�������������һ���µ���Ʒ��
        //��Ϊÿ��ԭ��Ʒֻ������һ��ȡ��������ֻ��Ҫ������ȡ�����»���ĳһ������
        while ( k <= s )
        {
            count++;
            v[count] = a*k;     
            w[count] = b*k;
            s -= k;
            k *= 2;
        }
        //���û�зָɾ�����ʣ�µķֳ�1��
        if ( s )  
        {
            count++;
            v[count] = a*s;
            w[count] = b*s;
        }
    }

    n = count; //������Ʒ����w
    //01����һά�Ż�ģ��
    for ( int i = 1; i <= n; i++ )
        for ( int j = V; j >= v[i]; j-- )
            dp[j] = max( dp[j], dp[j-v[i]] + w[i] );

    printf( "%d\n", dp[V] );

    return 0;
}