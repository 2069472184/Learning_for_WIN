//https://www.acwing.com/problem/content/832/

//�����ⷨ
/* #include<stdio.h>
#define N 100010

int n;
int stk[N], t;

int main ( int argc, char *argv[] )
{
    scanf( "%d", &n );
    for ( int i = 1; i <= n; i++ ) scanf( "%d", &stk[++t] );

    for ( int i = 1; i <= n; i++ )
    {
        int j;
        for ( j = i-1; j > 0; j++ )
        {
            if ( stk[j] < stk[i] ) 
            {
                printf( "%d ", stk[j] );
                break;
            }
        }

        if ( j == 0 ) printf( "-1 ");
    }

    return 0;
} */

//����ջ�Ż�
#include<stdio.h>
#define N 100010

int n, num;
int stk[N], t;

int main ( int argc, char *argv[] )
{
    scanf( "%d", &n );
    for ( int i = 1; i <= n; i++ ) 
    {
        scanf( "%d", &num );

        //���ջ��Ԫ��ֵ>=�·����ֵ���򵯳���ֱ���ҵ���һ������ֵС��ջ��ֵ
        while ( t && num <= stk[t] ) t--;

        if ( t ) printf( "%d ", stk[t] );
        else printf( "-1 ");

        //��������ֵ
        stk[++t] = num;
    }

    return 0;
}