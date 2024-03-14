//https://www.acwing.com/problem/content/94/

//��Ϊָ����ö�٣�����Ҫ��һ����n������ѡ��1~n������ѡ���ĺͣ�
//��ѡ�����У�Cn1 + Cn2 + ���� + Cnn = 2^n��Ϊָ����

//���¾�Ϊͷ�ݹ�ⷨ

//�ݹ��������������
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 32800     

int judge[16], n, i, j, k;   //judge(״̬)��ֵΪ0��ʾ��û���ǣ�Ϊ1��ʾѡ��Ϊ2��ʾ��ѡ

struct guide           //����һ���ṹ���Դ洢�����
{
    int number[16];    //number����洢ÿһλ�ϵķ�0����
    int count;         //count��¼��Щ���ֵ�����������������
} G[N];

void ans ( int u )
{
    if ( u > n ) {
        k++;
        for ( i = 1; i <= n; i++ ) 
            if ( judge[i] == 1 ) 
                G[k].number[++G[k].count] = i;
        return;
    }

    judge[u] = 2;   //��uλ����ѡ
    ans( u + 1 );
    //judge[u] = 0;   //�ָ��ֳ�       //����ýڵ�ֻ��һ�����ӣ������ʡ�Իָ��ֳ��Ĳ���
                                      //����ж�����ӣ���Щ������Ҫ�ָ�(һ����һЩ�ж��������漰�ı���)����Щ����
    judge[u] = 1;   //��uλ��ѡ
    ans( u + 1 );
    //judge[u] = 0;   //�ָ��ֳ�

    //return;    //���е������Զ����ݵ���һ��ݹ���ȥ������return
}

int main ( int argc, char *argv[] ) 
{   
    scanf( "%d", &n );

    for ( i = 1; i <= n; i++ ) {
        G[i].count = 0;
        memset( G[i].number, 0, sizeof( G[i].number ) );
    }
    
    ans(1);

    for ( j = 1; j <= k; j++ ) {
        for ( i = 1; i <= G[j].count; i++ ) 
            printf( "%d ", G[j].number[i] );
        printf( "\n" );
    }

    return 0;
}

//�ڵݹ���������
#include<stdio.h>

int judge[20], n, i;   //judge��ֵΪ0��ʾ��û���ǣ�Ϊ1��ʾѡ��Ϊ2��ʾ��ѡ

void ans ( int u )
{
    if ( u > n ) 
    {
        for ( i = 1; i <= n; i++ ) 
            if ( judge[i] == 1 ) 
                printf( "%d ", i );
        printf( "\n" );
        return;
    }

    judge[u] = 2;
    ans( u + 1 );
    //judge[u] = 0;

    judge[u] = 1;
    ans( u + 1 );
    //judge[u] = 0;

    //return;
}

int main ( int argc, char *argv[] ) 
{   
    scanf( "%d", &n );

    ans(1);

    return 0;
}