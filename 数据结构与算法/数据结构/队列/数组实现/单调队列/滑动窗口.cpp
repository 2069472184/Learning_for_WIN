//https://www.acwing.com/problem/content/156/

//˫ָ�뱩��
/* #include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 100010;

int n, k, a[N];
int maxn[N], minn[N];

int main ()
{
    cin >> n >> k;
    for ( int i = 0; i < n; i++ ) cin >> a[i];

    memset(minn, 0x3f, sizeof(minn));
    
    memset(maxn, -0x3f, sizeof(maxn));

    for ( int i = 0; i + k <= n; i++ )
    {
        for ( int l = i, r = l + k - 1; r >= l; l++, r-- )
        {
            maxn[i] = max( max( maxn[i], a[l] ), a[r] );
            minn[i] = min( min( minn[i], a[l] ), a[r] );
        }
    }

    for ( int i = 0; i + k <= n; i++ ) cout << minn[i] << ' ';
    cout << endl;
    for ( int i = 0; i + k <= n; i++ ) cout << maxn[i] << ' ';
    cout << endl;

    return 0;
} */

//���������Ż�
//�����С�ֿ�����
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1000010;

int q[N], h = 0, t = -1;   //�����д洢Ԫ���±����Ԫ��ֵ
int n, k, a[N];

int main ()
{
    cin >> n >> k;
    for ( int i = 0; i < n; i++ ) cin >> a[i];
    
    //i��ʾ���ڵ����Ҷ�
    for ( int i = 0; i < n; i++ )
    {
        //�ж϶�ͷ�Ƿ����봰��
        if ( h <= t && i - k + 1 > q[h] ) h++;  

        //��β�±��ӦԪ�� < ��Ԫ��ʱ���±��±�����
        //�������Ա�֤������һ��С���ѣ��ʵ�������״̬�������е���Сֵ�±���Ƕ�ͷ��Ԫ��
        while ( h <= t && a[q[t]] >= a[i] ) t--;

        //���±�����
        q[++t] = i;

        //����i�Ǵ�0��ʼ����������iҪ > ���ڳ��Ȳ���������
        if ( i >= k - 1 ) cout << a[q[h]] << ' ';
    }
    cout << endl;

    //memset(q, 0, sizeof(q));  ����ʡ�Գ�ʼ�����������涼�Ḳ��
    h = 0, t = -1;

    //ͬ��
    for ( int i = 0; i < n; i++ )
    {
        if ( h <= t && i - k + 1 > q[h] ) h++;

        while ( h <= t && a[q[t]] <= a[i] ) t--;

        q[++t] = i;

        if ( i >= k - 1 ) cout << a[q[h]] << ' ';        
    }
    cout << endl;
    
    return 0;
}
