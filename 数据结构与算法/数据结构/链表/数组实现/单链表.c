//https://www.acwing.com/problem/content/828/

//�����������ʵ�֣�
#include<stdio.h>
#define N 100010

int m, x, k;
char how[2];

//���������нڵ��±갴��0��1��2��3������˳������
//ÿ���ڵ���2��ֵe��ne
//head,idx,ne[N]���൱��ָ��ne[idx]��ʾ��ǰidxָ�����һ��ָ��
//ע�⣬idx�������еķֲ��ͽڵ��±겻ͬ�����ǰ�0��1��2��3������˳���ŵ�
int e[N];       //e[N]��ֵ����ÿ���ڵ�洢��ֵ��e���±��Ϊ�ڵ��±�
int ne[N];      //ne[N]��ֵ��ʾnextָ��ָ�����һ���ڵ���±꣬ne���±�Ϊnextָ�����ڽڵ���±�
int head;       //head��ʾ����ͷ�ڵ�ĵ�һ���ڵ���±꣬�ʼ��-1
int idx;        //idx��һ��ָ�룬��ʾ��ǰ�Ѿ��洢�����Ǹ��ڵ���±꣨������ǿսڵ㣩

//��ʼ��
void init ()
{
    head = -1;
    idx = 0;
}

//�ڵ�ͷ��
void add_to_head ( int x )
{
    e[idx] = x;      //��x�洢���±�Ϊidx�Ľڵ���
    ne[idx] = head;  //���ýڵ��nextָ��ָ��head
    head = idx;      //��headָ��ָ��idxָ��
    idx++; 
}

//�ڵ���뵽�±���p�Ľڵ㣨��p+1���ڵ㣩����
void add_behind_p ( int p, int x )
{
    e[idx] = x;
    ne[idx] = ne[p];
    ne[p] = idx;
    idx++;
}

//ɾ���±���p�Ľڵ����Ľڵ�
void remove_behind_p ( int p )
{
    ne[p] = ne[ne[p]];
}

int main ( int argc, char *argv[] )
{
    scanf( "%d", &m );

    init();

    while ( m-- )
    {
        scanf( "%s", how );

        if ( how[0] == 'H' ) 
        {
            scanf( "%d", &x );
            add_to_head( x );
        }
        else if ( how[0] == 'D' ) 
        {
            scanf( "%d%d", &k, &x );
            //�˴����У����kΪ0����ʾɾ��ͷ�ڵ㣬
            //ֻ��Ҫʹͷ�ڵ�ָ��ͷ�ڵ��nextָ��ָ��Ľڵ㣨ɾ����ԭ���ĵ�һ���ڵ㣩
            if ( !k ) head = ne[head];  
            remove_behind_p( k-1 );
        }
        else if ( how[0] == 'I' ) 
        {
            scanf( "%d%d", &k, &x );
            add_behind_p( k-1, x );
        }
    }

    for ( int i = head; i != -1; i = ne[i] ) printf( "%d ", e[i] );
    printf( "\n" );

    return 0;
}