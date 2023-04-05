//https://www.acwing.com/problem/content/829/

//˫�����ʾ˫��������������������
#include<stdio.h>
#define N 100010

int m, target, num;
char how[5];
int h, t, nel[N], ner[N], e[N], idx;

void init ()
{
    //ͷ�ڵ�Ϊ0�ŵ㣬β�ڵ�Ϊ1�ŵ�
    h = 0;
    t = 1;
    ner[h] = t;
    nel[t] = h;
    idx++;
}

//�˴���ʾ��k�ڵ��������һ���㣬
//���Ҫʵ����k�ڵ���Ҳ���룬���൱����l�ڵ��Ҳ�һ���ڵ�������룬������ner[k]��x
void add_behind_k ( int k, int x )  
{
    e[idx] = x;

    //���½ڵ����ָ��ָ��˫�����k�ڵ�
    nel[idx] = k;
    //���½ڵ����ָ��ָ��k�ڵ����һ���ڵ�
    ner[idx] = ner[k];
    
    //��k�ڵ����ָ��ָ���½ڵ�
    ner[k] = idx;
    //��k����һ���ڵ����ָ��ָ���½ڵ�
    nel[ner[idx]] = idx;

    //�����±�
    idx++;
}

void remove_k ( int k )
{
    //��k�ڵ����ڵ����ָ��ָ��k�ڵ���ҽڵ�
    ner[nel[k]] = ner[k];
    //��k�ڵ���ҽڵ����ָ��ָ��k�ڵ����ڵ�
    nel[ner[k]] = nel[k];
}

int main ( int argc, char *argv[] )
{
    scanf( "%d", &m );

    init();

    while ( m-- )
    {
        scanf( "%s%d", how, &num );
        if ( how[0] == 'L' ) add_behind_k( h, num );
        else if ( how[0] == 'R' ) add_behind_k( nel[t], num );
        else if ( how[0] == 'D' ) remove_k( num+1 ); //�˴���k������˼���±�Ϊ1+k����
        else if ( how[1] == 'L' )
        {
            scanf( "%d", &target );
            add_behind_k( nel[num+1], target );
        }
        else if ( how[1] == 'R' )
        {
            scanf( "%d", &target );
            add_behind_k( num+1, target );
        }
    }

    for ( int i = ner[h]; i != t; i = ner[i] ) printf( "%d ", e[i] );

    return 0;
}