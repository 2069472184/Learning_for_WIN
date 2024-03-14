//https://www.acwing.com/problem/content/1211/

//�ҳ��ݹ��Ӱ�ӣ������ҵ�����˳��->ȫ����

//��������ö��ȫ���У���ö��λ��������жϵ�ʽ�Ƿ����(�޷���֦)---8574ms
/* #include<stdio.h>
#include<math.h>

long n, box, result;
double a, b, c;
long long state[10];
int used[10], length;

long carryout ( long long *num )
{
    long count = 0;
    for ( int i = 1; i <= 6; i++ )     //�˴�i���Ϊ6����Ϊ���������Ϊ999999����ֳɴ�����������λ�϶�С��999999
    {
        for ( int j = i+1; j <= 8; j++ )
        {
            a = num[i];
            b = num[j] - num[i]*pow(10.0, j-i);
            c = num[9] - num[j]*pow(10.0, 9-j);
            if ( a + b / c == n*1.0 ) count++;
        }
    }
    return count;
}

void ans ( int u )
{
    if ( u > 9 ) 
    {
        result += carryout(state);
        return;
    }

    for ( int i = 1; i <= 9; i++ ) 
    {
        if ( !used[i] )
        {
            used[i] = 1;
            state[u] = i;
            state[u] += state[u-1]*10;
            ans( u+1 );
            used[i] = 0;
        }
    }
}

int main ( int argc, char *argv[] )
{
    scanf( "%ld", &n );
    box = n;
    length = 0;
    while ( box ) 
    {
        box /= 10;
        length++;
    }

    ans(1);

    printf( "%ld\n", result );

    return 0;
} */

//��ö��a����ö��c������ж�b�Ƿ����+��֦---1081ms
//ʹ��֦�Ŀ��ܾ����ܶ࣬��Ҫ���ȷ�����һ����֦�������
#include<stdio.h>

long n;
int used[10], tem[10];
long result;

int check (long a, long c)
{
    long b = n * c - a * c;     //�˴�ͨ����Ŀ�������Ƶ�b��ֵ��֮����ȥ�ж�b�Ƿ����������������ɡ�

    //����һ���������飬��Ӱ��������֧�Ľ���
    int j = 1;
    while ( j < 10 ) 
    {
        tem[j] = used[j];
        j++;
    }

    //�ж�b��ÿһλ�ǲ��Ƕ���Ϊ0�������ж�ÿһλ�Ƿ��ù�
    int x;
    do {       
        x = b % 10;
        b /= 10;
        if ( !x || tem[x] ) return 0;
        tem[x] = 1;
    } while ( b );

    //�ж�1~9��9�������Ƿ񶼱�ʹ��
    for ( int i = 1; i <= 9; i++ ) 
        if ( !tem[i] ) 
            return 0;

    //������ϼ��鶼ͨ������˵��b�������⣬a, b, c��һ����  
    return 1;

}

void dfs_c ( int u, long a, long c )
{
    if ( u == 9 ) return;     //��������Ǳ�Ҫ�ģ�������check�����оͲ�����ֱ�long�������

    if ( check( a, c ) ) result++;

    for ( int i = 1; i <= 9; i++ ) 
    {
        if ( !used[i] )
        {
            used[i] = 1;
            dfs_c( u + 1, a, c * 10 + i );
            used[i] = 0;
        }
    }

}

void dfs_a ( int u, long a )
{
    if ( a > n ) return;    //�˴���֦,��Ϊaһ��������n

    if ( a ) dfs_c( u, a, 0 ); 

    for ( int i = 1; i <= 9; i++ ) 
    {
        if ( !used[i] )  
        {
            used[i] = 1;
            dfs_a( u + 1, a * 10 + i );
            used[i] = 0;
        }
    }
}

int main ( int argc, char *argv[] )
{
    scanf( "%ld", &n );

    dfs_a( 0, 0 );

    printf( "%ld\n", result );

    return 0;
}