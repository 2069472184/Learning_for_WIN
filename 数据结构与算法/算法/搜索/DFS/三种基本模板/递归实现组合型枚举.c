//https://www.acwing.com/problem/content/95/

//�Լ�д��
/* #include<stdio.h>

int n, m;
int state[26];

void ans ( int u )
{   
    if ( u > m ) 
    {
        for ( int i = 1; i <= m; i++ ) 
            printf( "%d ", state[i] );
        printf( "\n" );
        return;
    }

    for ( int j = 1; j <= n; j++ ) 
    {
        if ( j > state[u-1] )   //�˴����ӵ�������Ϊ�˱�֤����һ����ʼ�մ���ǰ��һ����
        {
            state[u] = j;
            ans( u+1 );
        }
    }
}

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &m );

    ans( 1 );

    return 0;
}
 */

//y�ܽ��
/* #include<stdio.h>

int n, m;
int a[26];

void ans ( int u, int start )
{
    if ( u > m )
    {
        for ( int i = 1; i <= m; i++ ) 
            printf( "%d ", a[i] );
        printf( "\n" );

        return;
    }

    for ( int i = start; i <= n; i++ )
    {
        a[u] = i;
        ans( u+1, i+1 );
        //a[u] = 0;
    }
}

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &m );

    ans( 1, 1 );

    return 0;
} */

//��֦�Ż�
#include<stdio.h>

int n, m;
int a[26];

void ans ( int u, int start )
{
    if ( u + n - start < m ) return;   
    //�˴�Ϊ��֦����ʾ�����λu-1����������ö�ٵĴ���start������������(��n-start+1)С��m�Ļ�����ֱ�ӷ��ء�
    //u-1+n-start+1 = u+n-start < m

    if ( u > m )
    {
        for ( int i = 1; i <= m; i++ ) 
            printf( "%d ", a[i] );
        printf( "\n" );

        return;
    }

    for ( int i = start; i <= n; i++ )
    {
        a[u] = i;
        ans( u+1, i+1 );
        //a[u] = 0;
    }
}

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &m );

    ans( 1, 1 );

    return 0;
}