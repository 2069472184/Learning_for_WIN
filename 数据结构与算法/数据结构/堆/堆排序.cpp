//https://www.acwing.com/problem/content/840/

//ST��
/* #include <iostream>
#include <set>
using namespace std;

int n, m, x;
multiset<int> a;

int main ()
{
    cin >> n >> m;
    for ( int i = 0; i < n; i++ )
    {
        cin >> x;
        a.insert(x);
    }
    
    multiset<int>::iterator it = a.begin();
    
    for ( int i = 0; i < m; i++ )
        cout << *it++ << ' ';
    
    return 0;
} */

//ģ���
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <cstring>
#include <sstream>
#include <string>
#include <cstdio>
#include <cctype>
#include <vector>
#include <bitset>
#include <ctime>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
using namespace std;

const int N = 100010;
typedef long long ll;

int n, m, h[N], Size;

void down ( int kk )
{
    int tem = kk;
    //�ж�������Ƿ���ںʹ�С��ϵ
    if ( kk * 2 <= Size && h[kk*2] < h[tem] ) tem = kk * 2;
    //�ж��Ҷ����Ƿ���ںʹ�С��ϵ
    if ( kk * 2 + 1 <= Size && h[kk*2+1] < h[tem] ) tem = kk * 2 + 1;
    //���˵tem!=kk����˵���ӽڵ��и�С��ֵ��
    //������Ҫ�������ڵ�͸��ӽڵ��ֵ���������ӽڵ���±������down����
    if ( kk != tem )
    {
        swap(h[tem], h[kk]);
        down(tem);
    }
    //����ֵ�½����������½�ʱ��kk�ض�����tem����Ȼ������������
}

int main ()
{
    cin >> n >> m;
    Size = n;

    for ( int i = 1; i <= n; i++ ) cin >> h[i];

    //����һ����n�ڵ����ȫ��������Ҷ�ӽڵ�(����ײ��Ԫ��)Ϊn/2(����ȡ��)��
    //����ֻ��Ҫ�Ե����ڶ��㿪ʼ���ϵ�����Ԫ����down������
    for ( int i = n/2; i > 0; i-- ) down(i);
    //ѭ����������Ѿ��������ˣ�����h������±�Ҳ�ʹ˴���

    //���������ǲ����ظ����ͷ�ڵ㲢ɾ���Ĳ���
    while ( m-- )
    {
        cout << h[1] << ' ';
        h[1] = h[Size];
        Size--;
        down(1);
    } 

    return 0;
}