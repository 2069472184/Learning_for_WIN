/*
-------��Ŀ����-------

С���� MS.Jinlin �Ǹ������Ĺ��������кܶ�������� "LALA" "NIHAOMA" "WOBUHAO" "NIHAOBUHAO" ���ڶ��·���
���������·�̫����Ҫ������װ�����ӣ�������Ϊ�������϶��ǻ�ͻ����������ļ��·��ÿ����Ͱ������˳�����
��Ȼ�Ǽ��·�������·�Ҳ���ó����ˣ����һ�Ū���ˣ�С�����ھ������εĵ��·���ȡ�·�������֪����������������·�����һ����
�������Ϊ�յĻ����͸����� Empty ������ж��һ�����·����϶���ȡ�����������һ������

-------��������-------

�� 1 �У�����N�������ƽ����˼��β�����

�� 2 ������ N+1 �У����� in out ������in Ϊ �����·���out Ϊ ȡ���·���

��ʽ���£�

    in name1
    out name2

-------�������-------

��� NN �β���������������������·����֣�������Ϊ�գ���� Empty��
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int N, i;
char s1[3], s2[10];

typedef struct stack
{
    int capacity; //�������������Ƿ�ջ����capacity��û�����ˣ�����Ϊ�˹淶�����Ǳ�������
    int number;
    char **Array;
} S;

void in ( char *name, S *clothes )
{
    strcpy( clothes->Array[ ++clothes->number ], name ) ;
}

void out ( char *name, S *clothes )
{
    while ( strcmp( clothes->Array[clothes->number], name ) != 0 ) 
        clothes->number--;
    clothes->number--;
}

int main ( int argc, char *argv[] ) 
{   
    scanf( "%d", &N );

    S *clothes = ( S* )malloc( sizeof( S ) );
    clothes->Array = ( char** )malloc( sizeof( char* ) * ( N + 1 ) );
    for ( i = 0; i <= N; i++ ) 
    {
        clothes->Array[i] = ( char* )malloc( sizeof( char ) * 10 );
        memset( clothes->Array[i], '0', 10 );
    }
    clothes->capacity = N;
    clothes->number = 0;

    while ( N-- ) 
    {
        scanf( "%s %s", s1, s2 );
        getchar();
        if ( strcmp( s1, "in" ) == 0 ) 
            in( s2, clothes );
        if ( strcmp( s1, "out" ) == 0 ) 
            out( s2, clothes );
    }   

    if ( clothes->number != 0 ) 
        printf( "%s\n", clothes->Array[clothes->number] );
    else 
        printf( "Empty\n" );

    for ( i = 0; i <= N; i++ ) 
        free( clothes->Array[i] );
    free( clothes->Array );
    free( clothes );

    return 0;
}