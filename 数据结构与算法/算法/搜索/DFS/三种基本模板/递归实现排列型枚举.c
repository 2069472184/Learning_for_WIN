//https://www.acwing.com/problem/content/96/

//������������ⷨdfs 
#include<stdio.h>

int n, i;
int state[10];    //�±�洢���ֳ���λ�ã�ֵ��������
int used[10];     //usedΪ�������飬0��ʾ�±��Ӧ�����ֻ�û��ʹ�ù���1����ʹ�ù���

void ans ( int u )
{
    if ( u > n ) 
    {
        for ( i = 1; i <= n; i++ ) 
            printf( "%d ", state[i] );
        printf( "\n" );

        return;
    }

    for ( int j = 1; j <= n; j++ )  //�˴����ܶ���y��ȫ�ֱ�������Ϊÿ��ݹ�y��ֵ����Ҫˢ��Ϊ0���������ݵ���һ���ʱ��y��ֵ�ͻᱻ�ı䡣
    {
        if ( !used[j] ) 
        {
            state[u] = j;
            used[j] = 1;
            ans( u+1 );
            //����Ϊ�ָ��ֳ�
            //state[u] = 0;  
            used[j] = 0;     //��������Ǳ�Ҫ�ģ���Ϊ���ݵ���һ��֮��������Ϊ�ж�������Ӱ���������ӵ����ݶ���
        }
    }
}

int main ( int argc, char *argv[] )
{
    scanf( "%d", &n );

    ans(1);

    return 0;
}