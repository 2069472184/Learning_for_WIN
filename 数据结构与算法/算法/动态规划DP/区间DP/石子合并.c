//https://www.acwing.com/problem/content/284/

//����ϲ�
/*
״̬��ʾ��dp[i][j]��ʾ���н�����[i,j]����ô���ʯ�Ӻϲ���һ�ѵķ����Ĵ��۵ļ��ϣ�����Ϊmin
״̬���֣�
    1.���ߵ����һ���ǵ�i��.
    ��������
    2.���ߵ����һ���ǵ�k�ѣ�dp[i][j] = min( dp[i][k], dp[k+1][j] ) + s[j] - s[i-1];  //s����Ϊ���ֺ�
    ��������
    3.���ߵ����һ���ǵ�j-1��.
*/
#include <stdio.h>
#include <string.h>
#define min(a,b) ((a)>(b)?(b):(a))
#define N 305

int n, m[N], s[N];
int dp[N][N];

int main ( int argc, char *argv[] )
{
    scanf( "%d", &n );
    for ( int i = 1 ; i <= n; i++ ) 
    {
        scanf( "%d", &m[i] );
        s[i] += s[i-1] + m[i];  //ǰ׺�ͱ���֮������������Ʒ�ϲ�ʱ����������ѵĴ���
    }

    memset(dp, 0x3f, sizeof dp);
    for (int i = 0; i <= n; i++) dp[i][i] = 0;  // �ϲ�һ��ʯ�ӵĴ���Ϊ0
    
    for ( int len = 2; len <= n; len++ )  //��ö�����䳤��
        for ( int i = 1; i + len - 1 <= n; i++ )    //��ö�����Ҷ˵�
        {
            int j = i + len - 1;

            for ( int k = i; k < j; k++ )
                dp[i][j] = min( dp[i][j], dp[i][k] + dp[k + 1][j] + s[j] - s[i-1] );
        }

    printf( "%d\n", dp[1][n] );

    return 0;
}