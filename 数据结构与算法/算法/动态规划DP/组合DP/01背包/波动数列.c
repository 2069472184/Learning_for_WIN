//https://www.acwing.com/problem/content/1216/

/*
��������ⲻͬ����֮����ͨ�������е�һ��Ԫ��x�����ģ����Ծ���Ҫ�Ƶ�x�Ĺ�ʽ
��ʽ�Ƶ���
1.������dҪôΪ-aҪôΪ+b���������оͿ��Ա�ʾΪx,x+b1,x+b1+b2,����,x+b1+b2+����+bn-1.
  �õ���x = ( s - (n-1)b1 - (n-2)b2 - ���� - bn-1 ) / n.
2.�����������������У��� ( s - (n-1)b1 - (n-2)b2 - ���� - bn-1 ) % n == 0��
  �� ( (n-1)b1 + (n-2)b2 + ���� + bn-1 ) mod n �� s mod n �����ͬ -> ������� -> �౳������

״̬��ʾ��
���Ϻ��壺����dp[i][j]������ֻ����ǰi��(���Ϊn-1���Ϊ��ȥ�˵�һ��x)����ǰi�����ʽ ( (n-1)b1 + (n-2)b2 + ���� + (n-i)bi ) mod n = j �ķ����ļ���

״̬���㣺
���ּ��ϣ�
1.���һ��bi��+a�����з���
2.���һ��bi��-b�����з���
*/

#include<stdio.h>
#define N 1010
#define mod 100000007  

int n, s, a, b;
int dp[N][N];

int get_mod ( int a, int b )
{   
    return ( a % b + b ) % b;
}

int main ( int argc, char *argv[] )
{
    scanf( "%d%d%d%d", &n ,&s, &a, &b );

    dp[0][0] = 1;
    for ( int i = 1; i < n; i++ )
        for ( int j = 0; j < n; j++ )   //�κ���ģ��n���һ��<n
            dp[i][j] = ( dp[i-1][get_mod(j - a * (n - i), n)] + dp[i-1][get_mod(j + b * (n - i), n)] ) % mod;

    printf( "%d\n", dp[n-1][get_mod(s, n)] );

    return 0;
}